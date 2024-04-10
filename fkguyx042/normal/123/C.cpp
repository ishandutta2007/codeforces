#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<bitset>

#define ls (t<<1)
#define rs ((t<<1)+1)
#define mid ((l+r)>>1)
#define fi first
#define se second
#define mk make_pair

#define N 305
#define M 200005
#define seed 23333
#define Mo 998244353

using namespace std;
int i,j,m,n,p[N][N],id[N][N],tot,vis[N],ans[N][N];
long long k,f[N][N];
struct Node{int x,y;}A[N*N];
void jia(long long &x,long long y)
{
	  x+=y; if (x>=k) x=k;
}
long long work()
{
	  memset(f,0,sizeof(f));
	  f[0][0]=1;
	  int i,j;
	  for (i=0;i<tot;++i)
	    for (j=0;j<=i;++j)
	      if (vis[i+1]==1)
	      	     jia(f[i+1][j+1],f[i][j]);
	      else if (vis[i+1]==2)
	      {
	      	  if (j) jia(f[i+1][j-1],f[i][j]);
	      }
	      else 
	      {
	      	  jia(f[i+1][j+1],f[i][j]);
	      	  if (j) jia(f[i+1][j-1],f[i][j]);
	      }
	 return f[tot][0];
}
int main()
{
	  scanf("%d%d%I64d",&n,&m,&k);
	  for (i=1;i<=n;++i)
	    for (j=1;j<=m;++j)
	    {
	       scanf("%d",&p[i][j]);
	       A[p[i][j]].x=i;A[p[i][j]].y=j;
	    }
	  for (i=1;i<=n;++i) id[i][1]=++tot;
	  for (j=2;j<=m;++j) id[n][j]=++tot;
	  for (i=1;i<n;++i)
	    for (j=2;j<=m;++j)
	    {
	    	     int x=i,y=j;
	    	     while (x!=n&&y!=1) ++x,--y;
	    	     id[i][j]=id[x][y];
	    }
	  for (i=1;i<=n*m;++i)
	      if (vis[id[A[i].x][A[i].y]]) ans[A[i].x][A[i].y]=vis[id[A[i].x][A[i].y]];
	      else 
	      {
	      	    vis[id[A[i].x][A[i].y]]=1; ans[A[i].x][A[i].y]=1;
	      	    long long r=work();
	      	    if (r<k) k-=r,vis[id[A[i].x][A[i].y]]=2,ans[A[i].x][A[i].y]=2;
	      }
	 for (i=1;i<=n;++i)
	 {
	 	  for (j=1;j<=m;++j) if (ans[i][j]==1) printf("("); else printf(")");
	 	  puts("");
	 }
}