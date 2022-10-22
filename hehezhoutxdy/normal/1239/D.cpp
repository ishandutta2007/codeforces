#include<bits/stdc++.h>
using namespace std; 
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int head[2000003],nxt[2000003],to[2000003],cnt;
int vis[2000003],dfn[2000003],low[2000003],cur;
int id[2000003],icnt;
stack<int> s;
void dfs(int x)
{
    vis[x]=1,dfn[x]=low[x]=++cur,s.push(x);
	for(int i=head[x]; i; i=nxt[i])
	{
		int y=to[i];
		if(vis[y]==0) dfs(y),low[x]=min(low[x],low[y]);
		else if(vis[y]==1) low[x]=min(low[x],dfn[y]);
	}
	if(low[x]==dfn[x]) 
	{
		++icnt;
		while(vis[x]==1) vis[s.top()]=2,id[s.top()]=icnt,s.pop();
	}
	return ;
}
int u[1000003],v[1000003];
void fuckcmll()
{
    int n=read(),m=read();
    cnt=cur=icnt=0;
    for(int i=1; i<=n; ++i) head[i]=vis[i]=0;
    for(int i=1; i<=m; i++) 
		u[i]=read(),v[i]=read(),
		to[++cnt]=v[i],nxt[cnt]=head[u[i]],head[u[i]]=cnt;
	dfs(1);
	bool hasans=0;
	for(int i=2; i<=n; ++i) if(!vis[i]) hasans=1;
	if(hasans)
	{
		puts("Yes");
		int Q=0;
		for(int i=1; i<=n; ++i) Q+=(vis[i]>0); 
		printf("%d %d\n",Q,n-Q);
		for(int i=1; i<=n; ++i) if(vis[i]) printf("%d ",i);
		puts("");
		for(int i=1; i<=n; ++i) if(!vis[i]) printf("%d ",i);
		puts("");
		return ;
	}
    cnt=cur=icnt=0;
    for(int i=1; i<=n; ++i) head[i]=vis[i]=0;
    for(int i=1; i<=m; i++) 
		swap(u[i],v[i]),
		to[++cnt]=v[i],nxt[cnt]=head[u[i]],head[u[i]]=cnt;
	dfs(1);
	for(int i=2; i<=n; ++i) if(!vis[i]) hasans=1;
	if(hasans)
	{
		puts("Yes");
		int Q=0;
		for(int i=1; i<=n; ++i) Q+=(vis[i]>0); 
		printf("%d %d\n",n-Q,Q);
		for(int i=1; i<=n; ++i) if(!vis[i]) printf("%d ",i);
		puts("");
		for(int i=1; i<=n; ++i) if(vis[i]) printf("%d ",i);
		puts("");
		return ;
	}
	puts("No");
	return ;
}
signed main(){for(int T=read();T--;)fuckcmll();}