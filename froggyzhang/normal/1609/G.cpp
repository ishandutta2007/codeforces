#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
int n,m,Q;
ll a[N],b[N],all;
class Segment_Tree{
	int Len;
	struct node{
		ll mn,mx,sum;
		int add,len;
		inline void Add(int d){
			mn+=d,mx+=d;
			add+=d;
			sum+=1LL*len*d;
		}
	}t[N<<2];
	#define ls u<<1
	#define rs u<<1|1
	inline void update(int u){
		t[u].mn=t[ls].mn;
		t[u].mx=t[rs].mx;
		t[u].sum=t[ls].sum+t[rs].sum;
	}
	inline void pushdown(int u){
		if(t[u].add){
			t[ls].Add(t[u].add);
			t[rs].Add(t[u].add);
			t[u].add=0;
		}
	}
	void build(int u,int L,int R){
		t[u].len=R-L+1;
		if(L==R){
			t[u].mn=t[u].mx=t[u].sum=b[L]-b[L-1];
			return;
		}
		int mid=(L+R)>>1;
		build(ls,L,mid);
		build(rs,mid+1,R);
		update(u);
	}
	void _plus(int u,int L,int R,int l,int r,int d){
		if(L>=l&&R<=r){
			t[u].Add(d);
			return;
		}
		pushdown(u);
		int mid=(L+R)>>1;
		if(l<=mid)_plus(ls,L,mid,l,r,d);
		if(r>mid)_plus(rs,mid+1,R,l,r,d);
		update(u);
	}
	ll _query(int u,int L,int R,int l,int r){
		if(L>=l&&R<=r){
			return t[u].sum;
		}
		pushdown(u);
		int mid=(L+R)>>1;
		ll tot=0;
		if(l<=mid)tot+=_query(ls,L,mid,l,r);
		if(r>mid)tot+=_query(rs,mid+1,R,l,r);
		return tot;
	}
	int _find(int u,int L,int R,ll x){
		if(L==R)return t[u].mn<=x?L:L-1;
		int mid=(L+R)>>1;
		pushdown(u);
		if(t[rs].mn<=x)return _find(rs,mid+1,R,x);
		return _find(ls,L,mid,x);
	}
public:
	void init(int n){
		Len=n;
		build(1,2,n);
	}
	void Plus(int l,int r,int d){
		_plus(1,2,Len,l,r,d);	
	}
	ll Query(int l,int r){
		if(l>r)return 0;
		return _query(1,2,Len,l,r);
	}
	int Find(ll x){
		return _find(1,2,Len,x);	
	}
}T;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>Q;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=1;i<=m;++i){
		cin>>b[i];
		all+=b[i]-b[1];
	}
	T.init(m);
	while(Q--){
		int opt,k,d;
		cin>>opt>>k>>d;
		if(opt==1){
			for(int i=1;i<=k;++i){
				a[n-k+i]+=i*d;	
			}
		}
		else{
			if(k==m)b[1]+=d,--k;
			T.Plus(m-k+1,m,d);	
			all+=1LL*k*(k+1)/2*d;
		}
		ll ans=(n+m-1)*(a[1]+b[1]);
		for(int i=2;i<=n;++i){
			ll x=a[i]-a[i-1];
			int pos=T.Find(x);
			ans+=T.Query(2,pos)+x*(n+m-pos-i+1);
		}
		cout<<ans+all<<'\n';
	}
	return 0;
}