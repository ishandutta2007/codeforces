#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

#pragma 03

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

constexpr int INF=1e9+7;
constexpr ll LLINF=1e18+18;

int32_t main() {
    fastio;
    int n, m; cin>>n>>m;
    vvi adj(n);
    vvi radj(n);
    rep(i, m) {
        int u, v; cin>>u>>v;
        --u, --v;
        adj[u].eb(v);
        radj[v].eb(u);
    }
    constexpr int opt=21;
    vvi dist(n, vi(opt, INF));
    typedef pair<int, pii> i3;
    priority_queue<i3, vector<i3>, greater<i3>> pq;
    dist[0][0]=0;
    pq.emplace(0, mp(0, 0));
    while(!pq.empty()) {
        int cw=pq.top().fi;
        int x=pq.top().se.fi;
        int y=pq.top().se.se;
        pq.pop();
        if(cw!=dist[x][y]) continue;
        if(y%2==0) {
            for(int v: adj[x]) {
                if(dist[v][y]>dist[x][y]+1) {
                    dist[v][y]=dist[x][y]+1;
                    pq.emplace(dist[v][y], mp(v, y));
                }
            }
            if(y<opt) {
                for(int v: radj[x]) {
                    if(dist[v][y+1]>dist[x][y]+(1<<y)+1) {
                        dist[v][y+1]=dist[x][y]+(1<<y)+1;
                        pq.emplace(dist[v][y+1], mp(v, y+1));
                    }
                }
            }
        }
        else {
            for(int v: radj[x]) {
                if(dist[v][y]>dist[x][y]+1) {
                    dist[v][y]=dist[x][y]+1;
                    pq.emplace(dist[v][y], mp(v, y));
                }
            }
            if(y<opt) {
                for(int v: adj[x]) {
                    if(dist[v][y+1]>dist[x][y]+(1<<y)+1) {
                        dist[v][y+1]=dist[x][y]+(1<<y)+1;
                        pq.emplace(dist[v][y+1], mp(v, y+1));
                    }
                }
            }
        }
    }
    int ans=INF;
    rep(i, opt) ans=min(ans, dist[n-1][i]);
    if(ans<INF) {
        cout<<ans<<endl;
        return 0;
    }
    else {
        constexpr int md=998244353;
        vll dist(2*n, LLINF);
        vector<vector<pii>> g(2*n);
        rep(u, n) {
            for(int v: adj[u]) {
                g[u].eb(v, 1);
                g[n+v].eb(n+u, 1);
            }
        }
        rep(i, n) {
            g[i].eb(n+i, INF);
            g[n+i].eb(i, INF);
        }
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
        pq.emplace(0, 0);
        dist[0]=0;
        while(!pq.empty()) {
            ll cw=pq.top().fi;
            int u=pq.top().se;
            pq.pop();
            if(cw!=dist[u]) continue;
            for(auto& x: g[u]) {
                int v=x.fi; ll w=x.se;
                if(dist[v]>dist[u]+w) {
                    dist[v]=dist[u]+w;
                    pq.emplace(dist[v], v);
                }
            }
        }
        ll tot=min(dist[n-1], dist[2*n-1]);
        int rev=tot/INF, rem=tot%INF;
        int mov=rem;
        int exp=1; rep(i, rev) {exp*=2; if(exp>=md) exp-=md;}
        exp--; if(exp<0) exp+=md;
        int ans=mov+exp; if(ans>=md) ans-=md;
        cout<<ans<<endl;
    }
}