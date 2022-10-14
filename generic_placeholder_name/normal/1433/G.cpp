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
template<typename _def> using ordered_set=tree<_def, null_type, greater<_def>, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

//oops 
//forgot this existed

constexpr int N=1005;
constexpr int INF=1e9+7;
vector<pii> adj[N];
int dist[N][N];
bool vis[N];
array<int, 3> edge[N];
int l[N], r[N];
int mx[N];

int32_t main() {
    fastio;
    int n, m, k; cin>>n>>m>>k;
    rep(i, m) {
        int u, v, w; cin>>u>>v>>w; --u, --v;
        adj[u].eb(v, w);
        adj[v].eb(u, w);
        edge[i]={u, v, w};
    }
    rep(i, k) {
        cin>>l[i]>>r[i]; 
        --l[i], --r[i];
    }
    auto spfa = [&](int src) {
        rep(i, N) dist[src][i]=INF;
        rep(i, N) vis[i]=0;
        vis[src]=1; dist[src][src]=0;
        queue<int> Q; Q.push(src);
        while(!Q.empty()) {
            int u=Q.front(); Q.pop();
            vis[u]=0;
            for(auto& [v, w]: adj[u]) {
                if(dist[src][v]>dist[src][u]+w) {
                    dist[src][v]=dist[src][u]+w;
                    if(!vis[v]) {
                        vis[v]=1;
                        Q.push(v);
                    }
                }
            }
        }
    }; 
    rep(i, n) shuffle(all(adj[i]), rng);
    rep(i, n) spfa(i);
    int ans=INF;
    rep(i, m) {
        int cur=0;
        rep(j, k) {
            mx[j]=dist[l[j]][r[j]];
            mx[j]=min(mx[j], dist[l[j]][edge[i][0]]+dist[edge[i][1]][r[j]]);
            mx[j]=min(mx[j], dist[l[j]][edge[i][1]]+dist[edge[i][0]][r[j]]);
            cur+=mx[j];
        }
        ans=min(ans, cur);
    }
    cout<<ans<<endl;
}