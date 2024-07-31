#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

int find_word(const char* word, char words[MAX_WORDS][MAX_WORD_LENGTH], int counts[MAX_WORDS], int num_words);

int main() {
    char input[10000];
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int counts[MAX_WORDS] = {0};
    int num_words = 0;

    printf("Enter a paragraph:\n");
    fgets(input, sizeof(input), stdin);

    char* token = strtok(input, " \t\n,.!?;:");
    while (token != NULL) {
        // Convert token to lowercase
        for (int i = 0; token[i]; i++) {
            token[i] = tolower(token[i]);
        }

        int index = find_word(token, words, counts, num_words);
        if (index == -1) {
            // New word
            strncpy(words[num_words], token, MAX_WORD_LENGTH - 1);
            words[num_words][MAX_WORD_LENGTH - 1] = '\0';  // Ensure null termination
            counts[num_words] = 1;
            num_words++;
        } else {
            // Existing word
            counts[index]++;
        }

        token = strtok(NULL, " \t\n,.!?;:");
    }

    printf("\nWord Frequencies:\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i], counts[i]);
    }

    return 0;
}

int find_word(const char* word, char words[MAX_WORDS][MAX_WORD_LENGTH], int counts[MAX_WORDS], int num_words) {
    for (int i = 0; i < num_words; i++) {
        if (strcmp(word, words[i]) == 0) {
            return i;
        }
    }
    return -1;
}
