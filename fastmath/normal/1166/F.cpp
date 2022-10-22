#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 7;
map <int, int> num[N];
int nm[N];
int n, m, c, q;
struct Quer {
    bool add;
    int u, v, c;        
};
vector <int> a[N];
int par[N];
set <int> ms[N];
int root(int u) {
    if (u == par[u]) return u;
    else return par[u] = root(par[u]);
}   
void merge(int u, int v) {
    u = root(u); v = root(v);
    if (u == v) return;
    if (ms[v].size() < ms[u].size()) swap(u, v);
    for (int e : ms[u]) ms[v].insert(e);
    ms[u].clear();
    par[u] = v;
}  
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n >> m >> c >> q;
    vector <Quer> d;
    for (int i = 0; i < m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        a[u].push_back(c); a[v].push_back(c);
        d.push_back({1, u, v, c});
    }   
    for (int i = 0; i < q; ++i) {
        char t;
        cin >> t;
        if (t == '+') {
            int u, v, c;
            cin >> u >> v >> c;
            a[u].push_back(c); a[v].push_back(c);
            d.push_back({1, u, v, c});
        }
        else {
            int u, v;
            cin >> u >> v;
            d.push_back({0, u, v});
        }   
    }   
    int ptr = 0;
    for (int i = 1; i <= n; ++i) {
        ms[ptr] = {i};
        nm[i] = ptr++;
        sort(a[i].begin(), a[i].end());
        a[i].resize(unique(a[i].begin(), a[i].end()) - a[i].begin());
        for (int e : a[i]) {
            ms[ptr] = {i};
            num[i][e] = ptr++;
        }   
    }   
    for (int i = 0; i < ptr; ++i) {
        par[i] = i;
    }   
    for (auto e : d) {
        if (e.add) {
            merge(nm[e.u], num[e.v][e.c]);                
            merge(num[e.u][e.c], nm[e.v]);
        }
        else {
            int r = root(nm[e.u]);
            if (ms[r].find(e.v) != ms[r].end()) cout << "Yes\n";
            else cout << "No\n";
        }   
    }   
}