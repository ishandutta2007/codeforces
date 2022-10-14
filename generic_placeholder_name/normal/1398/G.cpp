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
template<typename _def> using ordered_set=tree<_def, null_type, less<_def>, rb_tree_tag, tree_order_statistics_node_update>;

constexpr int N=2e5+1, MX=5e5+1, INF=5e8;
int a[N];
bitset<N> has, vis;
vi dp(MX, INF);

int32_t main() {
    fastio;
    int n, x, y; cin>>n>>x>>y;
    rep(i, n+1) {cin>>a[i]; has[a[i]]=1;}
    vis=has;
    rep1(i, n) {
        has>>=a[i]-a[i-1];
        vis|=has;
    }
    rep1(i, N-1) if(vis[i]) {
        int x=i+y;
        for(int j=x; j<MX; j+=x) dp[j]=x;
    }
    int q; cin>>q;
    while(q--) {int x; cin>>x; cout<<(dp[x>>1]==INF?-1:dp[x>>1]<<1)<<" ";}
    cout<<endl;
}