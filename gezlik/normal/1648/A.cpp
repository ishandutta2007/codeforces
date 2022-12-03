#include<bits/stdc++.h>
using namespace std;

typedef long long int64;

int n,m;
map<int,vector<int>>vx,vy;

void work(){
  scanf("%d%d",&n,&m);
  for (int i=1;i<=n;++i)
    for (int j=1;j<=m;++j){
      int x;
      scanf("%d",&x);
      vx[x].push_back(i);
      vy[x].push_back(j);
    }
  int64 ans=0;
  for (auto [rub,d]:vx){
    sort(d.begin(),d.end());
    int64 sum=0,cnt=0;
    for (int x:d){
      ans+=x*cnt-sum;
      ++cnt;sum+=x;
    }
  }
  for (auto [rub,d]:vy){
    sort(d.begin(),d.end());
    int64 sum=0,cnt=0;
    for (int x:d){
      ans+=x*cnt-sum;
      ++cnt;sum+=x;
    }
  }
  printf("%lld\n",ans);
}

int main(){
  int T=1;
  //scanf("%d",&T);
  for (;T--;) work();
  return 0;
}