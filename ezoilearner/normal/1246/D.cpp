#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int n;
#define Maxn 100010 
int fa[Maxn];
int Ans[Maxn],cnt=0;
int head[Maxn],v[Maxn],nxt[Maxn],tot=0;
int seq[Maxn],L=0;

inline void add_edge(int s,int e){tot++;v[tot]=e;nxt[tot]=head[s];head[s]=tot;}

int *to[Maxn];
int len[Maxn],maxv[Maxn],haha[Maxn];
bool vis[Maxn];

void dfs(int u){
	maxv[u]=0;haha[u]=-1;
	for(int i=head[u];i;i=nxt[i]){
		dfs(v[i]);
		if(haha[u]==-1||maxv[v[i]]+1>=maxv[u])haha[u]=v[i];
		maxv[u]=max(maxv[u],maxv[v[i]]+1);
	}
}

void solve(int u){
	for(int i=head[u];i;i=nxt[i])solve(v[i]);
	for(int i=head[u];i;i=nxt[i])
	    if(!vis[v[i]])len[u]++;
	to[u]=new int[len[u]];
	len[u]=0;
	for(int i=head[u];i;i=nxt[i])
	    if(!vis[v[i]])to[u][len[u]++]=v[i];
}

inline void rd(int &x){
	x=0;char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
}

int main(){
	rd(n);
	for(register int i=1;i<n;++i){
		rd(fa[i]);
		add_edge(fa[i],i);
	}
	dfs(0);
	int node=0,tot=1;
	while(haha[node]!=-1){
		tot++;
		vis[node]=true;
		node=haha[node];
	}
	vis[node]=true;
	solve(0);
	while(tot<n){
		while(!len[fa[node]])node=fa[node];
		len[fa[node]]--;
		int tmp=to[fa[node]][len[fa[node]]];
		fa[node]=tmp;
		tot++;
		Ans[++cnt]=node;
	}
	memset(vis,false,sizeof(vis));
	for(int i=1;i<n;++i)vis[fa[i]]=true;
	for(int i=0;i<n;++i)
	    if(!vis[i])node=i;
	while(node){
		seq[++L]=node;
		node=fa[node];
	}
	seq[++L]=0;
	for(int i=L;i>=1;--i)printf("%d ",seq[i]);
	puts("");
	printf("%d\n",cnt);
	for(register int i=cnt;i>=1;--i)printf("%d ",Ans[i]);
	return 0;
}