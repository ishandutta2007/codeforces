#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k;
int a[51];
int main()
{ scanf("%d%d%d",&n,&m,&k);
  for (i=1;i<=n;i++) scanf("%d",&a[i]);
  sort(a+1,a+n+1);
  if (m<=k) { printf("0\n"); }
  else {   m-=k;
         for (i=1;i<=n;i++)
         {  m-=a[n-i+1]-1;
            if (m<=0) break;
         }
         if (i>n) printf("%d\n",-1);
         else printf("%d\n",i);
}
}