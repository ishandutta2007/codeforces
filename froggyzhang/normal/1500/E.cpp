#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
const ll inf=1e13;
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
	};
	return x*f;
}
int n,Q;
struct Segment_Tree{
	int rt,cnt;
	struct node{
		int ch[2],s0;
		ll sum,sl,sr;
	}tree[N*60];
	#define ls tree[u].ch[0]
	#define rs tree[u].ch[1]
	inline void update(int u){
		tree[u].s0=tree[ls].s0+tree[rs].s0;
		tree[u].sum=tree[ls].sum+tree[rs].sum;
		tree[u].sl=tree[ls].sl+tree[rs].sl+tree[ls].sum*tree[rs].s0;
		tree[u].sr=tree[ls].sr+tree[rs].sr+tree[rs].sum*tree[ls].s0;
	}
	void Insert(int &u,ll L,ll R,ll p,int d){
		if(!u)u=++cnt;
		if(L==R){
			tree[u].s0+=d;
			tree[u].sum+=p*d;
			tree[u].sl+=p*d;
			tree[u].sr+=p*d;
			return;
		}
		ll mid=(L+R)>>1;
		p<=mid?Insert(ls,L,mid,p,d):Insert(rs,mid+1,R,p,d);
		update(u);
	}
	ll Query1_L(int u,ll L,ll R,int sz){
		if(!u||!sz)return 0;
		if(L==R)return tree[u].sum;
		ll mid=(L+R)>>1;
		if(sz>=tree[ls].s0)return tree[ls].sum+Query1_L(rs,mid+1,R,sz-tree[ls].s0);
		return Query1_L(ls,L,mid,sz);
	}
	ll Query1_R(int u,ll L,ll R,int sz){
		if(!u||!sz)return 0;
		if(L==R)return tree[u].sum;
		ll mid=(L+R)>>1;
		if(sz>=tree[rs].s0)return tree[rs].sum+Query1_R(ls,L,mid,sz-tree[rs].s0);
		return Query1_R(rs,mid+1,R,sz);
	}
	ll Query2_L(int u,ll L,ll R,int sz){
		if(!u||!sz)return 0;
		if(L==R)return tree[u].sl;
		ll mid=(L+R)>>1;
		if(sz>=tree[ls].s0)return tree[ls].sl+tree[ls].sum*(sz-tree[ls].s0)+Query2_L(rs,mid+1,R,sz-tree[ls].s0);
		return Query2_L(ls,L,mid,sz);
	}
	ll Query2_R(int u,ll L,ll R,int sz){
		if(!u||!sz)return 0;
		if(L==R)return tree[u].sr;
		ll mid=(L+R)>>1;
		if(sz>=tree[rs].s0)return tree[rs].sr+tree[rs].sum*(sz-tree[rs].s0)+Query2_R(ls,L,mid,sz-tree[rs].s0);
		return Query2_R(rs,mid+1,R,sz);
	}
}T;
inline bool check(int p){
	return T.Query1_L(T.rt,1,inf,p)-T.Query1_R(T.rt,1,inf,p-1)>0;	
}
int main(){
	n=read(),Q=read();
	for(int i=1;i<=n;++i){
		ll x=read();
		T.Insert(T.rt,1,inf,x,1);
	}
	++Q;
	while(Q--){
		int sz=T.tree[T.rt].s0;
		int l=1,r=(sz+1)/2+1,pos=0;
		while(l<r){
			int mid=(l+r)>>1;
			if(check(mid)){
				l=mid+1,pos=mid;
			}
			else{
				r=mid;
			}
		}
		ll tot=0;
		if(pos)tot=(T.Query2_L(T.rt,1,inf,pos)-T.Query2_R(T.rt,1,inf,pos-1))*2;
		if(sz&1){
			tot-=max(0LL,T.Query1_L(T.rt,1,inf,(sz+1)/2)-T.Query1_R(T.rt,1,inf,(sz+1)/2-1));
		}
		printf("%lld\n",T.tree[T.rt].sum-tot);
		if(Q){
			int opt=read();
			ll x=read();
			T.Insert(T.rt,1,inf,x,opt==1?1:-1);
		}
	}
	return 0;
}