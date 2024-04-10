#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
double F[205][205][205],p[205],ans;
int a[205],A,i,j,m,n,k,l,id[205];
inline bool cmp(int A,int b) { return a[A]>a[b]; }
int main()
{ 
	scanf("%d%d%d",&n,&l,&k);
	F[0][0][min(k,n)]=1.;
	for (i=1;i<=n;++i) scanf("%lf",&p[i]),p[i]/=100.;
	for (i=1;i<=n;++i) scanf("%d",&a[i]),id[i]=i;
	sort(id+1,id+n+1,cmp);
    for (i=1;i<=n;++i)
    if (a[id[i]]==-1)
      for (j=0;j<=n;++j)
         for (k=0;k<=n;++k)
          {
			F[i][j+1][k]+=F[i-1][j][k+1]*p[id[i]];
            F[i][j][k]+=F[i-1][j][k]*(1.-p[id[i]]);
	      }
	else 
	  for (j=0;j<=n;++j)
	    for (k=0;k<=n;++k)
	    {
			F[i][j+1][min(k+a[id[i]],n)]+=F[i-1][j][k]*p[id[i]];
			F[i][j][k]+=F[i-1][j][k]*(1.-p[id[i]]);
	    }
	for (i=l;i<=n;++i)
	  for (j=0;j<=n;++j) ans+=F[n][i][j];
	printf("%.10lf\n",ans);
}