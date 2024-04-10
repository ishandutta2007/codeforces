#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const int N = 3e5+5;
ll d[N], pt[N], ans, sum;
vector<ll> adj[N], dp[N], s;
multiset<ll> f[N];

void dfs1(int i, int p) {
    pt[i] = d[i] = adj[i].size()-(i != 0);
    dp[i].resize(d[i]);
    for (auto& j : adj[i])
        if (j != p) {
            dfs1(j, i);
            for (int k = 0; k < min(d[i], d[j]); k++)
                dp[i][k]++;
            pt[i] += pt[j];
        }
    for (ll k = 0; k < d[i]; k++) {
        if (dp[i][k] <= k)
            dp[i][k] = 1;
        else {
            s.clear();
            for (auto& j : adj[i])
                if (j != p && d[j] > k)
                    s.push_back(dp[j][k]);
            nth_element(s.begin(), s.end()-1-k, s.end());
            debug(i, s, k);
            dp[i][k] = s[s.size()-1-k]+1;
        }
    }
    debug(i, dp[i]);
}

void ins(int i, int p) {
    for (int j = 0; j < d[i]; j++) {
        ll pre = f[j].empty() ? 0 : *--f[j].end();
        f[j].insert(dp[i][j]);
        sum += *--f[j].end()-pre;
    }
    for (auto& j : adj[i])
        if (j != p) ins(j, i);
}

void rem(int i, int p) {
    for (int j = 0; j < d[i]; j++) {
        ll pre = *--f[j].end();
        f[j].erase(f[j].find(dp[i][j]));
        sum += (f[j].empty() ? 0 : *--f[j].end())-pre;
    }
    for (auto& j : adj[i])
        if (j != p) rem(j, i);
}

void dfs2(int i, int p) {
    int k = -1;
    for (auto& j : adj[i])
        if (j != p && (k == -1 || pt[j] > pt[k]))
            k = j;
    for (auto& j : adj[i])
        if (j != p && j != k)
            dfs2(j, i), rem(j, i);
    if (k != -1) dfs2(k, i);
    for (auto& j : adj[i])
        if (j != p && j != k)
            ins(j, i);
    for (int j = 0; j < d[i]; j++) {
        ll pre = f[j].empty() ? 0 : *--f[j].end();
        f[j].insert(dp[i][j]);
        sum += *--f[j].end()-pre;
    }
    debug(i, sum);
    ans += sum;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].pb(v), adj[v].pb(u);
    }
    dfs1(0, 0);
    dfs2(0, 0);
    cout << ans+n*n << "\n";
}