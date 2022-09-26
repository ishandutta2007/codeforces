#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
#define N 150055
typedef long long ll;
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
int a[N],n,maxp[N],siz[N],root,vis[N],tot,qwq,bin[N*20],bbb,b[N];
ll ans;
struct PATH{
	ll sum,beg,ed;
	int dep;
}path[N];
vector<int> G[N];
struct Line{
	ll k,b;
}p[N];
struct node{
	int l,r,tag;
}tree[N<<2];
#define ls i<<1
#define rs i<<1|1
void build(int i,int l,int r){
	tree[i].l=l;
	tree[i].r=r;
	if(l==r)return;
	int mid=(l+r)>>1;
	build(ls,l,mid);
	build(rs,mid+1,r);
}
inline ll Val(int id,int x){
	return 1LL*x*p[id].k+p[id].b;
}
void Insert(int i,int id){
	if(tree[i].l==tree[i].r){
		if(Val(tree[i].tag,tree[i].l)<Val(id,tree[i].l)){
			tree[i].tag=id;
			bin[++bbb]=i;
		}
		return;
	}
	int mid=(tree[i].l+tree[i].r)>>1;
	if(p[id].k>p[tree[i].tag].k){
		if(Val(id,mid)>Val(tree[i].tag,mid)){
			Insert(ls,tree[i].tag);
			tree[i].tag=id;
			bin[++bbb]=i;
		}
		else{
			Insert(rs,id);
		}
	}
	else{
		if(Val(id,mid)>Val(tree[i].tag,mid)){
			Insert(rs,tree[i].tag);
			tree[i].tag=id;
			bin[++bbb]=i;
		}
		else{
			Insert(ls,id);
		}
	}
}
void Clear(){
	while(bbb)tree[bin[bbb--]].tag=0;
}
ll Query(int i,int pos){
	if(tree[i].l==tree[i].r){
		return Val(tree[i].tag,pos);
	}
	ll ans=Val(tree[i].tag,pos);
	int mid=(tree[i].l+tree[i].r)>>1;
	if(pos<=mid)ans=max(ans,Query(ls,pos));
	else ans=max(ans,Query(rs,pos));
	return ans;
}
void get_root(int u,int fa,int total){
	siz[u]=1;
	maxp[u]=0;
	for(auto v:G[u]){
		if(v==fa||vis[v])continue;
		get_root(v,u,total);
		siz[u]+=siz[v];
		maxp[u]=max(maxp[u],siz[v]);
	}
	maxp[u]=max(maxp[u],total-siz[u]);
	if(!root||maxp[u]<maxp[root]){
		root=u;
	}
}
void get_dis(int u,int fa,ll sum,ll tot1,ll tot2,int dep,int anc){
	b[++tot]=anc;
	path[tot]={sum,tot1,tot2,dep};
	for(auto v:G[u]){
		if(v==fa||vis[v])continue;
		get_dis(v,u,sum+a[v],tot1+1LL*(dep+2)*a[v],tot2+sum+a[v],dep+1,!anc?v:anc);
	}
} 
void Solve(int u){
	vis[u]=1;
	tot=0;
	qwq=a[u];
	get_dis(u,0,0,a[u],0,0,0);
	int pre=0;
	Clear();
	for(int i=1;i<=tot;i=pre+1){
		while(i<=tot&&b[i]==b[pre+1]){
			ans=max(ans,Query(1,path[i].dep)+path[i].ed);
			++i;
		}
		i=pre+1;
		while(i<=tot&&b[i]==b[pre+1]){
			p[i]={path[i].sum+a[u],path[i].beg};
			Insert(1,i);
			++i;
		}
		pre=i-1;
	}
	pre=tot+1;
	Clear();
	for(int i=tot;i>=1;i=pre-1){
		while(i>=1&&b[i]==b[pre-1]){
			ans=max(ans,Query(1,path[i].dep)+path[i].ed);
			--i;
		}
		i=pre-1;
		while(i>=1&&b[i]==b[pre-1]){
			p[i]={path[i].sum+a[u],path[i].beg};
			Insert(1,i);
			--i;
		}
		pre=i+1;
	}
	for(auto v:G[u]){
		if(vis[v])continue;
		root=0;
		get_root(v,u,siz[v]);
		Solve(root);
	}
}
int main(){
	n=read();
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	build(1,1,n);
	get_root(1,0,n);
	Solve(root);
	cout<<ans<<endl;
	return 0;
}