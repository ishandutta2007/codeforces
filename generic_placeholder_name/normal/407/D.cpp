//testing cache
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
#define rep(i, n) for (short i=0; i<(n); i++)
#define irep(i, n) for(int i=0; i<(n); i++)
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

constexpr short N=401;
constexpr int M=160001;
short n, m;
int a[N][N];
short last[N][M];
short f[N][N];
short dp[N][N][2];

int32_t main() {
    fastio;
    cin>>n>>m; rep(i, n) rep(j, m) cin>>a[i][j];
    rep(i, m) irep(j, M) last[i][j]=n;
    ll ans=0;
    rep(i, m) f[i][i]=last[i][a[n-1][i]];
    rep(i, m) last[i][a[n-1][i]]=n-1;
    rep(i, m) rep(j, m) if(i!=j) f[i][j]=last[j][a[n-1][i]];
    rep(i, m) dp[i][i][1]=f[i][i];
    rep(i, m-1) dp[i][i+1][1]=min(f[i][i+1], f[i+1][i]);
    for(short df=2; df<m; df++) rep(i, m-df) {
        short j=i+df;
        dp[i][j][1]=min(min(dp[i][j-1][1], dp[i+1][j][1]), min(f[i][j], f[j][i]));
    }
    rep(i, m) rep(j, m) if(j>=i) ans=max(ans, 1LL*(j-i+1)*(dp[i][j][1]-n+1));
    //actually doing meaningful stuff
    for(short k=n-2; k>=0; k--) {
        rep(i, m) f[i][i]=last[i][a[k][i]];
        rep(i, m) last[i][a[k][i]]=k;
        rep(i, m) rep(j, m) if(i!=j) f[i][j]=last[j][a[k][i]];
        rep(i, m) dp[i][i][0]=min(f[i][i], dp[i][i][1]);
        for(short df=1; df<m; df++) rep(i, m-df) {
            short j=i+df;
            dp[i][j][0]=min(dp[i][j][1], min(min(dp[i][j-1][0], dp[i+1][j][0]), min(f[i][j], f[j][i])));
        }
        rep(i, m) rep(j, m) if(j>=i) ans=max(ans, 1LL*(j-i+1)*(dp[i][j][0]-k));
        rep(i, m) rep(j, m) dp[i][j][1]=dp[i][j][0], dp[i][j][0]=0;
    }
    cout<<ans<<endl;
}