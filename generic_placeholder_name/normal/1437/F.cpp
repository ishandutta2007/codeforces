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
template<typename T, typename comp = less<T>>
using ordered_set = tree<T, null_type, comp, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

constexpr int N=5005;
int dp[2][N];
int a[N];

constexpr int MOD=998244353;
#define inline __attribute__((always_inline))
inline int add(int a, int b) {return (a+=b)>=MOD?a-MOD:a;}
inline int sub(int a, int b) {return (a-=b)<0?a+MOD:a;}
inline int mul(int a, int b) {return (a*1LL*b)%MOD;}
#undef inline

int32_t main() {
    fastio;
    int n; cin>>n;
    rep(i, n) cin>>a[i];
    sort(a, a+n, greater<int>());
    dp[0][0]=1;
    rep1(i, n-1) {
        memset(dp[1], 0, sizeof(dp[1]));
        int prv=0, sum=0;
        while(a[prv]>=2*a[i]) {
            dp[1][prv]=mul(i, dp[0][prv]);
            sum=add(sum, dp[0][prv]);
            prv++;
        }
        for(; prv<i; prv++) dp[1][prv]=mul(i-1, dp[0][prv]);
        dp[1][i]=sum;
        memcpy(dp[0], dp[1], sizeof(dp[1]));
    }
    int ans=0;
    rep(i, n) ans=add(ans, dp[0][i]);
    cout<<ans<<endl;
}