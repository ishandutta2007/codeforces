#include<bits/stdc++.h>
using namespace std;
int n;
#define Maxn 200010
char ch[Maxn];
int last=1,tot=1;
struct Node{
	int son[26],fa,len;
}tree[Maxn<<1];
int pos[Maxn<<1],posid=0;
int head[Maxn<<1],v[Maxn<<1],nxt[Maxn<<1],bb=0;
void add_edge(int s,int e){bb++;v[bb]=e;nxt[bb]=head[s];head[s]=bb;}
int seq[Maxn<<1],in[Maxn<<1],out[Maxn<<1],dfk=0;

void insert(char c){
	int dir=c-'a';
	int k=last,now=++tot;
	while(k&&!tree[k].son[dir])tree[k].son[dir]=now,k=tree[k].fa;
	if(!tree[k].son[dir])tree[now].fa=1;
	else{
		int q=tree[k].son[dir];
		if(tree[q].len==tree[k].len+1)tree[now].fa=q;
		else{
			int nq=++tot;
			tree[nq]=tree[q];
			tree[nq].len=tree[k].len+1;
			tree[now].fa=tree[q].fa=nq;
			while(k&&tree[k].son[dir]==q)tree[k].son[dir]=nq,k=tree[k].fa;
		}
	}
	pos[now]=++posid;tree[now].len=posid;
	last=now;
}

void dfs(int u){
	in[u]=++dfk;
	seq[dfk]=pos[u];
	for(int i=head[u];i;i=nxt[i]){
		dfs(v[i]);
		if(!pos[u])pos[u]=pos[v[i]];
	}
	out[u]=dfk;
}

namespace Seg{
	#define V 8000010
	struct Node{
		int ls,rs,sum;
	}tree[V];
	int root[Maxn<<1],cnt=0;
	void Insert(int &k,int x,int l,int r,int pos){
		k=++cnt;
		tree[k]=tree[x];
		tree[k].sum++;
		if(l==r)return;
		int mid=(l+r)>>1;
		if(pos<=mid)Insert(tree[k].ls,tree[x].ls,l,mid,pos);
		else Insert(tree[k].rs,tree[x].rs,mid+1,r,pos);
	}
	int Query(int k1,int k2,int l,int r,int L,int R){
		if(l==L&&r==R)return tree[k2].sum-tree[k1].sum;
		int mid=(l+r)>>1;
		if(R<=mid)return Query(tree[k1].ls,tree[k2].ls,l,mid,L,R);
		else if(mid<L)return Query(tree[k1].rs,tree[k2].rs,mid+1,r,L,R);
		else return Query(tree[k1].ls,tree[k2].ls,l,mid,L,mid)+Query(tree[k1].rs,tree[k2].rs,mid+1,r,mid+1,R);
	}
	int query(int u,int l,int r){
		l=max(l,1);r=min(r,n);
		if(l>r)return 0;
		return Query(root[in[u]-1],root[out[u]],1,n,l,r);
	}
}

int ans[Maxn<<1],ansanc[Maxn<<1],Ans=1;
void solve(int u,int f){
	if(u>1){
		int to=ansanc[f];
		ans[u]=max(1,ans[f]);
		if(Seg::query(to,pos[u]-(tree[u].len-tree[to].len),pos[u]-1))ans[u]=ans[f]+1;
		if(ans[u]==ans[f]+1)ansanc[u]=u;
		else ansanc[u]=to;
	}else ansanc[u]=1;
	Ans=max(Ans,ans[u]);
	for(int i=head[u];i;i=nxt[i])solve(v[i],u);
}

int main(){
	scanf("%d",&n);
	scanf("%s",ch+1);
	n=strlen(ch+1);
	for(int i=1;i<=n;++i)insert(ch[i]);
	for(int i=2;i<=tot;++i)add_edge(tree[i].fa,i);
	dfs(1);
	for(int i=1;i<=dfk;++i)
		if(seq[i])Seg::Insert(Seg::root[i],Seg::root[i-1],1,n,seq[i]);
		else Seg::root[i]=Seg::root[i-1];
	solve(1,0);
	printf("%d\n",Ans);
	return 0;
}