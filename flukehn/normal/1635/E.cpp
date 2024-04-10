#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
using ll=long long;
#ifdef flukehn
#include "algo/debug.h"
#else
#define dbg(...) 0
#define debug(...) 0
#endif
const int N=2e5+11;
vector<int> e[N];
int n,m;
int ty[N],u[N],v[N];
int col[N];
int fl=1;
void dfs(int x){
  for(int y:e[x]){
    if(!col[y]){
      col[y]=-col[x];
      dfs(y);
    }else if(col[y]==col[x]){
      fl=0;
    }
  }
}
int d[N];
int q[N];
int ans[N];
int main(){
#ifdef flukehn
	freopen("A.in","r",stdin);
#endif
  ios::sync_with_stdio(0),cin.tie(0);
  cin>>n>>m;
  for(int i=1;i<=m;++i) {
    cin>>ty[i]>>u[i]>>v[i];
    e[u[i]].push_back(v[i]);
    e[v[i]].push_back(u[i]);
  }
  for(int i=1;i<=n;++i)if(!col[i]) {
    col[i]=1;
    dfs(i);
  }
  if(!fl){
    cout<<"NO\n";
    return 0;
  }
  
  for(int i=1;i<=n;++i) e[i].clear();
  for(int i=1;i<=m;++i){
    int x=u[i],y=v[i];
    if(ty[i]==1){
      if(col[x]==1) e[y].push_back(x);
      else e[x].push_back(y);
    }else{
      if(col[x]==1) e[x].push_back(y);
      else e[y].push_back(x);
    }
  }
  for(int i=1;i<=n;++i)for(int y:e[i])d[y]+=1;
  int h=0,t=0;
  for(int i=1;i<=n;++i)if(!d[i]) q[t++]=i;
  while(h<t){
    int x=q[h++];
    for(int y:e[x]){
      d[y]-=1;
      if(d[y]==0)q[t++]=y;
    }
  }
  if(t!=n){
    cout<<"NO\n";
    return 0;
  }
  cout<<"YES\n";
  For(i,0,n) ans[q[i]]=2*n+1-i;
  for(int i=1;i<=n;++i){
    if(col[i]==1)cout<<"L ";
    else cout<<"R ";
    cout<<ans[i]<<"\n";
  }
}