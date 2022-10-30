#include<bits/stdc++.h>
#define SZ(x) ((int)x.size())
#define pb push_back
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=200005,M=N<<1;
int X[M],Y[M],C[M],t[M];
struct edge{int v,nxt,w;}c[M<<1];
int front[N],edge_cnt;
inline void addedge(int u,int v,int w){c[++edge_cnt]=(edge){v,front[u],w},front[u]=edge_cnt;}
int dfn[N],id,Fa[N],w[N],pos;
std::vector<int> cyc[N];
bool cov[N];
void dfs(int x,int fa){
	dfn[x]=++id,Fa[x]=fa;
	for(int i=front[x];i;i=c[i].nxt){
		int v=c[i].v;
		if(v==fa)continue;
		if(!dfn[v])w[v]=c[i].w,dfs(v,x);
		else if(dfn[v]<dfn[x]){
			cyc[++pos]={c[i].w};
			for(int u=x;u!=v;u=Fa[u])cyc[pos].pb(w[u]),cov[u]=true;
		}
	}
}
std::vector<int> occ[N];
bool mark[N],used[N];
struct node{
	int u,d;
	inline bool operator < (const node &o)const{return d>o.d;}
};
std::priority_queue<node> q;
int cnt[N],siz[N];
int main(){
	int n,m;read(n,m);
	int _p=0;
	for(int i=1;i<=m;++i)read(X[i],Y[i],C[i]),t[++_p]=C[i];
	std::sort(t+1,t+_p+1),_p=std::unique(t+1,t+_p+1)-t-1;
	for(int i=1;i<=m;++i)C[i]=std::lower_bound(t+1,t+_p+1,C[i])-t,addedge(X[i],Y[i],C[i]),addedge(Y[i],X[i],C[i]);
	for(int i=1;i<=n;++i)if(!dfn[i])dfs(i,0);
	for(int i=2;i<=n;++i)if(!cov[i])cyc[++pos]={w[i]};
	for(int i=1;i<=pos;++i)for(auto it:cyc[i])occ[it].pb(i),++cnt[it];
	for(int i=1;i<=pos;++i)siz[i]=SZ(cyc[i])-1;
	for(int i=1;i<=_p;++i)q.push({i,cnt[i]});
	int ans=0;
	while(!q.empty()){
		node x=q.top();q.pop();
		if(cnt[x.u]!=x.d)continue;
		used[x.u]=true;
		int id=-1;for(auto it:occ[x.u])if(!mark[it]){id=it;break;}
		if(id==-1)continue;
		++ans;
		if(!--siz[id]){
			mark[id]=true;
			for(auto it:cyc[id])if(!used[it])--cnt[it],q.push({it,cnt[it]});
		}
	}
	printf("%d\n",ans);
	return 0;
}