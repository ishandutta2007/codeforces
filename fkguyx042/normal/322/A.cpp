#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k;
int main()
 {scanf("%d%d",&n,&m);
   printf("%d\n",n+m-1);
   for (i=1;i<=n;i++)
    printf("%d %d\n",i,1);
   for (i=2;i<=m;i++)
    printf("%d %d\n",1,i);
  return 0;
}