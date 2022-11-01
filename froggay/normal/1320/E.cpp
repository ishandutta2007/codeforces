#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
#define N 400030
const int inf=0x3f3f3f3f;
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
int n,st[N],Q,m,k,cnt,head[N];
int son[N],top[N],siz[N],dep[N],f[N],dfn[N],num,a[N],b[N],p[N],s[N];
vector<int> bin;
struct Edge{
	int to,nxt;
}edge[N<<1];
void add(int a,int b){
	cnt++;
	edge[cnt].to=b;
	edge[cnt].nxt=head[a];
	head[a]=cnt;
}
void dfs1(int u,int fa,int deep){
	dep[u]=deep;
	f[u]=fa;
	siz[u]=1;
	int maxson=-1;
	for(int i=head[u];i;i=edge[i].nxt){
		int v=edge[i].to;
		if(v==fa)continue;
		dfs1(v,u,deep+1);
		siz[u]+=siz[v];
		if(siz[v]>maxson){
			maxson=siz[v];
			son[u]=v;
		}
	}
}
void dfs2(int u,int topf){
	top[u]=topf;
	dfn[u]=++num;
	if(!son[u])return;
	dfs2(son[u],topf);
	for(int i=head[u];i;i=edge[i].nxt){
		int v=edge[i].to;
		if(v==son[u]||v==f[u])continue;
		dfs2(v,v);
	}
}
int LCA(int x,int y){
	while(top[x]^top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		x=f[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	return x;
}
inline int Abs(int x){
	return x>=0?x:-x;
}
int step[N],col[N],vis[N],dis[N],from[N];
struct QAQ{
	int dis,step,col,from;
	bool operator <(const QAQ y)const{
		return step==y.step?col<y.col:step<y.step;
	}
}g[N];
priority_queue<pair<QAQ,int>,vector<pair<QAQ,int> >,greater<pair<QAQ,int> > > q;
void Dijkstra(int n){
	for(int i=0;i<bin.size();i++){
		int u=bin[i];
		g[u].step=g[u].dis=inf,g[u].col=g[u].from=0;
		vis[u]=0;
	}
	for(int i=1;i<=m;i++){
		g[a[i]].col=i,g[a[i]].from=a[i];
		g[a[i]].step=g[a[i]].dis=0;
		q.push(make_pair(g[a[i]],a[i]));
	}
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int i=head[u];i;i=edge[i].nxt){
			int v=edge[i].to;
			QAQ nw=g[u];
			nw.dis+=Abs(dep[u]-dep[v]);
			nw.step=(nw.dis-1)/s[nw.from]+1;
			if(nw<g[v]){
				g[v]=nw;
				q.push(make_pair(g[v],v));
			}
		}
	} 
}
bool cmp(int i,int j){
	return dfn[i]<dfn[j];
}
void Solve(int n){
	sort(p+1,p+n+1,cmp);
	n=unique(p+1,p+n+1)-p-1;
	static int top;
	st[top=1]=1;
	bin.clear();
	bin.push_back(1);
	for(int i=1;i<=n;i++){
		int u=p[i];
		if(u==1)continue;
		int lca=LCA(st[top],u);
		while(top>1&&dfn[st[top-1]]>=dfn[lca]){
			bin.push_back(st[top]);
			add(st[top-1],st[top]),add(st[top],st[top-1]),--top;
		}
		if(lca^st[top]){
			bin.push_back(st[top]);
			add(st[top],lca),add(lca,st[top]),--top;
			st[++top]=lca;
		}
		st[++top]=u;
	}
	while(top>1)bin.push_back(st[top]),add(st[top-1],st[top]),add(st[top],st[top-1]),--top;
	Dijkstra(n);
	for(int i=1;i<=k;i++){
		printf("%d ",g[b[i]].col);
	}
	printf("\n");
	for(int i=0;i<bin.size();i++){
		head[bin[i]]=0;
	}
	cnt=0;
}
int main(){
	n=read();
	for(int i=1;i<=n-1;i++){
		int u=read(),v=read();
		add(u,v),add(v,u);
	}
	dfs1(1,0,1);
	dfs2(1,1);
	memset(head,0,sizeof(head));cnt=0;
	Q=read();
	while(Q--){
		m=read(),k=read();
		int tot=0;
		for(int i=1;i<=m;i++){
			a[i]=read(),p[++tot]=a[i];
			s[a[i]]=read();
		}
		for(int i=1;i<=k;i++){
			b[i]=read(),p[++tot]=b[i];
		}
		Solve(tot);
	}
	return 0;
}