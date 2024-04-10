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

//there will be a lot of excess information here
//as this solution is adapted from another problem
//which reduces to this one
//I am too lazy to remove the excess values
//so I'll just leave them there

constexpr int N=2e5+1;
constexpr int L=19;

int n, m;
vector<vector<pii>> adj(N), mst(N); //adj is normal array, mst is mst
int tin[N], tout[N]; //tin and tout is in/out time of the dfs
int p[N][L], dp[N][L]; //p is parent and dp is max on path to parent;
int u[N], v[N], w[N], c[N]; vvi idx(N); //edge info
bool incl[N]; //is included in MST
ll tot=0; //weight of MST
ll ans[N];
ll S; //max reduction

void dfs(int u, int par, int dist) {
    static int t=0;
    tin[u]=t++;
    p[u][0]=par;
    dp[u][0]=dist;
    rep1(i, L-1) {
        p[u][i]=p[p[u][i-1]][i-1];
        dp[u][i]=max(dp[u][i-1], dp[p[u][i-1]][i-1]);
    }
    rep(i, mst[u].size()) if(mst[u][i].fi!=par) dfs(mst[u][i].fi, u, mst[u][i].se);
    tout[u]=t++;
    //if(clock()/CLOCKS_PER_SEC>3) cout<<"dfs TLE"<<endl;
}

constexpr int INF=1e9+7; //there it is; different limits are a bitch
int par[N], id[N], key[N]; bool vis[N]; //aux variables for MST
void getMST() { //OK ok prim slow as shit ok
    rep(i, n) key[i]=INF;
    set<pii> pq;
    pq.emplace(0, 0);
    key[0]=0;
    while (!pq.empty()) {
        int u=pq.begin()->se;
        pq.erase(pq.begin());
        vis[u]=1;
        rep(i, adj[u].size()){
            int v=adj[u][i].fi, w=adj[u][i].se;
            if (!vis[v]&&key[v]>w) {
                if(pq.find({key[v], v})!=pq.end()) pq.erase(pq.find({key[v], v}));
                key[v]=w;
                pq.emplace(key[v], v);
                par[v]=u;
                id[v]=idx[u][i];
            }
        }
    }
    //actual building of MST
    rep1(i, n-1) {
        mst[i].eb(par[i], w[id[i]]);
        mst[par[i]].eb(i, w[id[i]]);
        incl[id[i]]=1;
        tot+=w[id[i]];
    }
    //if(clock()/CLOCKS_PER_SEC>3) cout<<"MST TLE"<<endl;
}

bool is_ancestor(int u, int v){
    return tin[u]<=tin[v]&&tout[u]>=tout[v];
}

int query_util(int u, int v){
    int res=0;
    //if(clock()/CLOCKS_PER_SEC>3) cout<<"query TLE "<<u<<" "<<v<<endl;
    if(is_ancestor(u, v)){
        for (int i=L-1; i>=0; i--){
            if (!is_ancestor(p[v][i], u)){
                if(res<dp[v][i]) {
                    res=dp[v][i];
                }
                v=p[v][i];
            }
        }
        if(res<dp[v][0]) {
            res=dp[v][0];
        }
        return res;
    }
    else if(is_ancestor(v, u)){
        for (int i=L-1; i>=0; i--){
            if (!is_ancestor(p[u][i], v)){
                if(res<dp[u][i]) {
                    res=dp[u][i];
                }
                u=p[u][i];
            }
        }
        if(res<dp[u][0]) {
            res=dp[u][0];
        }
        return res;
    }
    else {
        for (int i=L-1; i>=0; i--){
            if (!is_ancestor(p[u][i], v)){
                if(res<dp[u][i]) {
                    res=dp[u][i];
                }
                u=p[u][i];
            }
        }
        if(res<dp[u][0]) {
            res=dp[u][0];
        }
        u=p[u][0];
        for (int i=L-1; i>=0; i--){
            if (!is_ancestor(p[v][i], u)){
                if(res<dp[v][i]) {
                    res=dp[v][i];
                }
                v=p[v][i];
            }
        }
        if(res<dp[v][0]) {
            res=dp[v][0];
        }
        v=p[v][0];
        return res;
    }
}

ll query(int idx) {
    if(incl[idx]) return tot;
    else return tot-query_util(u[idx], v[idx])+w[idx];
}

void answer() {
    getMST();
    dfs(0, 0, INF);
    rep(i, m) cout<<query(i)<<endl;
}

int32_t main() {
    //freopen("ROUGHROAD.inp", "r", stdin);
    //freopen("ROUGHROAD.out", "w", stdout);
    fastio;
	cin>>n>>m;
	rep(i, m) {
	    cin>>u[i]>>v[i]>>w[i]; --u[i], --v[i];
	    adj[u[i]].eb(v[i], w[i]);
	    adj[v[i]].eb(u[i], w[i]);
	    idx[u[i]].pb(i);
	    idx[v[i]].pb(i);
	}
	answer();
}