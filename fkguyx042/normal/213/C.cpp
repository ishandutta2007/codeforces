#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int Maxn=301;
int f[600][301][301];
int a[Maxn][Maxn],i,j,m,n,p,k,sum;
const int INF=(int)1e9;
int main()
{ scanf("%d",&n);
  for (i=1;i<=n;i++) 
    for (j=1;j<=n;j++) scanf("%d",&a[i][j]);

 for (i=0;i<=2*n-1;i++)
   for (j=1;j<=n;j++)
     for (k=1;k<=n;k++) f[i][j][k]=-INF;
      f[1][1][1]=a[1][1];
 for (i=1;i<2*n-1;i++)
    for (j=1;j<=n;j++)
	  for (k=1;k<=n;k++)
	   if (f[i][j][k]!=-INF)
	  {   if (i-j+2<=n&&i-k+2<=n)
	      {  if (j==k)  sum=a[j][i-j+2];
	         else sum=a[j][i-j+2]+a[k][i-k+2];
	         f[i+1][j][k]=max(f[i+1][j][k],f[i][j][k]+sum);
	      }
	      if (i-j+2<=n&&k<n)
	      {  if (j==k+1) sum=a[j][i-j+2];
	        else sum=a[j][i-j+2]+a[k+1][i-k+1];
	         f[i+1][j][k+1]=max(f[i+1][j][k+1],f[i][j][k]+sum);
	      }
	      if (j<n&&i-k+2<=n)
	    {   if (k==j+1) sum=a[k][i-k+2];
	        else sum=a[k][i-k+2]+a[j+1][i-j+1];
	        f[i+1][j+1][k]=max(sum+f[i][j][k],f[i+1][j+1][k]);
	    }
	     if (j<n&&k<n)
	     {  if (j==k) sum=a[j+1][i-j+1];
	        else sum=a[j+1][i-j+1]+a[k+1][i-k+1];
	        f[i+1][j+1][k+1]=max(sum+f[i][j][k],f[i+1][j+1][k+1]);
}
}
printf("%d\n",f[2*n-1][n][n]);
}