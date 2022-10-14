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

//turns out neg edges negates disjointness
//so n^3 it is
constexpr int INF=1e9+7;
constexpr int N=303;

int a[N][N];
int dp[2*N][N][N];

template<typename T>
void chmax(T& a, T b) {a=a<b?b:a;}

int32_t main() {
    fastio;
    int n; cin>>n;
    rep1(i, n) rep1(j, n) cin>>a[i][j];
    if(n==1) {return cout<<a[1][1], 0;}
    rep(i, n*2+1) rep(j, n+1) rep(k, n+1) dp[i][j][k]=-INF;
    dp[2][1][0]=a[1][1]+a[1][2]+a[2][1];
    dp[2][1][1]=a[1][1]+a[2][1];
    dp[2][0][0]=a[1][1]+a[1][2];
    for(int i=3; i<=n*2-1; i++) {
        for(int j=0; j<=n&&j<i; j++) {
            for(int k=0; k<=j; k++) {
                if(j>0&&k>0) chmax(dp[i][j][k], dp[i-1][j-1][k-1]);
                chmax(dp[i][j][k], dp[i-1][j][k]);
                if(k>0) chmax(dp[i][j][k], dp[i-1][j][k-1]);
                if(j>k) chmax(dp[i][j][k], dp[i-1][j-1][k]);
                if(j!=k) dp[i][j][k]+=a[j+1][i-j]+a[k+1][i-k];
                else dp[i][j][k]+=a[j+1][i-j];
            }
        }
    }
    cout<<dp[n*2-1][n-1][n-1];
}