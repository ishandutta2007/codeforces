#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
const int mod=1e9+7;
int n,Q,a[N],w[N];
class Segment_Tree{
	struct node{
		ll sum;
		int jb;
		node(ll _s=0,int _j=0){sum=_s,jb=_j;}
		friend node operator + (const node &a,const node &b){
			return node(a.sum+b.sum,(a.jb+b.jb)%mod);	
		}
	}t[N<<2];
	#define ls u<<1
	#define rs u<<1|1
public:
	void build(int u,int L,int R){
		if(L==R){
			t[u].sum=w[L];
			t[u].jb=1LL*(a[L]-L)*w[L]%mod;
			return;
		}
		int mid=(L+R)>>1;
		build(ls,L,mid);
		build(rs,mid+1,R);
		t[u]=t[ls]+t[rs];
	}
	void Change(int u,int L,int R,int p){
		if(L==R){
			t[u].sum=w[p];
			t[u].jb=1LL*w[p]*(a[p]-p)%mod;
			return;
		}
		int mid=(L+R)>>1;
		p<=mid?Change(ls,L,mid,p):Change(rs,mid+1,R,p);
		t[u]=t[ls]+t[rs];
	}
	node Query(int u,int L,int R,int l,int r){
		if(L>=l&&R<=r)return t[u];
		int mid=(L+R)>>1;
		if(l<=mid&&r>mid)return Query(ls,L,mid,l,r)+Query(rs,mid+1,R,l,r);
		if(l<=mid)return Query(ls,L,mid,l,r);
		return Query(rs,mid+1,R,l,r);
	}
	
	pair<ll,int> Find(int u,int L,int R,int l,int r,ll lim){
		int mid=(L+R)>>1;
		if(L>=l&&R<=r){
			if(t[u].sum<lim)return make_pair(t[u].sum,-1);
			if(L==R)return make_pair(0LL,L);
			if(t[ls].sum<lim)return Find(rs,mid+1,R,l,r,lim-t[ls].sum);
			return Find(ls,L,mid,l,r,lim);
		}
		if(l<=mid&&r>mid){
			auto [sl,pl]=Find(ls,L,mid,l,r,lim);
			if(~pl)return make_pair(sl,pl);
			auto [sr,pr]=Find(rs,mid+1,R,l,r,lim-sl);
			if(~pr)return make_pair(sr,pr);
			return make_pair(sl+sr,-1);
		}
		else if(l<=mid)return Find(ls,L,mid,l,r,lim);
		else return Find(rs,mid+1,R,l,r,lim);	
	}
	int Ask(int l,int r){
		node t=Query(1,1,n,l,r);
		auto [jbjbjbjb,pos]=Find(1,1,n,l,r,(t.sum+1)/2);
		node A=Query(1,1,n,l,pos);
		node B=Query(1,1,n,pos,r);
		int ans=((1LL*(a[pos]-pos)*A.sum-A.jb)+(B.jb+1LL*(pos-a[pos])*B.sum))%mod;
		return (ans+mod)%mod;
	}
}T;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>Q;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=1;i<=n;++i){
		cin>>w[i];
	}
	T.build(1,1,n);
	while(Q--){
		int x,y;
		cin>>x>>y;
		if(x<0){
			x=-x;
			w[x]=y;
			T.Change(1,1,n,x);
		}
		else{
			cout<<T.Ask(x,y)<<'\n';
		}	
	}
	return 0;
}