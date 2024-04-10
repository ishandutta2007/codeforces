#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 500;
const int MAXVAL = 500;
const int INF = 10000000;

int dp[1 + MAXN][1 + MAXVAL];
int dad[1 + MAXN][1 + MAXVAL];
int v[1 + MAXN];
int real[1 + MAXN];

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, k;
    scanf("%d%d", &n, &k);
    dp[0][0] = 0;
    for (int i = 1; i <= k; i++)
        dp[0][i] = INF;
    for (int i = 1; i <= n; i++)
        real[i] = -1;
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        if (x > k) {
            real[i] = x;
            x = k;
        }
        for (int j = 0; j < x; j++)
            dp[i][j] = INF;
        if (i == 1) {
            for (int j = x; j <= k; j++)
                dp[i][j] = j - x;
            continue;
        }
        for (int j = x; j <= k; j++) {
            dp[i][j] = INF;
            for (int l = k - j; l <= k; l++)
                if (dp[i - 1][l] + j - x < dp[i][j]) {
                    dp[i][j] = dp[i - 1][l] + j - x;
                    dad[i][j] = l;
                }
        }
    }
    int answer = INF, where = -1;
    for (int i = 0; i <= k; i++)
        if (dp[n][i] < answer) {
            answer = dp[n][i];
            where = i;
        }
    printf("%d\n", answer);
    for (int i = n; i >= 1; i--) {
        v[i] = where;
        where = dad[i][where];
    }
    for (int i = 1; i <= n; i++)
        if (real[i] == -1)
            printf("%d ", v[i]);
        else
            printf("%d ", real[i]);
    return 0;
}