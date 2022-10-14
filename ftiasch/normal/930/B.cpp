#include <algorithm>
#include <cstdio>
#include <cstring>

const int N = 5000;

char s[N + 1];
int cnt[26], cnt2[26][N][26];

int main()
{
    scanf("%s", s);
    int n = strlen(s);
    for (int i = 0; i < n; ++ i) {
        cnt[s[i] - 'a'] ++;
        for (int j = 1; j < n; ++ j) {
            cnt2[s[i] - 'a'][j][s[(i + j) % n] - 'a'] ++;
        }
    }
    double result = 0;
    for (int s = 0; s < 26; ++ s) {
        int m = 0;
        for (int len = 1; len < n; ++ len) {
            int sum = 0;
            for (int c = 0; c < 26; ++ c) {
                sum += cnt2[s][len][c] == 1;
            }
            m = std::max(m, sum);
        }
        result += 1.0 * m / n;
    }
    printf("%.9f\n", result);
}