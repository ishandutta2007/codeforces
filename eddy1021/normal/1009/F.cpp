// eddy1021
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
inline int getint(){
  int _x=0; char _tc=getchar();    
  while(_tc<'0'||_tc>'9') _tc=getchar();
  while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
  return _x;
}
const int N=(1<<20);
#include <bits/extc++.h>
using namespace __gnu_pbds;
#include <ext/pb_ds/assoc_container.hpp>
typedef cc_hash_table<int,int> umap_t;
umap_t cnt[N];
//unordered_map<int,int> cnt[N];
int who[N], id[N];
int n, ans[N];
vector<int> v[N];
inline int combine(int id1, int id2){
  if(cnt[id1].size() < cnt[id2].size()) swap(id1, id2);
  for(auto i: cnt[id2]){
    cnt[id1][i.first]+=i.second;
    if(cnt[id1][i.first] > cnt[id1][who[id1]] or
      (cnt[id1][i.first] == cnt[id1][who[id1]] and i.first < who[id1]))
      who[id1]=i.first;
  }
  return id1;
}
void go(int now, int prt, int dep){
  id[now]=now;
  who[now]=dep;
  cnt[now][dep]=1;
  for(int son: v[now]){
    if(son == prt) continue;
    go(son, now, dep+1);
    id[now]=combine(id[now], id[son]);
  }
  ans[now]=who[id[now]]-dep;
}
int main(){
  n=getint();
  for(int i=1; i<n; i++){
    int ui=getint();
    int vi=getint();
    v[ui].push_back(vi);
    v[vi].push_back(ui);
  }
  go(1, 1, 0);
  for(int i=1; i<=n; i++)
    printf("%d\n", ans[i]);
}