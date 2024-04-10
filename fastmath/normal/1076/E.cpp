#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 3e5 + 7;

int n, m;
vector <int> g[MAXN];
int v[MAXN], d[MAXN], x[MAXN];

void read() {
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }   
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> v[i] >> d[i] >> x[i];
        --v[i];
    }   
}

int h[MAXN];
int tl[MAXN], tr[MAXN];
vector <int> e;

void dfs(int u, int parent, int d) {
    h[u] = d;
    tl[u] = e.size();
    e.push_back(u);
    for (int v : g[u]) {
        if (v == parent) continue;
        dfs(v, u, d + 1);
    }   
    tr[u] = e.size() - 1;
}   

vector <int> open[MAXN], close[MAXN];

int f[MAXN];

void add_(int i, int x) {
    i = min(i, n);
    for (; i < MAXN; i |= (i + 1)) {
        f[i] += x;
    }   
}

int get_(int i) {
    int ans = 0;
    for (; i >= 0; i = (i & (i + 1)) - 1) ans += f[i];
    return ans;
}

void add(int i) {
    int u = v[i];
    add_(h[u] + d[i], x[i]);
}

void del(int i) {
    int u = v[i];
    add_(h[u] + d[i], -x[i]);
}   

int get(int u) {
    return get_(n) - get_(h[u] - 1);
}   

int ans[MAXN];

void solve() {
    dfs(0, 0, 0);
    for (int i = 0; i < m; ++i) {
        int u = v[i];
        open[tl[u]].push_back(i);
        close[tr[u]].push_back(i);
    }   
    for (int i = 0; i < n; ++i) {
        for (int e : open[i]) add(e);
        ans[e[i]] = get(e[i]);
        for (int e : close[i]) del(e);
    }   
}                 

void print() {
    for (int i = 0; i < n; ++i) cout << ans[i] << ' ';
    cout << '\n';    
}

signed main() {
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    read();
    solve();
    print();
            
    return 0;
}