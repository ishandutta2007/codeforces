#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<bitset>

#define ls (t<<1)
#define rs ((t<<1)+1)
#define mid ((l+r)>>1)
#define fi first
#define se second
#define mk make_pair

#define N 505
#define M 205
#define seed 23333
#define Mo 998244353

using namespace std;
int i,j,m,n,p,k,f[N][N],g[N][N],a[N][N],A[N][N],ans=(int)-1e9;
int sum(int sx,int ex,int sy,int ey)
{
	  return a[ex][ey]-a[sx-1][ey]-a[ex][sy-1]+a[sx-1][sy-1];
}
int main()
{
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;++i)
	   for (j=1;j<=m;++j) scanf("%d",&a[i][j]),A[i][j]=a[i][j];
	for (i=1;i<=n;++i)
	   for (j=1;j<=m;++j) a[i][j]+=a[i-1][j];
	for (i=1;i<=n;++i)
	   for (j=1;j<=m;++j) a[i][j]+=a[i][j-1];
	for (i=1;i<=n-2;++i)
	   for (j=1;j<=m-2;++j)
	      {
	      	  f[i][j]=A[i][j]+A[i][j+1]+A[i][j+2]+A[i+1][j+2]+A[i+2][j+2]+A[i+2][j+1]+A[i+2][j];
	      	  ans=max(ans,f[i][j]);
	      }
	for (k=5;k<=n&&k<=m;k+=2)
    {
	  for (i=1;i<=n-k+1;++i)
	    for (j=1;j<=m-k+1;++j)
	       {
		      g[i][j]=sum(i,i+k-1,j,j+k-1)-f[i+1][j+1]-A[i+1][j];
		      ans=max(ans,g[i][j]);
		      f[i][j]=g[i][j];
		   }
	}
	printf("%d\n",ans);
}