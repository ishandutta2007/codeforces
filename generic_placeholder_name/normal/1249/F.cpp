#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
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
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

//there's no way this is gonna pass

constexpr int N=201;
int a[N];
vi adj[N];
int dp[N][N];
int n, k;

void dfs(int u, int par=-1) {
    dp[u][0]=a[u];
    for(int v: adj[u]) if(v!=par) dfs(v, u);
    for(int v: adj[u]) if(v!=par) {
        rep(d, n) {
            if(!d) dp[u][0]+=dp[v][k];
            else {
                int sum=dp[v][d-1];
                for(int x: adj[u]) if(x!=v&&x!=par) sum+=dp[x][max(k-d, d-1)];
                dp[u][d]=max(dp[u][d], sum);
            }
        }
    }
    for(int i=n-2; i>=0; i--) dp[u][i]=max(dp[u][i], dp[u][i+1]);
}

int32_t main() {
    fastio;
    cin>>n>>k;
    rep(i, n) cin>>a[i];
    rep(i, n-1) {
        int u, v; cin>>u>>v;
        adj[--u].pb(--v); adj[v].pb(u);
    }
    dfs(0);
    cout<<dp[0][0]<<endl;
}