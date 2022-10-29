#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int Mo=(int)1e9+7;
int i,j,m,n,p,k,f[1005][1005],a[1005],tot,G[1005];
int ans=1,sum;
int main()
{
	  scanf("%d",&n);
	  for (i=1;i<=n;++i) scanf("%d",&a[i]),tot+=a[i];
	  for (i=1;i<=tot;++i)
	  {
	  	 f[i][1]=1; (G[1]+=f[i][1])%=Mo;
	     for (j=2;j<=tot;++j)
	     {
	         f[i][j]=G[j-1];
	         (G[j]+=f[i][j])%=Mo;
	     }
	  }
	  for (i=1;i<=n;++i)
	  if (a[i]>1)
	  {
	     for (j=1,sum=0;j<=p+1;++j)
	     sum=(sum+f[a[i]-1][j])%Mo;
	     ans=1ll*sum*ans%Mo;
		p+=a[i];
      }
      else p+=a[i];
	   printf("%d\n",ans);
}