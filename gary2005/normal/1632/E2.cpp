/**
 *    author:  gary
 *    created: 30.01.2022 22:33:24
**/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define rep(a,b) for(int a=0;a<b;++a)
#define LL long long
#define PB push_back
#define POB pop_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9, LG = 18;

vector<int> g[N];
int par[N][LG + 1], dep[N], sz[N];
void dfs(int u, int p = 0) {
  par[u][0] = p;
  dep[u] = dep[p] + 1;
  sz[u] = 1;
  for (int i = 1; i <= LG; i++) par[u][i] = par[par[u][i - 1]][i - 1];
  for (auto v: g[u]) if (v != p) {
    dfs(v, u);
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
// int32_t main() {
//   int n; cin >> n;
//   for (int i = 1; i < n; i++) {
//     int u, v; cin >> u >> v;
//     g[u].push_back(v);
//     g[v].push_back(u);
//   }
//   dfs(1);
//   int q; cin >> q;
//   while (q--) {
//     int u, v; cin >> u >> v;
//     cout << dist(u, v) << '\n';
//   }
//   return 0;
// }
int ans[N];
mp D;
vector<int> v[N];
void addi(int tmp){
    if(D==II(-1,-1)) D=II(tmp,tmp);
    else{
        vector<mp> P;
        P.PB(D);
        P.PB(II(D.first,tmp));
        P.PB(II(D.second,tmp));
        for(auto it:P) if(dist(it.first,it.second)>dist(D.first,D.second)) D=it;
    }
}
void extend(int A){
    if(A!=1){
        for(auto it:v[A]) addi(it);
    }
}
void solve(){
    D=II(-1,-1);
    int n;
    cin>>n;
    rb(i,1,n) sz[i]=0,dep[i]=0,memset(par[i],0,sizeof(par[i]));
    rb(i,1,n) g[i].clear();
    rb(i,1,n-1){
        int u,v;
        cin>>u>>v;
        g[u].PB(v);
        g[v].PB(u);
    }
    dfs(1);
    rb(i,1,n) dep[i]--;
    ans[n]=*max_element(dep+1,dep+1+n);
    rb(i,0,n) v[i].clear();
    rb(i,1,n) v[dep[i]].PB(i);
    extend(ans[n]);
    rl(i,n-1,1){
        ans[i]=ans[i+1];
        while(ans[i]!=1){
            int G=dist(D.first,D.second);
            if((G+1)/2+i<ans[i]){
                ans[i]--;
                extend(ans[i]);
            }
            else break;
        }
    }
    rb(i,1,n){
        cout<<ans[i]<<' ';
    }
    cout<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}