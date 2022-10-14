#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
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

constexpr int N=2e4+5;

struct Edge {
    int to, nxt;
    char c;

    Edge() {}
    Edge(int to, char c, int nxt): to(to), c(c), nxt(nxt) {}
} edge[2*N];
int lst[N];
int n, q;

int e=0;
void add_edge(int u, int v, char c) {
    edge[++e]=Edge(v, c, lst[u]);
    lst[u]=e;
}

int par[N];
int dep[N];
char c[N];
int sz[N];
int heavy[N], heavy_size[N];

void dfs1(int u, int p=0) {
    par[u]=p;
    sz[u]=1;
    for(int id=lst[u]; id; id=edge[id].nxt) {
        int v=edge[id].to;
        if(v!=p) {
            c[v]=edge[id].c;
            dep[v]=dep[u]+1;
            dfs1(v, u);
            sz[u]+=sz[v];
            if(sz[v]>heavy_size[u]) {
                heavy[u]=v;
                heavy_size[u]=sz[v];
            }
        }
    }
}

int tin[N];

void dfs2(int u) {
    static int t=0;
    tin[u]=++t;
    if(heavy[u]) dfs2(heavy[u]);
    for(int id=lst[u]; id; id=edge[id].nxt) {
        int v=edge[id].to;
        if(v!=par[u]&&v!=heavy[u]) dfs2(v);
    }
}

int conv[N];

template<typename T>
void __reorder(T a[], bool reorder_elem=0) {
    vector<T> buf(n+1);
    rep1(i, n) buf[i]=a[conv[i]];
    rep1(i, n) a[i]=buf[i];
    if (reorder_elem) {
        rep1(i, n) a[i]=tin[a[i]];
    }
}

void reorder() {
    rep1(i, n) conv[tin[i]]=i;
    rep1(i, e) edge[i].to=tin[edge[i].to];
    __reorder(par, 1);
    __reorder(dep);
    __reorder(lst);
    __reorder(c);
    __reorder(sz);
}

char s[N];
char invs[N];
int mark[N];
int ans, k, invk;

unordered_map<int, int> cache[N];

void solve_query(int u, int v) {
    if(cache[u].find(v)!=cache[u].end()) return void(ans=cache[u][v]);
    k=invk=ans=0;
    int _u=u, _v=v;
    while(u!=v) {
        if(dep[u]>dep[v]) s[++k]=c[u], u=par[u];
        else invs[++invk]=c[v], v=par[v];
    }
    for(int i=invk; i; i--) s[++k]=invs[i];
    memset(mark, -1, sizeof(mark));
    for(int id=lst[_u]; id; id=edge[id].nxt) {
        int v=edge[id].to;
        if(v!=par[_u]) mark[v]=1;
    }
    for(int i=1, x=par[_u], prv=_u; x&&i<=k; i++, prv=x, x=par[x]) {
        if(c[prv]<s[i]) {ans+=n-sz[prv]; break;}
        if(c[prv]>s[i]) break;
        if(i==k) continue;
        ans++;
        for(int id=lst[x]; id; id=edge[id].nxt) {
            int v=edge[id].to;
            if(v!=par[x]&&v!=prv) mark[v]=i+1;
        }
    }
    rep1(i, n) if(~mark[i]) {
        if(c[i]<s[mark[i]]) {
            ans+=sz[i];
            i+=sz[i]-1;
        }
        else if(c[i]>s[mark[i]]||mark[i]==k) i+=sz[i]-1;
        else {
            ans++;
            for(int id=lst[i]; id; id=edge[id].nxt) {
                int v=edge[id].to;
                if(v!=par[i]) mark[v]=mark[i]+1;
            }
        }
    }
    cache[_u][_v]=ans;
}

int32_t main() {
    fastio;
    cin>>n>>q;
    rep(i, n-1) {
        int u, v; char c; cin>>u>>v>>c;
        add_edge(u, v, c);
        add_edge(v, u, c);
    }
    dfs1(1);
    dfs2(1);
    reorder();
    while(q--) {
        int u, v; cin>>u>>v; u=tin[u], v=tin[v];
        solve_query(u, v);
        cout<<ans<<endl;
    }
}