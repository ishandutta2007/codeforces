#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100 + 5;

int n, m, k, P;
int fac[MAX_N], c[MAX_N][MAX_N], f[MAX_N][MAX_N][MAX_N];

int add(int a, int b) {
    return a + b < P ? a + b : a + b - P;
}

void dp(int sz, int cnt, int dep) {
    if (f[dep][sz][cnt] != -1) return ;
    register int &F = f[dep][sz][cnt] = 0;
    if (!sz) {
        F = 1;
        return ;
    }
    if ((m - dep < 7 && (1 << (m - dep)) < cnt) || (cnt && sz < m - dep)) return ;
    if (dep == m) {
        F = (cnt == 1 ? fac[sz] : 0);
        return ;
    }
    for (int i = 0; i < sz; i ++) {
        register int fi = 0;
        register int *fl = f[dep + 1][i], *fr = f[dep + 1][sz - i - 1];
        for (int j = max(0, cnt + i + 1 - sz); j <= min(cnt, i); j ++)
            if (fl[j] && fr[cnt - j]) {
                dp(i, j, dep + 1);
                dp(sz - i - 1, cnt - j, dep + 1);
                fi = (fi + 1ll * fl[j] * fr[cnt - j]) % P;
            }
        F = (F + 1ll * fi * c[sz - 1][i]) % P;
    }
}

int main() {
    cin >> n >> m >> k >> P; m --;
    for (int i = c[0][0] = fac[0] = 1; i <= n; i ++) {
        c[i][0] = c[i][i] = 1;
        fac[i] = 1ll * fac[i - 1] * i % P;
        for (int j = 1; j < i; j ++) c[i][j] = add(c[i - 1][j - 1], c[i - 1][j]);
    }
    memset(f, -1, sizeof(f));
    dp(n, k, 0);
    cout << f[0][n][k] << endl;
    return 0;
}