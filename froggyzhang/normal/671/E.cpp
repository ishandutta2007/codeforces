#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 100010
const ll inf=0x0f3f3f3f3f3f3f3f;
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
int n,k;
int w[N],g[N],ans;
ll a[N],b[N],c[N],d[N];
int st[N],top;
struct node{
	int l,r;
	ll x,y,add;
	inline void Add(ll d){
		add+=d;
		x+=d;
	}
}tree[N<<2];
#define ls i<<1
#define rs i<<1|1
inline void update(int i){
	tree[i].x=max(tree[ls].x,tree[rs].x);
	tree[i].y=max(tree[ls].y,tree[rs].y);
}
inline void pushdown(int i){
	if(tree[i].add){
		tree[ls].Add(tree[i].add);
		tree[rs].Add(tree[i].add);
		tree[i].add=0;
	}
}
void build(int i,int l,int r){
	tree[i].l=l;
	tree[i].r=r;
	tree[i].x=-inf;
	if(l==r)return;
	int mid=(l+r)>>1;
	build(ls,l,mid);
	build(rs,mid+1,r);
}
void Set(int i,int p,ll d){
	if(tree[i].l==tree[i].r){
		tree[i].x=tree[i].y=d;
		return;
	}
	pushdown(i);
	int mid=(tree[i].l+tree[i].r)>>1;
	if(p<=mid){
		Set(ls,p,d);
	}
	else{
		Set(rs,p,d);
	}
	update(i);
}
void Change(int i,int l,int r,ll d){
	if(tree[i].l>=l&&tree[i].r<=r){
		tree[i].Add(d);
		return;
	}
	pushdown(i);
	int mid=(tree[i].l+tree[i].r)>>1;
	if(l<=mid){
		Change(ls,l,r,d);
	}
	if(r>mid){
		Change(rs,l,r,d);
	}
	update(i);
}
ll Find(int i,int r){
	if(tree[i].l==tree[i].r)return tree[i].y;
	int mid=(tree[i].l+tree[i].r)>>1;
	if(r>mid)return max(tree[ls].y,Find(rs,r));
	return Find(ls,r);
}
int Query(int i,int l,int r,ll d){
	if(tree[i].l==tree[i].r)return tree[i].l;
	pushdown(i);
	int mid=(tree[i].l+tree[i].r)>>1;
	if(l<=mid&&r>mid){
		if(Find(rs,r)+k>=max(d,tree[ls].x)){
			return Query(rs,l,r,max(d,tree[ls].x));
		}
		return Query(ls,l,r,d);
	}
	if(l<=mid)return Query(ls,l,r,d);
	return Query(rs,l,r,d);
}
int main(){
	n=read(),k=read();
	for(int i=1;i<n;++i){
		w[i]=read();
	}
	for(int i=1;i<=n;++i){
		g[i]=read();
	}
	for(int i=1;i<=n;++i){
		a[i]=a[i-1]+w[i];
		b[i]=b[i-1]+g[i];
	}
	for(int i=1;i<=n;++i){
		c[i]=a[i-1]-b[i-1];
		d[i]=b[i]-a[i-1];
	}
	build(1,1,n);
	for(int i=n;i>=1;--i){
		while(top&&c[i]>=c[st[top]]){
			if(top>1){
				Change(1,st[top-1]-1,n,c[st[top]]-c[st[top-1]]);
			}
			--top;
		}
		st[++top]=i;
		Set(1,i,d[i]);
		if(top>1){
			Change(1,st[top-1]-1,n,c[st[top-1]]-c[i]);
		}
		int l=1,r=top,p=top;
		while(l<r){
			int mid=(l+r)>>1;
			if(c[st[mid]]-c[i]<=k)r=p=mid;
			else l=mid+1;
		}
		p=(p==1?n:st[p-1]-1);
		ans=max(ans,Query(1,i,p,-inf)-i+1);
	}
	printf("%d\n",ans);
	return 0;
}