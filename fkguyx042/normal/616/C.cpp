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
#define M 200005
#define seed 23333
#define Mo 998244353

using namespace std;
const int x[4]={-1,1,0,0};
const int y[4]={0,0,-1,1};
int i,j,m,n,p,k,vis[N][N],v[N*N],ans=0,tot,id[N][N],sum[N][N];
char c[N][N];
struct Node{int x,y;}Q[N*N];
bool check(int x,int y)
{
	 if (x<0||x>=n||y<0||y>=m||c[x][y]=='*') return 0;
	 return 1;
}
void bfs(int cx,int cy)
{
	  vis[cx][cy]=1;
	  int l=1,r=1,i; Q[1]=(Node){cx,cy};
	  for (l=1;l<=r;++l)
	  {
	  	   int ax=Q[l].x,ay=Q[l].y;
	  	   for (i=0;i<4;++i) 
	  	      if (check(ax+x[i],ay+y[i])&&!vis[ax+x[i]][ay+y[i]])
	  	        vis[ax+x[i]][ay+y[i]]=1,Q[++r]=(Node){ax+x[i],ay+y[i]};
	  }
	  ++tot;
	  for (i=1;i<=r;++i) id[Q[i].x][Q[i].y]=tot,sum[Q[i].x][Q[i].y]=r;
}
int main()
{
	  scanf("%d%d",&n,&m);
	  for (i=0;i<n;++i) scanf("%s",c[i]);
	  for (i=0;i<n;++i)  for (j=0;j<m;++j) if (c[i][j]=='.'&&!vis[i][j]) bfs(i,j);
	  for (i=0;i<n;++i)
	  {
	      for (j=0;j<m;++j) if (c[i][j]=='.') putchar('.');
		  else 
		  {
		  	   ++tot; ans=0;
		       for (k=0;k<4;++k) if (check(i+x[k],j+y[k]))
		       {
		       	      ans+=(1-(v[id[i+x[k]][j+y[k]]]==tot))*sum[i+x[k]][j+y[k]];
		       	      v[id[i+x[k]][j+y[k]]]=tot;
		       }
		       printf("%d",(ans+1)%10);
	      }
	      puts("");
	  }
}