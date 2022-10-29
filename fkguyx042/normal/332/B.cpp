#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
long long i,j,m,n,p,k,A,B,b,Max,Min;
long long a[200001],kth[200001];
int main()
{ scanf("%I64d%I64d",&n,&k);
  for (i=1;i<=n;i++) scanf("%I64d",&a[i]);
  for (i=1;i<=k;i++) kth[1]+=a[i];
  for (i=k+1;i<=n;i++) kth[i-k+1]=kth[i-k]+a[i]-a[i-k];
  for (i=n-2*k+1;i;i--)
   { if (Max<=kth[i+k]) { Max=kth[i+k]; b=i+k;}
     if (Min<=Max+kth[i]) { Min=Max+kth[i]; A=i; B=b; }
}
printf("%I64d %I64d\n",A,B);
}