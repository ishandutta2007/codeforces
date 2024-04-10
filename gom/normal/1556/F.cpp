#include <bits/stdc++.h>
#pragma GCC optimize("O3")
//#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double db;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<db,db> pdb;
typedef tuple<int,int,int> tii;
typedef tuple<db,db,db> tdb;
typedef tuple<ll,ll,ll> tll;
typedef tuple<int,int,int,int> ti4;
typedef pair<pii,pii> ppii;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); //shuffle(a+1,a+1+n,rng)
//uniform_int_distribution<> gen(1,100); //gen(rng)
//modnum: https://codeforces.com/contest/1264/submission/66344993 + own edit
//fastmod: https://github.com/kth-competitive-programming/kactl/blob/main/content/various/FastMod.h
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
	static const ull b=MOD;
	static const __uint128_t m=-1ULL/b;
	static const bool FASTMOD=true;
	static ull reduce(ull a) { //mi::reduce()
		ull q = (ull)((m * a) >> 64), r = a - q * b;
		return r - (r >= b) * b;
	}
	modnum() : v(0) {}
	modnum(ll v_) {
		v = FASTMOD ? (v_ < 0 ? (MOD - reduce(-v_)) : reduce(v_)) : (v_ % MOD + (v_ < 0 ? MOD : 0));
	}
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
		v = FASTMOD ? reduce((ull)v * o.v) : ((ll)v * o.v % MOD);
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
const int N=25;
int n,ok[N];
mi a[N],pw[N],e[N][N],ans,D[20000];
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) e[i][j]=a[i]/(a[i]+a[j]);
	for(int mask=1;mask<(1<<n);mask++){
		D[mask]=1;
		int siz=0;
		for(int i=0;i<n;i++) if(mask&(1<<i)) siz++;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int ok1=mask&(1<<(i-1)),ok2=mask&(1<<(j-1));
				if(ok1&&!ok2) D[mask]*=e[i][j];
				if(!ok1&&ok2) D[mask]*=e[j][i];
			} 
		}
		for(int sub=mask;sub;sub=(sub-1)&mask) if(mask!=sub){
			int sub2=sub^mask;
			mi res=D[sub];
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					int ok1=sub2&(1<<(i-1)),ok2=mask&(1<<(j-1));
					if(ok1&&!ok2) res*=e[i][j];
				} 
			}
			D[mask]-=res;
		}
		ans+=D[mask]*siz;
	}
	cout<<ans;
	return 0;
}