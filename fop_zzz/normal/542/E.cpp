#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
#define For(i,j,k)	for(int i=j;i<=k;++i)
#define Dow(i,j,k)	for(int i=k;i>=j;--i)
#define ll long long
#define pb push_back


using namespace std;

inline ll read()
{
	ll t=0,dp=1;char c=getchar();
	while(!isdigit(c))	{if(c=='-')	dp=-1;c=getchar();}
	while(isdigit(c))	t=t*10+c-48,c=getchar();
	return t*dp;
}
inline void write(ll x){if(x<0)	{putchar('-');x=-x;}	if(x>=10)	write(x/10);putchar(x%10+48);}
inline void writeln(ll x){write(x);puts("");}
inline void write_p(ll x){write(x);putchar(' ');}
/*------------------------------------------------------------------------------------------------------*/

const int N=200005;
int n,m,poi[N],nxt[N],head[N],cnt,vis[N],top,q[N],dis[N],mx,col[N];
inline void add(int x,int y){poi[++cnt]=y;nxt[cnt]=head[x];head[x]=cnt;poi[++cnt]=x;nxt[cnt]=head[y];head[y]=cnt;}
inline void Dfs(int x,int c)
{
	if(col[x])
	{
		if(col[x]!=c){puts("-1");exit(0);}
		return;
	}
	col[x]=c;
	for(int i=head[x];i;i=nxt[i])
		Dfs(poi[i],3-c);
}

inline int Bfs(int tx)
{
	queue<int> Q;
	For(i,1,n)	vis[i]=0;
	Q.push(tx);vis[tx]=1;dis[tx]=0;
	int mx=0;
	while(!Q.empty())
	{
		int x=Q.front();Q.pop();
		for(int i=head[x];i;i=nxt[i])
			if(!vis[poi[i]])	Q.push(poi[i]),vis[poi[i]]=1,q[++top]=poi[i],dis[poi[i]]=dis[x]+1;
		
		mx=dis[x];if(Q.empty())	{return mx;}
	}
	
}
bool tvis[N];
inline void tBfs(int tx)
{
	queue<int> Q;
	For(i,1,n)	tvis[i]=0;
	Q.push(tx);tvis[tx]=1;
	while(!Q.empty())
	{
		int x=Q.front();Q.pop();
		for(int i=head[x];i;i=nxt[i])
			if(!tvis[poi[i]])	Q.push(poi[i]),tvis[poi[i]]=1;
	}
}
int alr[N],ans;
inline void Get(int x)
{
	tBfs(x);
	int tmx=0;
	For(i,1,n)	if(tvis[i])	tmx=max(tmx,Bfs(i)),tvis[i]=0,alr[i]=1;
	ans+=tmx;
}
int main()
{
	n=read();m=read();
	For(i,1,m)	add(read(),read());
	For(i,1,n)	if(!col[i])	Dfs(i,1);
	For(i,1,n)
	if(!alr[i])
	{
		Get(i);
	}
	writeln(ans);
}