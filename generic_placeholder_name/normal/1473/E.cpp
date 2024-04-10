#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

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
template<typename T, typename cmp = less<T>>
using ordered_set=tree<T, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

template<typename T>
using min_heap=priority_queue<T, vector<T>, greater<T>>;

constexpr int N=2e5+5;
vector<pii> adj[N];
ll dist[N][2][2];

int32_t main() {
    fastio;
    int n, m; cin>>n>>m;
    rep(i, m) {
        int u, v, w; cin>>u>>v>>w; --u, --v;
        adj[u].eb(v, w);
        adj[v].eb(u, w);
    }
    min_heap<pair<ll, tuple<int, bool, bool>>> pq;
    memset(dist, 0x3f, sizeof(dist));
    dist[0][0][0]=0;
    pq.emplace(0, make_tuple(0, 0, 0));
    while(!pq.empty()) {
        auto info=pq.top(); pq.pop();
        auto [u, f, s]=info.se;
        if(info.fi!=dist[u][f][s]) continue;
        for(auto& [v, w]: adj[u]) {
            if(dist[v][f][s]>dist[u][f][s]+w) {
                dist[v][f][s]=dist[u][f][s]+w;
                pq.emplace(dist[v][f][s], make_tuple(v, f, s));
            }
            if(!f&&dist[v][1][s]>dist[u][0][s]) {
                dist[v][1][s]=dist[u][0][s];
                pq.emplace(dist[v][1][s], make_tuple(v, 1, s));
            }
            if(!s&&dist[v][f][1]>dist[u][f][0]+w*2) {
                dist[v][f][1]=dist[u][f][0]+w*2;
                pq.emplace(dist[v][f][1], make_tuple(v, f, 1));
            }
        }
    }
    rep1(i, n-1) cout<<min(dist[i][0][0], dist[i][1][1])<<' '; cout<<endl;
}