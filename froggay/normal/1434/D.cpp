#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<tuple>
#include<algorithm>
using namespace std;
#define N 500050
typedef long long ll;
const int inf=0x3f3f3f3f;
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
int n,wdep[N],dep[N],In[N],Out[N],p[N],tot,Q,a[N<<1];
vector<tuple<int,int,int> > G[N];
struct node{
	int l,r;
	int A[2],B,AB[2],BA[2],ABA[2];
	node(){A[0]=A[1]=B=AB[0]=AB[1]=BA[0]=BA[1]=ABA[0]=ABA[1]=-inf;}
	bool rev;
	void Rev(){
		swap(A[0],A[1]);
		swap(AB[0],AB[1]);
		swap(BA[0],BA[1]);
		rev^=1;
	}
}tree[N<<3];
#define ls i<<1
#define rs i<<1|1
void dfs(int u,int fa){
	a[++tot]=u;
	In[u]=tot;
	for(auto [v,w,id]:G[u]){
		if(v==fa)continue;
		p[id]=v;
		dep[v]=dep[u]+1;
		wdep[v]=wdep[u]+w;
		dfs(v,u);
		a[++tot]=u;
	}
	Out[u]=tot;
}
inline void pushdown(int i){
	if(tree[i].rev){
		tree[ls].Rev();
		tree[rs].Rev();
		tree[i].rev=0;
	}
}
inline void update(int i){
	tree[i].B=max(tree[ls].B,tree[rs].B);
	for(int p=0;p<2;++p){
		tree[i].A[p]=max(tree[ls].A[p],tree[rs].A[p]);
		tree[i].AB[p]=max(max(tree[ls].AB[p],tree[rs].AB[p]),tree[ls].A[p]+tree[rs].B);
		tree[i].BA[p]=max(max(tree[ls].BA[p],tree[rs].BA[p]),tree[ls].B+tree[rs].A[p]);
		tree[i].ABA[p]=max(tree[ls].ABA[p],tree[rs].ABA[p]);
	}
	for(int p1=0;p1<2;++p1){
		for(int p2=0;p2<2;++p2){
			tree[i].ABA[p1^p2]=max(tree[i].ABA[p1^p2],max(tree[ls].AB[p1]+tree[rs].A[p2],tree[ls].A[p1]+tree[rs].BA[p2]));
		}
	}
}
void build(int i,int l,int r){
	tree[i].l=l;
	tree[i].r=r;
	if(l==r){
		int u=a[l];
		int p=wdep[u]&1;
		tree[i].A[p]=dep[u];
		tree[i].B=-2*dep[u];
		tree[i].AB[p]=tree[i].BA[p]=-dep[u];
		return;
	}
	int mid=(l+r)>>1;
	build(ls,l,mid);
	build(rs,mid+1,r);
	update(i);
}
void Change(int i,int l,int r){
	if(tree[i].l>=l&&tree[i].r<=r){
		tree[i].Rev();
		return;
	}
	pushdown(i);
	int mid=(tree[i].l+tree[i].r)>>1;
	if(l<=mid){
		Change(ls,l,r);
	}
	if(r>mid){
		Change(rs,l,r);
	}
	update(i);
}
int main(){
	n=read();
	for(int i=1;i<n;++i){
		int u=read(),v=read(),w=read();
		G[u].emplace_back(v,w,i);
		G[v].emplace_back(u,w,i);
	}
	dfs(1,0);
	build(1,1,tot);
	Q=read();
	while(Q--){
		int u=read();
		Change(1,In[p[u]],Out[p[u]]);
		printf("%d\n",tree[1].ABA[0]);
	}
	return 0;
}