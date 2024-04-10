#include <cstdio>
#include <cstring>

const int N = 10000;
const int M = 1000000;

char s_1[N + 1], s_2[M + 1];
int next[N + 1][26];

int main() {
    scanf("%s%s", s_1, s_2);
    int n = strlen(s_1);
    int m = strlen(s_2);
    for (int c = 0; c < 26; ++ c) {
        next[n][c] = n;
    }
    for (int i = n - 1; i >= 0; -- i) {
        for (int c = 0; c < 26; ++ c) {
            next[i][c] = next[i + 1][c];
        }
        next[i][s_1[i] - 'a'] = i;
    }
    int answer = 0;
    int current = n;
    for (int i = 0; i < m; ++ i) {
        if (next[0][s_2[i] - 'a'] == n) {
            puts("-1");
            return 0;
        }
        if (next[current][s_2[i] - 'a'] < n) {
            current = next[current][s_2[i] - 'a'] + 1;
        } else {
            answer ++;
            current = next[0][s_2[i] - 'a'] + 1;
        }
    }
    printf("%d\n", answer);
    return 0;
}