#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<ctime>
#include<set>
#include<vector>
#include<map>
#include<queue>

#define N 1505 

#define ls (t<<1)
#define rs ((t<<1)|1)
#define mid ((l+r)>>1)

#define mk make_pair
#define pb push_back
#define fi first
#define se second

using namespace std;

int vis[N][N],i,j,m,n,p,k;

const int x[4]={0,0,-1,1};
const int y[4]={-1,1,0,0};

char c[N][N];

pair<int,int> Q[N*N],mat[N][N]; 

int mx(int x){ return (n + (x % n) ) % n; }
int my(int y){ return (m + (y % m) ) % m; }

int check(int x,int y)
{
		return c[x][y]!='#';
}

int bfs(int sx,int sy)
{
		vis[sx][sy]=1;
		int i,ax,ay,l,r; 
		Q[r=1]=mk(sx,sy); mat[sx][sy]=mk(sx,sy);
		for (l=1;l<=r&&r<=m*n;++l)
		{
				ax=Q[l].fi,ay=Q[l].se;
				for (i=0;i<4;++i)
					if (check(mx(ax+x[i]),my(ay+y[i])))
					{
							if (mat[mx(ax+x[i])][my(ay+y[i])]==mk(ax+x[i],ay+y[i])) continue;
							Q[++r]=mk(ax+x[i],ay+y[i]); 
							if (vis[mx(ax+x[i])][my(ay+y[i])]) 
							return 1;
							vis[mx(ax+x[i])][my(ay+y[i])]=1;
							mat[mx(ax+x[i])][my(ay+y[i])]=mk(ax+x[i],ay+y[i]);
					}
		}
		return r>n*m;
}

int main()
{
		scanf("%d%d",&n,&m);
		for (i=0;i<n;++i) scanf("%s",c[i]);
		for (i=0;i<n;++i)
			for (j=0;j<m;++j) mat[i][j]=mk(-100000000,-10000000);
		for (i=0;i<n;++i) 
			for (j=0;j<m;++j) if (c[i][j]=='S') printf("%s\n",bfs(i,j)?"Yes":"No");
}