#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
const int C=1e9+1;
const ll inf=1e18;
int Q;
class Segment_Tree{
	int cnt;
	struct node{
		int ch[2],cov,len;
		ll sum,smn;
		node(){sum=len=0,smn=inf;}
		inline void Cov(int d){
			sum=1LL*len*d;
			smn=d<=0?1LL*len*d:0;
			cov=d;
		}
	}t[N<<6];
	#define ls t[u].ch[0]
	#define rs t[u].ch[1]
	inline void update(int u){
		t[u].sum=t[ls].sum+t[rs].sum;
		t[u].smn=min(t[ls].smn,t[rs].smn+t[ls].sum);
	}
	int NewNode(int Len){
		int u=++cnt;
		t[u].sum=t[u].smn=0,t[u].cov=C,t[u].len=Len;
		return u;
	} 
	inline void pushdown(int u){
		if(t[u].cov^C){
			if(!ls)ls=NewNode((t[u].len+1)>>1);
			if(!rs)rs=NewNode(t[u].len>>1);
			t[ls].Cov(t[u].cov);
			t[rs].Cov(t[u].cov);
			t[u].cov=C;
		}
	}
public:
	int rt;
	void Cover(int &u,int L,int R,int l,int r,int d){
		if(!u)u=NewNode(R-L+1);
		if(L>=l&&R<=r){
			t[u].Cov(d);
			return;
		}
		pushdown(u);
		int mid=(L+R)>>1;
		if(l<=mid)Cover(ls,L,mid,l,r,d);
		if(r>mid)Cover(rs,mid+1,R,l,r,d);
		update(u);
	}
	pair<double,ll> Query(int &u,int L,int R,int l,int r,ll lim){
		if(!u)u=NewNode(R-L+1);
		int mid=(L+R)>>1;
		if(L>=l&&R<=r){
			if(lim+t[u].smn>0)return make_pair(-1,t[u].sum);
			if(L==R)return make_pair(L-1.0*lim/t[u].cov,t[u].sum);
		}
		pushdown(u);
		if(l<=mid&&r>mid){
			auto [dl,sl]=Query(ls,L,mid,l,r,lim);
			if(dl!=-1)return make_pair(dl,sl);
			auto [dr,sr]=Query(rs,mid+1,R,l,r,lim+sl);
			if(dr!=-1)return make_pair(dr,sr);
			return make_pair(-1,sl+sr);
		}
		else if(l<=mid)return Query(ls,L,mid,l,r,lim);
		else return Query(rs,mid+1,R,l,r,lim);
	}
}T;
map<int,int> mp;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.setf(ios::fixed);
	cout.precision(10);
	cin>>Q;
	mp[0]=mp[C]=0;
	while(Q--){
		int opt;
		cin>>opt;
		if(opt==1){
			int t,s;
			cin>>t>>s;
			mp[t]=s;
			int r=mp.upper_bound(t)->first;
			T.Cover(T.rt,0,C,t,r-1,s); 
		}
		else if(opt==2){
			int t;
			cin>>t;
			int r=mp.upper_bound(t)->first;
			int k=(--mp.lower_bound(t))->second;
			T.Cover(T.rt,0,C,t,r-1,k); 
			mp.erase(t);
		}
		else{
			int l,r,v;
			cin>>l>>r>>v;
			if(!v){cout<<l<<'\n';continue;}
			l=max(l,mp.lower_bound(l)->first);
			cout<<(l>=r?-1:T.Query(T.rt,0,C,l,r-1,v).first)<<'\n';	
		}
	}
	return 0;
}