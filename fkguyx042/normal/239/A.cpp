#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,y;
int main()
 {scanf("%d%d%d",&y,&k,&n);
  p=0;
   for (i=k;i<=n;i+=k)
    { if (i-y>0)  { p=1; printf("%d ",i-y);}}
    if (p==0) printf("-1\n"); else printf("\n");
    return 0;
}