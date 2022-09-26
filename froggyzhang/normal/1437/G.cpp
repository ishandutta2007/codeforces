#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<set>
using namespace std;
#define N 300030
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
int n,pos[N],Q,a[N];
multiset<int> vals[N];
char s[N];
namespace Tree{int Query(int u);}
namespace AC{
	struct node{
		int ch[26],nxt,ed;
	}trie[N];
	int tot;
	int Insert(char *s){
		int u=1;
		int len=strlen(s+1);
		for(int i=1;i<=len;++i){
			int c=s[i]-'a';
			if(!trie[u].ch[c])trie[u].ch[c]=++tot;
			u=trie[u].ch[c];
		}
		trie[u].ed=1;
		return u;
	}
	void build(){
		queue<int> q;
		for(int i=0;i<26;++i)trie[0].ch[i]=1;
		q.push(1);
		while(!q.empty()){
			int u=q.front();
			q.pop();
			for(int i=0;i<26;++i){
				int v=trie[u].ch[i];
				if(v){
					trie[v].nxt=trie[trie[u].nxt].ch[i];
					q.push(v);
				}
				else trie[u].ch[i]=trie[trie[u].nxt].ch[i];
			}
		}
	}
	int Query(char *s){
		int len=strlen(s+1);
		int ans=-1,u=1;
		for(int i=1;i<=len;++i){
			int c=s[i]-'a';
			u=trie[u].ch[c];
			if(!u)return ans;
			ans=max(ans,Tree::Query(u));
		}
		return ans;
	}
}
namespace Seg{
	struct node{
		int l,r,mx;
	}tree[N<<2];
	#define ls i<<1
	#define rs i<<1|1
	inline void update(int i){
		tree[i].mx=max(tree[ls].mx,tree[rs].mx);
	}
	void build(int i,int l,int r){
		tree[i].l=l;
		tree[i].r=r;
		tree[i].mx=-1;
		if(l==r)return;
		int mid=(l+r)>>1;
		build(ls,l,mid);
		build(rs,mid+1,r);
	}
	void Change(int i,int pos,int val){
		if(tree[i].l==tree[i].r){
			tree[i].mx=val;
			return;
		}
		int mid=(tree[i].l+tree[i].r)>>1;
		if(pos<=mid){
			Change(ls,pos,val);
		}
		else{
			Change(rs,pos,val);
		}
		update(i);
	}
	int Query(int i,int l,int r){
		if(tree[i].l>=l&&tree[i].r<=r){
			return tree[i].mx;
		}
		int ans=-1;
		int mid=(tree[i].l+tree[i].r)>>1;
		if(l<=mid)ans=max(ans,Query(ls,l,r));
		if(r>mid)ans=max(ans,Query(rs,l,r));
		return ans;
	}
}
namespace Tree{
	vector<int> G[N];
	int dep[N],siz[N],son[N],top[N],f[N],dfn[N],num;
	void dfs1(int u){
		siz[u]=1;
		for(auto v:G[u]){
			f[v]=u;
			dep[v]=dep[u]+1;
			dfs1(v);
			siz[u]+=siz[v];
			if(siz[v]>siz[son[u]])son[u]=v;
		}
	}
	void dfs2(int u,int topf){
		top[u]=topf;
		dfn[u]=++num;
		if(!son[u])return;
		dfs2(son[u],topf);
		for(auto v:G[u]){
			if(v==son[u])continue;
			dfs2(v,v);
		}
	}
	void Modify(int x,int w){
		Seg::Change(1,dfn[x],w);
	}
	int Query(int x){
		int ans=-1;
		while(x){
			ans=max(ans,Seg::Query(1,dfn[top[x]],dfn[x]));
			x=f[top[x]];
		}
		return ans;
	}
	void init(){
		dfs1(1);
		dfs2(1,1);
		Seg::build(1,1,num);
	}
}
int main(){
	n=read(),Q=read(),AC::tot=1;
	for(int i=1;i<=n;++i){
		scanf("%s",s+1);
		pos[i]=AC::Insert(s);
		vals[pos[i]].insert(0);
	}
	AC::build();
	for(int i=2;i<=AC::tot;++i){
		Tree::G[AC::trie[i].nxt].push_back(i);
	}
	Tree::init();
	for(int i=2;i<=AC::tot;++i){
		if(!vals[i].empty())Tree::Modify(i,0);
	}
	while(Q--){
		int opt=read();
		if(opt==1){
			int x=read(),val=read();
			int u=pos[x];
			vals[u].erase(vals[u].find(a[x]));
			a[x]=val;
			vals[u].insert(a[x]);
			Tree::Modify(u,*--vals[u].end());
		}
		else{
			scanf("%s",s+1);
			printf("%d\n",AC::Query(s));
		}
	}
	return 0;
}