#include<bits/stdc++.h>
using namespace std;
#define N 600010
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,m,a[N],p[N],ans[N];
vector<int> G[N];
int f[N],top[N],dep[N],siz[N],son[N];
int in[N],out[N],tot;
void dfs1(int u){
	siz[u]=1;
	in[u]=++tot;
	p[tot]=u;
	for(auto v:G[u]){
		if(v==f[u])continue;
		f[v]=u;
		dep[v]=dep[u]+1;
		dfs1(v);
		siz[u]+=siz[v];
		if(siz[v]>siz[son[u]])son[u]=v;
	}
	out[u]=++tot;
	p[tot]=u;
}
void dfs2(int u,int topf){
	top[u]=topf;
	if(!son[u])return;
	dfs2(son[u],topf);
	for(auto v:G[u]){
		if(v==f[u]||v==son[u])continue;
		dfs2(v,v);
	}
}
inline int LCA(int x,int y){
	while(top[x]^top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		x=f[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	return x;
}
namespace FK{
	int len,blocks,L[N],R[N],pos[N];
	void init(){
		len=min(n,600);
		blocks=n/len;
		if(n%len)++blocks;
		for(int i=1;i<=blocks;++i){
			L[i]=(i-1)*len+1,R[i]=min(i*len,n);
			for(int j=L[i];j<=R[i];++j)pos[j]=i;
		}
	}
	int cnt[N],e[N];
	inline void Change(int x){
		e[a[x]]?--cnt[pos[a[x]]]:++cnt[pos[a[x]]];
		e[a[x]]^=1;
	}
	inline int Ask(int l,int r){
		int x=pos[l],y=pos[r];
		if(x==y){
			for(int i=l;i<=r;++i){
				if(e[i])return i;
			}
		}
		else{
			if(cnt[x])for(int i=l;i<=R[x];++i)if(e[i])return i;
			if(cnt[y])for(int i=L[y];i<=r;++i)if(e[i])return i;
			for(int i=x+1;i<y;++i){
				if(cnt[i]){
					for(int j=L[i];j<=R[i];++j)if(e[j])return j;
				}
			}
		}
		return -1;
	}
}
struct Query{
	int l,r,u,v,id,lca,pos;
	friend operator <(const Query a,const Query b){
		return a.pos==b.pos?(a.pos&1?a.v>b.v:a.v<b.v):a.pos<b.pos;
	}
}q[N];
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs1(1);
	dfs2(1,1);
	FK::init();
	int len=510;
	for(int i=1;i<=m;++i){
		int u=read(),v=read();
		int lca=LCA(u,v);
		if(in[u]>in[v])swap(u,v);
		if(u==lca){
			q[i].u=in[u],q[i].v=in[v];
			q[i].pos=in[u]/len;
		}
		else{
			q[i].u=out[u],q[i].v=in[v];
			q[i].pos=out[u]/len;
			q[i].lca=lca;
		}
		q[i].l=read(),q[i].r=read(),q[i].id=i;
	}
	sort(q+1,q+m+1);
	for(int i=1,l=1,r=0;i<=m;++i){
		while(l>q[i].u)FK::Change(p[--l]);
		while(r<q[i].v)FK::Change(p[++r]);
		while(l<q[i].u)FK::Change(p[l++]);
		while(r>q[i].v)FK::Change(p[r--]);
		if(q[i].lca)FK::Change(q[i].lca);
		ans[q[i].id]=FK::Ask(q[i].l,q[i].r);
		if(q[i].lca)FK::Change(q[i].lca);
	}
	for(int i=1;i<=m;++i){
		printf("%d\n",ans[i]);
	}
	return 0;
}