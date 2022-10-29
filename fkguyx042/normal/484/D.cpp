#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const long long INF=(long long)1e18;
int i,j,m,n,p,k,a[1000001];
long long Tree[5000001],tree[5000001],sum,f[1000001],ans=-INF,A,B;
int main()
{  scanf("%d",&n);
   for (i=1;i<=n;i++) scanf("%d",&a[i]);
   A=a[1];B=-a[1];
   for (i=1;i<=n;i++) f[i]=-(long long)1e18;
   for (i=1;i<=n;i++)
{   f[i]=max(A-a[i],B+a[i]);
    A=max(A,f[i]+a[i+1]);
    B=max(B,f[i]-a[i+1]);
    ans=max(ans,f[i]);
}
printf("%I64d\n",ans);
}