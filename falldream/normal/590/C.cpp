#include<iostream>
#include<cstring>
#include<cstdio>
#define pa pair<int,int>
#define MN 1000 
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
char st[MN+5][MN+5];
int n,m,d[4][MN+5][MN+5],top,D[4][4],ans=1e8;pa q[MN*MN+5];
const int dis[4][2]={{1,0},{0,1},{0,-1},{-1,0}};

void Bfs(int id)
{
	top=0;
	for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) if(st[i][j]==id+'0') q[++top]=make_pair(i,j),d[id][i][j]=0;
	for(int i=1;i<=top;++i)
	{
		int x=q[i].first,y=q[i].second;	
		for(int k=0;k<4;++k)
		{
			int nx=x+dis[k][0],ny=y+dis[k][1];	
			if(nx<1||nx>n||ny<1||ny>m||st[nx][ny]=='#') continue;
			if(st[nx][ny]=='.')
			{
				if(d[id][x][y]+1<d[id][nx][ny]) 
					d[id][nx][ny]=d[id][x][y]+1,q[++top]=make_pair(nx,ny);	
			}
			else 
				D[id][st[nx][ny]-'0']=min(D[id][st[nx][ny]-'0'],d[id][x][y]);
		}
	}
}

int main()
{
	memset(d,40,sizeof(d));	
	memset(D,40,sizeof(D));
	n=read();m=read();
	for(int i=1;i<=n;++i) scanf("%s",st[i]+1);
	Bfs(1);Bfs(2);Bfs(3);
	for(int i=1;i<=3;++i)
	{
		int res=0;
		for(int j=1;j<=3;++j) if(i!=j) res+=min(D[i][j],D[j][i]);
		ans=min(ans,res);	
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j) if(st[i][j]=='.') ans=min(ans,d[1][i][j]+d[2][i][j]+d[3][i][j]-2);
	printf("%d\n",ans>=1e8?-1:ans);
	return 0;
}