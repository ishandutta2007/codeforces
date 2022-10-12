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

// returns a unique number b s.t. ab = 1 mod m in O(logm) time.
template<typename T>
T inv(T a, T m) {
    T r = 1;
    for (T k = m-2; k; k >>= 1) {
        if (k&1) r = (r*a)%m;
        a = (a*a)%m;
    }
    return r%m;
}

ll n, p;
vector<vector<int>> adj;
vector<vector<ll>> dp1, dp2, ch;

// dp1[k] = number of sequences of length k of non-empty subsets of the subtree of i
// dp2[k] = number of sequences of length k of subsets of the subtree of i

void dfs(int i, int pi) {
    vector<int> c;
    for (int j : adj[i])
        if (j != pi)
            dfs(j, i), c.pb(j);

    vector<ll> x(n, 1);
    vector<vector<ll>> y(c.size(), vector<ll>(n, 0));
    vector<ll> px(c.size(), 1), sx(c.size(), 1);

    for (int k = 0; k < n; k++) {
        for (int j : c)
            x[k] = (x[k]*dp2[j][k])%p;

        fill(all(px), 1), fill(all(sx), 1);
        for (int j = 0; j < c.size(); j++)
            px[j] = ((j == 0 ? 1 : px[j-1])*dp2[c[j]][k])%p;
        if (c.size() > 0)
            for (int j = c.size()-1; j >= 0; j--)
                sx[j] = ((j+1 == c.size() ? 1 : sx[j+1])*dp2[c[j]][k])%p;

        // debug(x[k], px, sx);

        if (k != n-1)
            for (int j = 0; j < c.size(); j++)
                y[j][k+1] = (y[j][k] + (j == 0 ? 1 : px[j-1])*(j+1 == c.size() ? 1 : sx[j+1]))%p;
        for (int j = 0; j < c.size(); j++)
            dp1[i][k] = (dp1[i][k]+dp1[c[j]][k]*y[j][k])%p;
        dp1[i][k] = (dp1[i][k]+x[k])%p;
        dp2[i][k] = ((k == 0 ? 0 : dp2[i][k-1]) + dp1[i][k])%p;
    }

    if (i == 0) {
        // dp3[i] = number of sequences of subsets of length i+1, such that the
        // last one is empty, and the first one is [1..n], possibly with duplicates
        vector<ll> dp3 = x;
        dp3.insert(dp3.begin(), 0);

        // remove dups from dp3
        for (int k = 1; k < n; k++) {
            for (int j = 1; j < k; j++)
                dp3[k] = (dp3[k]-(dp3[j]*ch[k][j])%p+p)%p;
            cout << dp3[k] << " \n"[k == n-1];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> p;
    adj.resize(n);
    dp1.assign(n, vector<ll>(n, 0));
    dp2.assign(n, vector<ll>(n, 0));
    ch.assign(n, vector<ll>(n, 0));

    for (int i = 0; i < n-1; i++) {
        int x, y; cin >> x >> y; x--, y--;
        adj[x].pb(y), adj[y].pb(x);
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++)
            ch[i][j] = (j == 0 || j == i) ? 1 : (ch[i-1][j]+ch[i-1][j-1])%p;

    dfs(0, 0);
}