#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef long double db;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<db,db> pdb;
typedef tuple<int,int,int> tii;
typedef tuple<db,db,db> tdb;
typedef tuple<ll,ll,ll> tll;
typedef tuple<int,int,int,int> ti4;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); //shuffle(a+1,a+1+n,rng)
//uniform_int_distribution<> gen(1,100); //gen(rng)
//https://codeforces.com/contest/1264/submission/66344993 +     
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
	int get(){
		return v;
	}
};
const ll mod=1e9+7,inf=1e18;
using mi=modnum<mod>;
const int N=1e5+5,M=1e6+5;
typedef pair<mi,mi> ND;
int n,q;
ll a[N],b[N],c[N],s[N];
struct T{
	ll T[4*N];
	void init(int nd,int l,int r,bool md){
		if(l==r){
			T[nd]=s[l];
			if(md) T[nd]=-s[l];
			return;
		}
		int m=(l+r)>>1;
		init(nd<<1,l,m,md); init(nd<<1|1,m+1,r,md);
		T[nd]=max(T[nd<<1],T[nd<<1|1]);
	}
	ll qry(int nd,int l,int r,int s,int e){
		if(r<s||e<l) return -inf;
		if(s<=l&&r<=e) return T[nd];
		int m=(l+r)>>1;
		return max(qry(nd<<1,l,m,s,e),qry(nd<<1|1,m+1,r,s,e));
	}
}T1,T2;
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	for(int i=1;i<=n;i++){
		c[i]=a[i]-b[i];
		s[i]=s[i-1]+c[i];
	}
	T1.init(1,1,n,false);
	T2.init(1,1,n,true);
	for(int l,r,i=1;i<=q;i++){
		cin>>l>>r;
		if(s[r]!=s[l-1]){
			cout<<"-1\n"; continue;
		}
		ll Q=T1.qry(1,1,n,l,r-1);
		if(Q>s[l-1]){
			cout<<"-1\n"; continue;
		}
		Q=T2.qry(1,1,n,l,r-1);
		cout<<s[l-1]+Q<<"\n";
	}
	return 0;
}