#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
unordered_map<int,int> f, sz, sz2;
const int N=121212;
int F(int x){
  return x==f[x]?x:f[x]=F(f[x]);
}
void uni(int x, int y){
  x=F(x);
  y=F(y);
  if(x==y) return;
  f[x]=y;
  sz[y]+=sz[x];
  sz2[y]+=sz2[x];
}
int n;
bool ok(LL x){
  return __builtin_popcountll(x) == 1;
}
int main(){
  scanf("%d", &n);
  vector<int> cand;
  for(int i=0, x; i<n; i++){
    scanf("%d", &x);
    f[x]=x;
    sz[x]++;
    sz2[x]=1;
    cand.push_back(x);
  }
  sort(cand.begin(), cand.end());
  cand.resize(unique(cand.begin(), cand.end())-cand.begin());
  for(int xx: cand)
    for(int g=1; g<31; g++){
      LL goal=(1LL<<g)-xx;
      auto it=f.find(goal);
      if(it==f.end()) continue;
      uni(xx, goal);
    }
  int ans=n;
  for(int xx: cand){
    if(F(xx)!=xx) continue;
    if(sz2[xx] == 1){
      if(sz[xx] > 1 and ok(xx+xx))
        ans-=sz[xx];
    }else
      ans-=sz[xx];
  }
  cout<<ans<<endl;
}