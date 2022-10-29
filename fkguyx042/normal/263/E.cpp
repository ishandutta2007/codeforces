#include<cstdio>
#include<algorithm>
#include<cstring>

#define N 2005

using namespace std;
int i,j,m,n,p,k,ansx,ansy;
long long a[N][N],b[3*N][N],c[3*N][N];
int Idy[N][N],idy[N][N];
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for (i=1;i<=n;++i)
      for (j=1;j<=m;++j)
        scanf("%I64d",&a[i][j]),a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
    for (i=1;i<=n;++i)
       for (j=0;j<=m;++j)
    {
    	  if (j)
    	{
    	  int id=i-j+max(n,m);
    	  ++b[id][0];
    	  b[id][b[id][0]]=(b[id][0]>1?b[id][b[id][0]-1]:0)+a[i][j];
    	  idy[i][j]=b[id][0];
        }
    	  int id=i+j;
    	  ++c[id][0];
    	  c[id][c[id][0]]=(c[id][0]>1?c[id][c[id][0]-1]:0)+a[i][j];
    	  Idy[i][j]=c[id][0];
    }
    for (i=1;i<=3*max(n,m);++i) b[i][0]=c[i][0]=0;
    long long ans=0;
    for (i=k;i<=n-k+1;++i)
       for (j=k;j<=m-k+1;++j)
    {
    	  long long sum=0;
    	  int id=i+j+k-1;
    	  sum=c[id][Idy[i+k-1][j]]-c[id][max(0,Idy[i][j+k-1]-1)];
    	  id=i+j-k-1;
    	  sum+=c[id][Idy[i-1][j-k]]-c[id][max(0,Idy[i-k][j-1]-1)];
    	  id=i-k-j+max(n,m);
    	  sum-=b[id][idy[i-1][j+k-1]]-b[id][max(0,idy[i-k][j]-1)];
    	  id=i-j+k+max(n,m);
    	  sum-=b[id][idy[i+k-1][j-1]]-b[id][max(0,idy[i][j-k]-1)];
    	  if (sum>ans||!ansx) { ans=sum; ansx=i; ansy=j;}
    }
    printf("%d %d\n",ansx,ansy);
}