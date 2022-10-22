#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 7;
const int V = N << 2;
int nx[N];
vector <int> g[V];
int vert[N];
int pos[V];
bool used[V];
void prec(int v, int tl, int tr) {
    if (tl == tr) {
        pos[v] = tl;
        vert[tl] = v;
        return;
    }   
    int tm = (tl + tr) >> 1;
    g[v].push_back(v * 2 + 1); 
    g[v].push_back(v * 2 + 2);
    prec(v * 2 + 1, tl, tm); prec(v * 2 + 2, tm + 1, tr);
}   
void add(int v, int tl, int tr, int l, int r, int x) {
    if (tr < l || r < tl) return;
    if (l <= tl && tr <= r) {
        g[x].push_back(v);
        return;
    }   
    int tm = (tl + tr) >> 1;
    add(v * 2 + 1, tl, tm, l, r, x); add(v * 2 + 2, tm + 1, tr, l, r, x);
}   
vector <int> tp;
void dfs(int u) {
    used[u] = 1;
    for (int v : g[u]) {
        if (!used[v]) dfs(v);
    }   
    tp.push_back(u);
}   
int imp[V];
int ans[N];

int t = 0;

void solve() {
    ++t;

    int n;
    cin >> n;
    tp.clear();
    for (int i = 0; i < (n << 2); ++i) {
        g[i].clear();
        pos[i] = -1;
        used[i] = 0;
    }
    prec(0, 0, n - 1);
    for (int i = 0; i < n; ++i) {
        cin >> nx[i];
        if (nx[i] != -1) {
            --nx[i];
            add(0, 0, n - 1, i + 1, nx[i] - 1, vert[i]);
            if (nx[i] != n) g[vert[nx[i]]].push_back(vert[i]);
        }   
    }   
    for (int i = 0; i < (n << 2); ++i) {
        if (!used[i]) dfs(i);
    }   
    for (int i = 0; i < (int)tp.size(); ++i) {
        imp[tp[i]] = i;
    }   
    for (int u = 0; u < (n << 2); ++u) {
        for (int v : g[u]) {
            if (imp[u] < imp[v]) {
                cout << "-1\n";
                return;
            }   
        }   
    }
    int ptr = 1;
    for (int v : tp) {
        if (pos[v] != -1) {
            ans[pos[v]] = ptr++;
        }   
    }   
    for (int i = 0; i < n; ++i) cout << ans[i] << ' ';
    cout << '\n';
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int t;
    cin >> t;
    while (t--) solve();
}