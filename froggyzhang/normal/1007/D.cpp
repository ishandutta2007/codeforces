#include<bits/stdc++.h>
using namespace std;
#define N 100010
#define M 3000200
typedef long long ll;
int n,top[N],son[N],dep[N],siz[N],f[N],m,dfn[M],num;
vector<int> G[M];
inline int yes(int x){return 2*x+1;}
inline int no(int x){return 2*x;}
inline void adde(int u,int v){
	G[u].push_back(v);
	G[v^1].push_back(u^1);
}
void dfs1(int u){
	siz[u]=1;
	for(auto v:G[u]){
		if(v==f[u])continue;
		f[v]=u,dep[v]=dep[u]+1;
		dfs1(v);
		siz[u]+=siz[v];
		if(siz[v]>siz[son[u]]){
			son[u]=v;
		}
	}
}
void dfs2(int u,int topf){
	dfn[u]=++num;
	top[u]=topf;
	if(!son[u])return;
	dfs2(son[u],topf);
	for(auto v:G[u]){
		if(v==f[u]||v==son[u])continue;
		dfs2(v,v);
	}
}
vector<int> t[N<<2];
#define ls (u<<1)
#define rs (u<<1|1)
void _ins(int u,int L,int R,int l,int r,int w){
	if(L>=l&&R<=r){return t[u].push_back(w);}
	int mid=(L+R)>>1;
	if(l<=mid)_ins(ls,L,mid,l,r,w);
	if(r>mid)_ins(rs,mid+1,R,l,r,w);
}
void Ins(int l,int r,int w){
	_ins(1,1,n,l,r,w);
}
void Cover(int u,int v,int w){
	while(top[u]^top[v]){
		if(dep[top[u]]<dep[top[v]])swap(u,v);
		Ins(dfn[top[u]],dfn[u],w);
		u=f[top[u]];
	}
	if(dep[u]>dep[v])swap(u,v);
	if(u^v)Ins(dfn[u]+1,dfn[v],w);
}
int jb;
void build(int u,int L,int R){
	vector<int> p(t[u].size()+1);
	for(auto &x:p)x=++jb;
	adde(yes(u+m),yes(p[0]));
	for(int i=0;i<(int)t[u].size();++i){
		adde(t[u][i],no(p[i]));
		adde(t[u][i],yes(p[i+1]));
		adde(yes(p[i]),yes(p[i+1]));
	}
	if(L==R)return;
	int mid=(L+R)>>1;
	build(ls,L,mid);
	build(rs,mid+1,R);
	adde(yes(p.back()),yes(ls+m));
	adde(yes(p.back()),yes(rs+m));
}
int low[M],tot,col[M];
void Tarjan(int u){
	static int st[M],top;
	static bool vis[M];
	dfn[u]=low[u]=++num;
	vis[u]=1;
	st[++top]=u;
	for(auto v:G[u]){
		if(!dfn[v]){
			Tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(vis[v]){
			low[u]=min(low[u],dfn[v]);
		}
	}
	if(dfn[u]==low[u]){
		++tot;
		int t=0;
		while(t^u){
			t=st[top--];
			vis[t]=0;
			col[t]=tot;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<n;++i){
		int u,v;
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs1(1);
	dfs2(1,1);
	cin>>m;
	for(int i=1;i<=m;++i){
		int u1,v1,u2,v2;
		cin>>u1>>v1>>v2>>u2;
		Cover(u1,v1,no(i));
		Cover(u2,v2,yes(i));
	}
	for(int i=1;i<=n;++i)G[i].clear();
	jb=4*n+m;
	build(1,1,n);
	memset(dfn,0,sizeof(dfn));
	num=0;
	for(int i=2;i<=2*jb+1;++i){
		if(!dfn[i])Tarjan(i);
	}
	for(int i=1;i<=m;++i){
		if(col[yes(i)]==col[no(i)]){
			cout<<"NO\n";
			return 0;
		}
	}
	cout<<"YES\n";
	for(int i=1;i<=m;++i){
		cout<<(col[no(i)]<col[yes(i)]?1:2)<<'\n';
	}
	return 0;
}