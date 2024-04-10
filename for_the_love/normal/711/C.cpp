#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 7;

long long f[N][N][N], l[N][N][N], r[N][N][N];

int c[N], p[N][N];

int n, m, K;

int main() {
    cin >> n >> m >> K;
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
        cin >> p[i][j];

    memset(f, 0x7f, sizeof(f));
    memset(l, 0x7f, sizeof(l));
    memset(r, 0x7f, sizeof(r));

    f[0][0][0] = 0;
    r[0][0][0] = 0;
    for (int i = 0; i <= m; i++)
        l[0][0][i] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= K; j++) {
            for (int k = 1; k <= m; k++) {
                int delta;
                if (c[i] == 0) delta = p[i][k];
                else if (c[i] == k) delta = 0;
                else continue;
                f[i][j][k] = f[i - 1][j][k] + delta;
                f[i][j][k] = min(f[i][j][k], l[i - 1][j - 1][k - 1] + delta);
                f[i][j][k] = min(f[i][j][k], r[i - 1][j - 1][k + 1] + delta);
            }
            l[i][j][0] = f[0][0][1];
            for (int k = 1; k <= m; k++)
                l[i][j][k] = min(f[i][j][k], l[i][j][k - 1]);

            r[i][j][m + 1] = f[0][0][1];
            for (int k = m; k >= 1; k--) {
                r[i][j][k] = min(f[i][j][k], r[i][j][k + 1]);
            }
        }
    }




    long long ans = f[0][0][1];
    for (int i = 1; i <= m; i++)
        ans = min(ans, f[n][K][i]);

    if (ans == f[0][0][1]) puts("-1");
    else cout << ans << endl;



}