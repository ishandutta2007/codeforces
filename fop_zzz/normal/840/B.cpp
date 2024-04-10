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
	while(c<'0'||c>'9')	{if(c=='-')	f=-1;c=getchar();}
	while(c<='9'&&c>='0')	t=t*10+c-48,c=getchar();
	return t*f;
}
int poi[700001],nxt[700001],f[400001],bel[700001],v[400001],ans[400001],tot;
bool vis[400001];
int n,m,rt=1,cnt;
inline void add(int x,int y,int z){poi[++cnt]=y;nxt[cnt]=f[x];f[x]=cnt;bel[cnt]=z;}
inline void dfs(int x)
{
	vis[x]=1;
	for(int i=f[x];i;i=nxt[i])
	{
		if(vis[poi[i]])	continue;
		dfs(poi[i]);
		if(v[poi[i]]==1)	v[poi[i]]^=1,v[x]^=1,ans[++tot]=bel[i];
	}
}
int x,y;
int main()
{
	n=read();m=read();
	For(i,1,n)	v[i]=read();
	bool flag=0;
	For(i,1,n)
		if(v[i]==-1)	rt=i,flag=1,v[i]=2;
	For(i,1,m)	x=read(),y=read(),add(x,y,i),add(y,x,i);
	dfs(rt);
	if(!flag&&v[rt]==1)	return puts("-1"),0;	
	printf("%d\n",tot);
	For(i,1,tot)	printf("%d\n",ans[i]);
}