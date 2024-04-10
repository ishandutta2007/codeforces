#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9+10;
const ll inf_ll = 1e18+10;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))

#ifndef LOCAL
#define debug(...) 0
#else
#include "../../debug.cpp"
#endif

ll n, k, ans = 0;
vector<ll> len;
vector<vector<ll>> a, dp;

void apply(int i) {
    debug("apply", i);
    vector<ll> b(dp.back());
    for (int j = len[i]; j <= k; j++)
        cmax(b[j], dp.back()[j-len[i]]+a[i].back());
    dp.pb(b);
}

void undo() {
    debug("undo");
    dp.pop_back();
}

void upd(int i) {
    debug("upd", i);
    for (int j = 0; j <= len[i]; j++)
        cmax(ans, dp.back()[k-j]+a[i][j]);
}

void dfs(int l, int r) {
    if (r == l+1) {
        upd(l);
        return;
    }
    int m = (l+r)/2;
    for (int i = l; i < m; i++)
        apply(i);
    dfs(m, r);
    for (int i = l; i < m; i++)
        undo();
    for (int i = m; i < r; i++)
        apply(i);
    dfs(l, m);
    for (int i = m; i < r; i++)
        undo();
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    a.resize(n);
    len.resize(n);
    dp.resize(1);
    dp[0].assign(k+1, -inf_ll);
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        a[i].resize(t+1);
        for (int j = 1; j <= t; j++) {
            cin >> a[i][j];
            a[i][j] += a[i][j-1];
        }
        while (a[i].size() > k+1)
            a[i].pop_back();
        len[i] = a[i].size()-1;
    }
    dfs(0, n);
    cout << ans << "\n";
}