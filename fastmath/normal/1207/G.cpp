#include<bits/stdc++.h>
using namespace std;
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcount
#define ll long long
#define mp make_pair
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define Time (double)clock()/CLOCKS_PER_SEC
const int N = 4e5 + 7, C = 26;
vector <pair <char, int> > tree[N];
vector <int> q[N];
int ans[N], in_karas[N];
int trie[N][C], father[N];
char last_c[N];
int ptr = 1;
int add_in_karas(string &s) {
    int v = 0;
    for (char c : s) {
        if (!trie[v][c - 'a']) {
            trie[v][c - 'a'] = ptr;
            father[ptr] = v;
            last_c[ptr] = c;
            ++ptr;
        }
        v = trie[v][c - 'a'];
    }   
    return v;
}   
int link_mem[N], automat_mem[N][C];
int automat(int u, char c);
int link(int u) {
    if (u == 0 || father[u] == 0) return 0;
    if (link_mem[u] != -1) return link_mem[u];
    return link_mem[u] = automat(link(father[u]), last_c[u]);
}   
int automat(int u, char c) {
    if (automat_mem[u][c - 'a'] != -1) return automat_mem[u][c - 'a'];
    if (trie[u][c - 'a']) return automat_mem[u][c - 'a'] = trie[u][c - 'a'];
    if (u == 0) return 0;
    return automat_mem[u][c - 'a'] = automat(link(u), c);
}   
vector <int> link_tree[N];
int l[N], r[N], cur = 0;
void dfs_karas(int u) {
    l[u] = ++cur;
    for (int v : link_tree[u]) dfs_karas(v);
    r[u] = cur;
}   
struct Fen {
int f[N];
void clear() {
    for (int i = 0; i < N; ++i) f[i] = 0;
}   
void add(int i, int x) {
    for (; i < N; i |= i + 1) f[i] += x;
}   
int get(int i) {
    int ans = 0;
    for (; i >= 0; i &= i + 1, --i) ans += f[i];
    return ans;
}   
int get(int l, int r) { return get(r) - get(l - 1); }
} f;
void dfs(int u, int karas) {
    f.add(l[karas], 1);
    for (auto e : tree[u]) dfs(e.s, automat(karas, e.f));
    for (int i : q[u]) ans[i] = f.get(l[in_karas[i]], r[in_karas[i]]);
    f.add(l[karas], -1);    
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    for (int i = 0; i < N; ++i) link_mem[i] = -1;
    for (int i = 0; i < N; ++i) for (int j = 0; j < C; ++j) automat_mem[i][j] = -1;
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        int t; cin >> t;
        if (t == 1) {
            char c; cin >> c;
            tree[0].app(mp(c, i));
        }
        else {
            int p; char c; cin >> p >> c;
            tree[p].app(mp(c, i));
        }  
    }   
    int m; cin >> m;
    for (int i = 1; i <= m; ++i) {
        int v; string s; cin >> v >> s;
        q[v].app(i); in_karas[i] = add_in_karas(s);
    }   
    for (int i = 1; i < ptr; ++i) link_tree[link(i)].app(i);
    dfs_karas(0);
    dfs(0, 0);
    for (int i = 1; i <= m; ++i) cout << ans[i] << '\n';
}