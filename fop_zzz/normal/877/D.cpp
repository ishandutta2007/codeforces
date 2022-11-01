#include<iostream>
#include<cstdio>
#include<queue>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<cstring>
#define For(i,j,k)	for(ll i=j;i<=k;++i)
#define Dow(i,j,k)	for(ll i=k;i>=j;--i)
#define maxm 10011
#define maxn 511
#define pb push_back
#define ll  long long
using namespace std;
inline ll read()
{
	ll t=0,f=1;char c=getchar();
	while(c<'0'||c>'9')	{c=getchar();}
	while(c<='9'&&c>='0')	t=t*10+c-48,c=getchar();
	return t*f;
}
int qx[10000001],qy[10000001],qv[10000001];
bool vis[2001][1001][5],no[2001][2001];
int n,m,k,ex,ey,sx,sy;
int dx[]={0,1,0,-1,0};
int dy[]={0,0,1,0,-1};
inline void bfs()
{
	qx[1]=sx;qy[1]=sy;qv[1]=0;
	int l=1,r=1;
	For(i,1,4)	vis[sx][sy][i]=1;
	while(l<=r)
	{
		int tx=qx[l],ty=qy[l];
		if(tx==ex&&ty==ey)
		{
			printf("%d",qv[l]);
			exit(0);
		}
		For(dir,1,4)
		{
			For(dis,1,k)
			{
				int nx=tx+dis*dx[dir],ny=ty+dis*dy[dir];
				if(nx<1||ny<1||nx>n||ny>m)	break;
				if(no[nx][ny])	break;
				if(vis[nx][ny][dir])	break;
				qv[++r]=qv[l]+1;qx[r]=nx;qy[r]=ny;
				vis[nx][ny][dir]=1;
			}
		}
		++l;
	}
}
char s[2001];
int main()
{
	n=read();m=read();k=read();
	For(i,1,n)
	{
		scanf("%s",s+1);
		For(j,1,m)	if(s[j]=='#')	no[i][j]=1;
	}
	sx=read();sy=read();ex=read();ey=read();
	bfs();
	puts("-1");
}