#include<cstdio>
#include<algorithm>
using namespace std;
int cnt[1010],n,x;
main(){
  scanf("%d",&n);
  while(n--){scanf("%d",&x);cnt[x]++;}
  int all=0,m=0;
  for(int i=1;i<1010;i++)all+=cnt[i]>0,m=max(m,cnt[i]);
  printf("%d %d\n",m,all);
}