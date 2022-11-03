#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 1e5 + 13;
const int A = 26;

/*
1
2
2 2
*/

vector<int> g[N];
int d[N], d1[N];

void dfs(int v, int par, int deep) {
    d[v] = deep;

    for(auto u : g[v])
        if(u != par)
            dfs(u, v, deep + 1);
}

void dfs1(int v, int par, int deep) {
    d1[v] = deep;

    for(auto u : g[v])
        if(u != par)
            dfs1(u, v, deep + 1);
}

void solve() {
    int n, a, b, da, db;
    cin >> n >> a >> b >> da >> db;


    a--;
    b--;

    for(int i = 0; i < n; i++) {
        g[i].erase(g[i].begin(), g[i].end());
        d[i] = d1[i] = 0;
    }

    for(int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u;

        v--;
        u--;

        g[v].push_back(u);
        g[u].push_back(v);
    }

    dfs(a, a, 0);

    int mx = 0;
    for(int i = 0; i < n; i++)
        if(d[mx] < d[i])
            mx = i;

    dfs1(mx, mx, 0);

    for(int i = 0; i < n; i++)
        if(d1[mx] < d1[i])
            mx = i;

//    cout << d1[mx] << endl;

    cout << (d[b] <= da || db <= da * 2 || d1[mx] <= da * 2 ? "Alice" : "Bob") << endl;
}

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}