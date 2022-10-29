#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,ans;
int a[1000001],f[1000001];
int main()
 {scanf("%d",&n);
   for (i=1;i<=n;i++)
   scanf("%d",&a[i]),ans^=a[i];
   for (i=1;i<=n;i++)
     f[i]=f[i-1]^i;
  for (i=2;i<=n;i++)
   {   p=n/i;
       k=n%i;
       if (p%2==1) ans^=f[i-1];
       ans^=f[k];
}
printf("%d\n",ans);
return 0;
}