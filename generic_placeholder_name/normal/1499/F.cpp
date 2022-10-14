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

constexpr int MOD=998244353;
#define _F __attribute__((always_inline))
_F int add(int a, int b) {return (a+=b)>=MOD?a-=MOD:a;}
_F int sub(int a, int b) {return (a-=b)<0?a+MOD:a;}
_F int mul(int a, int b) {return (a*1LL*b)%MOD;}
_F void set_add(int& a, int b) {if((a+=b)>=MOD) a-=MOD;}
_F void set_sub(int& a, int b) {if((a-=b)<0) a+=MOD;}
_F void set_mul(int& a, int b) {a=mul(a, b);}
_F int exp(int a, int b) {
    int ans=1;
    for(; b; b>>=1) {
        if(b&1) set_mul(ans, a);
        set_mul(a, a);
    }
    return ans;
}
#undef _F

constexpr int N=5005;
int dp[N][N];
vi adj[N];
int m[N][N];
int n, k;

void dfs(int u, int p=-1) {
    rep(i, k+1) m[u][i]=1;
    dp[u][1]=1;
    for(int v: adj[u]) if(v!=p) {
        dfs(v, u);
        rep(i, k+1) set_mul(m[u][i], add(dp[v][i], dp[v][k]));
        set_mul(dp[u][1], dp[v][k]);
    }
    for(int i=2; i<=k; i++) {
        if(i*2<=k+1) dp[u][i]=sub(m[u][i-1], m[u][i-2]);
        else {
            int mx=k-i;
            for(int v: adj[u]) if(v!=p&&dp[v][i-1]!=dp[v][i-2]) {
                set_add(dp[u][i], mul(sub(dp[v][i-1], dp[v][i-2]), mul(m[u][k-i], exp(add(dp[v][k-i], dp[v][k]), MOD-2))));
            }
        }
    }
    rep1(i, k) set_add(dp[u][i], dp[u][i-1]);
}

//eh idk what to say
//edge diameter -> vertex diameter
// -> bad k
//gotta read more carefully :v
//also 5000 * 5000 mod operations squeeze is super toxic
//maybe 2000 next time?

int32_t main() {
    fastio;
    cin>>n>>k; ++k; //oops edge diameter not vertex
    rep(i, n-1) {
        int u, v; cin>>u>>v; --u, --v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(0);
    cout<<dp[0][k]<<endl;
}