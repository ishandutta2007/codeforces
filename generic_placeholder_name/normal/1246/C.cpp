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
template<typename T, typename cmp = less<T>>
using ordered_set=tree<T, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

constexpr int MOD=1e9+7;
#define F constexpr __attribute__((always_inline))
F int add(int a, int b) {return (a+=b)>=MOD?a-MOD:a;}
F int sub(int a, int b) {return (a-=b)<0?a+MOD:a;}
F int mul(int a, int b) {return (a*1ll*b)%MOD;}
#undef F

constexpr int N=2005;
char c[N][N];
int dp[N][N][2];
int16_t r[N][N], d[N][N];

int32_t main() {
    fastio;
    int n, m; cin>>n>>m;
    rep1(i, n) rep1(j, m) cin>>c[i][j];
    for(int i=n; i; i--) for(int j=m; j; j--) {
        r[i][j]=r[i][j+1]+(c[i][j]=='R');
        d[i][j]=d[i+1][j]+(c[i][j]=='R');
    }
    dp[1][1][0]=1;
    dp[1][m-r[1][1]+1][0]=sub(0, 1);
    rep1(i, n) rep1(j, m) {
        dp[i][j][0]=add(dp[i][j][0], dp[i][j-1][0]);
        dp[i][j][1]=add(dp[i][j][1], dp[i-1][j][1]);
        if(i<n) {
            dp[i+1][j][1]=add(dp[i+1][j][1], dp[i][j][0]);
            dp[n-d[i+1][j]+1][j][1]=sub(dp[n-d[i+1][j]+1][j][1], dp[i][j][0]);
        }
        if(j<m) {
            dp[i][j+1][0]=add(dp[i][j+1][0], dp[i][j][1]);
            dp[i][m-r[i][j+1]+1][0]=sub(dp[i][m-r[i][j+1]+1][0], dp[i][j][1]);
        }
    }
    cout<<add(dp[n][m][0], dp[n][m][1])<<endl;
}