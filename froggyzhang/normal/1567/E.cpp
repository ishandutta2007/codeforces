#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
int n,Q,a[N];
class Segment_tree{
	struct node{
		int len,l,r,lval,rval;
		ll sum;
		friend node operator + (const node &a,const node &b){
			node c;
			c.len=a.len+b.len;
			c.sum=a.sum+b.sum;
			c.lval=a.lval,c.rval=b.rval;
			c.l=a.l,c.r=b.r;
			if(a.l==a.len&&a.rval<=b.lval)c.l+=b.l;
			if(b.l==b.len&&a.rval<=b.lval)c.r+=a.r;
			if(a.rval<=b.lval)c.sum+=1LL*a.r*b.l;
			return c;
		}
	}tree[N<<2];
public:
	#define ls u<<1
	#define rs u<<1|1
	void build(int u,int L,int R){
		if(L==R){
			tree[u].len=tree[u].sum=tree[u].l=tree[u].r=1;
			tree[u].lval=tree[u].rval=a[L];
			return;
		}
		int mid=(L+R)>>1;
		build(ls,L,mid),build(rs,mid+1,R);
		tree[u]=tree[ls]+tree[rs];
	}
	void Change(int u,int L,int R,int p){
		if(L==R){
			tree[u].lval=tree[u].rval=a[L];
			return;
		}
		int mid=(L+R)>>1;
		p<=mid?Change(ls,L,mid,p):Change(rs,mid+1,R,p);
		tree[u]=tree[ls]+tree[rs];
	}
	node Query(int u,int L,int R,int l,int r){
		if(L>=l&&R<=r)return tree[u];
		int mid=(L+R)>>1;
		if(l<=mid&&r>mid)return Query(ls,L,mid,l,r)+Query(rs,mid+1,R,l,r);
		if(l<=mid)return Query(ls,L,mid,l,r);
		return Query(rs,mid+1,R,l,r);
	}
}T;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>Q;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	T.build(1,1,n);
	while(Q--){
		int opt,x,y;
		cin>>opt>>x>>y;
		if(opt==1){
			a[x]=y;
			T.Change(1,1,n,x);
		}
		else{
			cout<<T.Query(1,1,n,x,y).sum<<'\n';
		}
	}
	return 0;
}