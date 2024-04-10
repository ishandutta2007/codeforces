#include <bits/stdc++.h>
#define owo(i,a, b) for(int i=(a);i<(b); ++i)
#define uwu(i,a, b) for(int i=(a)-1; i>=(b); --i)
#define senpai push_back
#define ttgl pair<int, int>
#define ayaya cout<<"ayaya~"<<endl
 
using namespace std;
/*#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
gp_hash_table<int, int> mp;*/
using ll = long long;
using ld = long double;
const ll MOD = 1000000007;
const ll root = 62;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
ll binpow(ll a,ll b){ll res=1;while(b){if(b&1)res=(res*a)%MOD;a=(a*a)%MOD;b>>=1;}return res;}
ll modInv(ll a){return binpow(a, MOD-2);}
const double PI = acos(-1);
const double eps = -1e6;
const int INF = 0x3f3f3f3f;
const int NINF = 0xc0c0c0c0;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll NINFLL = 0xc0c0c0c0c0c0c0c0;
const int mxN = 300001;
vector<ttgl> adj[mxN];
vector<pair<int, ll>> tree[mxN];
set<ttgl> bridges;
int dsu[mxN];
bool has[mxN];
ll val[mxN];
int tin[mxN];
int low[mxN];
array<int, 3> edges[mxN];
int cnt = 1;
int n, m, k;
ll gsz[mxN];
ll dp[mxN];
ll ans[mxN];
void dfs1(int u, int p) {
    tin[u]=low[u] = cnt++;
    for(auto v: adj[u]) {
        if(v.first^p) {
            if(tin[v.first]) {
                low[u] = min(low[u], tin[v.first]);
            }else {
                dfs1(v.first, u);
                low[u] = min(low[u], low[v.first]);
                if(low[v.first]>tin[u]) {
                    bridges.insert({u, v.first});
                    bridges.insert({v.first, u});
                }
            }
        }
    }
}
void dfs2(int u, int p) {
    gsz[u] = has[u];
    dp[u] = val[u];
    for(auto v: tree[u]) {
        if(v.first^p) {
            dfs2(v.first, u);
            gsz[u]+=gsz[v.first];
            dp[u]+=max(dp[v.first]-(gsz[v.first]==0||gsz[v.first]==k ? 0 : v.second), 0LL);
        }
    }
}
void solve(int u, int p, ll tot, ll w) {
    tot-=(gsz[u]==0||gsz[u]==k ? 0 : w);
    tot = max(tot, 0LL);
    ans[u] = dp[u]+tot;
    //cout<<u<<" "<<p<<" "<<dp[u]<<" "<<gsz[u]<<" "<<tot<<" "<<w<<"\n";
    tot += val[u];
    //cout<<tot<<"\n";
    for(auto v: tree[u]) {
        if(v.first^p) {
            tot+=max(dp[v.first]-(gsz[v.first]==0||gsz[v.first]==k ? 0 : v.second), 0LL);
        }
    }
    //cout<<tot<<"\n";
    for(auto v: tree[u]) {
        if(v.first^p) {
            tot-=max(dp[v.first]-(gsz[v.first]==0||gsz[v.first]==k ? 0 : v.second), 0LL);
            solve(v.first, u, tot, v.second);
            tot+=max(dp[v.first]-(gsz[v.first]==0||gsz[v.first]==k ? 0 : v.second), 0LL);
        }
    }
}
int find(int a) { 
    return a==dsu[a] ? a : dsu[a] = find(dsu[a]); 
}
void merge(int a, int b) {
    a = find(a); b = find(b);
    if(a==b)return;
    dsu[b] = a;
    has[a]|=has[b];
    val[a]+=val[b];
}
int main() {
    //freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m>>k;
    int a;
    owo(i, 0, k) {
        cin>>a;
        a--;
        has[a] = true;
    }
    owo(i, 0, n) {
        dsu[i] = i;
        cin>>val[i];
    }
    owo(i, 0, m) {
        cin>>edges[i][2];
    }
    owo(i, 0, m) {
        cin>>edges[i][0]>>edges[i][1];
        edges[i][0]--; edges[i][1]--;
        adj[edges[i][0]].senpai({edges[i][1], edges[i][2]});
        adj[edges[i][1]].senpai({edges[i][0], edges[i][2]});
    }
    dfs1(0, 0);
    for(auto p: edges) {
        if(bridges.count({p[0], p[1]})==0) {
            merge(p[0], p[1]);
        }
    }
    k = 0;
    owo(i, 0, n) {
        if(find(i)==i) {
            k+=has[i];
        }
    }
    for(auto p: edges) {
        if(bridges.count({p[0], p[1]})) {
            tree[find(p[0])].senpai({find(p[1]), p[2]});
            tree[find(p[1])].senpai({find(p[0]), p[2]});
        }
    }
    dfs2(find(0), find(0));
    solve(find(0), -1, 0, 0);
    //cout<<(best[dsu[0]] + val[dsu[0]])<<"\n";
    owo(i, 0, n) {
        cout<<(ans[find(i)])<<" ";
    }
    return 0;
}