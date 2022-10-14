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

//aight i give up on that sol
//so here's a binsearch

constexpr int N=2e5+5;
constexpr int INF=5e8;
int dp[N];
vi adj[N];

void dfs(int u, int m, int p=-1, int d=0) {
    vi val;
    for(int v: adj[u]) if(v!=p) {
        dfs(v, m, u, d+1);
        val.eb(dp[v]);
    }
    if(adj[u].size()==1&&u) dp[u]=d;
    else if(val.size()==1) dp[u]=val[0];
    else {
        int mx=*max_element(all(val));
        int mn=*min_element(all(val));
        if(mx-d+1>m) {
            int id=-1;
            rep(i, val.size()) if(val[i]==mx) {id=i; break;}
            int s=-1;
            rep(i, val.size()) if(i!=id) s=max(s, val[i]);
            if(s-d+1>m) dp[u]=INF;
            else dp[u]=mx;
        }
        else dp[u]=mn;
    }
}

int32_t main() {
    fastio;
    int T; cin>>T;
    while(T--) {
        int n; cin>>n;
        rep(i, n) adj[i].clear();
        rep(_, n-1) {
            int u, v; cin>>u>>v; --u, --v;
            adj[u].eb(v);
            adj[v].eb(u);
        }
        auto check = [&n](int m) {
            memset(dp, 0, n*sizeof(int));
            dfs(0, m);
            return dp[0]<=m;
        };
        int l=1, r=n-1;
        while(l<r) {
            int m=(l+r)/2;
            if(check(m)) r=m;
            else l=m+1;
        }
        cout<<r<<endl;
    }
}