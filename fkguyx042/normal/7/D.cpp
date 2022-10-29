#include<cstdio>
#include<algorithm>
#include<cstring>
#define N 5000005
#define seed 233
#define Mo 998244353
using namespace std;
long long ans=1;
char c[N];
int i,j,m,n,p,k,hash[N],Hash[N],sum[N],pow[N];
int gethash(int x,int y)
{
	 return (Hash[x]-1ll*Hash[y+1]*pow[y-x+1]%Mo+Mo)%Mo;
}
int main()
{
	scanf("%s",c); pow[0]=1; for (i=1;i<N;++i) pow[i]=1ll*pow[i-1]*seed%Mo;
	int len=strlen(c);
	for (i=0;i<len;++i) hash[i+1]=(1ll*hash[i]*seed%Mo+c[i])%Mo;
	for (i=len;i;--i) Hash[i]=(1ll*Hash[i+1]*seed%Mo+c[i-1])%Mo;
	sum[1]=1;
	for (i=2;i<=len;++i)
  {
  	   if (hash[i/2]==gethash((i+3)/2,i)) sum[i]=sum[i/2]+1;
  	   ans+=sum[i];
  }
  printf("%I64d\n",ans);
}