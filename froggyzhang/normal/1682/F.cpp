#include<bits/stdc++.h>
using namespace std;
#define N 200020
const int mod=1e9+7;
int n,Q,a[N],b[N],len,p[N],rk[N];
__int128 s[N];
inline pair<__int128,__int128> operator + (const pair<__int128,__int128> &a,const pair<__int128,__int128> &b){
	return make_pair(a.first+b.first,a.second+b.second);
}
class Segment_Tree{
	int Len;
	struct node{
		pair<__int128,__int128> sum;
		pair<__int128,__int128> add;
		inline void Add(pair<__int128,__int128> d){
			add=add+d;
			sum=sum+d;
		}
	}t[N<<2];
	#define ls u<<1
	#define rs u<<1|1
	inline void pushdown(int u){
		t[ls].Add(t[u].add);
		t[rs].Add(t[u].add);
		t[u].add=make_pair(__int128(0),__int128(0));
	}
	void _ins(int u,int L,int R,int p){
		if(L==R){
			t[u].sum=t[u].add=make_pair(__int128(0),__int128(0));
			return;
		}
		pushdown(u);
		int mid=(L+R)>>1;
		p<=mid?_ins(ls,L,mid,p):_ins(rs,mid+1,R,p);
	}
	pair<__int128,__int128> _ask(int u,int L,int R,int p){
		if(L==R){
			return t[u].sum;
		}
		pushdown(u);
		int mid=(L+R)>>1;
		return p<=mid?_ask(ls,L,mid,p):_ask(rs,mid+1,R,p);
	}
	void _plus(int u,int L,int R,int l,int r,pair<__int128,__int128> d){
		if(L>=l&&R<=r){
			t[u].Add(d);
			return;
		}
		pushdown(u);
		int mid=(L+R)>>1;
		if(l<=mid)_plus(ls,L,mid,l,r,d);
		if(r>mid)_plus(rs,mid+1,R,l,r,d);
	}
public:
	void init(int n){
		Len=n;
	}
	void Ins(int u){
		_ins(1,0,Len,u);
	}
	void Plus(int l,int r,pair<__int128,__int128> w){
		if(l>r)return;
		_plus(1,0,Len,l,r,w);
	}
	pair<__int128,__int128> Ask(int u){
		return _ask(1,0,Len,u);
	}
}T;
__int128 ans[N];
vector<pair<int,int> > q[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>Q;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=1;i<=n;++i){
		cin>>b[i];
		s[i]=s[i-1]+b[i];
	}
	for(int i=0;i<=n;++i){
		b[i]=s[i];
		p[i]=i;
	}
	sort(p,p+n+1,[&](int i,int j){return s[i]<s[j];});
	for(int i=0;i<=n;++i){
		rk[p[i]]=i;
	}
	T.init(n);
	for(int i=1;i<=Q;++i){
		int l,r;
		cin>>l>>r;
		q[r].emplace_back(l,i);
	}
	for(int i=1;i<=n;++i){
		for(auto [l,id]:q[i]){
			auto [c0,c1]=T.Ask(rk[l-1]);
			ans[id]=c0+c1*s[l-1];
		}
		__int128 d=a[i+1]-a[i];
		T.Plus(0,rk[i]-1,make_pair(d*s[i],-d));
		T.Plus(rk[i]+1,n,make_pair(-d*s[i],d));
		T.Ins(rk[i]);
	}
	for(int i=1;i<=Q;++i){
		cout<<(int)(ans[i]%mod)<<'\n';
	}
	return 0;
}