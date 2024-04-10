#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
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
template<typename _def> using ordered_set=tree<_def, null_type, greater<_def>, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

//i suck at dp lel

constexpr int N=75;
constexpr int INF=1e8;
int a[N][N];
int dp[N][N][N];

template<typename T>
inline void chmax(T& a, T b) {a=a<b?b:a;}

int32_t main() {
    fastio;
    int n, m, k; cin>>n>>m>>k;
    rep(i, n) rep(j, m) cin>>a[i][j];
    rep(i, n) rep(j, m) rep(x, k) dp[i][j][x]=-INF;
    dp[0][0][0]=0;
    rep(i, n) {
        rep(y, m) for(int j=m/2; ~j; j--) rep(x, k) chmax(dp[i][j+1][(x+a[i][y])%k], dp[i][j][x]+a[i][y]);
        rep(j, m/2+1) rep(x, k) chmax(dp[i+1][0][x], dp[i][j][x]);
    }
    int ans=0;
    rep(i, m/2+1) chmax(ans, dp[n-1][i][0]);
    cout<<ans<<endl;
}