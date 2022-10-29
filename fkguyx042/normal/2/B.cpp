#include<cstdio>
#include<algorithm>
#include<cstring>

#define N 1005
#define M 4005

using namespace std;
bool G[N][N],F[N][N],flag;
short int two[N][N],fiv[N][N];
int i,j,m,n,p,k,a[N][N],g[N][N],sum[M],c[N][N];
void getF()
{
	  int i=n,j=n;
	  while (i!=1||j!=1)
	{
		 sum[++sum[0]]=F[i][j];
		 if (F[i][j]==0) --i; else --j;
	}
}
void getG()
{
	  int i=n,j=n;
	  while (i!=1||j!=1)
	{
		 sum[++sum[0]]=G[i][j];
		 if (G[i][j]==0) --i; else --j;
	}
}
int main()
{
	  scanf("%d",&n);
	  for (i=1;i<=n;++i)
	     for (j=1;j<=n;++j) scanf("%d",&a[i][j]),c[i][j]=a[i][j];
	  for (i=1;i<=n;++i)
	     for (j=1;j<=n;++j)
	     {
	     	  if (!a[i][j]) { flag=1; continue; }
	         for (k=a[i][j];k%2==0;k/=2) ++two[i][j];
	         for (k=a[i][j];k%5==0;k/=5) ++fiv[i][j];
	     }
	  memset(a,60,sizeof(a));
	  a[1][1]=two[1][1];
	  for (i=1;i<=n;++i)
	     for (j=1;j<=n;++j)
	    {
	    	  if (i==n&&j==n) break;
	    	  if (i!=n)
	    	  {
	    	  	  if (a[i+1][j]>a[i][j]+two[i+1][j])
	    	    {
	    	    	  a[i+1][j]=a[i][j]+two[i+1][j];
	    	    	  F[i+1][j]=0;
	    	    }
	    	  }
	    	  if (j!=n)
	    	  {
	    	  	  if (a[i][j+1]>a[i][j]+two[i][j+1])
	    	  	{
	    	  		   a[i][j+1]=a[i][j]+two[i][j+1];
	    	  		   F[i][j+1]=1;
	    	  	}
	    	  }
	    }
	  memset(g,60,sizeof(g));
	  g[1][1]=fiv[1][1];
	  for (i=1;i<=n;++i)
	    for (j=1;j<=n;++j)
	  { 
	    	  if (i==n&&j==n) break;
	    	  if (i!=n)
	    	  {
	    	  	  if (g[i+1][j]>g[i][j]+fiv[i+1][j])
	    	    {
	    	    	  g[i+1][j]=g[i][j]+fiv[i+1][j];
	    	    	  G[i+1][j]=0;
	    	    }
	    	  }
	    	  if (j!=n)
	    	  {
	    	  	  if (g[i][j+1]>g[i][j]+fiv[i][j+1])
	    	  	{
	    	  		   g[i][j+1]=g[i][j]+fiv[i][j+1];
	    	  		   G[i][j+1]=1;
	    	  	}
	    	  }
	    }
	    if (flag&&min(a[n][n],g[n][n])>1)
	{
		  puts("1");
		  for (i=1;i<=n;++i)
		  {
		    for (j=1;j<=n;++j) 
		          if (!c[i][j]) break;
		    if (j<=n) break;
		  }
		  for (k=1;k<i;++k) printf("D");
		  for (k=1;k<j;++k) printf("R");
		  for (k=i;k<n;++k) printf("D");
		  for (k=j;k<n;++k) printf("R");
	}
	else 
	{
	    printf("%d\n",min(a[n][n],g[n][n]));
	    if (a[n][n]<g[n][n]) getF();
	    else getG();
	    for (i=sum[0];i;--i) if (!sum[i]) printf("D"); else printf("R");
	}
}