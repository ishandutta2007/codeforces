#include<cstdio>
#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<numeric>
#include<cmath>
#include<cstring>
#include<cassert>
using namespace std;

#define ALL(t) t.begin(),t.end()
#define FOR(i,n) for (int i=0;i<(int)(n);i++)
#define FOREACH(i,t) for (typeof(t.begin())i=t.begin();i!=t.end();i++)
typedef vector<int> vi;
typedef long long int64;

int n,m;
char t[1010][1010];
set<char> seen;
int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
void mark(int x,int y){
  FOR(k,4)if(x+dx[k]>=0&&y+dy[k]>=0)seen.insert(t[x+dx[k]][y+dy[k]]);
}
typedef pair<int,int> p2;
typedef pair<p2,p2> p4;
vector<p4> f;
void two(int x0,int y0,int x1,int y1){
  seen.clear();
  mark(x0,y0);
  mark(x1,y1);
  char c='0';
  while(seen.count(c))++c;
  t[x0][y0]=t[x1][y1]=c;
  f.push_back(p4(p2(x0,y0),p2(x1,y1)));
}
bool empty(int x,int y){
  return x>=0&&y>=0&&t[x][y]=='.';
}
void color(vector<p2> a){
  FOR(i,a.size())t[a[i].first][a[i].second]='.';
  seen.clear();
  FOR(i,a.size())mark(a[i].first,a[i].second);
  char c='0';
  while(seen.count(c))++c;
  FOR(i,a.size())t[a[i].first][a[i].second]=c;  
}
main(){
  scanf("%d %d",&n,&m);
  FOR(i,n)scanf(" %s",t[i]);
  FOR(i,n)FOR(j,m-1)if(t[i][j]=='.'&&t[i][j+1]=='.')two(i,j,i,j+1);
  FOR(i,n-1)FOR(j,m)if(t[i][j]=='.'&&t[i+1][j]=='.')two(i,j,i+1,j);

//  FOR(i,n)puts(t[i]);

  FOR(i,f.size()){
    int x0=f[i].first.first,y0=f[i].first.second,x1=f[i].second.first,y1=f[i].second.second;
    int cnt[2]={};
    FOR(k,4)cnt[0]+=empty(x0+dx[k],y0+dy[k]),cnt[1]+=empty(x1+dx[k],y1+dy[k]);
//cout<<cnt[0]<<" "<<cnt[1]<<endl;
    if(cnt[0]+cnt[1]<=3){
      vector<p2> t;
      t.push_back(p2(x0,y0));
      t.push_back(p2(x1,y1));
      FOR(k,4){if(empty(x0+dx[k],y0+dy[k]))t.push_back(p2(x0+dx[k],y0+dy[k]));if(empty(x1+dx[k],y1+dy[k]))t.push_back(p2(x1+dx[k],y1+dy[k]));}
      color(t);
      continue;
    }else{
      //assert(0);
    } 
  }
  FOR(i,n)FOR(j,m)if(t[i][j]=='.'){
    puts("-1");
    return 0;
  } 
  FOR(i,n)puts(t[i]);
}