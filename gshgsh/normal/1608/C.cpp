#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 200001
int T,N,mx[MAXN],ans[MAXN],deg[MAXN];struct Node{int a,b,id;}a[MAXN];vector<int>E[MAXN];
int tot,dfn[MAXN],low[MAXN],top,sta[MAXN],cnt,id[MAXN];bool in[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
void dfs(int u)
{
	dfn[u]=low[u]=++tot;sta[++top]=u;in[u]=1;for(auto v:E[u])if(!dfn[v])dfs(v),low[u]=min(low[u],low[v]);else if(in[v])low[u]=min(low[u],low[v]);
	if(dfn[u]==low[u]){cnt++;while(top){id[sta[top]]=cnt;in[sta[top]]=0;if(sta[top--]==u)break;}}
}
int main()
{
	T=get();
	while(T--)
	{
		N=get();For(i,1,N)a[i].a=get(),a[i].id=i,E[i].clear();For(i,1,N)a[i].b=get();
		sort(a+1,a+N+1,[&](const Node&x,const Node&y){return x.a>y.a;});
		For(i,1,N-1)E[a[i].id].push_back(a[i+1].id);
		sort(a+1,a+N+1,[&](const Node&x,const Node&y){return x.b>y.b;});
		For(i,1,N-1)E[a[i].id].push_back(a[i+1].id);
		For(i,1,N)dfn[i]=low[i]=id[i]=in[i]=0;tot=top=cnt=0;
		For(i,1,N)if(!dfn[i])dfs(i);For(i,1,N)deg[i]=0;
		For(i,1,N)for(auto j:E[i])if(id[i]!=id[j])deg[id[j]]++;
		For(i,1,N)if(!deg[id[i]])cout<<1;else cout<<0;cout<<'\n';
	}
	return 0;
}