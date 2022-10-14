#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define gcd __gcd
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define rep(i, n) for (int i=0; i<(n); i++)
#define rep1(i, n) for (int i=1; i<=(n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned uint;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
template<typename T, typename cmp = less<T>>
using ordered_set=tree<T, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

struct SegTree {
    struct Node {
        int sum;
        Node *l, *r;
        Node(): sum(0), l(nullptr), r(nullptr) {}
    };

    void add(Node* root, int pos, int val, int l, int r) {
        root->sum+=val;
        if(l==r) return;
        int m=(l+r)/2;
        if(pos<=m) {
            if(root->l==nullptr) root->l=new Node();
            add(root->l, pos, val, l, m);
        }
        else {
            if(root->r==nullptr) root->r=new Node();
            add(root->r, pos, val, m+1, r);
        }
    }

    int get(Node* root, int ql, int qr, int l, int r) {
        if (!root||l>r||ql>r||qr<l) return 0;
        if(ql<=l&&qr>=r) return root->sum;
        else {
            int m=(l+r)/2;
            return get(root->l, ql, qr, l, m)+get(root->r, ql, qr, m+1, r);
        }
    }

    int N;
    Node* rt;

    SegTree(int N): N(N) {rt = new Node();}
    void add(int pos, int val) {add(rt, pos, val, 0, N - 1);}
    int get(int ql, int qr) {return get(rt, ql, qr, 0, N - 1);}
};

constexpr int N = 1e5 + 5;
constexpr int S = 100;

map<string, int> idx;
vector<string> vec;
vector<SegTree> t;

int ls[N], rs[N];
int l[N], r[N];

vector<pair<int, char>> adj[N];
int heavy[N];
int sz[N];
int par[N];
char par_edge[N];
int dep[N];
int nxt[N];
int ord[N];
int tour[N];
int rtour[N];

void dfs1(int u, int p = -1) {
    sz[u] = 1;
    for(auto& [v, c]: adj[u]) if(v != p) {
        par[v] = u;
        par_edge[v] = c;
        dep[v] = dep[u] + 1;
        dfs1(v, u);
        if(!~heavy[u] || sz[v] > sz[heavy[u]]) heavy[u] = v;
        sz[u] += sz[v];
    }
}

void dfs2(int u, int p = -1) {
    static int t = 0;
    tour[u] = t;
    rtour[t++] = u;
    if(~heavy[u]) {
        nxt[heavy[u]] = nxt[u];
        dfs2(heavy[u], u);
    }
    for(auto& [v, _]: adj[u]) if(v != p && v != heavy[u]) {
        nxt[v] = v;
        dfs2(v, u);
    }
}

int lca(int u, int v) {
    while(nxt[u] != nxt[v]) {
        if(dep[nxt[u]] > dep[nxt[v]]) swap(u, v);
        v = par[nxt[v]];
    }
    if(dep[u] > dep[v]) swap(u, v);
    return u;
}

vi z(const string& s) {
    int n = s.size();
    vi z(n);
    for(int i = 1, l = 0, r = 0; i < n; ++i) {
        if(i <= r) z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
        if(i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }
    return z;
}

int col(const string& s, const string& t) {
    string all = t + '#' + s;
    auto Z = z(all);
    int ans = 0;
    rep(i, s.size()) ans += Z[i + t.size() + 1] == t.size();
    return ans;
}

int32_t main() {
    fastio;
    int n; cin >> n;
    rep(_, n - 1) {
        int u, v; char c; cin >> u >> v >> c; --u, --v;
        adj[u].eb(v, c);
        adj[v].eb(u, c);
    }
    rep(i, n) heavy[i] = -1;
    dfs1(0);
    dfs2(0);
    int q; cin >> q;
    int __t = 0;
    rep(i, q) {
        cin >> l[i] >> r[i]; --l[i], --r[i];
        string s; cin >> s;
        if(idx.find(s) != idx.end()) ls[i] = idx[s];
        else {
            ls[i] = idx[s] = __t++;
            vec.pb(s);
            t.eb(n);
        }
        reverse(all(s));
        if(idx.find(s) != idx.end()) rs[i] = idx[s];
        else {
            rs[i] = idx[s] = __t++;
            vec.pb(s);
            t.eb(n);
        }
        reverse(all(s));
    }
    rep(i, n) {
        int cur = i; string s = "";
        rep(_, min(S, dep[i])) {
            s += par_edge[cur];
            cur = par[cur];
            if(idx.find(s) != idx.end()) t[idx[s]].add(tour[i], 1);
        }
    }
    rep(i, q) {
        int ans = 0;
        int v = lca(l[i], r[i]);
        string mid = "";
        string s = vec[ls[i]];
        int len = s.size();
        int u = l[i];
        if(dep[u] - len >= dep[v]) {
            while(dep[nxt[u]] - len > dep[v]) {
                ans += t[ls[i]].get(tour[nxt[u]], tour[u]);
                u = par[nxt[u]];
            }
            int df = dep[u] - len - dep[v];
            ans += t[ls[i]].get(tour[u] - df, tour[u]);
            u = par[rtour[tour[u] - df]];
        }
        string tmp = "";
        while(u != v) tmp += par_edge[u], u = par[u];
        mid += tmp;
        u = r[i];
        if(dep[u] - len >= dep[v]) {
            while(dep[nxt[u]] - len > dep[v]) {
                ans += t[rs[i]].get(tour[nxt[u]], tour[u]);
                u = par[nxt[u]];
            }
            int df = dep[u] - len - dep[v];
            ans += t[rs[i]].get(tour[u] - df, tour[u]);
            u = par[rtour[tour[u] - df]];
        }
        tmp = "";
        while(u != v) tmp += par_edge[u], u = par[u];
        reverse(all(tmp));
        mid += tmp;
        ans += col(mid, s);
        cout << ans << endl;
    }
}