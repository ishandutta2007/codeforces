#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MXN=5140;
const int N=5140;
#define PB push_back
#define FZ(X) memset(X,0,sizeof(X))
struct Scc{
  int n, nScc, vst[MXN], bln[MXN];
  vector<int> E[MXN], rE[MXN], vec;
  void init(int _n){
    n = _n;
    for (int i=0; i<MXN; i++)
      E[i].clear(), rE[i].clear();
  }
  void addEdge(int u, int v){
    E[u].PB(v); rE[v].PB(u);
  }
  void DFS(int u){
    vst[u]=1;
    for (auto v : E[u]) if (!vst[v]) DFS(v);
    vec.PB(u);
  }
  void rDFS(int u){
    vst[u] = 1; bln[u] = nScc;
    for (auto v : rE[u]) if (!vst[v]) rDFS(v);
  }
  void solve(){
    nScc = 0;
    vec.clear();
    FZ(vst);
    for (int i=0; i<n; i++)
      if (!vst[i]) DFS(i);
    reverse(vec.begin(),vec.end());
    FZ(vst);
    for (auto v : vec)
      if (!vst[v]){
        rDFS(v); nScc++;
      }
  }
} graph;
int n, m, s, ind[N];
int main(){
  scanf("%d%d%d", &n, &m, &s);
  s--;
  graph.init(n);
  while(m--){
    int ui, vi;
    scanf("%d%d", &ui, &vi);
    graph.addEdge(ui-1, vi-1);
  }
  graph.solve();
  for(int i=0; i<n; i++)
    for(int j: graph.E[i])
      if(graph.bln[i] != graph.bln[j])
        ind[graph.bln[j]]++;
  int ans=0;
  for(int i=0; i<graph.nScc; i++)
    if(ind[i] == 0 and graph.bln[s] != i)
      ans++;
  cout<<ans<<endl;
}