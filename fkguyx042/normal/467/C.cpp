#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

#define N 5005
const long long inf=(long long)1e15;
const int Mo=(int)1e9+7;
int n,i,m,k,j;
long long f[N][N],a[N];
int main()
{
	 scanf("%d%d%d",&n,&m,&k);
	 for (i=1;i<=n;++i) scanf("%I64d",&a[i]),a[i]+=a[i-1];
	 for (i=0;i<=n;++i)
	   for (j=0;j<=k;++j) f[i][j]=-inf;
	 f[0][0]=0;
	 for (i=0;i<n;++i)
	   for (j=0;j<=k;++j)
	        if (f[i][j]!=-inf)
			{ 
			    f[i+1][j]=max(f[i+1][j],f[i][j]);
			    if (j!=k&&i+m<=n) f[i+m][j+1]=max(f[i+m][j+1],f[i][j]+a[i+m]-a[i]);
		    }
	  printf("%I64d\n",f[n][k]);
}