#include<cstdio>
#include<algorithm>
#include<cstring>

#define N 1000005

using namespace std;
const int Mo=(int)1e9+7;
int i,j,m,n,p,k,sum,id,x,y,a[N],flag,ans;
int power(int x,int y)
{
	  int sum=1;
	  for (;y;y>>=1)
	  {
	  	 if (y&1) sum=1ll*x*sum%Mo;
	  	 x=1ll*x*x%Mo;
	  }
	  return sum;
}
int main()
{
	 scanf("%d%d%d",&n,&m,&k); id=1;
	 for (i=1;i<=m;++i)
	{
		 scanf("%d%d",&x,&y); 
		 if (y-x!=1&&y-x!=k+1) { printf("0\n"); return 0; }
		 else if (y-x!=1) a[x]++,++sum,id=x;
	}
	for (i=1;i<=n;++i) a[i]+=a[i-1];
	for (i=id;i<=n&&i+k+1<=n;++i)
		  if (a[max(0,i-k-1)]==0)
      	  ans=(ans+power(2,(i-1-max(0,i-k-1)-(a[i-1]-a[max(0,i-k-1)]))))%Mo;
    if (!a[n]) ans=(ans+1)%Mo; 
    printf("%d\n",ans);
}