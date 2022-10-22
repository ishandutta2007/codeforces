//#pragma GCC optimize("O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma")
#include <bits/stdc++.h>
//#include <atcoder/all>
//using namespace atcoder;
//#include <bits/extc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/priority_queue.hpp>
#define fi first
#define se second
using namespace std;
//using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<db,db> pdb;
typedef tuple<int,int,int> tii;
typedef tuple<db,db,db> tdb;
typedef tuple<ll,ll,ll> tll;
typedef tuple<int,int,int,int> ti4;
typedef tuple<ll,ll,ll,ll> tl4;
typedef tuple<db,db,db,db> td4;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> oset;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); //shuffle(a+1,a+1+n,rng)
uniform_int_distribution<> gen(1,100); //gen(rng)
ll modinv(ll a,ll m){
	if(m==1) return 0;
	a%=m;
	if(a<0) a+=m;
	if(a==1) return 1;
	return m-modinv(m,a)*m/a;
}
template <int MOD_> struct modnum{
private:
	int v;
public:
	static const int MOD = MOD_;
 
	modnum() : v(0) {}
	modnum(ll v_) : v(int(v_ % MOD)) { if (v < 0) v += MOD; }
	explicit operator int () const { return v; }
	friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
	friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }
	friend bool operator < (const modnum& a, const modnum& b) { return a.v < b.v; }
	friend bool operator <= (const modnum& a, const modnum& b) { return a.v <= b.v; }
	friend bool operator > (const modnum& a, const modnum& b) { return a.v > b.v; }
	friend bool operator >= (const modnum& a, const modnum& b) { return a.v >= b.v; }
 
	modnum operator ~ () const {
		modnum res;
		res.v = modinv(v, MOD);
		return res;
	}
 
	modnum& operator += (const modnum& o) {
		v += o.v;
		if (v >= MOD) v -= MOD;
		return *this;
	}
	modnum& operator -= (const modnum& o) {
		v -= o.v;
		if (v < 0) v += MOD;
		return *this;
	}
	modnum& operator *= (const modnum& o) {
		v = int(ll(v) * ll(o.v) % MOD);
		return *this;
	}
	modnum& operator /= (const modnum& o) {
		return *this *= (~o);
	}
 
	modnum operator-() const { return modnum(-v); }
	modnum& operator++() { return *this += 1; }
	modnum operator++(int){ modnum tmp=*this; ++*this; return tmp; }
	modnum& operator--() { return *this -= 1; }
	modnum operator--(int){ modnum tmp=*this; --*this; return tmp; }
 
	friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
	friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
	friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }
	friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= b; }
	friend modnum pow(modnum a, ll p) {
		modnum ans = 1;
		for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans;
	}
	friend ostream& operator<<(std::ostream& os, const modnum& o)
	{
		os << o.v;
		return os;
	}
	friend istream& operator>>(std::istream& is, modnum& o)
	{
		is >> o.v;
		return is;
	}
};
using mi=modnum<1000000007>;
const int N=5e5+5,M=(1<<21),Q=1e6+5;
const ll mod=1000000007,inf=1e18;
struct SegmentTree{
	ll T[2*N];
	void init(int nd,int l,int r){
		T[nd]=-inf;
		if(l==r) return;
		int m=(l+r)>>1;
		init(nd+1,l,m); init(nd+2*(m-l+1),m+1,r);		
	}
	void upd(int nd,int l,int r,int x,ll v){
		T[nd]=max(T[nd],v);
		if(l==r) return;
		int m=(l+r)>>1;
		if(x<=m) upd(nd+1,l,m,x,v);
		else upd(nd+2*(m-l+1),m+1,r,x,v);
	}
	ll qry(int nd,int l,int r,int s,int e){
		if(r<s||e<l) return -inf;
		if(s<=l&&r<=e) return T[nd];
		int m=(l+r)>>1;
		return max(qry(nd+1,l,m,s,e),qry(nd+2*(m-l+1),m+1,r,s,e));
	}
}T1,T2;
int n,m;
ll a[N],s[N],dp[N],x[N],mx[N];
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
		x[i]=s[i];
	}
	sort(x+1,x+1+n); m=unique(x+1,x+1+n)-x-1;
	for(int i=0;i<=m;i++) mx[i]=-inf;
	T1.init(1,1,m); T2.init(1,1,m);
	for(int i=1;i<=n;i++){
		dp[i]=-inf;
		int j=lower_bound(x+1,x+1+m,s[i])-x;
		if(s[i]>0) dp[i]=i;
		else{
			if(s[i]<0) dp[i]=-i;
			else dp[i]=0;
			dp[i]=max(dp[i],mx[j]);
			if(1<j) dp[i]=max(dp[i],T1.qry(1,1,m,1,j-1)+i);
			if(j<m) dp[i]=max(dp[i],T2.qry(1,1,m,j+1,m)-i);
		}
		mx[j]=max(mx[j],dp[i]);
		T1.upd(1,1,m,j,dp[i]-i);
		T2.upd(1,1,m,j,dp[i]+i);
	}
	cout<<dp[n]<<"\n";
}
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin>>t;
	while(t--) solve();
	return 0;
}