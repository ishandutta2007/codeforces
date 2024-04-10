#include <stdio.h>
#define FOR(i,n) for(i=0;i<n;i++)
#define MAXN 100001

int ax[MAXN],ay[MAXN];

int main(int argc, char *argv[]){
  int N,i,mx,my;
  long long J;
  scanf("%d%I64d%d%d",&N,&J,&mx,&my);
  FOR(i,N){ scanf("%d",&(ax[i])); scanf("%d",&(ay[i])); }
  long long j=J%(2*((long long)N));
  FOR(i,j){ mx=2*ax[(i%N)]-mx; my=2*ay[(i%N)]-my; }
  printf("%d %d\n",mx,my);
  return 0;
}