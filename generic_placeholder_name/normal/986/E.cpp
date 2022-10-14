#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

#pragma GCC optimize ("Ofast")
#pragma GCC optimization ("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")

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

constexpr int INF=1e7, N=1e5, MOD=1e9+7;
vi adj[N];
int ans[N];
int a[N];
constexpr int root=0;
int n;

int exp(int a, int b) {
    if(!b) return 1;
    else {
        int x=exp(a, b/2);
        x=(x*1LL*x)%MOD;
        if(b&1) return (x*1LL*a)%MOD;
        else return x;
    }
}

struct Query {
    int pw; //power to which prime is raised
    bool is_lca; //if is_lca then we minus two of the amount
    int idx;

    Query() {}
    Query(int pw, int idx, bool is_lca): pw(pw), idx(idx), is_lca(is_lca) {}

    bool operator < (const Query& oth) {return pw<oth.pw;}
};

gp_hash_table<int, vector<Query>> Q[N]; //Q[i][j] = decomposed queries having value of j, at node i

struct Counter {
    static constexpr int M=25;
    int a[M];
    
    Counter() {memset(a, 0, sizeof(a));}
    
    void add(int pos, int val) {a[pos]+=val;}
    
    int get_cnt(int l, int r) {
        int ans=0;
        for(int i=l; i<=r; i++) ans+=a[i];
        return ans;
    }
    
    int get_sum(int l, int r) {
        int ans=0;
        for(int i=l; i<=r; i++) ans+=i*a[i];
        return ans;
    }
};

struct Factorizer {
    int f[INF+1];

    void init() {
        for(int i=2; i*i<=INF; i++) if(!f[i]) for(int j=i; j<=INF; j+=i) if(!f[j]) f[j]=i;
        for(int i=2; i<=INF; i++) if(!f[i]) f[i]=i;
    }

    void factorize(int x, gp_hash_table<int, int>& factors) {
        while(x>1) factors[f[x]]++, x/=f[x];
    }
} factorizer;


struct LCA_Finder { //binary lifting lca because it doesn't really matter
    static constexpr int M=19;
    int memo[N][M+1], h[N];

    void dfs(int u, int p) {
        memo[u][0]=p;
        rep1(i, M) memo[u][i]=memo[memo[u][i-1]][i-1];
        for(int v: adj[u]) if(v!=p){
            h[v]=h[u]+1;
            dfs(v, u);
        }
    }
    void init() {
        dfs(root, root);
    }

    int find_lca(int u, int v){
        if (h[u]<h[v]) swap(u, v);
        for(int i=M; i>=0; i--) {
            if (h[u]-(1<<i)>=h[v]) u=memo[u][i];
        }
        if (u==v) return u;
        for(int i=M; i>=0; i--) {
            if (memo[u][i]!=memo[v][i]){
                u=memo[u][i];
                v=memo[v][i];
            }
        }
        return memo[u][0];
    }
} lca_finder;

unordered_set<int> queried_primes;
gp_hash_table<int, int> fact[N];
gp_hash_table<int, Counter> counters;

void decompose_into_queries(int u, int v, int x, int idx) {
    gp_hash_table<int, int> primes_count;
    factorizer.factorize(x, primes_count);
    int lca=lca_finder.find_lca(u, v);
    for(auto it: primes_count) {
        int prime=it.fi, cnt=it.se;
        queried_primes.insert(prime);
        Q[u][prime].eb(cnt, idx, 0);
        Q[v][prime].eb(cnt, idx, 0);
        Q[lca][prime].eb(cnt, idx, 1);
    }
    ans[idx]=gcd(a[lca], x); //add back 1 lca
}

void dfs(int u, int p=-1) {
    for(auto& [curPrime, cnt]: fact[u]) counters[curPrime].add(cnt, 1);
    for(auto& [curPrime, curQueries]: Q[u]) {
        for(auto& curQuery: curQueries) {
            #define curCounter counters[curPrime]
            int res=(curCounter.get_sum(0, curQuery.pw)+
            curQuery.pw*1LL*curCounter.get_cnt(curQuery.pw+1, curCounter.M-1))%(MOD-2);
            if(curQuery.is_lca) {
                int inv=exp(exp(curPrime, res), MOD-2);
                ans[curQuery.idx]=((ans[curQuery.idx]*1LL*inv)%MOD*1LL*inv)%MOD;
            }
            else {
                res=exp(curPrime, res);
                ans[curQuery.idx]=(ans[curQuery.idx]*1LL*res)%MOD;
            }
            #undef curCounter
        }
    }
    for(int v: adj[u]) if(v!=p) dfs(v, u);
    for(auto& [curPrime, cnt]: fact[u]) counters[curPrime].add(cnt, -1);
}

int32_t main() {
    fastio;
    cin>>n; rep(i, n-1) {
        int u, v; cin>>u>>v;
        adj[--u].pb(--v); adj[v].pb(u);
    }
    factorizer.init();
    lca_finder.init();
    rep(i, n) cin>>a[i], factorizer.factorize(a[i], fact[i]);
    int q; cin>>q; rep(i, q) {
        int u, v, x; cin>>u>>v>>x;
        decompose_into_queries(--u, --v, x, i);
    }
    dfs(root);
    rep(i, q) cout<<ans[i]<<endl;
}