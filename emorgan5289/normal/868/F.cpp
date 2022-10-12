#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e16;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const int N = 1e5+5;
ll a[N], dp[2][N], f[N], s, p, q;

void transform(int u, int v) {
    while (p < u) s -= --f[a[p++-1]];
    while (p > u) s += f[a[--p-1]]++;
    while (q > v) s -= --f[a[q---1]];
    while (q < v) s += f[a[++q-1]]++;
}

void dfs(int l, int r, int x, int y) {
    if (l > r) return;
    int m = (l+r)/2;
    ll j = y-1, c = inf_ll;
    for (int i = min(m, y); i >= x; i--) {
        transform(i, m);
        if (dp[0][i-1]+s < c)
            c = dp[0][i-1]+s, j = i;
    }
    dp[1][m] = c;
    dfs(l, m-1, x, j), dfs(m+1, r, j, y);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    fill(dp[1]+1, dp[1]+N, inf_ll);
    while (k--) {
        copy(dp[1], dp[1]+N, dp[0]);
        s = 0, p = 0, q = -1;
        fill(f, f+N, 0);
        dfs(1, n, 1, n);
    }
    cout << dp[1][n] << "\n";
}