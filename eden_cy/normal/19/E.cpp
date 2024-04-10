#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#define FOR(i,s,t) for(int i=(s),_t=(t);i<=_t;++i)
#define DOR(i,s,t) for(int i=(s),_t=(t);i>=_t;--i)
#define M 10005

struct edge{
	int x,y;
};
vector<edge> E[M];
vector<int> es[M];
int Id[M];
int mark[M];
edge Edge[M];

int rt[M],vis[M];

int dep[M],Top[M],Fa[M],sz[M],son[M];

int Ans[M];

void dfs(int x) {
	vis[x]=1;
	FOR(i,0,E[x].size()-1) {
		int y=E[x][i].x;
		if(vis[y]) continue;
		es[x].push_back(y);
		Id[y]=E[x][i].y;
		mark[Id[y]]=1;
		dfs(y);
	}
}
void dfs(int x,int fr) {
	Fa[x]=fr;son[x]=0;
	sz[x]=1;dep[x]=dep[fr]+1;
	FOR(i,0,es[x].size()-1) {
		int y=es[x][i];
		dfs(y,x);
		sz[x]+=sz[y];
		if(sz[y]>sz[son[x]]) son[x]=y;
	}
}
void DFS(int x,int tp) {
	Top[x]=tp;
	if(son[x]) DFS(son[x],tp);
	FOR(i,0,es[x].size()-1) {
		int y=es[x][i];
		if(y!=son[x]) DFS(y,y);
	}
}
int LCA(int x,int y) {
	while(Top[x]!=Top[y]) {
		if(dep[Top[x]]>dep[Top[y]]) x=Fa[Top[x]];
		else y=Fa[Top[y]];
	}
	return dep[x]<dep[y]?x:y;
}
int sum[M][2];
void rdfs(int x,int fr) {
	FOR(i,0,es[x].size()-1) {
		int y=es[x][i];
		rdfs(y,x);
		sum[x][0]+=sum[y][0];
		sum[x][1]+=sum[y][1];
	}
}
int main() {
	int n,m,k=0;
	scanf("%d%d",&n,&m);
	FOR(i,1,m) {
		int x,y;
		scanf("%d%d",&x,&y);
		Edge[i]=(edge){x,y};
		E[x].push_back((edge){y,i});
		E[y].push_back((edge){x,i});
	}
	FOR(i,1,n) if(!vis[i]) dfs(rt[++k]=i);
	FOR(i,1,k) {
		dfs(rt[i],0);
		DFS(rt[i],rt[i]);
	}
	int cnt=0,s;
	FOR(i,1,m) {
		if(mark[i]) continue;
		int x=Edge[i].x,y=Edge[i].y;
		int lca=LCA(x,y);
		int len=dep[x]+dep[y]-dep[lca]*2+1;
		if(len&1) {
			cnt++;
			s=i;
			sum[lca][1]-=2;
			sum[x][1]++;
			sum[y][1]++;
		} else {
			sum[lca][0]-=2;
			sum[x][0]++;
			sum[y][0]++;
		}
	}
	if(cnt==0) {
		printf("%d\n",m);
		FOR(i,1,m) printf("%d ",i);
		putchar('\n');
		return 0;
	}
	FOR(i,1,k) rdfs(rt[i],0);
	int res=0;
	FOR(i,1,n) if(Id[i]) {
		if(sum[i][1]==cnt&&!sum[i][0]) {
			res++;
			Ans[Id[i]]=1;
		}
	}
	if(cnt==1) {
		res++;
		Ans[s]=1;
	}
	printf("%d\n",res);
	FOR(i,1,m) if(Ans[i]) printf("%d ",i);
	putchar('\n');
	return 0;
}