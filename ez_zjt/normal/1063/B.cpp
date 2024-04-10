#include <bits/stdc++.h>
#define MAXN 2010
#define MAXM MAXN*MAXN
using namespace std;

struct edge{
	int to,next,w;
}e[MAXM*4];

int n,m;
int g[MAXM],nume;
int sx,sy,l1,l2;
char str[MAXN][MAXN];
int p[MAXN][MAXN],np;
int d[MAXM];
deque<int> Q;
bool visit[MAXM];

void addEdge(int u,int v,int w){
	e[nume]=(edge){v,g[u],w};
	g[u]=nume++;
}

void gao(){
	memset(d,0x11,sizeof d);
	d[p[sx][sy]]=0;
	int mind=0;
	Q.push_back(p[sx][sy]);
	while(!Q.empty()){
		int x=Q.front();
		Q.pop_front();
		if(visit[x]) continue;
		visit[x]=1;
		for(int i=g[x];~i;i=e[i].next)
			if(d[e[i].to]>d[x]+e[i].w){
				d[e[i].to]=d[x]+e[i].w;
				if(e[i].w) Q.push_back(e[i].to);
				else Q.push_front(e[i].to);
			}
	}
}

int main(){
#ifdef DEBUG
	freopen("B.in","r",stdin);
#endif
	memset(g,-1,sizeof g);
	scanf("%d%d%d%d%d%d",&n,&m,&sx,&sy,&l1,&l2);
	for(int i=1;i<=n;i++) scanf("%s",str[i]+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			p[i][j]=++np;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(str[i][j]=='.'){
				if(str[i-1][j]=='.') addEdge(p[i][j],p[i-1][j],0);
				if(str[i+1][j]=='.') addEdge(p[i][j],p[i+1][j],0);
				if(str[i][j-1]=='.') addEdge(p[i][j],p[i][j-1],1);
				if(str[i][j+1]=='.') addEdge(p[i][j],p[i][j+1],0);
			}
	gao();
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(str[i][j]=='.' && d[p[i][j]]<=n*m){
				int d1=d[p[i][j]];
				int d2=j-sy+d1;
				if(d1<=l1 && d2<=l2)
					ans++;
			}
	printf("%d\n",ans);
}