#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma,popcnt")

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

constexpr int N=40;
vi adj[N];
ll adj_msk[N];
int n, m;

//connected components
vll comps;
bool vis[N];

void dfs(int u, ll& comp) {
    vis[u]=1;
    comp|=(1LL<<u);
    for(int v: adj[u]) if(!vis[v]) dfs(v, comp);
}

void get_connected_components() {
    rep(i, n) if(!vis[i]) {
        comps.pb(0);
        dfs(i, comps.back());
    }
}

int count_components() {
    return comps.size();
}

int count_isolated() {
    int ans=0;
    for(auto& v: comps) ans+=(__builtin_popcountll(v)==1);
    return ans;
}

//bipartiteness
int side[N];
bool check_bipartite() {
    memset(side, -1, sizeof(side));
    bool ok=1;
    queue<int> q;
    rep(u, n) if(!~side[u]) {
        q.push(u);
        side[u]=0;
        while(!q.empty()) {
            int u=q.front(); q.pop();
            for(int v: adj[u]) {
                if(!~side[v]) side[v]=side[u]^1, q.push(v);
                else ok&=(side[u]!=side[v]);
            }
        }
    }
    return ok;
}

#pragma GCC target("bmi,bmi2")
#include<immintrin.h>
unsigned int selectBit(unsigned long long x, unsigned int n) {
    return _tzcnt_u64(_pdep_u64(1ULL << n, x));
} //evil parallel bullshit

int get_rand(int l, int r) {
    uniform_int_distribution<int> engine(l, r);
    return engine(rng);
}

int get_rand_bit(ll v) {
    int x=get_rand(0, __builtin_popcountll(v)-1);
    return selectBit(v, x);
}

//independent set
ll get_independent_set(ll msk) {
    if(!msk) return 1;
    if(__builtin_popcountll(msk)==1) return 2;
    int u=get_rand_bit(msk);
    ll to=adj_msk[u]&msk;
    #define self get_independent_set
    if(!to) return 2*self(msk^(1LL<<u));
    else return self(msk^(1LL<<u))+self(msk^(1LL<<u)^to);
    #undef self
} // this is O(fib(n)), faster is possible, but const factor would be bad

int32_t main() {
    fastio;
    cin>>n>>m;
    rep(_, m) {
        int u, v; cin>>u>>v; --u, --v;
        adj[u].pb(v);
        adj[v].pb(u);
        adj_msk[u]|=(1LL<<v);
        adj_msk[v]|=(1LL<<u);
    }
    get_connected_components();
    ll ans[8]={0};
    ans[0]=m?0:1LL<<n;
    ans[7]=1LL<<n;
    ans[3]=ans[6]=get_independent_set((1LL<<n)-1);
    ans[1]=ans[4]=1LL<<count_isolated();
    ans[5]=1LL<<count_components();
    ans[2]=check_bipartite()?1LL<<count_components():0;
    for(int p=8; p; p>>=1) rep(i, 8) if(i&p) ans[i]-=ans[i-p];
    cout<<ans[7]<<endl;
}