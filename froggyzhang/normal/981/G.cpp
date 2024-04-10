#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
typedef pair<int,int> pii;
const int mod=998244353;
int n,Q;
class Segment_Tree{
	int Len;
	struct node{
		int len,sum,add,mul;
		node(){mul=1;add=sum=0;}
		inline void Add(int d){
			sum=(sum+1LL*len*d)%mod;
			add=(add+d)%mod;
		}
		inline void Mul(int d){
			mul=1LL*mul*d%mod;
			add=1LL*add*d%mod;
			sum=1LL*sum*d%mod;	
		}
	}t[N<<2];
	#define ls u<<1
	#define rs u<<1|1
	inline void update(int u){
		t[u].sum=(t[ls].sum+t[rs].sum)%mod;
	}
	void build(int u,int L,int R){
		t[u].len=R-L+1;
		if(L==R)return;
		int mid=(L+R)>>1;
		build(ls,L,mid),build(rs,mid+1,R);	
	}
	inline void pushdown(int u){
		if(t[u].mul^1){
			t[ls].Mul(t[u].mul);
			t[rs].Mul(t[u].mul);
			t[u].mul=1;
		}
		if(t[u].add){
			t[ls].Add(t[u].add);
			t[rs].Add(t[u].add);
			t[u].add=0;
		}
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
	void _multiply(int u,int L,int R,int l,int r,int d){
		if(L>=l&&R<=r){
			t[u].Mul(d);
			return;
		}
		pushdown(u);
		int mid=(L+R)>>1;
		if(l<=mid)_multiply(ls,L,mid,l,r,d);
		if(r>mid)_multiply(rs,mid+1,R,l,r,d);
		update(u);
	}
	int _query(int u,int L,int R,int l,int r){
		if(L>=l&&R<=r){
			return t[u].sum;
		}
		pushdown(u);
		int mid=(L+R)>>1,tot=0;
		if(l<=mid)tot+=_query(ls,L,mid,l,r);
		if(r>mid)tot+=_query(rs,mid+1,R,l,r);
		return tot%mod;
	}
public:
	void init(int _n){
		Len=_n;
		build(1,1,Len);
	}
	void Plus(int l,int r){
		if(l>r)return;
		_plus(1,1,Len,l,r,1);
	}
	void Mul2(int l,int r){
		if(l>r)return;
		_multiply(1,1,Len,l,r,2);	
	}
	int Query(int l,int r){
		return _query(1,1,Len,l,r);	
	}
}T;
set<pii> s[N];
void Insert(int x,int l,int r){
	auto it=s[x].lower_bound(pii(l,0));
	int pos=l;
	if(it!=s[x].begin()){
		--it;
		if(it->second>=l){
			T.Mul2(l,min(r,it->second));
			pos=it->second+1;
			if(it->second>r)s[x].emplace(r+1,it->second);
			pii t=*it;
			t.second=l-1;
			s[x].erase(it);
			s[x].insert(t);
		}
	}
	while(pos<=r){
		it=s[x].lower_bound(pii(pos,0));
		if(it==s[x].end()||it->first>r)break;
		T.Plus(pos,it->first-1);
		T.Mul2(it->first,min(it->second,r));
		pos=it->second+1;
		if(it->second>r){
			pii t=*it;
			t.first=r+1;
			s[x].erase(it);
			s[x].insert(t);
		}
		else{
			s[x].erase(it);
		}
	}
	T.Plus(pos,r);
	
	s[x].emplace(l,r);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>Q;
	T.init(n);
	while(Q--){
		int opt,l,r;
		cin>>opt>>l>>r;
		if(opt==1){
			int x;
			cin>>x;
			Insert(x,l,r);
		}
		else{
			cout<<T.Query(l,r)<<'\n';	
		}
	}
	return 0;
}