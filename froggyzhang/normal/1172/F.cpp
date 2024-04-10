#include<bits/stdc++.h>
using namespace std;
#define N 1000100
typedef long long ll;
const ll inf=1e18;
int n,Q,p,c[N];
class Segment_Tree{
	struct node{
		ll sum;
		vector<ll> V;	
	}t[N<<2];
	#define ls u<<1
	#define rs u<<1|1
	inline void update(int u){
		t[u].sum=t[ls].sum+t[rs].sum;
		t[u].V=vector<ll>(t[ls].V.size()+t[rs].V.size()-1,inf);
		auto Get = [&](int x,int y) -> ll{
			if(x>=t[ls].V.size()||x<0||y>=t[rs].V.size()||y<0)return inf;
			return max(t[ls].V[x],t[rs].V[y]-(t[ls].sum-1LL*x*p));
		};
		for(int i=0,j=0;i<(int)t[u].V.size();++i){
			while(Get(j+1,i-j-1)<=Get(j,i-j))++j;
			t[u].V[i]=Get(j,i-j);
		}
	}
public:
	void build(int u,int L,int R){
		if(L==R){
			t[u].sum=c[L];
			t[u].V=vector<ll>({-inf,p-c[L]});
			return;
		}
		int mid=(L+R)>>1;
		build(ls,L,mid);
		build(rs,mid+1,R);
		update(u);
	}
	void Query(int u,int L,int R,int l,int r,ll &d){
		if(L>=l&&R<=r){
			d+=t[u].sum-1LL*p*(upper_bound(t[u].V.begin(),t[u].V.end(),d)-t[u].V.begin()-1);
			return;	
		}
		int mid=(L+R)>>1;
		if(l<=mid)Query(ls,L,mid,l,r,d);
		if(r>mid)Query(rs,mid+1,R,l,r,d);
	}
}T;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>Q>>p;
	for(int i=1;i<=n;++i){
		cin>>c[i];	
	}
	T.build(1,1,n);
	while(Q--){
		int l,r;
		ll ans=0;
		cin>>l>>r;
		T.Query(1,1,n,l,r,ans);
		cout<<ans<<'\n';
	}
	return 0;
}