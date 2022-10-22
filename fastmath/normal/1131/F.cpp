#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
int n;
int x[N], y[N];
int to[N];
bool ch[N];
void print() {
    for (int i = 0; i < n; ++i) ch[i] = 1;
    for (int i = 0; i < n; ++i) {
        if (to[i] != -1) {
            ch[to[i]] = 0;
        }   
    }
    int f = -1;   
    for (int i = 0; i < n; ++i) {
        if (ch[i]) {
            f = i;
        }   
    }   
    int c = f;
    for (int i = 0; i < n; ++i) {
        cout << c + 1 << ' ';
        c = to[c];
    }   
    cout << '\n';
}
int par[N];
int l[N], r[N];
int root(int u) {
    if (par[u] == u) return u;
    else return par[u] = root(par[u]);
}   
void merge(int u, int v) {
    par[u] = v;
    l[v] = l[u];
}   
signed main() {
    #ifdef HOME
        freopen("input.txt", "r", stdin);
    #else 
        ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n;
    for (int i = 0; i < n; ++i) {
        par[i] = l[i] = r[i] = i;
    }   
    for (int i = 0; i < n; ++i) {
        to[i] = -1;
    }   
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        u = root(u); v = root(v);
        to[r[u]] = l[v];
        merge(u, v);
    }   
    print();
}