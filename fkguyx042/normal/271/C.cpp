#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k;
int main()
{ scanf("%d%d",&n,&k);
  if (n<3*k) printf("-1\n");
  else { 
    for (i=1;i<=2*k;i++)
       printf("%d ",i/2+(i%2!=0));
    for (i=1;i<=k;i++)
    printf("%d ",i);
    for (i=3*k+1;i<=n;i++) printf("%d ",k);
}
}