#include<bits/stdc++.h>
using namespace std;
#define N 400040
const int mod=1e9+7;
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
int ntp[333],p[333],pn,n,Q,inv[333],a[N];
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1LL*ans*a%mod;
		a=1LL*a*a%mod;
		b>>=1;
	}
	return ans;
}
void init(int n){
	ntp[1]=1;
	for(int i=2;i<=n;++i){
		if(!ntp[i]){
			p[pn++]=i;
			for(int j=i+i;j<=n;j+=i)ntp[j]=1;
		}
	}
	inv[1]=1;
	for(int i=2;i<=n;++i){
		inv[i]=1LL*inv[mod%i]*(mod-mod/i)%mod;
	}
}
struct Segment_tree{
	struct node{
		int mul,pro;
		ll t,cov;
		inline void Mul(int x,int len){
			mul=1LL*mul*x%mod;
			pro=1LL*pro*qpow(x,len)%mod;
		}
		inline void Cov(ll d){
			t|=d,cov|=d;
		}
	}tree[N<<2];
	#define ls i<<1
	#define rs i<<1|1
	inline void update(int i){
		tree[i].pro=1LL*tree[ls].pro*tree[rs].pro%mod;
		tree[i].t=tree[ls].t|tree[rs].t;
	}
	inline void pushdown(int i,int L,int R){
		int mid=(L+R)>>1;
		if(tree[i].mul^1){
			tree[ls].Mul(tree[i].mul,mid-L+1);
			tree[rs].Mul(tree[i].mul,R-mid);
			tree[i].mul=1;
		}	
		if(tree[i].cov){
			tree[ls].Cov(tree[i].cov);
			tree[rs].Cov(tree[i].cov);
			tree[i].cov=0;
		}
	}
	void build(int i,int L,int R){
		tree[i].mul=1;	
		if(L==R){
			tree[i].pro=a[L];
			for(int j=0;j<pn;++j){
				if(a[L]%p[j]==0)tree[i].t|=1LL<<j;
			}
			return;
		}
		int mid=(L+R)>>1;
		build(ls,L,mid);
		build(rs,mid+1,R);
		update(i);
	}
	void Change(int i,int L,int R,int l,int r,int x,ll d){
		if(L>=l&&R<=r){
			tree[i].Mul(x,R-L+1);
			tree[i].Cov(d);
			return;
		}
		pushdown(i,L,R);
		int mid=(L+R)>>1;
		if(l<=mid)Change(ls,L,mid,l,r,x,d);
		if(r>mid)Change(rs,mid+1,R,l,r,x,d);
		update(i);	
	}
	pair<int,ll> Query(int i,int L,int R,int l,int r){
		if(L>=l&&R<=r)return make_pair(tree[i].pro,tree[i].t);
		pushdown(i,L,R);
		pair<int,ll> ans=make_pair(1,0LL);
		int mid=(L+R)>>1;
		if(l<=mid){
			auto h=Query(ls,L,mid,l,r);
			ans.first=1LL*ans.first*h.first%mod;
			ans.second|=h.second;
		}
		if(r>mid){
			auto h=Query(rs,mid+1,R,l,r);
			ans.first=1LL*ans.first*h.first%mod;
			ans.second|=h.second;
		}
		return ans;
	}
}T;
int main(){
	init(300);
	n=read(),Q=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	T.build(1,1,n);
	while(Q--){
		static string opt;
		cin>>opt;
		if(opt[0]=='M'){
			int l=read(),r=read(),x=read();
			ll d=0;
			for(int i=0;i<pn;++i){
				if(x%p[i]==0)d|=1LL<<i;
			}
			T.Change(1,1,n,l,r,x,d);
		}
		else{
			int l=read(),r=read();
			auto t=T.Query(1,1,n,l,r);
			int ans=t.first;
			for(int i=0;i<pn;++i){
				if(t.second>>i&1)ans=1LL*ans*inv[p[i]]%mod*(p[i]-1)%mod;
			}
			printf("%d\n",ans);
		}
	}		
	return 0;
}