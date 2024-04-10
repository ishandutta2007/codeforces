#include<cstdio>
#include<algorithm>
#include<cstring>
#define N 1000005
#define seed 233
#define Mo 998244353
using namespace std;
char c[N];
int i,j,m,n,p,k,hash[N],Hash[N],sum[N],pow[N],next[N],ax,ans[N];
int gethash(int x,int y)
{
	 return (hash[y]-1ll*hash[x-1]*pow[y-x+1]%Mo+Mo)%Mo;
}
int main()
{
	scanf("%d%d",&n,&k);
	scanf("%s",c); pow[0]=1; for (i=1;i<N;++i) pow[i]=1ll*pow[i-1]*seed%Mo;
	int len=strlen(c);
	for (i=0;i<len;++i) hash[i+1]=(1ll*hash[i]*seed%Mo+c[i])%Mo;
	for (i=len;i;--i) c[i]=c[i-1];
	for (i=2,j=0;i<=len;++i)
	{
		  while (j&&c[j+1]!=c[i]) j=next[j];
		  if (c[j+1]==c[i]) ++j;
		  next[i]=j;
	}
	if (k==1)
	{
		  sum[1]++;
	}
	else 
	for (i=1;i<=len;++i)
	{
		  int lx=i-next[i];
		  if (i%lx!=0) continue;
		  int duan=i/lx;
		  if (duan%k!=0) continue;
		  int rx=i/k;
		  sum[i]++;
		  int l=i+1,r=min(len,i+rx)+1,mid=0;
		  while ((l+r)>>1!=mid)
		  {
		  	  mid=(l+r)>>1;
		  	  if (gethash(i+1,mid)!=gethash(1,mid-i)) r=mid; else l=mid;
	      }
	      sum[r]--;
	}
	for (i=1;i<=len;++i)
	{
		 ax+=sum[i];
		 ans[i]=(ax>0);
	}
	for (i=1;i<=len;++i) printf("%d",ans[i]);
}