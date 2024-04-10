#include <bits/stdc++.h>
using namespace std;

const int maxn = 150010, maxV = maxn * 32, P = 998244353;
int n, X, tot = 1, sz[maxV], ch[maxV][2], pw[maxn];

int calc(int d, int k1, int k2, int lim) {
    if (!sz[k1] || !sz[k2]) return 0;
    if (!~d) return 1LL * (pw[sz[k1]] - 1) * (pw[sz[k2]] - 1) % P;
    if (lim >= (1 << d)) {
        int t1 = (1LL * calc(d - 1, ch[k1][0], ch[k2][1], lim ^ (1 << d)) + pw[sz[ch[k1][0]]] + pw[sz[ch[k2][1]]] - 1) % P;
        int t2 = (1LL * calc(d - 1, ch[k1][1], ch[k2][0], lim ^ (1 << d)) + pw[sz[ch[k1][1]]] + pw[sz[ch[k2][0]]] - 1) % P;
        int t = 1LL * t1 * t2 % P;
        return (1LL * t - (pw[sz[k1]] - 1) - (pw[sz[k2]] - 1) - 1 + 2 * P) % P;
    } else {
        return (calc(d - 1, ch[k1][0], ch[k2][0], lim) + calc(d - 1, ch[k1][1], ch[k2][1], lim)) % P;
    }
}

int solve(int d, int k) {
    if (!sz[k]) return 0;
    if (!~d) return pw[sz[k]] - 1;
    if (!sz[ch[k][0]]) return solve(d - 1, ch[k][1]);
    if (!sz[ch[k][1]]) return solve(d - 1, ch[k][0]);
    if (X < (1 << d)) return (solve(d - 1, ch[k][0]) + solve(d - 1, ch[k][1])) % P;
    int ans = (pw[sz[ch[k][0]]] + pw[sz[ch[k][1]]] - 2) % P;
    return (ans + calc(d - 1, ch[k][0], ch[k][1], X ^ (1 << d))) % P;
}

int main() {
    scanf("%d %d", &n, &X);
    for (int i = pw[0] = 1; i <= n; i++) {
        pw[i] = 2 * pw[i - 1] % P;
    }
    for (int i = 1, x; i <= n; i++) {
        scanf("%d", &x);
        int cur = 1;
        sz[1]++;
        for (int j = 29; ~j; j--) {
            int c = x >> j & 1;
            if (!ch[cur][c]) ch[cur][c] = ++tot;
            sz[cur = ch[cur][c]]++;
        }
    }
    printf("%d\n", solve(29, 1));
    return 0;
}