#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int i,j,m,n,p,k,x;
int f[1000001];
long long ans;
int main()
{scanf("%d",&n);
  for (i=n;i;i--)
    if (!f[i])
    {    k=(int)log2(i)+1; x=(1<<k)-i-1;
        f[x]=i; f[i]=x; ans+=((1<<k)-1)*2;
}
printf("%I64d\n",ans);
for (i=0;i<=n;i++) printf("%d ",f[i]);
}