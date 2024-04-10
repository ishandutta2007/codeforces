#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 7;
int LF = 0;
int par[N];
vector <int> g[N];
bool type[N];
int dfs(int u) {
    vector <int> a;
    for (int v : g[u]) {
        a.push_back(dfs(v));
    }   
    sort(a.begin(), a.end());

    if (a.empty()) return 1;

    if (type[u]) {
        return a[0];
    }
    else {
        int ans = 0;
        for (int e : a) ans += e;
        return ans;
    }   
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> type[i];
    for (int i = 1; i < n; ++i) {
        cin >> par[i]; --par[i];
        g[par[i]].push_back(i);
    }   
    for (int i = 0; i < n; ++i) LF += g[i].empty();
    int w = dfs(0);
    cout << LF - w + 1 << '\n';
}