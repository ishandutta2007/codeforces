#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k;
long long a[2000005],ans;
inline bool cmp(int a,int b) {return a>b;}
int main()
{scanf("%d",&n);
 for (i=1;i<=n;i++) scanf("%I64d",&a[i]);
   sort(a+1,a+n+1);
   for (i=n;i;i--) a[i]=a[i+1]+a[i];
   for (m=n;n;n/=4)   ans+=a[m-n+1];
   printf("%I64d\n",ans);
}