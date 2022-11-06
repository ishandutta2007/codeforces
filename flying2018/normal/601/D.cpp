#include<iostream>
#include<cstdio>
#include<cstring>
#define N 300010
using namespace std;
int nxt[N<<1],to[N<<1],head[N],cnt;
void add(int u,int v)
{
	nxt[++cnt]=head[u];
	to[cnt]=v;
	head[u]=cnt;
}
int c[N];
char s[N];
#define C 26
int ch[N*10][C],tot;
int val[N*10],sm[N*10];
void insert(int &u,int c)
{
	if(!u) u=++tot;
	if(ch[u][c]) return;
	ch[u][c]=++tot;
	sm[ch[u][c]]++,sm[u]++;
	val[ch[u][c]]++;
}
int merge(int u,int v)
{
	if(!u || !v) return u+v;
	val[u]|=val[v];
	sm[u]=val[u];
	for(int i=0;i<C;i++)
	ch[u][i]=merge(ch[u][i],ch[v][i]),sm[u]+=sm[ch[u][i]];
	return u;
}
int root[N];
int ans,pcnt;
void dfs(int u,int p)
{
	insert(root[u],s[u]-'a');
	int &rt=ch[root[u]][s[u]-'a'];
	for(int i=head[u];i;i=nxt[i])
	{
		int v=to[i];
		if(v==p) continue;
		dfs(v,u);
		rt=merge(rt,root[v]);
	}
	sm[root[u]]=sm[rt];
	if(sm[root[u]]+c[u]>ans) ans=sm[root[u]]+c[u],pcnt=1;
	else if(sm[root[u]]+c[u]==ans) ++pcnt;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	scanf("%s",s+1);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v),add(v,u);
	}
	dfs(1,0);
	printf("%d\n%d",ans,pcnt);
	return 0;
}