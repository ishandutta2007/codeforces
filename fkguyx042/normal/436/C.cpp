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

#define N 1005
#define M 15
#define seed 23333
#define Mo 998244353

using namespace std;
vector<int>v[N];
int i,j,m,n,p,k,w,sum[N][N],vis[N],Dis[N],fa[N],Q[N];
char c[N][M][M];
int dis(int x,int y)
{
	  int i,j,A=0;
	  for (i=0;i<n;++i)
	    for (j=0;j<m;++j) A+=(c[x][i][j]!=c[y][i][j]);
	    return A;
}
void add(int x,int y) {v[x].push_back(y); }
void prim()
{
	 memset(vis,0,sizeof(vis));
	 memset(Dis,60,sizeof(Dis));
	 Dis[0]=0;
	 for (i=0;i<=k;++i)
	 {
	      p=-1;
		  for (j=0;j<=k;++j) if (!vis[j]&&(p==-1||Dis[j]<Dis[p])) p=j;
		  vis[p]=1;
		  if (p)
		  add(fa[p],p);
		  for (j=0;j<=k;++j)
		      if (!vis[j]&&sum[p][j]<Dis[j])
		        {
		        	  Dis[j]=sum[p][j];
		        	  if (sum[p][j]==n*m) fa[j]=0; else fa[j]=p;
		        }
	}
	int ans=0;
	for (i=1;i<=k;++i) ans+=Dis[i];
	printf("%d\n",ans);
}
void bfs()
{
	  int i,l;
	  for (i=0;i<(int)v[0].size();++i) Q[++Q[0]]=v[0][i];
	  for (l=1;l<=Q[0];++l)
	  {
	  	   p=Q[l];
	  	   printf("%d %d\n",p,fa[p]);
	  	   for (i=0;i<(int)v[p].size();++i)
	  	      Q[++Q[0]]=v[p][i];
	  }
}
int main()
{
	 scanf("%d%d%d%d",&n,&m,&k,&w);
	 for (i=1;i<=k;++i)
	   for (j=0;j<n;++j)
	  	scanf("%s",c[i][j]);
	 for (i=1;i<=k;++i)
	    for (j=i+1;j<=k;++j)
	      sum[i][j]=sum[j][i]=dis(i,j)*w;
	 for (i=1;i<=k;++i) sum[0][i]=n*m; 
	 prim();
	 memset(vis,0,sizeof(vis));
	 bfs();
}