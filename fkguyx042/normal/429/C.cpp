#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,N,leaf,sum[10005],size[10005];
int c[25];
bool f[14][10005][14];
inline bool cmp(int a,int b) {return a>b; }
void dfs(int x,int y,int z)
{
	  int i;
	  for (i=0;i<(1<<N);++i)
	    if (!(y&i))
	    {
	    	  int le=c[x]-sum[i]-1;
	    	  if (le>=0&&le<=z&&le+size[i]>1)
	    	    f[x][y|i][z-le]=1;
	    }
}
int main()
{
	 scanf("%d",&n);
	 for (i=1;i<=n;++i) scanf("%d",&c[i]);
	 sort(c+1,c+n+1,cmp);
	 for (i=1;i<=n;++i) if (c[i]==1) break;
	 N=i-1;
	 leaf=n-N;
	 if (n==1&&leaf==1) printf("YES\n");
	 else 
      if (leaf==n||leaf<(n+1)/2) printf("NO\n");
	 else 
	 {
	 	    for (i=0;i<(1<<N);++i) 
	 	      for (j=0;j<N;++j)
	 	        if (i&(1<<j)) sum[i]+=c[j+1],size[i]++;
	      f[0][1][leaf]=1;
		  for (i=0;i<N;++i)
		    for (j=0;j<(1<<N);++j)
			  for (k=0;k<=leaf;++k)
			     if (f[i][j][k]) dfs(i+1,j,k); 
	       if (f[N][(1<<N)-1][0]) printf("YES\n");
	       else printf("NO\n");
	}
}