#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

#pragma 03

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
template<typename _def> using ordered_set=tree<_def, null_type, less<_def>, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

constexpr int N=2e5+1;

struct dsu {
    vi d;
    dsu() {}
    dsu(int n): d(n, -1) {}
    int find(int x) {return d[x]<0?x:d[x]=find(d[x]);}
    void join(int x, int y) {
        x=find(x), y=find(y);
        if(x==y) return;
        if(d[x]>d[y]) swap(x, y);
        d[x]+=d[y];
        d[y]=x;
    }
} D(N);

struct edge {
    int u, v;
    bool used=0;
    edge() {}
    edge(int u, int v): u(u), v(v) {}
} E[N];

vi G[N];
int a[N];
int ans[N];
int lvl[N], sum[N];

void dfs(int u, int par=-1) {
    sum[u]=a[u];
    for(int v: G[u]) if(v!=par) {
        lvl[v]=lvl[u]+1;
        dfs(v, u);
        sum[u]+=sum[v];
    }
}

int32_t main() {
    fastio;
    int n; cin>>n;
    rep(i, n) cin>>a[i];
    if(accumulate(a, a+n, 0)!=0) return cout<<"Impossible\n", 0;
    cout<<"Possible\n";
    int m; cin>>m;
    rep(i, m) {
        int u, v; cin>>u>>v;
        E[i]={u-1, v-1};
    }
    rep(i, m) if(D.find(E[i].u)!=D.find(E[i].v)) {
        D.join(E[i].u, E[i].v);
        E[i].used=1;
        G[E[i].u].pb(E[i].v);
        G[E[i].v].pb(E[i].u);
    }
    dfs(0);
    rep(i, m) {
        if(E[i].used) ans[i]=lvl[E[i].u]<lvl[E[i].v]?sum[E[i].v]:-sum[E[i].u];
        cout<<ans[i]<<endl;
    }
}