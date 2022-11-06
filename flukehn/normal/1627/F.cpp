#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
#ifdef flukehn
#include "algo/debug.h"
#else
#define dbg(...) 0
#define debug(...) 0
#endif
const int inf=~0u>>2;
const int N=511;
const int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
int e[N][N][4];
int vis[N][N];
int d[N][N];
int solve(){
  int n,m;
  cin>>n>>m;
  For(i,0,m+2)
    For(j,0,m+2){
      vis[i][j]=0;
      d[i][j]=inf;
      For(k,0,4)
        e[i][j][k]=0;
    }
  for(int i=0;i<n;++i){
    int x,y,u,v;
    cin>>x>>y>>u>>v;
    if(x>u||y>v)swap(x,u),swap(y,v);
    if(x<u){
      y-=1;
      e[x][y][0]+=1;
      e[x][y+1][1]+=1;
      x=m-x;
      y=m-y;
      e[x][y][1]+=1;
      e[x][y-1][0]+=1;
    }else{
      x-=1;
      e[x][y][2]+=1;
      e[x+1][y][3]+=1;
      x=m-x;
      y=m-y;
      e[x][y][3]+=1;
      e[x-1][y][2]+=1;
    }
  }
  using E=tuple<int,int,int>;
  priority_queue<E,vector<E>,greater<E>> Q;
  for(int i=0;i<=m;++i) {
    d[i][0]=0;
    d[0][i]=0;
    Q.push(E(0,i,0));
    Q.push(E(0,0,i));
  }
  while(!Q.empty()){
    auto [l,x,y]=Q.top();
    Q.pop();
    if(vis[x][y])continue;
    vis[x][y]=1;
    for(int i=0;i<4;++i) {
      int u=x+dx[i];
      int v=y+dy[i];
      if(u<1||v<1||u>=m||v>=m||vis[u][v])continue;
      int w=e[x][y][i]+l;
      if(d[u][v]>w){
        d[u][v]=w;
        Q.push(E(w,u,v));
      }
    }
  }
  return n-d[m/2][m/2];
}
int main(){
#ifdef flukehn
  //freopen("a.in","r",stdin);
#endif
  ios::sync_with_stdio(0),cin.tie(0);
  int t;
  cin>>t;
  while(t--){
    cout<<solve()<<"\n";
  }
}