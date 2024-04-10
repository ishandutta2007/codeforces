#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
long long a[3];
int i,j,m,n,p,k;
int main()
{  for (i=0;i<3;i++) scanf("%I64d",&a[i]);
   sort(a,a+3);
   if (a[2]/2>=1ll*(a[1]+a[0])) printf("%I64d\n",a[0]+a[1]);
   else printf("%I64d\n",1ll*(a[0]+a[1]+a[2])/3);
}