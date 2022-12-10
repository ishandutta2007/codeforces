#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
#define MAX 1234
int n,a[MAX],cost[MAX][MAX];
typedef pair<int,int> p2;
p2 next[MAX][MAX],take[MAX][MAX];
int solve(int x,int y){
  if(cost[x][y]>-1)return cost[x][y];
  if(y>n)return a[x];
  if(y==n){
    next[x][y]=p2(n+1,n+1);
    take[x][y]=p2(x,y);
    return cost[x][y]=max(a[x],a[y]);
  }
#define INF 2000000000
  int c[3]={x,y,y+1};
  cost[x][y]=INF;
  for(int j=0;j<3;j++)for(int i=0;i<j;i++){
    int add=max(a[c[i]],a[c[j]]);
    p2 tmp_next,tmp_take=p2(c[i],c[j]);
    if(i)tmp_next=p2(x,y+2);else if(j==1)tmp_next=p2(y+1,y+2);else tmp_next=p2(y,y+2);
    add+=solve(tmp_next.first,tmp_next.second);
    if(add<cost[x][y]){
      cost[x][y]=add;
      next[x][y]=tmp_next;
      take[x][y]=tmp_take;
    }
  }
  return cost[x][y];
}
main(){
  int x,y;
  scanf("%d",&n);
  for(int i=1;i<=n;i++)scanf("%d",&a[i]);
  if(n==1){
    printf("%d\n1\n",a[1]);
    return 0; 
  }
  memset(cost,-1,sizeof(cost));
  printf("%d\n",solve(1,2));
  x=1;y=2;
  while(y<=n){
    printf("%d %d\n",take[x][y].first,take[x][y].second);
    p2 tmp=next[x][y];
    x=tmp.first;y=tmp.second; 
  }
  if(x<=n)printf("%d\n",x);
}