#include <stdio.h>
int n,v,k,x,i,good,ansi=0,ans[55];

int main()
{
 scanf("%d%d",&n,&v);
 for (i=1; i<=n; ++i) {
  scanf("%d",&k);
  good=0;
  while (k--) {
   scanf("%d",&x);
   if (x<v) { good=1; }
  }
  if (good) ans[ansi++]=i;
 }
 printf("%d\n",ansi);
 for (i=0; i<ansi; ++i) printf("%d ",ans[i]);
 return 0;
}