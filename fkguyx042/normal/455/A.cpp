#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k;
long long f[100005],Max,ans,a[100001];
int main()
{ scanf("%d",&n);
   for (i=1;i<=n;i++) scanf("%d",&k),a[k]+=k;
   for (i=100000;i;i--) 
   { f[i]=max(f[i],f[i+1]);
     f[i]=max(f[i],Max+a[i]);
     ans=max(f[i],ans);
     Max=max(f[i+1],Max);
}
printf("%I64d\n",ans);
}