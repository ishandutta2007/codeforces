#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>

#pragma 03

using namespace std;
using namespace __gnu_pbds;

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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define gcd __gcd
#define lcm(a, b) (a)*(b)/gcd((a), (b))
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define rep(i, n) for (int i=0; i<(n); i++)
#define pcnt __builtin_popcountll
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

vi p;
vvi adj;

pii dfs(int v, int par=-1, int dist=0) {
    p[v]=par;
    pii ans=mp(dist, v);
    for(int to: adj[v]) {
        if(to==par) continue;
        ans=max(ans, dfs(to, v, dist+1));
    }
    return ans;
}

pii BFS(vi d, int n) {
    vector<bool> visited(n, 0);
    queue<int> Q;
    int deg[n];
    for(auto v: d) {visited[v]=1; Q.push(v); deg[v]=0;}
        while(!Q.empty()) {
            int src=Q.front(); Q.pop();
            for (int j=0; j<adj[src].size(); j++) {
                int dest=adj[src][j];
                if (!visited[dest]) {
                    visited[dest]=true;
                    deg[dest]=deg[src]+1;
                    Q.emplace(dest);
                }
            }
        }
    pii ans=mp(0, 0);
    rep(i, n) ans=max(ans, mp(deg[i], i));
    return ans;
}

int32_t main() {
    fastio;
    int n; cin>>n; p=vi(n);  adj.assign(n, vi());
    rep(i, n-1) {
        int u, v; cin>>u>>v; u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    pii a=dfs(0);
    pii b=dfs(a.se);
    vi d;
    int v=b.se;
    while(v!=-1) {d.pb(v); v=p[v];}
    if(d.size()==n) cout<<n-1<<endl<<d[0]+1<<' '<<d[1]+1<<' '<<d[d.size()-1]+1<<endl;
    else {
        pii ans=BFS(d, n);
        cout<<d.size()-1+ans.fi<<endl<<d[0]+1<<' '<<ans.se+1<<' '<<d[d.size()-1]+1<<endl;
    }
}