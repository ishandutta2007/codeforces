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
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); //shuffle(a+1,a+1+n,rng)
//uniform_int_distribution<> gen(1,100); //gen(rng)
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
const ll mod=1000000007,inf=1e18;
using mi=modnum<mod>;
const int N=4e5+5,M=2555,Q=1e6+5;
int q,d,n=200000;
ll C[N],S[N],D[N],L[N];
int F[N],in[N];
void fadd(int i,int v){
	for(;i<=n;i+=i&-i) F[i]+=v;
}
int fqry(int i){
	int ret=0;
	for(;i;i-=i&-i) ret+=F[i];
	return ret;
}
void pd(int nd,int l,int r){
	if(!L[nd]) return;
	C[nd]+=L[nd]*S[nd]+D[nd]*(L[nd]*L[nd]-L[nd])/2;
	S[nd]+=L[nd]*D[nd];
	if(l!=r){
		int m=(l+r)>>1;
		L[nd+1]+=L[nd];
		L[nd+2*(m-l+1)]+=L[nd];
	}
	L[nd]=0;
}
void setv(int nd,int l,int r,int x,ll v){
	pd(nd,l,r);
	if(r<x||x<l) return;
	if(l==r){
		if(v>0){
			v--;
			C[nd]=v*(v-1)/2;
			S[nd]=v;
			D[nd]=1;
		} else{
			C[nd]=S[nd]=D[nd]=0;
		}
		return;
	}
	int m=(l+r)>>1,ln=nd+1,rn=nd+2*(m-l+1);
	setv(ln,l,m,x,v); setv(rn,m+1,r,x,v);
	C[nd]=C[ln]+C[rn];
	S[nd]=S[ln]+S[rn];
	D[nd]=D[ln]+D[rn];
}
void upd(int nd,int l,int r,int s,int e,int v){
	pd(nd,l,r);
	if(r<s||e<l) return;
	if(s<=l&&r<=e){
		L[nd]+=v;
		pd(nd,l,r);
		return;
	}
	int m=(l+r)>>1,ln=nd+1,rn=nd+2*(m-l+1);
	upd(ln,l,m,s,e,v); upd(rn,m+1,r,s,e,v);
	C[nd]=C[ln]+C[rn];
	S[nd]=S[ln]+S[rn];
	D[nd]=D[ln]+D[rn];
}
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	cin>>q>>d;
	for(int a,i=1;i<=q;i++){
		cin>>a;
		if(in[a]){
			if(a>1) upd(1,1,n,max(1,a-d),a-1,-1);
			setv(1,1,n,a,0);
			fadd(a,-1);
			in[a]=0;
		} else{
			if(a>1) upd(1,1,n,max(1,a-d),a-1,1);
			setv(1,1,n,a,fqry(min(n,a+d))-fqry(a)+1);
			fadd(a,1);
			in[a]=1;
		}
		pd(1,1,n);
		cout<<C[1]<<"\n";
	}
	return 0;
}