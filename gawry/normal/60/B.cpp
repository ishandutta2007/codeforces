#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<sstream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<numeric>
#include<cmath>
using namespace std;

typedef long long int64;
typedef pair<int,int> p2;
typedef vector<int> vi;

#define ALL(t) t.begin(),t.end()
#define FOR(i,n) for (int i=0; i<(n); i++)
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)

template<typename T,typename TT> ostream &operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream &operator<<(ostream &s,vector<T> t){s<<"{";FOR(i,t.size())s<<t[i]<<(i==t.size()-1?"":",");return s<<"}"<<endl; }

bool b[20][20][20];
int k,n,m;
char t[20][20][20];
int main() {
  scanf("%d %d %d",&k,&n,&m);
  FOR(i,k)FOR(j,n)scanf(" %s",&t[i][j]);
  int x,y;
  scanf("%d %d",&x,&y);
  --x;--y;
  typedef pair<int,int> p2;
  typedef pair<int,p2> p3;
  vector<p3> q;
  if(t[0][x][y]!='#')q.push_back(p3(0,p2(x,y))),b[0][x][y]=true;
  FOR(i,q.size()){
    int x=q[i].first,y=q[i].second.first,z=q[i].second.second;
//    cout<<x<<" "<<y<<" "<<z<<endl;
    int dx[6]={-1,1,0,0,0,0},dy[6]={0,0,-1,1,0,0},dz[6]={0,0,0,0,-1,1};
    FOR(j,6){
      int xx=x+dx[j],yy=y+dy[j],zz=z+dz[j];
      if(xx<0||xx>=k||yy<0||yy>=n||zz<0||zz>=m)continue;
      if(t[xx][yy][zz]=='#'||b[xx][yy][zz])continue;
      b[xx][yy][zz]=true;
      q.push_back(p3(xx,p2(yy,zz)));
    }
  }
  printf("%d\n",q.size());
  return 0;
}