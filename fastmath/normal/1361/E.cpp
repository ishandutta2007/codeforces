#include<bits/stdc++.h>
using namespace std;
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC

const int N = 2e5 + 7;
vector <int> g[N], tree[N], link[N];
int r[N], c[N];

//r - last, c - current type

int ptr = 1;
int add[N];
bool dfs1(int u) {
    c[u] = 1;
    r[u] = ptr;
    for (int v : g[u]) {
        if (r[v] < r[u]) {
            tree[u].app(v);
            if (!dfs1(v))
                return 0;
        }
        else if (c[v] == 2) {
            return 0;            
        }
        else {
            link[u].app(v);
            --add[v];
            ++add[u];
        }   
    }   
        
    c[u] = 2;
    return 1;
}   

int h[N], up[N];
int getup(int u, int v) {
    if (u == -1)
        return v;
    if (v == -1)
        return u;
    if (h[u] < h[v])
        return u;
    else
        return v;
}
void dfs2(int u) {
    up[u] = -1;
    for (auto e : link[u])
        up[u] = getup(up[u], e);
    for (int v : tree[u]) {
        h[v] = h[u] + 1;
        dfs2(v);
        add[u] += add[v];
        up[u] = getup(up[u], up[v]);
    }   
}
bool bad[N];
void dfs3(int u, vector <int> &ans) {
    if (h[u]) {
        bad[u] = (add[u] > 1) || bad[up[u]];
    }   
    if (!bad[u])
        ans.app(u);
    for (int v : tree[u])
        dfs3(v, ans);                    
}   

mt19937 rnd(2007);
void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        g[i].clear();
        tree[i].clear();
        link[i].clear();
        add[i] = 0;
        bad[i] = 0;
    }   

    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        g[u].app(v);
    }   

    vector <int> ord;
    for (int i = 1; i <= n; ++i) 
        ord.app(i);
    shuffle(all(ord), rnd);

    int root = -1;
    for (int p = 0; p < min(100, n); ++p) {
        for (int i = 1; i <= n; ++i) {
            tree[i].clear();
            link[i].clear();
            add[i] = 0;
            bad[i] = 0;
        }   
        int u = ord[p];
        ++ptr;
        if (dfs1(u)) {
            root = u;
            break;
        }
    }   

    if (root == -1) {
        cout << -1 << endl;
        return;
    }   

    vector <int> ans;
    h[root] = 0;
    dfs2(root);

    dfs3(root, ans);

    if (ans.size() * 5 < n) {
        cout << -1 << endl;
        return;
    }   
    sort(all(ans));
    for (auto e : ans)
        cout << e << ' ';
    cout << endl;
}   

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

}