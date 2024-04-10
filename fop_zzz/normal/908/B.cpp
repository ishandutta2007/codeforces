#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
#define For(i,j,k)	for(register ll i=j;i<=k;++i)
#define Dow(i,j,k)	for(register ll i=k;i>=j;--i)
#define ll long long
#define mk make_pair
#define pb push_back
using namespace std;
inline ll read()
{
	ll t=0,f=1;char c=getchar();
	while(c<'0'||c>'9')	{if(c=='-')	f=-1;c=getchar();}
	while(c>='0'&&c<='9')	t=(t*10+c-48),c=getchar();
	return t*f;
}
bool vis[5];
int ans,n,m,len,sx,sy,ex,ey;
int dx[]={0,1,0,-1,0};
int dy[]={0,0,1,0,-1},to[5];
char ds[20001];
char s[201];
bool no[101][101];
inline void bfs()
{
	int nx=sx,ny=sy;
	For(i,1,len)
	{
		nx+=dx[to[ds[i]-48]];ny+=dy[to[ds[i]-48]];
//		cout<<nx<<' '<<ny<<endl;
		if(no[nx][ny]||nx<1||nx>n||ny<1||ny>m)	return;
		if(nx==ex&&ny==ey)	{ans++;return;}
	}
}
inline void dfs(int x)
{
	if(x==4)	{bfs();return;}
	For(i,1,4)	if(!vis[i])	to[x]=i,vis[i]=1,dfs(x+1),vis[i]=0;
}
int main()
{
	n=read();m=read();
	For(i,1,n)
	{
		scanf("\n%s",s+1);
		For(j,1,m)
		{
			if(s[j]=='S')	sx=i,sy=j;
			if(s[j]=='E')	ex=i,ey=j;
			if(s[j]=='#')	no[i][j]=1;
		}
	}
	scanf("\n%s",ds+1);
	len=strlen(ds+1);
	dfs(0);
	cout<<ans<<endl;
}