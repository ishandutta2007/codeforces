#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,a[2001],x,y;
double f[2001][2001],ans;
double skydec(double &a,double &b)
{ a=b=(a+b)/2.0; }
int main()
{   scanf("%d%d",&n,&m);
    for (i=1;i<=n;i++) scanf("%d",&a[i]);
     for(i=1;i<n;i++)  
        for(j=i+1;j<=n;j++)  
            f[i][j]=a[i]>a[j],f[j][i]=1-f[i][j]; 
	for (i=1;i<=m;i++)
	{ scanf("%d%d",&x,&y);
	  skydec(f[x][y],f[y][x]);
	for (j=1;j<=n;j++)
	  if (x!=j&&y!=j) skydec(f[j][x],f[j][y]),skydec(f[x][j],f[y][j]);
}
for (i=1;i<=n;i++)
 for (j=i+1;j<=n;j++)
   ans+=f[i][j];
printf("%.10lf\n",ans);
}