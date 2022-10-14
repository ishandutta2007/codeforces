/**
 *    author:  gary
 *    created: 05.08.2022 15:29:16
**/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=(b);a<=(c);++a)
#define rl(a,b,c) for(int a=(b);a>=(c);--a)
#define rep(a,b) for(int a=0;a<(b);++a)
#define LL long long
#define II(a,b) make_pair(a,b)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
const int N = 3e5 + 9, LG = 18;
vector<int> g[N];
int par[N][LG + 1], dep[N], sz[N],bel[N];
void dfs(int u, int p = 0) {
  par[u][0] = p;
  dep[u] = dep[p] + 1;
  sz[u] = 1;
  bel[u]=u;
  for (int i = 1; i <= LG; i++) par[u][i] = par[par[u][i - 1]][i - 1];
  for (auto v: g[u]) if (v != p) {
    dfs(v, u);
    bel[u]=bel[v];
    sz[u] += sz[v];
  }
}
int lca(int u, int v) {
  if (dep[u] < dep[v]) swap(u, v);
  for (int k = LG; k >= 0; k--) if (dep[par[u][k]] >= dep[v]) u = par[u][k];
  if (u == v) return u;
  for (int k = LG; k >= 0; k--) if (par[u][k] != par[v][k]) u = par[u][k], v = par[v][k];
  return par[u][0];
}
int kth(int u, int k) {
  assert(k >= 0);
  for (int i = 0; i <= LG; i++) if (k & (1 << i)) u = par[u][i];
  return u;
}
int dist(int u, int v) {
  int l = lca(u, v);
  return dep[u] + dep[v] - (dep[l] << 1);
}
//kth node from u to v, 0th node is u
int go(int u, int v, int k) {
  int l = lca(u, v);
  int d = dep[u] + dep[v] - (dep[l] << 1);
  assert(k <= d);
  if (dep[l] + k <= dep[u]) return kth(u, k);
  k -= dep[u] - dep[l];
  return kth(v, dep[v] - dep[l] - k);
}
int n,m,k;
vector<int> gra[N];
vector<int> each[N];
vector<int> getcyc(int x,int y){
    vector<int> v;
    int l=lca(x,y);
    int now=x;
    while (true){
        v.push_back(now);
        if(now==l) break;
        now=par[now][0];
    }
    vector<int> v2;
    now=y;
    while (now!=l){
        v2.push_back(now);
        now=par[now][0];
    }
    reverse(ALL(v2));
    for(auto it:v2) v.push_back(it);
    return v;
}
bool vis[N];
void dfs1(int now){
    vis[now]=1;
    for(auto it:gra[now]) if(!vis[it]){
        g[now].push_back(it);
        dfs1(it);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>k;
    rb(i,1,m){
        int u,v;
        cin>>u>>v;
        gra[u].push_back(v);
        gra[v].push_back(u);
    }
    dfs1(1);
    dfs(1);
    rb(i,1,n) each[dep[i]].push_back(i);
    if(*max_element(dep+1,dep+1+n)>=(n+k-1)/k){
        cout<<"PATH\n";
        rb(i,1,n){
            if(dep[i]>=(n+k-1)/k){
                cout<<dep[i]<<'\n';
                rl(T,dep[i],1){
                    cout<<i<<' ';
                    i=par[i][0];
                } 
                cout<<'\n';
                break;
            }
        }
        return 0;
    }
    cout<<"CYCLES\n";
    vector<vector<int> > c;
    rb(i,1,n) if(each[i].size()>=k){
        rep(j,k){
            int v=each[i][j];
            v=bel[v];
            int x,y;
            x=-1,y=-1;
            for(auto it:gra[v]) if(it!=par[v][0]){
                if(x==-1) x=it;
                else y=it;
            }
            if(abs(dep[v]-dep[x])%3!=2){
                c.push_back(getcyc(v,x));
            }
            else if(abs(dep[v]-dep[y])%3!=2){
                c.push_back(getcyc(v,y));
            }
            else{
                c.push_back(getcyc(x,y));
                c.back().push_back(v);
                reverse(ALL(c.back()));
            }
        }
        break;
    }
    assert(c.size()==k);
    rep(i,k){
        cout<<c[i].size()<<'\n';
        for(auto it:c[i]) cout<<it<<' ';
        cout<<'\n';
    }
    return 0;
}