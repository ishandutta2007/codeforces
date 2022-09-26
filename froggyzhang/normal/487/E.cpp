//gua gua gua
#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
#include<vector>
#include<stack>
using namespace std;
const int inf=0x3f3f3f3f;
#define N 200010
inline int read(){
	int x=0,f=1;
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
int n,m,Q,w[N];
vector<int> G[N],T[N];
stack<int> st;
multiset<int> s[N];
int dfn[N],low[N],num,tot;
void Tarjan(int u){
	low[u]=dfn[u]=++num;
	st.push(u);
	for(auto v:G[u]){
		if(!dfn[v]){
			Tarjan(v);
			low[u]=min(low[u],low[v]);
			if(low[v]>=dfn[u]){
				int t=0;
				++tot;
				while(t^v){
					t=st.top();
					T[t].push_back(tot);
					T[tot].push_back(t);
					st.pop();
				}
				T[u].push_back(tot);
				T[tot].push_back(u);
			}
		}
		else{
			low[u]=min(low[u],dfn[v]);
		}
	}
}
namespace WZP{
	int wl[N];
	struct node{
		int l,r,mn;
	}tree[N<<2];
	#define ls i<<1
	#define rs i<<1|1
	inline void update(int i){
		tree[i].mn=min(tree[ls].mn,tree[rs].mn);
	}
	void build(int i,int l,int r){
		tree[i].l=l;
		tree[i].r=r;
		if(l==r){
			tree[i].mn=wl[l];
			return;
		}
		int mid=(l+r)>>1;
		build(ls,l,mid);
		build(rs,mid+1,r);
		update(i);
	}
	int Query(int i,int l,int r){
		if(tree[i].l>=l&&tree[i].r<=r){
			return tree[i].mn;
		}
		int ans=inf;
		int mid=(tree[i].l+tree[i].r)>>1;
		if(l<=mid){
			ans=min(ans,Query(ls,l,r));
		}
		if(r>mid){
			ans=min(ans,Query(rs,l,r));
		}
		return ans;
	}
	void Change(int i,int pos,int d){
		if(tree[i].l==tree[i].r){
			tree[i].mn=d;
			return;
		}
		int mid=(tree[i].l+tree[i].r)>>1;
		if(pos<=mid){
			Change(ls,pos,d);
		}
		else{
			Change(rs,pos,d);
		}
		update(i);
	}
	#undef ls
	#undef rs
}
namespace MYH{
	int top[N],son[N],siz[N],dep[N],f[N],seg[N],num;
	void dfs1(int u,int fa,int deep){
		dep[u]=deep;
		f[u]=fa;
		siz[u]=1;
		int maxson=-1;
		for(auto v:T[u]){
			if(v==fa)continue;
			dfs1(v,u,deep+1);
			if(u>n)s[u].insert(w[v]);
			siz[u]+=siz[v];
			if(siz[v]>maxson){
				maxson=siz[v];
				son[u]=v;
			}
		}
	}
	void dfs2(int u,int topf){
		seg[u]=++num;
		WZP::wl[num]=(u<=n?w[u]:(*s[u].begin()));
		top[u]=topf;
		if(!son[u])return;
		dfs2(son[u],topf);
		for(auto v:T[u]){
			if(v==f[u]||v==son[u])continue;
			dfs2(v,v);
		}
	}
	void init(){
		dfs1(1,0,1);
		dfs2(1,1);
		WZP::build(1,1,tot);
	}
	int Query(int x,int y){
		int ans=inf;
		while(top[x]^top[y]){
			if(dep[top[x]]<dep[top[y]])swap(x,y);
			ans=min(ans,WZP::Query(1,seg[top[x]],seg[x]));
			x=f[top[x]];
		}
		if(dep[x]>dep[y])swap(x,y);
		ans=min(ans,WZP::Query(1,seg[x],seg[y]));
		if(x>n)ans=min(ans,w[f[x]]);
		return ans;
	}
	void Change(int x,int d){
		if(f[x]){
			s[f[x]].erase(s[f[x]].find(w[x]));
			s[f[x]].insert(d);
			WZP::Change(1,seg[f[x]],*s[f[x]].begin());
		}
		WZP::Change(1,seg[x],d);
		w[x]=d;
	}
}
int main(){
	n=read(),m=read(),Q=read();
	tot=n;
	for(int i=1;i<=n;++i){
		w[i]=read();
	}
	for(int i=1;i<=m;++i){
		int u=read(),v=read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	Tarjan(1);
	MYH::init();
	while(Q--){
		char opt[3];
		scanf("%s",opt+1);
		int x=read(),y=read();
		if(opt[1]=='C'){
			MYH::Change(x,y);
		}
		else{
			printf("%d\n",MYH::Query(x,y));
		}
	}
	return 0;
}