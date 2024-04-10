// Codeforces Beta Round #50
// Problem D -- Writing a Song
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 111;
const int K = 26;

int n, k, next[N][K], fail[N];
char pattern[N], match[N];
bool dp[N][N];

int main () {
    scanf("%d%d%s%s", &n, &k, pattern + 1, match + 1);
    int len = strlen(pattern + 1);
    fail[0] = fail[1] = 0;    
    for (int j = 0; j < k; ++ j) {
        next[0][j] = 0;
    }
    next[0][pattern[1] - 'a'] = 1;
    for (int i = 1; i <= len; ++ i) {
        if (i + 1 <= len) {
            fail[i + 1] = next[fail[i]][pattern[i + 1] - 'a'];
        }
        for (int j = 0; j < k; ++ j) {
            if (i + 1 <= len && pattern[i + 1] - 'a' == j) {
                next[i][j] = i + 1;
            } else {
                next[i][j] = next[fail[i]][j];
            }
        }
    }
    //for (int i = 0; i <= len; ++ i) {
    //    printf("%d: %d\n", i, fail[i]);
    //    for (int j = 0; j < k; ++ j) {
    //        printf("%d ", next[i][j]);
    //    }
    //    printf("\n");
    //}
    memset(dp, 0, sizeof(dp));
    for (int i = n; i >= 0; -- i) {
        for (int j = 0; j <= len; ++ j) {            
            if (i == n) {
                dp[i][j] = true;
            } else {
                for (int c = 0; c < k; ++ c) {
                    dp[i][j] |= dp[i + 1][next[j][c]];
                }
            }
            if (i >= len) {
                dp[i][j] &= (j == len) ^ (match[i - len + 1] == '0');
            }
        }
    }
    if (dp[0][0]) {
        for (int i = 0, j = 0; i < n; ++ i) {
            int c = 0;
            while (!dp[i + 1][next[j][c]]) {
                c ++;
            }
            printf("%c", 'a' + c);
            j = next[j][c];
        }
        printf("\n");
    } else {
        printf("No solution\n");
    }
    return 0;
}