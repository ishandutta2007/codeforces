#include<cstdio>
#include<algorithm>
#include<iostream>
#include<set>
#include<vector>
using namespace std;
const int INF=1000000000;
const double EPS=1e-9;
int n,m,t[210][210],d[210][210];
bool active[210];
vector< pair<int,int> > x_sorted;
double calc(int x,int y){
  double ans=INF;
  vector< pair<int,int> > s;
  multiset<int> up;
  int down=-INF;
  for(int i=1;i<=n;i++){
    // z+d[x][i] == t[x][y]-z+d[y][i]
    // z = (t[x][y]+d[y][i]-d[x][i])/2
    int tmp=t[x][y]+d[y][i]-d[x][i];
    active[i]=false;
    if(tmp<0)down=max(down,t[x][y]+d[y][i]);
    else if(tmp>2*t[x][y]){
      active[i]=true;
  //    up.insert(d[x][i]);
    }else{
      s.push_back(make_pair(tmp,i));
      active[i]=true;
  //    up.insert(d[x][i]);
    }
  }
  active[0]=true;
  s.push_back(make_pair(0,-1));
  s.push_back(make_pair(2*t[x][y],-1));
  sort(s.begin(),s.end());
  int _x_sorted=0;
  for(int i=0;i+1<s.size();i++){
    if(s[i].second>-1){
      active[s[i].second]=false;
//      up.erase(up.find(d[x][s[i].second]));
      down=max(down,t[x][y]+d[y][s[i].second]);
    }
      while(!active[x_sorted[_x_sorted].second])++_x_sorted;
      int up_best=x_sorted[_x_sorted].first;
      //up.empty()?0:*up.rbegin();
      // up_best+z == down_best-z
      // z = (down_best-up_best)/2
      int z=down-up_best;
      z=max(s[i].first,z);
      z=min(s[i+1].first,z);
      ans=min(ans,max(up_best+0.5*z,down-0.5*z));
  }
  return ans;
}
main(){
  scanf("%d %d",&n,&m);
  for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)t[i][j]=INF;
  while(m--){
    int x,y,z;
    scanf("%d %d %d",&x,&y,&z);
    t[x][y]=t[y][x]=z;
  }
  for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)d[i][j]=i==j?0:t[i][j];
  for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
  double ans=INF;
  for(int i=1;i<=n;i++){
    x_sorted.clear();
    for(int j=1;j<=n;j++)x_sorted.push_back(make_pair(d[i][j],j));
    x_sorted.push_back(make_pair(-1,0));
    sort(x_sorted.begin(),x_sorted.end());
    reverse(x_sorted.begin(),x_sorted.end());
    
    for(int j=1;j<i;j++)ans=min(ans,calc(i,j));
  }
  printf("%.9lf\n",ans);
}