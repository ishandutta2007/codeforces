#include <bits/stdc++.h>
using namespace std;
const int N=101010;
int n, m, u[N], v[N], c[N];
vector<int> e[N];
vector<int> ans;
int at[N], ind[N];
bool good(int cst, bool con){
  for(int i=1; i<=n; i++)
    e[i].clear(), ind[i]=0;
  for(int i=1; i<=m; i++){
    if(c[i]<=cst) continue;
    e[u[i]].push_back(v[i]);
    ind[v[i]]++;
  }
  vector<int> topo;
  for(int i=1; i<=n; i++)
    if(ind[i]==0)
      topo.push_back(i);
  for(size_t i=0; i<topo.size(); i++){
    int cur=topo[i];
    for(int nxt: e[cur]){
      ind[nxt]--;
      if(ind[nxt]==0)
        topo.push_back(nxt);
    }
  }
  if((int)topo.size() < n) return false;
  if(con){
    ans.clear();
    for(int i=0; i<n; i++)
      at[topo[i]]=i;
    for(int i=1; i<=m; i++){
      if(c[i]>cst) continue;
      if(at[u[i]] < at[v[i]]) continue;
      ans.push_back(i);
    }
  }
  return true;
}
int main(){
  scanf("%d%d", &n, &m);
  for(int i=1; i<=m; i++)
    scanf("%d%d%d", &u[i], &v[i], &c[i]);
  int bl=0, br=1e9, ba=1e9;
  while(bl<=br){
    int bmid=(bl+br)>>1;
    if(good(bmid, false)) ba=bmid, br=bmid-1;
    else bl=bmid+1;
  }
  assert(good(ba, true));
  printf("%d %d\n", ba, (int)ans.size());
  for(size_t i=0; i<ans.size(); i++)
    printf("%d%c", ans[i], " \n"[i+1==ans.size()]);
}