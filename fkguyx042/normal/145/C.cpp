#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>

#define lim 2005
#define N 100005
using namespace std;
const int Mo=(int)1e9+7;
map<int,int>mp;
int Q[lim],sum[lim],f[lim+5];
int i,j,m,n,p,k,R,ans,a[N],pow[N],inv[N];
int power(int x,int y)
{
	  int sum=1;
	  for (;y;y>>=1)
	  {
	  	 if (y&1) sum=1ll*sum*x%Mo;
	  	 x=1ll*x*x%Mo;
	  }
	  return sum;
}
void dfs(long long x)
{
	  if (x>(int)1e9) return;
	  Q[++Q[0]]=x;
	  mp[x]=Q[0];
	  dfs(x*10+4); dfs(x*10+7);
}
int C(int x,int y)
{
	  return 1ll*pow[x]*inv[y]%Mo*inv[x-y]%Mo;
}
int main()
{
	 scanf("%d%d",&n,&k);
	 dfs(4); dfs(7);
	 pow[0]=1;
	 for (i=1;i<=n;++i) pow[i]=1ll*pow[i-1]*i%Mo;
	 for (i=0;i<=n;++i) inv[i]=power(pow[i],Mo-2);
	 for (i=1;i<=n;++i)
	 { 
	 scanf("%d",&a[i]);
	 if (mp[a[i]]) sum[mp[a[i]]]++;
	 else ++R;
	 }
	 f[0]=1;
	 for (i=1;i<=lim;++i)
	    if (sum[i])
	    {
	    	 if (i==512)
	    	   i=512;
	      for (j=lim;j;--j)
	        (f[j]+=1ll*f[j-1]*sum[i]%Mo)%=Mo;
	    }
	 for (i=0;i<=lim;++i)
	     if (i+R>=k&&i<=k)
	      (ans+=1ll*f[i]*C(R,k-i)%Mo)%=Mo;
	 printf("%d\n",ans);
}