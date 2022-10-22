#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2007;

int n;
vector <int> g[MAXN];

int k1, k2;
vector <int> a, b;

int get(char c, int x) {
    cout << c << ' ' << x << endl;
    fflush(stdout);
    int ans;
    cin >> ans;
    if (ans == -1) exit(1);
    return ans;
}

bool ch[MAXN];

int dfs(int u, int parent) {
    if (ch[u]) return u;
    for (int v : g[u]) {
        if (v == parent) continue;
        int t = dfs(v, u);
        if (t != -1) return t;
    }
    return -1;
}

void solve() {
    for (int i = 0; i < MAXN; ++i) g[i].clear();

    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    cin >> k1;
    a.resize(k1);
    for (int i = 0; i < k1; ++i) cin >> a[i];

    memset(ch, 0, sizeof ch);
    for (int e : a) ch[e] = 1;

    cin >> k2;
    b.resize(k2);
    for (int i = 0; i < k2; ++i) cin >> b[i];

    int v = get('B', b[0]);

    if (ch[v]) {
        cout << "C " << v << endl;
        fflush(stdout);
        return;
    }

    int u = dfs(v, v);
    
    int nv = get('A', u);

    bool have = 0;
    for (int e : b) have |= (e == nv);

    if (have) {
        cout << "C " << u << endl;
        fflush(stdout);
        return;
    }   
    
    cout << "C -1" << endl;
    fflush(stdout);
}

signed main() {

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) solve();   

    return 0;
}