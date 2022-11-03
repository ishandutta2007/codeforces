#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<li, li>;

const int INF = 1e9 + 14;
const int M = 998244353;
const int N = 2e5 + 13;

vector<int> g[N];
int lf[N], rg[N];

pii dfs(int v, int par) {
    pii p = {0, 0};
    for(auto u : g[v]) if(u != par) {
        pii res = dfs(u, v);


        p.f += max(res.f + abs(lf[u] - lf[v]), res.s + abs(rg[u] - lf[v]));
        p.s += max(res.f + abs(lf[u] - rg[v]), res.s + abs(rg[u] - rg[v]));
    }

//    cout << "dfs " << v << ' ' << p.f << ' ' << p.s << endl;

    return p;
}

void solve() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> lf[i] >> rg[i];
        g[i].erase(g[i].begin(), g[i].end());
    }

    for(int i = 1; i < n; i++) {
        int v, u;
        cin >> v >> u;

        v--;
        u--;

        g[v].push_back(u);
        g[u].push_back(v);
    }

    pii p = dfs(0, -1);

    cout << max(p.f, p.s) << endl;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}