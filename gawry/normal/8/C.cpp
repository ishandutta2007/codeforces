#include<cstdio>
#include<algorithm>
using namespace std;
int x0,y0,n,x[30],y[30],d[30][30],t[1<<24];
main(){
  scanf("%d %d %d",&x0,&y0,&n);
  for(int i=0;i<n;i++)scanf("%d %d",&x[i],&y[i]),x[i]-=x0,y[i]-=y0;
  for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)d[i][j]=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
  for(int i=1;i<(1<<n);i++){
    int pos=0;
    while(!(i&1<<pos))pos++;
    t[i]=t[i-(1<<pos)]+2*d[pos][n];
    for(int j=pos+1;j<n;j++)if(i&1<<j)t[i]=min(t[i],t[i-(1<<pos)-(1<<j)]+d[pos][n]+d[j][n]+d[pos][j]);
  }
  printf("%d\n",t[(1<<n)-1]);
  int left=(1<<n)-1;
  while(left){
    int pos=0;
    while(!(left&1<<pos))pos++;
    if(t[left]==t[left-(1<<pos)]+2*d[pos][n]){
      printf("0 %d ",pos+1);
      left-=1<<pos;
      continue;
    }
    for(int j=pos+1;j<n;j++)if(left&1<<j&&t[left]==t[left-(1<<pos)-(1<<j)]+d[pos][n]+d[j][n]+d[pos][j]){
      printf("0 %d %d ",pos+1,j+1);
      left-=1<<pos;
      left-=1<<j;
      break;
    }
  }
  puts("0");
}