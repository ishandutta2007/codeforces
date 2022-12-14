#include <cstdio>
#include <cstring>
#include <vector>
#define MAXN 300010
using namespace std;

struct edge{
	int to,next,w;
	edge(int _to=0,int _next=0,int _w=0):to(_to),next(_next),w(_w){}
}e[MAXN<<1];

int n,m;
int g[MAXN],nume=0;
int d[MAXN];
int f[MAXN][2];
vector<int> ans;

namespace LCT{
	int f[MAXN];

	void init(){ for(int i=1;i<=n;i++) f[i]=i; }

	int getf(int x){
		if(f[x]==x) return x;
		return f[x]=getf(f[x]);
	}

	int merge(int x,int y){
		f[f[x]]=f[y];
	}
}

void addEdge(int u,int v,int w){
	e[nume]=edge(v,g[u],w);
	g[u]=nume++;
}

void dfs(int x,int p){
	for(int i=g[x];~i;i=e[i].next)
		if(e[i].to^p)
			dfs(e[i].to,x);
	int numch=0;
	static int ch[MAXN][2];
	int c0=0,c1=0;
	for(int i=g[x];~i;i=e[i].next)
		if(e[i].to^p){
			++numch;
			ch[numch][0]=f[e[i].to][0];
			ch[numch][1]=f[e[i].to][1];
			if(!ch[numch][0] && !ch[numch][1]){
				f[x][0]=f[x][1]=0;
				return;
			}
			if(ch[numch][0] && ch[numch][1]){
				f[x][0]=f[x][1]=1;
				return;
			}
			if(ch[numch][0]) c0++;
			if(ch[numch][1]) c1++;
		}
	if(d[x]==-1){
		f[x][0]=f[x][1]=1;
		return;
	}
	if(d[x]==0){
		if(c1&1){
			f[x][1]=1;
			f[x][0]=0;
		}else{
			f[x][1]=0;
			f[x][0]=1;
		}
	}else{
		if(c1&1){
			f[x][1]=0;
			f[x][0]=1;
		}else{
			f[x][1]=1;
			f[x][0]=0;
		}
	}
}

void dfs2(int x,int p,int fx){
	if(f[x][0]!=f[x][1]){
		for(int i=g[x];~i;i=e[i].next)
			if(e[i].to^p)
				if(f[e[i].to][0]){
					dfs2(e[i].to,x,0);
				}else{
					ans.push_back(e[i].w);
					dfs2(e[i].to,x,1);
				}
	}else{
		int temp=-1,c1=0;
		for(int i=g[x];~i;i=e[i].next)
			if(e[i].to^p){
				if(f[e[i].to][0]==f[e[i].to][1] && temp==-1){
					temp=i;
				}else{
					if(f[e[i].to][0]) dfs2(e[i].to,x,0);
					else{
						dfs2(e[i].to,x,1);
						ans.push_back(e[i].w);
						c1++;
					}
				}
			}
		if(temp==-1) return;
		if((c1&1)==fx^d[x])
			dfs2(e[temp].to,x,0);
		else{
			dfs2(e[temp].to,x,1);
			ans.push_back(e[temp].w);
		}
	}
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("B.in","r",stdin);
#endif
	memset(g,-1,sizeof g);
	scanf("%d%d",&n,&m);
	LCT::init();
	for(int i=1;i<=n;i++)
		scanf("%d",d+i);
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		if(LCT::getf(u)^LCT::getf(v)){
			addEdge(u,v,i);
			addEdge(v,u,i);
			LCT::merge(u,v);
		}
	}
	dfs(1,0);
	if(!f[1][0]){
		puts("-1");
		return 0;
	}
	dfs2(1,0,0);
	int numans=ans.size();
	printf("%d\n",numans);
	for(int i=0;i<numans;i++)
		printf("%d\n",ans[i]);
	return 0;
}