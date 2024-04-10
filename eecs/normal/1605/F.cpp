#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 85, maxm = 6405;
int n, m, P, ans, pw[maxm], C[maxn][maxn], f[maxn][maxn], tot[maxn][maxn], bad[maxn][maxn];

int down(int x, int y) {
    int ans = 1;
    for (int i = x; i >= x - y + 1; -- i) ans = (ll)ans * i % P;
    return ans;
}

int main() {
    scanf("%d %d %d", &n, &m, &P);
    for (int i = pw[0] = 1; i < maxm; i++) {
        pw[i] = pw[i - 1] * 2 % P;
    }
    for (int i = 0; i < maxn; i++) {
        for (int j = C[i][0] = 1; j <= i; j++) {
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % P;
        }
    }
    for (int i = 0; i <= n; i++) for (int j = 0; j <= m; j++) {
        for (int k = 0; k <= j; k++) {
            int coef = (ll)C[j][k] * pw[i * k] % P;
            (tot[i][j] += (j - k) & 1 ? P - coef : coef) %= P;
            coef = (ll)C[j][k] * down(pw[k] - 1, i) % P;
            (f[i][j] += (j - k) & 1 ? P - coef : coef) %= P;
        }
    }
    for (int i = 0; i <= n; i++) for (int j = 0; j <= m; j++) {
        for (int a = 0; a < i; a++) for (int b = 0; b < j; b++) {
            if (n % 2 && i == n && a == n - 1) continue;
            (bad[i][j] += (ll)C[i][a] * C[j][b] % P * f[i - a][j - b] % P * (tot[a][b] - bad[a][b]
                    + P) % P * pw[(i - a) * b] % P) %= P;
        }
    }
    for (int i = 0; i <= m; i++) {
        (ans += (ll)C[m][i] * (tot[n][i] - bad[n][i] + P) % P) %= P;
    }
    printf("%d\n", ans);
    return 0;
}