#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
#include<queue>
#include<cmath>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 100001
int N,M,B,K,l[MAXN],r[MAXN],fa[MAXN],dep[MAXN],siz[MAXN],son[MAXN],top[MAXN],opt[MAXN],x[MAXN],mn[MAXN];vector<int>E[MAXN];bool vis[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
void dfs(int u)
{
	vector<int>s;for(auto v:E[u])if(v!=fa[u])s.push_back(v);E[u]=s;siz[u]=1;
	for(auto v:E[u])fa[v]=u,dep[v]=dep[u]+1,dfs(v),siz[u]+=siz[v],siz[v]>siz[son[u]]&&(son[u]=v);
}
void dfs1(int u,int t){top[u]=t;if(!son[u])return;dfs1(son[u],t);for(auto v:E[u])if(v!=son[u])dfs1(v,v);}
int lca(int x,int y){while(top[x]!=top[y]){if(dep[top[x]]<dep[top[y]])swap(x,y);x=fa[top[x]];}return dep[x]<dep[y]?x:y;}
int dis(int x,int y){return dep[x]+dep[y]-dep[lca(x,y)]*2;}
int main()
{
	N=get(),M=get(),B=sqrt(N/log2(N));while(r[K]<M)K++,l[K]=r[K-1]+1,r[K]=min(K*B,M);
	For(i,1,N-1){int u=get(),v=get();E[u].push_back(v),E[v].push_back(u);}For(i,1,M)opt[i]=get(),x[i]=get();dfs(1);dfs1(1,1);For(i,1,N)mn[i]=dep[i];
	For(i,1,K)
	{
		vector<int>ssh;For(j,l[i],r[i])if(opt[j]==1)ssh.push_back(x[j]);else{int ans=mn[x[j]];for(auto karry5307:ssh)ans=min(ans,dis(karry5307,x[j]));cout<<ans<<'\n';}
		queue<int>q;for(auto karry5307:ssh)q.push(karry5307),mn[karry5307]=0;For(j,1,N)vis[j]=0;
		while(!q.empty())
		{
			int u=q.front();q.pop();if(fa[u]&&!vis[fa[u]])mn[fa[u]]=min(mn[fa[u]],mn[u]+1),vis[fa[u]]=1,q.push(fa[u]);
			for(auto v:E[u])if(!vis[v])mn[v]=min(mn[v],mn[u]+1),vis[v]=1,q.push(v);
		}
	}
	return 0;
}