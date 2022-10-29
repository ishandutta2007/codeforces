#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int Mo=1000000007;
int All,n,i,j,k;
int a[2000005],b[2000005],f[2000005];
long long two[2000005],ans,tmp;
int main()
{ All=(1<<20)-1; scanf("%d",&n);
  for (i=1;i<=n;i++) scanf("%d",&a[i]),b[a[i]]++;
  two[0]=1;
  for (i=1;i<=n;i++) two[i]=two[i-1]*2%Mo;
  for (i=0;i<20;i++)
   for (j=0;j<=All;j++) if (j&(1<<i)) b[j-(1<<i)]+=b[j],f[j]++;
   for (i=0;i<=All;i++)
   {  tmp=(two[b[i]]+Mo-1)%Mo;
      if (f[i]&1) ans=(ans+Mo-tmp)%Mo;
	  else ans=(ans+tmp)%Mo;
  }
  printf("%I64d\n",ans);
}