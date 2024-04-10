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

constexpr int N=1e5+5;
pii a[N];
vector<pii> adj[N];
array<uint, N> dist;
array<bool, N> vis;
constexpr uint INF=2e9+123;

int32_t main() {
    fastio;
    int wtf; cin>>wtf;
    int n; cin>>n;
    int sx, sy, fx, fy; cin>>sx>>sy>>fx>>fy;
    adj[0].eb(n+1, abs(fx-sx)+abs(fy-sy));
    rep1(i, n) {
        cin>>a[i].fi>>a[i].se;
        adj[0].eb(i, min(abs(sx-a[i].fi), abs(sy-a[i].se)));
        adj[i].eb(n+1, abs(fx-a[i].fi)+abs(fy-a[i].se));
    }
    vi idx(n); iota(all(idx), 1);
    sort(all(idx), [&](int x, int y) {return a[x].fi<a[y].fi;});
    rep(i, n-1) {
        adj[idx[i]].eb(idx[i+1], a[idx[i+1]].fi-a[idx[i]].fi);
        adj[idx[i+1]].eb(idx[i], a[idx[i+1]].fi-a[idx[i]].fi);
    }
    sort(all(idx), [&](int x, int y) {return a[x].se<a[y].se;});
    rep(i, n-1) {
        adj[idx[i]].eb(idx[i+1], a[idx[i+1]].se-a[idx[i]].se);
        adj[idx[i+1]].eb(idx[i], a[idx[i+1]].se-a[idx[i]].se);
    }
    //trying to implement SPFA for some reason
    queue<int> q;
    dist.fill(INF); vis.fill(0);
    dist[0]=0; vis[0]=1;
    q.push(0);
    while(!q.empty()) {
        int u=q.front(); q.pop();
        vis[u]=0;
        for(auto& v: adj[u]) {
            if(dist[u]+v.se<dist[v.fi]) {
                dist[v.fi]=dist[u]+v.se;
                if(!vis[v.fi]) q.push(v.fi), vis[v.fi]=1;
            }
        }
    }
    cout<<dist[n+1]<<endl;
}