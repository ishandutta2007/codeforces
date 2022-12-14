#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#define MAXN 30010
#define MAXM 210
using namespace std;

struct edge{
	int to,next;
	edge(int _to=0,int _next=0):to(_to),next(_next){}
}e[MAXN<<1];

int n,m;
int g[MAXN],nume;
int f[MAXN];
int dis[MAXM][MAXN],s[MAXN],l[MAXN];
vector< pair<int,int> > S[MAXN];

void addEdge(int u,int v){
	e[nume]=edge(v,g[u]);
	g[u]=nume++;
}

namespace Tree{
	int size[MAXN],son[MAXN],top[MAXN],pre[MAXN],dep[MAXN],w[MAXN],pt[MAXN],numw;

	void dfs(int x,int p){
		size[x]=1; son[x]=0;
		pre[x]=p;
		for(int i=g[x];~i;i=e[i].next)
			if(e[i].to^p){
				dep[e[i].to]=dep[x]+1;
				dfs(e[i].to,x);
				size[x]+=size[e[i].to];
				if(size[e[i].to]>size[son[x]]) son[x]=e[i].to;
			}
	}

	void dfs2(int x,int p){
		pt[w[x]=++numw]=x;
		if(son[x]){
			top[son[x]]=top[x];
			dfs2(son[x],x);
		}
		for(int i=g[x];~i;i=e[i].next)
			if(e[i].to!=p && e[i].to!=son[x]){
				top[e[i].to]=e[i].to;
				dfs2(e[i].to,x);
			}
	}

	void build(){
		dfs(s[1],0);
		top[s[1]]=s[1];
		dfs2(s[1],0);
	}

	int getLCA(int x,int y){
		while(top[x]^top[y]){
			if(dep[top[x]]<dep[top[y]]) x^=y^=x^=y;
			x=pre[top[x]];
		}
		return dep[x]<dep[y]?x:y;
	}

	int getDis(int x,int y){
		return dep[x]+dep[y]-2*dep[getLCA(x,y)];
	}

	int getPos(int x,int p){
		int s1=s[x],s2=s[x+1];
		int len=l[x];
		if((dis[x][p]+dis[x+1][p]-len)&1) return -1;
		int d1=dis[x][p]-(dis[x][p]+dis[x+1][p]-len)/2;
		if(d1<0 || d1>len) return -1;
		return d1;
	}

	int goUp(int x,int d){
		while(dep[x]-dep[top[x]]+1<=d){
			d-=dep[x]-dep[top[x]]+1;
			x=pre[top[x]];
		}
		return pt[w[x]-d];
	}

	int go(int x,int y,int d){
		int lca=getLCA(x,y);
		if(dep[x]-dep[lca]>=d) return goUp(x,d);
		d=dep[x]+dep[y]-2*dep[lca]-d;
		return goUp(y,d);
	}

	bool insert(int x){
		if(m==1){
			S[s[1]].push_back(make_pair(dis[1][x],x));
			return 1;
		}
		int mindep=n;
		for(int i=1;i<m;i++){
			int len=l[i],pos=getPos(i,x);
			if(pos==-1) return 0;
			if(dis[i][x]-pos<mindep)
				mindep=dis[i][x]-pos;
		}
		for(int i=1;i<m;i++){
			int len=l[i],pos=getPos(i,x);
			if(dis[i][x]-pos==mindep){
				int temp=go(s[i],s[i+1],pos);
				S[temp].push_back(make_pair(dis[i][x]-pos,x));
				return 1;
			}
		}
		return 0;
	}

	bool gao_insert(int x){
		int last=x,lastdep=0;
		sort(S[x].begin(),S[x].end());
		for(int i=0;i<S[x].size();i++){
			if(S[x][i].first==lastdep) return 0;
			if(S[x][i].first-lastdep>1){
				if(i==0) return 0;
				last=S[x][i-1].second;
				lastdep=S[x][i-1].first;
				if(S[x][i].first-lastdep>1) return 0;
			}
			addEdge(last,S[x][i].second);
			addEdge(S[x][i].second,last);
		}
		return 1;
	}
}

namespace Check{
	int d[MAXN];

	bool check(int id){
		int S=s[id];
		static queue<int> Q;
		for(int i=1;i<=n;i++) d[i]=-1;
		Q.push(S);
		d[S]=0;
		while(!Q.empty()){
			int x=Q.front();
			Q.pop();
			for(int i=g[x];~i;i=e[i].next)
				if(d[e[i].to]==-1){
					d[e[i].to]=d[x]+1;
					Q.push(e[i].to);
				}
		}
		for(int i=1;i<=n;i++)
			if(d[i]!=dis[id][i]) return 0;
		return 1;
	}
}

int getf(int x){
	if(f[x]==x) return x;
	return f[x]=getf(f[x]);
}

bool gao(int x){
	static int pt[MAXN];
	int s1=0,s2=0;
	for(int i=1;i<=n;i++){
		if(dis[x][i]==0) s1=i;
		if(dis[x+1][i]==0) s2=i;
	}
	if(!s1 || !s2) return 0;
	int len=dis[x][s2];
	l[x]=len;
	for(int i=0;i<=len;i++) pt[i]=0;
	for(int i=1;i<=n;i++)
		if(dis[x][i]+dis[x+1][i]==len){
			if(pt[dis[x][i]]) return 0;
			pt[dis[x][i]]=i;
		}
	for(int i=1;i<=len;i++){
		if(!pt[i-1] || !pt[i]) return 0;
		if(getf(pt[i-1])!=getf(pt[i])){
			f[f[pt[i-1]]]=f[pt[i]];
			addEdge(pt[i-1],pt[i]);
			addEdge(pt[i],pt[i-1]);
		}
	}
	return 1;
}

int main(){
#ifdef DEBUG
	freopen("E.in","r",stdin);
#endif
	memset(g,-1,sizeof g);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++){
			scanf("%d",&dis[i][j]);
			if(!dis[i][j]) s[i]=j;
		}
	for(int i=1;i<m;i++)
		if(!gao(i)){
			puts("-1");
			return 0;
		}
	Tree::build();
	for(int i=1;i<=n;i++)
		if(getf(i)!=getf(s[1]))
			if(!Tree::insert(i)){
				puts("-1");
				return 0;
			}
	for(int i=1;i<=n;i++)
		if(!Tree::gao_insert(i)){
			puts("-1");
			return 0;
		}
	for(int i=1;i<=m;i++)
		if(!Check::check(i)){
			puts("-1");
			return 0;
		}
	Tree::build();
	for(int i=1;i<=n;i++)
		if(i!=s[1])
			printf("%d %d\n",Tree::pre[i],i);
	return 0;
}