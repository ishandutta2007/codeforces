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

constexpr int N = 505, K = 11;
int a[N][N];
int down[N][N];
#define right aeifuhbk
int right[N][N];
int dp[K][N][N];
int n, m, k;

int32_t main() {
    fastio;
    cin>>n>>m>>k;
    if(k&1) {
        rep(i, n) rep(j, m) cout<<-1<<" \n"[j+1==m];
        return 0;
    }
    rep(i, n) rep(j, m-1) cin>>right[i][j];
    rep(i, n-1) rep(j, m) cin>>down[i][j];
    memset(dp, 0x3f, sizeof(dp));
    memset(dp[0], 0, sizeof(dp[0]));
    rep1(l, k/2) rep(i, n) rep(j, m)  {
        if(i) dp[l][i][j]=min(dp[l][i][j], dp[l-1][i-1][j]+down[i-1][j]);
        if(j) dp[l][i][j]=min(dp[l][i][j], dp[l-1][i][j-1]+right[i][j-1]);
        if(i+1<n) dp[l][i][j]=min(dp[l][i][j], dp[l-1][i+1][j]+down[i][j]);
        if(j+1<m) dp[l][i][j]=min(dp[l][i][j], dp[l-1][i][j+1]+right[i][j]);
    }
    rep(i, n) rep(j, m) cout<<dp[k/2][i][j]*2<<" \n"[j+1==m];
}