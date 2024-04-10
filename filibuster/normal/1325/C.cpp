#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;

const int M = 1e9 + 7;

void solve() {
}

const int N = 1e5 + 13;

vector<int> g[N];
map<pair<int, int>, int> mp;
int d[N], p[N];

void dfs(int v, int par, int deep) {
//    cout << v << endl;
    d[v] = deep;
    p[v] = par;

    for(auto u : g[v]) {
        if(u != par)
            dfs(u, v, deep + 1);
    }
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> e;
    for(int i = 0; i < n -1 ; i++) {
        int v, u;
        cin >> v >> u;

        v--;
        u--;

        if(v > u)
            swap(v, u);

        e.emplace_back(v, u);

        g[v].push_back(u);
        g[u].push_back(v);

        mp[e.back()] = i;
    }

    if(n == 2) {
        cout << 0 << endl;
        return 0;
    }

//    int mx = 0;
//    for(int i = 0; i < n; i++) {
//        mx = max(g[i].size(), mx);
//    }

    dfs(0, 0, 0);
    int mx = 0;
    for(int i = 0; i < n; i++) {
        if(d[i] > d[mx])
            mx = i;
    }

    if(d[mx] == n - 1) {
        for(int i = 0; i < n - 1; i++)
            cout << i << endl;
        return 0;
    }

    vector<int> ans(n - 1, -1);
    ans[mp[{min(mx, p[mx]), max(mx, p[mx])}]] = 0;

    dfs(mx, -1, 0);

    int mx1 = 0;
    for(int i = 0; i < n; i++) {
        if(d[i] > d[mx1])
            mx1 = i;
    }

    ans[mp[{min(mx1, p[mx1]), max(mx1, p[mx1])}]] = 1;

    int v = mx1;
    int cur = n - 1;
    while(true) {
        v = p[v];
        if(p[v] == mx)
            break;
        ans[mp[{min(v, p[v]), max(v, p[v])}]] = --cur;

    }

    for(int i = 0; i < n - 1; i++) {
        cout << (ans[i] == -1 ? --cur : ans[i]) << endl;
    }

//    int t;
//    cin >> t;
//
//    while(t--)
//        solve();
}