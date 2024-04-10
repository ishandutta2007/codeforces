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

struct Query {
    int r, s, t, idx; //l implicit
    Query() {}
    Query(int r, int s, int t, int idx): r(r), s(s), t(t), idx(idx) {}
};

constexpr int N=1000, M=2e5;
int dp[N][N];
pii edge[M];
vector<Query> query[M];
int ans[M];

int32_t main() {
    fastio;
    int n, m, q; cin>>n>>m>>q;
    rep(i, m) {
        int u, v; cin>>u>>v;
        edge[i]={u-1, v-1};
    }
    rep(i, q) {
        int l, r, s, t; cin>>l>>r>>s>>t;
        query[l-1].eb(r-1, s-1, t-1, i);
    }
    rep(i, n) rep(j, n) dp[i][j]=m;
    for(int i=m-1; i>=0; i--) {
        int u=edge[i].fi, v=edge[i].se;
        dp[u][v]=dp[v][u]=i;
        rep(j, n) dp[u][j]=dp[v][j]=min(dp[u][j], dp[v][j]);
        for(Query& Q: query[i]) {
            ans[Q.idx]=(dp[Q.s][Q.t]<=Q.r);
        }
    }
    rep(i, q) cout<<(ans[i]?"Yes\n":"No\n");
}