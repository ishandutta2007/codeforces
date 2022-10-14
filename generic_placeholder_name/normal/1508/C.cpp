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

constexpr int N=2e5+5;
constexpr int T=650;
int u[N], v[N], w[N];
int dist[T][T];
vi adj[N];
int deg[N];
bool vis[N];
bool in[N];
int n, m, t, xr;
ll ans;


struct dsu {
    int d[N];
    void reset(int n) {memset(d, -1, n*sizeof(int));}
    dsu() {reset(N);}
    int find(int x) {return d[x]<0?x:d[x]=find(d[x]);}
    void join(int x, int y) {
        x=find(x), y=find(y);
        if(x==y) return;
        if(d[x]>d[y]) swap(x, y);
        d[x]+=d[y]; d[y]=x;
    }
    bool is_joined(int x, int y) {
        return find(x)==find(y);
    }
} d;

int32_t main() {
    fastio;
    cin>>n>>m;
    rep(i, m) {
        cin>>u[i]>>v[i]>>w[i]; --u[i], --v[i];
        xr^=w[i];
        adj[u[i]].pb(i);
        adj[v[i]].pb(i);
    }
    if(n*1LL*(n-1)/2>=n+m) {
        vi large, small;
        rep(i, n) {
            if(n-adj[i].size()>n/2) large.pb(i);
            else small.pb(i);
        }
        rep1(i, (int)large.size()-1) d.join(large[i], large[0]);
        for(int i: small) {
            bitset<N> to;
            for(int idx: adj[i]) to[u[idx]]=to[v[idx]]=1;
            rep(v, n) {
                if(v!=i&&!to[v]) d.join(i, v);
            }
        }
        vi edges(m); iota(all(edges), 0);
        sort(all(edges), [](int x, int y) {return w[x]<w[y];});
        for(int i: edges) if(!d.is_joined(u[i], v[i])) {
            d.join(u[i], v[i]);
            ans+=w[i];
        }
        return cout<<ans<<endl, 0;
    }
    assert(n<=T);
    rep(i, m) dist[u[i]][v[i]]=dist[v[i]][u[i]]=w[i];
    vector<pii> unset;
    rep(i, n) rep(j, i) if(!dist[i][j]) unset.eb(i, j);
    vi edges(m); iota(all(edges), 0);
    sort(all(edges), [](int x, int y) {return w[x]<w[y];});
    for(auto& [x, y]: unset) d.join(x, y);
    for(int i: edges) if(!d.is_joined(u[i], v[i])) {
        d.join(u[i], v[i]);
        ans+=w[i];
    }
    ans+=xr;
    for(auto& [x, y]: unset) {
        int cnt=0; ll mst=0;
        d.reset(n);
        for(auto& [_u, _v]: unset) if(_u!=x||_v!=y) {
            if(!d.is_joined(_u, _v)) {
                d.join(_u, _v);
                cnt++;
            }
        }
        assert(cnt<n-1);
        for(int i: edges) if(!d.is_joined(u[i], v[i])) {
            d.join(u[i], v[i]);
            cnt++;
            mst+=w[i];
            if(cnt==n-1) {
                ans=min(ans, mst);
                break;
            }
        }
    }
    cout<<ans<<endl;
}