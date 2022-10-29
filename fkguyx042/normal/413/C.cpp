#include<cstdio>
#include<algorithm>
using namespace std;
long long sum;
int n,m,i,j;
long long b[1001],a[1001];
int main()
 {scanf("%d%d",&n,&m);
 for (i=1;i<=n;i++)
  {scanf("%I64d",&a[i]); sum+=a[i]; }
 for (i=1;i<=m;i++)
  {scanf("%I64d",&b[i]);
    sum-=a[b[i]];
}
for (i=1;i<=m;i++) b[i]=a[b[i]];
sort(b+1,b+m+1);
for (i=m;i>=1;i--)
 sum+=max(sum,b[i]);
printf("%I64d\n",sum);
return 0;
}