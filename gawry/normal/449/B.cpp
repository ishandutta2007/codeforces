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
#include<queue>
using namespace std;
typedef vector<int> vi;
typedef long long int64;
#define FOR(i,n)for(int i=0;i<(int)(n);i++)
int n,m,k;
typedef pair<long long,long long> p2;
typedef pair<p2,long long> p3;
vector<p2> s[1000000];
priority_queue<p3> q;
long long e[1000000];
p2 d[1000000];
int main(){
  scanf("%d%d%d",&n,&m,&k);
  while(m--){
    int x,y,z;
    scanf("%d%d%d",&x,&y,&z);
    s[x].push_back(p2(y,z));
    s[y].push_back(p2(x,z));
  }
  for(int i=1;i<=n;i++)d[i]=p2(-1LL<<60,0);
  for(int i=0;i<k;i++){
    int y,z;
    scanf("%d%d",&y,&z);
    if(!e[y]||z<e[y])e[y]=z;
  }
  for(int i=2;i<=n;i++)if(e[i]){
    d[i]=p2(-e[i],0);
    q.push(p3(d[i],i));
  }
  d[1]=p2(0,0);
  q.push(p3(d[1],1));
  while(!q.empty()){
    int x=q.top().second;
    p2 tmp=q.top().first;
    q.pop();
    if(d[x]!=tmp)continue;
    for(int i=0;i<s[x].size();i++){
      int y=s[x][i].first;
      p2 z=p2(d[x].first-s[x][i].second,d[x].second|1);
      if(d[y].first<z.first||(d[y].first==z.first&&!d[y].second)){
        d[y]=z;
        q.push(p3(d[y],y));
      }
    }
  }
  int cnt=k;
  for(int i=1;i<=n;i++)cnt-=e[i]&&!d[i].second;
  printf("%d\n",cnt);
  return 0;
}