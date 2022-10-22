#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 7;

int n, k;
vector <int> g[MAXN];
void read() {
    cin >> n >> k;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v; 
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

multiset <int> dp[MAXN];

void add(multiset <int> &ms, int x, int d) {
    auto it = ms.upper_bound(k + 2 * d - x);
    if (it == ms.begin()) {
        ms.insert(x);
    }
    else {
        --it;
        int m = max(x, *it);
        ms.erase(it);
        ms.insert(m);
    }
}

void dfs(int u, int parent, int d) {
    for (int v : g[u]) {
        if (v == parent) continue;
        dfs(v, u, d + 1);
    }
    int mx = -1;
    for (int v : g[u]) {
        if (v == parent) continue;
        if (mx == -1 || dp[mx].size() < dp[v].size()) mx = v;
    }
    if (mx == -1) {
        add(dp[u], d, d);
        return;
    }   
    else {                                 
        swap(dp[u], dp[mx]);
        if (g[u].size() == 1) add(dp[u], d, d);
        for (int v : g[u]) {
            if (v == parent || v == mx) continue;
            for (int nv : dp[v]) {
                add(dp[u], nv, d);
            }   
            dp[v].clear();
        }
    }
}

void solve() {
    dfs(0, 0, 0);
}

void print() {
    cout << dp[0].size() << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    read();
    solve();
    print();

    return 0;
}