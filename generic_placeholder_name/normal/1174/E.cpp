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

constexpr int MOD=1e9+7;
constexpr int N=1e6+1, L=21;
int dp[N][L][2];

int32_t main() {
    fastio;
    int n; cin>>n;
    auto f=[&](int x, int y) -> int {
        int tmp=(1<<x);
        return y?n/(tmp*3):n/tmp;
    };
    int p=0; while((1<<p)<=n) p++; p--;
    dp[1][p][0]=1;
    if ((1<<(p-1))*3<=n) dp[1][p-1][1]=1;
    rep1(i, n-1) {
        rep(x, p+1) {
            rep(y, 2) {
                dp[i+1][x][y]=(dp[i+1][x][y]+1LL*dp[i][x][y]*(f(x,y)-i))%MOD;
                if(x) dp[i+1][x-1][y]=(dp[i+1][x-1][y]+1LL*dp[i][x][y]*(f(x-1, y)-f(x,y)))%MOD;
                if(y) dp[i+1][x][y-1]=(dp[i+1][x][y-1]+1LL*dp[i][x][y]*(f(x, y-1)-f(x,y)))%MOD;
            }
        }
    }
    cout<<dp[n][0][0]<<endl;
}