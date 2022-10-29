#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k;
int a[1005][1005],A[1005][1005],B[1005][1005],C[1005][1005],D[1005][1005],ans;
int main()
{
	 scanf("%d%d",&n,&m);
	 for (i=1;i<=n;++i)
       for (j=1;j<=m;++j) scanf("%d",&a[i][j]);
	 for (i=1;i<=n;++i)
	   for (j=1;j<=m;++j)
	     A[i][j]=max(A[i-1][j],A[i][j-1])+a[i][j];
	 for (i=n;i;--i)
	   for (j=1;j<=m;++j)
	       B[i][j]=max(B[i+1][j],B[i][j-1])+a[i][j];
	 for (i=1;i<=n;++i)
	    for (j=m;j;--j)
	       C[i][j]=max(C[i-1][j],C[i][j+1])+a[i][j];
	 for (i=n;i;--i)
	    for (j=m;j;--j)  
	      D[i][j]=max(D[i+1][j],D[i][j+1])+a[i][j];
	 for (i=2;i<n;++i)
	   for (j=2;j<m;++j)
	     ans=max(ans,max(A[i-1][j]+B[i][j-1]+C[i][j+1]+D[i+1][j],A[i][j-1]+B[i+1][j]+C[i-1][j]+D[i][j+1]));
	 printf("%d\n",ans);
}