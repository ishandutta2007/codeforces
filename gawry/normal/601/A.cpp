#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<numeric>
#include<map>
#include<set>
#include<cstdlib>
#include<string>
#include<cassert>
#include<iostream>
using namespace std;
typedef vector<int> vi;
typedef long long int64;
#define FOR(i,n)for(int i=0;i<(int)(n);i++)
int n,m;
bool e[410][410];
int d[410];
const int INF=1000000;
vector<int> q;
int dist(bool edge){
  for(int i=1;i<=n;i++){
    d[i]=-1;
  }
  q.clear();
  q.push_back(1);
  d[1]=0;
  for(int i=0;i<q.size();i++){
    int x=q[i];
    for(int y=1;y<=n;y++)if(e[x][y]==edge&&d[y]==-1){
      q.push_back(y);
      d[y]=d[x]+1;
    }
  }
  return d[n]==-1?INF:d[n];
}
int main(){
  scanf("%d %d",&n,&m);
  while(m--){
    int x,y;
    scanf("%d %d",&x,&y);
    e[x][y]=e[y][x]=true;
  }
  int a=dist(false),b=dist(true);
  printf("%d\n",a==INF||b==INF?-1:max(a,b));
  return 0;
}