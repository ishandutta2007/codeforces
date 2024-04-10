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
const int N=1011;
int a[N][N];
int b[N][N];
int n,m;
int main(){
#ifdef flukehn
	freopen("A.in","r",stdin);
#endif
  ios::sync_with_stdio(0),cin.tie(0);
  cin>>n>>m;
  for(int i=1;i<=n;++i)
    for(int j=1;j<=m;++j)
      cin>>a[i][j];
  using E=tuple<int,int,int>;
  vector<E> e;
  using pa=pair<int,int>;
  queue<pa> q;
  for(int i=1;i<n;++i){
    for(int j=1;j<m;++j){
      if(set<int>{a[i][j],a[i][j+1],a[i+1][j],a[i+1][j+1]}.size() == 1) q.push(pa(i,j));
    }
  }
  const int dx[]={0,0,1,1};
  const int dy[]={0,1,0,1};
  while(!q.empty()) {
    auto [x,y]=q.front();
    //dbg(x,y);
    q.pop();
    int i,u,v;
    for(i=0;i<4;++i){
      u=x+dx[i];
      v=y+dy[i];
      if(a[u][v])break;
    }
    if(i>=4) continue;
    e.emplace_back(x,y,a[u][v]);
    for(i=0;i<4;++i){
      u=x+dx[i];
      v=y+dy[i];
      a[u][v]=0;
    }
    //dbg(a[x][y]);
    auto wk=[&](int x,int y){
      //dbg(x,y);
      if(x<1||x>=n||y<1||y>=m)return;
      set<int> s{a[x][y],a[x+1][y],a[x+1][y+1],a[x][y+1]};
      s.erase(0);
      //dbg(x,y,s.size());
      //for(int w:s)debug(w<<" ");debug("\n");
      if(s.size() == 1)q.push(pa(x,y));
    };
    wk(x-1,y-1),wk(x-1,y),wk(x-1,y+1);
    wk(x,y-1),wk(x,y+1);
    wk(x+1,y-1),wk(x+1,y),wk(x+1,y+1);
  }
  for(int i=1;i<=n;++i)
    for(int j=1;j<=m;++j)
      if(a[i][j]){
        cout<<"-1\n";
        return 0;
      }
  reverse(e.begin(),e.end());
  cout<<e.size()<<"\n";
  for(auto [x,y,z]:e)cout<<x<<" "<<y<<" "<<z<<"\n";
}