#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 7;
const int INF = 1e9 + 7;

int tree[MAXN * 4];

void upd(int v, int tl, int tr, int p, int x) {
    if (tl == tr) {
        tree[v] = x;
        return;
    }

    int tm = (tl + tr) / 2;
    if (p <= tm) upd(v * 2 + 1, tl, tm, p, x);
    else upd(v * 2 + 2, tm + 1, tr, p, x);
    tree[v] = max(tree[v * 2 + 1], tree[v * 2 + 2]);
}

int get(int v, int tl, int tr, int l, int r) {
    if (tr < l || r < tl) return -INF;
    if (l <= tl && tr <= r) return tree[v];
    int tm = (tl + tr) / 2;
    return max(get(v * 2 + 1, tl, tm, l, r), get(v * 2 + 2, tm + 1, tr, l, r));
}

int a[MAXN], dp[MAXN];;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < MAXN * 4; ++i) tree[i] = -INF;
    
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int l = lower_bound(a, a + n, (a[i] + 1) / 2) - a;
        int r = i - 1;
        dp[i] = max(1, get(0, 0, n - 1, l, r) + 1);
        upd(0, 0, n - 1, i, dp[i]);
        ans = max(ans, dp[i]);
    }

    cout << ans << '\n';
    return 0;
}