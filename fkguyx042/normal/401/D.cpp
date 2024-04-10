#include<cstdio>
#include<algorithm>
#include<cstring>

#define M 100
#define K 18

using namespace std;
long long n,f[M][1<<K];
int m,i,j,p,k,Q[K],tot,vis[10];
int main()
{
	 scanf("%I64d%d",&n,&m);
	 for (;n;n/=10) Q[tot++]=n%10;
	 int lim=(1<<tot);
	 f[0][0]=1;
	 for (j=0;j<lim;++j)
	     for (i=0;i<m;++i)
	       if (f[i][j])
	     {
	     	    memset(vis,0,sizeof(vis));
	     	    for (k=0;k<tot;++k)
	     	         if ((!(j&(1<<k)))&&(Q[k]||j)&&!vis[Q[k]]) 
	     	         {
	     	         	  vis[Q[k]]=1;
	     	         	  f[(i*10+Q[k])%m][j|(1<<k)]+=f[i][j];
	     	         }
	     }
	 printf("%I64d\n",f[0][lim-1]);
}