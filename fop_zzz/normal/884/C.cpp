#include<cstdio>
#include<string>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
#define For(i,j,k) for(ll i=j;i<=k;++i)
#define Dow(i,j,k) for(ll i=k;i>=j;--i)
#define ll long long
#define inf 1e17
using namespace std;
inline ll read()
{
	ll t=0,f=1;char c=getchar();
	while(c<'0'||c>'9')	{if(c=='-')	f=-1;c=getchar();}
	while(c<='9'&&c>='0')	t=t*10LL+c-48LL,c=getchar();
	return t*f;
}
int cnt,poi[300001],nxt[300001],head[300001],sz[300001],col,n;
ll ans;
bool vis[300001];
inline ll sqr(int x){return 1LL*x*x;}
inline void add(int x,int y){poi[++cnt]=y;nxt[cnt]=head[x];head[x]=cnt;}
inline void dfs(int x,int col)
{
	sz[col]++;vis[x]=1;
	for(int i=head[x];i;i=nxt[i])
		if(!vis[poi[i]])	dfs(poi[i],col);
}
inline bool cmp(int x,int y){return x>y;}
int main()
{
	n=read();
	For(i,1,n)
		add(i,read());
	For(i,1,n)
		if(!vis[i])	dfs(i,++col),ans+=sqr(sz[col]);
	sort(sz+1,sz+col+1,cmp);
	ans+=(sqr(sz[1]+sz[2])-sqr(sz[1])-sqr(sz[2]));
	cout<<ans<<endl;
}