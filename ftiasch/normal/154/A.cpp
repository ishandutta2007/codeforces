#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>
using namespace std;

const int N = 111111;
const int INF = 1000000000;

int n, m, dp[N][26];
char s[N];
bool conflict[26][26];

void update(int &x, int a) {
    x = min(x, a);
}

int main() {
    scanf("%s", s);
    n = strlen(s);
    for (int i = 0; i < n; ++ i) {
        s[i] -= 'a';
    }
    scanf("%d", &m);
    memset(conflict, 0, sizeof(conflict));
    for (int i = 0; i < m; ++ i) {
        char buffer[26];
        scanf("%s", buffer);
        conflict[buffer[0] - 'a'][buffer[1] - 'a'] = true;
        conflict[buffer[1] - 'a'][buffer[0] - 'a'] = true;
    }
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < 26; ++ j) {
            dp[i + 1][j] = INF;
        }
        for (int j = 0; j < 26; ++ j) {
            if (!conflict[j][(int)s[i]]) {
                update(dp[i + 1][(int)s[i]], dp[i][j]);
            }
            update(dp[i + 1][j], dp[i][j] + 1);
        }
    }
    int result = INF;
    for (int j = 0; j < 26; ++ j) {
        result = min(result, dp[n][j]);
    }
    printf("%d\n", result);
    return 0;
}