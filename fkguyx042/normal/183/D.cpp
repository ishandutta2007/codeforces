#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
#include<vector>

#define fi first
#define se second

#define N 3005
#define M 305

#define max(a,b) (a)>(b)?(a):(b)

using namespace std;
int i,j,m,n,p,k,f[M],g[M],Q[M],lim=100,l[M],id[M][N],tot;
double a[N][N];
double h[2*N][N],Ans,G[M][N];
void work()
{
       int i,j,k,now=0,last;
       for (i=0;i<m;++i) h[i][0]=1.,id[i][0]=i; tot=m-1;
       for (i=0;i<n;++i)
         for (j=0;j<m;++j) a[i][j]/=1000.;
       for (i=0;i<n;++i)
       {
            for (j=0;j<m;++j) G[j][1]+=h[j][i]*a[i][j];
              for (j=0;j<m;++j)
                     h[j][i+1]=h[j][i]*(1.-a[i][j]);
       }
}
inline int read()
{
        int x; char c;
        while (c=getchar(),c<'0'||c>'9');
        x=c-'0';
        while (c=getchar(),c>='0'&&c<='9') x=(x<<1)+(x<<3)+c-'0';
        return x;
}
void change(int x,int y)
{
	   int i;
	  id[x][y]=++tot;
	  for (i=0;i<n;++i)
	  {
	  	   G[x][y+1]+=h[tot][i]*a[i][x];
	  	   h[tot][i+1]+=h[tot][i]*(1.-a[i][x]);
	  	   h[tot][i+1]+=h[id[x][y-1]][i]*a[i][x];
	  }
}	  	   	   
void Try()
{
     for (i=0;i<m;++i) l[i]=1;
     for (i=0;i<n;++i)
    {
    	    int k=0;
    	    for (j=1;j<m;++j) if (G[j][l[j]]>G[k][l[k]]) k=j;
    	    Ans+=G[k][l[k]];
    	    change(k,l[k]++);
    }
    printf("%.15lf\n",Ans);
}
void shi()
{
     work();
     Try();
}
int main()
{
     scanf("%d%d",&n,&m); 
     for (i=0;i<n;++i)
       for (j=0;j<m;++j) 
	   {
	      a[i][j]=(double)read();
	   }
     shi();
}