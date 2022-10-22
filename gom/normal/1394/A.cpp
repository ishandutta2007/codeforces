#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
//typedef __int128 l2;
//typedef long long l2;
typedef long double db;
typedef pair<int,int> pii;
//typedef pair<l2,l2> pll;
typedef pair<db,db> pdb;
typedef tuple<int,int,int> tii;
//typedef tuple<l2,l2,l2> tll;
typedef tuple<int,int,int,int> ti4;
typedef vector<vector<ll>> mat;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
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
const ll mod=1e9+7,inf=1e15;
const int N=1e6+5,M=205,K=1e5+5;
ll n,d,m,a[N],ans,b[N],c[N],sb[N],sc[N],k,l;
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin>>n>>d>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>m) b[++k]=a[i];
		else c[++l]=a[i];
	}
	sort(b+1,b+1+k,greater<ll>()); sort(c+1,c+1+l,greater<ll>());
	for(int i=1;i<=k;i++) sb[i]=sb[i-1]+b[i];
	for(int i=1;i<=l;i++) sc[i]=sc[i-1]+c[i];
	for(ll i=0;i<=k;i++){
		ll j;
		if(i==0) j=l;
		else j=min(l,n-1-(d+1)*(i-1));
		if(j<0) continue;
		ans=max(ans,sb[i]+sc[j]);
	}
	cout<<ans;
	return 0;
}