#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k;
int row[205],sum[205];
int a[105][105];
int main()
{
	 scanf("%d%d",&n,&m);
	 for (i=1;i<=n;++i)
	   for (j=1;j<=m;++j) scanf("%d",&a[i][j]);
	 for (i=1;i<=n;++i)
	   for (j=1;j<=m;++j) 
	     row[i]+=a[i][j];
	 for (i=1;i<=m;++i)
	   for (j=1;j<=n;++j)
	     row[i+n]+=a[j][i];
	 for (;;)
	 {
	 	   int id=1;
	 	   for (i=2;i<=n+m;++i) if (row[i]<row[id]) id=i;
	 	   if (row[id]>=0) break;
	 	   sum[id]^=1;
	 	   if (id<=n)
	 	   {
	 	   	    for (i=1;i<=m;++i) row[id]-=2*a[id][i];
	 	   	    for (i=1;i<=m;++i) row[i+n]-=2*a[id][i],a[id][i]=-a[id][i];
	 	   }
	 	   else 
	 	   {
	 	   	    id-=n;
	 	   	    for (i=1;i<=n;++i) row[id+n]-=2*a[i][id];
	 	   	    for (i=1;i<=n;++i) row[i]-=2*a[i][id],a[i][id]=-a[i][id];
	 	   }
	 }
	 int A=0;
	 for (i=1;i<=n;++i) if (sum[i]) ++A;
	 printf("%d",A);
	 for (i=1;i<=n;++i) if (sum[i]) printf(" %d",i);
	 puts("");
	 A=0;
	 for (i=1;i<=m;++i) if (sum[i+n]) ++A;
	 printf("%d",A);
	 for (i=1;i<=m;++i) if (sum[i+n]) printf(" %d",i);
}