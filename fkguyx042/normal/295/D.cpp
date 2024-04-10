#include<cstdio>
#include<algorithm>
#include<cstring>

#define N 2005

using namespace std;
int f[N][N],g[N][N],i,j,m,n,p,k,ans;
const int Mo=(int)1e9+7;
void jia(int &x,int y) { x+=y; if (x>=Mo) x-=Mo; }
int main()
{
	scanf("%d%d",&n,&m);
	for (i=2;i<=m;++i) f[1][i]=1;
	for (i=2;i<=n;++i)
	{ 
	      int s=0;
		  for (j=1;j<=m;++j)
		  {
		  	  jia(s,f[i-1][j]);
		  	  jia(f[i][j],f[i][j-1]+s);
	      }
	}
	for (i=1;i<=n;++i) for (j=1;j<=m;++j) g[i][j]=(f[i][j]-f[i-1][j]+Mo)%Mo;
	for (i=1;i<=n;++i) for (j=1;j<=m;++j) jia(g[i][j],g[i-1][j]),jia(f[i][j],f[i-1][j]);
	for (i=1;i<=n;++i)
	  for (j=2;j<=m;++j)
	     jia(ans,1ll*g[i][j]*f[n-i+1][j]%Mo*(m-j+1)%Mo);
	printf("%d\n",ans);
}