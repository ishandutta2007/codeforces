#include<cstdio>
#include<algorithm>
using namespace std;
int sum(int from,int to){
  if(from<0&&to<0)return sum(-to,-from);
  if(from<0)return sum(0,-from)+sum(0,to);
  return (from+to)*(to-from+1)/2; 
}
int n,k,M,s[110][110],dead[110][110],xc,yc;
main(){
  scanf("%d %d",&n,&k);
  xc=k/2;yc=k/2;
  while(n--){
    scanf("%d",&M);    
#define INF 1000000000    
    int best_y,best_x,best_cost=INF;
    for(int x=0;x<k;x++)for(int y=k-1;y>=0;y--)s[x][y]=s[x][y+1]+dead[x][y];
    for(int x=0;x<k;x++)for(int y=0;y+M<=k;y++)if(s[x][y+M]==s[x][y]){
      int cost=M*abs(x-xc)+sum(y-yc,y+M-1-yc);
      if(cost<best_cost){
        best_cost=cost;
        best_x=x;
        best_y=y;
      }
    }
    if(best_cost==INF)puts("-1");else printf("%d %d %d\n",best_x+1,best_y+1,best_y+M);
    if(best_cost<INF)for(int i=0;i<M;i++)dead[best_x][best_y+i]=1;
  }
}