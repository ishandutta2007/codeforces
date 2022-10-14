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
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

//the complexity is still O(n^2 log n) with brute force mult
//and sort is O(n^2 log n) anyway
//so no point in FFT

constexpr int MOD=998244353;

struct dsu {
    vi d, e;
    vvi dp;

    dsu() {}
    dsu(int n): d(n, -1), e(n, 0), dp(n, vi(n+1, 0)) {rep(i, n) dp[i][1]=1;}

    int find(int x) {return d[x]<0?x:d[x]=find(d[x]);}
    void join(int x, int y) {
        x=find(x); y=find(y);
        if(x==y) {
            e[x]++;
            if(2*e[x]==d[x]*(d[x]+1)) dp[x][1]++;
        }
        else {
            if(d[x]>d[y]) swap(x, y);
            vi tmp(-d[x]-d[y]+1, 0);
            rep1(i, -d[x]) rep1(j, -d[y]) tmp[i+j]=(tmp[i+j]+dp[x][i]*1LL*dp[y][j])%MOD;
            rep1(i, -d[x]-d[y]) dp[x][i]=tmp[i];
            d[x]+=d[y]; d[y]=x;
            e[x]+=e[y]+1;
            if(2*e[x]==d[x]*(d[x]+1)) dp[x][1]++;
        }
    }
};

vector<array<int, 3>> edges;

int32_t main() {
    fastio;
    int n; cin>>n;
    rep(i, n) rep(j, n) {
        int x; cin>>x;
        if(i<j) edges.pb({x, i, j});
    }
    dsu d(n);
    sort(all(edges));
    for(auto& e: edges) d.join(e[1], e[2]);
    int rt=d.find(0);
    rep1(i, n) cout<<d.dp[rt][i]<<' '; cout<<endl;
}