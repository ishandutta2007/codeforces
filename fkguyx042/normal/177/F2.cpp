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
#define fi first
#define se second
#define mk make_pair

#define N 105
#define M 200005
#define seed 23333
#define Mo 998244353

using namespace std;
int i,j,m,n,p,k,t,sum,vis[N],a[N][N],l,r,mid,x,y;
bool dfs(int x,int y)
{
	  if (x==n+1)
	  {
	  	 ++sum;
	  	 if (sum==t) return 1;
	  	 return 0;
	  }
	  int i;
	  for (i=1;i<=n;++i)
	    if (a[x][i]&&!vis[i]&&y+a[x][i]<=mid)
	    {
	    	  vis[i]=1;
	    	  if (dfs(x+1,y+a[x][i])) { vis[i]=0; return 1; }
	    	  vis[i]=0;
	    }
	  if (dfs(x+1,y)) return 1;
	  return 0;
}
int main()
{
	  scanf("%d%d%d",&n,&m,&t);
	  l=0,r=4000000,mid=0;
	  for (i=1;i<=m;++i)
	  {
	     scanf("%d%d",&x,&y);
		 scanf("%d",&a[x][y]);
	  }
	  while ((l+r)>>1!=mid)
	  {
	  	  mid=(l+r)>>1; sum=0;
	  	  if (dfs(1,0)) r=mid; else l=mid;
	  }
	  printf("%d\n",r);
}