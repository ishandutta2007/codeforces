#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 1000010
using namespace std;

struct edge{
	int to,next;
	edge(int _to=0,int _next=0):to(_to),next(_next){}
}e[MAXN];

int n,m;
int g[MAXN],nume=0;
int w[MAXN][2],numw=0;
int dep[MAXN],pre[MAXN][21];

void addEdge(int u,int v){
	e[nume]=edge(v,g[u]);
	g[u]=nume++;
}

void dfs(int x,int p){
	w[x][0]=++numw;
	pre[x][0]=p;
	for(int i=1;i<=20;i++)
		pre[x][i]=pre[pre[x][i-1]][i-1];
	for(int i=g[x];~i;i=e[i].next)
		if(e[i].to^p){
			dep[e[i].to]=dep[x]+1;
			dfs(e[i].to,x);
		}
	w[x][1]=numw;
}

int getLCA(int x,int y){
	if(dep[x]^dep[y]){
		if(dep[x]<dep[y]) x^=y^=x^=y;
		for(int i=20;i>=0;i--)
			if(dep[pre[x][i]]>dep[y])
				x=pre[x][i];
		x=pre[x][0];
	}
	if(x==y) return x;
	for(int i=20;i>=0;i--)
		if(pre[x][i]!=pre[y][i]){
			x=pre[x][i];
			y=pre[y][i];
		}
	return pre[x][0];
}

int query(int x1,int x2,int x3,int l1,int l2,int l3){
	if(l1==x1 && l2==x1){
		return dep[l3]-dep[x1]+1;
	}else if(l1!=x1 && l2!=x1){
		if(l1==l2){
			return dep[x1]+dep[l3]-2*dep[l1]+1;
		}else{
			return dep[x1]-max(dep[l1],dep[l2])+1;
		}
	}else return 1;
}

int main(){
	memset(g,-1,sizeof g);
	scanf("%d%d",&n,&m);
	for(int i=2;i<=n;i++){
		int t;
		scanf("%d",&t);
		addEdge(t,i);
		addEdge(i,t);
	}
	dep[1]=1;
	dfs(1,0);
	while(m--){
		int t1,t2,t3;
		scanf("%d%d%d",&t1,&t2,&t3);
		int l1=getLCA(t1,t2);
		int l2=getLCA(t1,t3);
		int l3=getLCA(t2,t3);
		printf("%d\n",max(max(query(t1,t2,t3,l1,l2,l3),query(t2,t1,t3,l1,l3,l2)),query(t3,t1,t2,l2,l3,l1)));
	}
	return 0;
}