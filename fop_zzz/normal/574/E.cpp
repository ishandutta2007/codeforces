#include<iostream> 
#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
#include<algorithm>
#define eps 1e-10
#define inf 1e9
#define For(i,j,k)	for(int i=j;i<=k;++i)
#define Dow(i,j,k)	for(int i=k;i>=j;--i)
#define ll long long
#define y1 orz
using namespace std;
inline ll read()
{
	ll t=0,f=1;char c=getchar();
	while(c<'0'||c>'9')	{if(c=='-')	f=-1;c=getchar();}
	while(c>='0'&&c<='9')	t=t*10+c-48,c=getchar();
	return t*f;
}
int poi[300001],cnt[300001],nxt[300001],f[300001],n,x,y,deg[300001],no,cnt1,top,q[300001];
bool vis[300001];
inline void add(int x,int y){poi[++cnt1]=y;nxt[cnt1]=f[x];f[x]=cnt1;}
inline void dfs(int x)
{
	vis[x]=1;
	for(int i=f[x];i;i=nxt[i])
		if(!vis[poi[i]])
			if(deg[poi[i]]<=2)	dfs(poi[i]);		
}
int main()
{
	n=read();
	For(i,1,n-1)	x=read(),y=read(),add(x,y),add(y,x),deg[x]++,deg[y]++;
	For(i,1,n)	if(deg[i]==1)	dfs(i);
	For(i,1,n)	if(!vis[i])	q[++top]=i;
	For(i,1,n)
	{
		if(vis[i])
			for(int t=f[i];t;t=nxt[t])	cnt[poi[t]]++;
	}
	For(i,1,top)
	{
		int tmp=0,x=q[i];
		for(int j=f[x];j;j=nxt[j])
			if(!vis[poi[j]]&&deg[poi[j]]-min(cnt[poi[j]],2)>1)	tmp++;
		if(tmp>2)	{puts("No");return 0;}
	}
	puts("Yes");
}