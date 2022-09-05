#include <bits/stdc++.h>
using namespace std;

const int maxn = 510, P = 998244353;
int n, m, ans, c[maxn], f[maxn][maxn];

int solve(int l, int r) {
    if (l >= r) return 1;
    if (~f[l][r]) return f[l][r];
    int p = min_element(c + l, c + r + 1) - c;
    int ans1 = 0, ans2 = 0;
    for (int i = l; i <= p; i++) {
        ans1 = (ans1 + 1LL * solve(l, i - 1) * solve(i, p - 1)) % P;
    }
    for (int i = p; i <= r; i++) {
        ans2 = (ans2 + 1LL * solve(p + 1, i) * solve(i + 1, r)) % P;
    }
    return f[l][r] = 1LL * ans1 * ans2 % P;
}

int main() {
    memset(f, -1, sizeof(f));
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &c[i]);
    }
    printf("%d\n", solve(1, n));
    return 0;
}