#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
//typedef __int128 l2;
typedef long double db;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<db,db> pdb;
typedef tuple<int,int,int> tii;
typedef tuple<ll,ll,ll> tll;
typedef tuple<ll,ll,ll,ll> tl4;
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
using mi=modnum<998244353>;
const ll mod=1e9+7,inf=2e9;
const int N=105,M=10005,K=1e7+5;
int n,a[N],s,c;
db ncr[N][N],x,dp[2][N][M],ans;
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
	cin>>n>>x;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s+=a[i];
	}
	for(int i=0;i<=n;i++){
		ncr[i][0]=1;
		for(int j=1;j<=i;j++) ncr[i][j]=ncr[i-1][j-1]+ncr[i-1][j];
	}
	dp[c][0][0]=1;
	for(int t=1;t<=n;t++,c=1-c){
		for(int i=0;i<=t;i++) for(int j=0;j<=s;j++) dp[1-c][i][j]=dp[c][i][j];
		for(int i=0;i<=t;i++) for(int j=0;j<=s-a[t];j++) dp[1-c][i+1][j+a[t]]+=dp[c][i][j];
	}
	for(int i=0;i<n;i++) for(int j=0;j<=s;j++){
		ans+=dp[c][i][j]*min((s-j)/((db)n-i),(n/((db)n-i)+1)*x/2)/ncr[n][i];
	}
	cout<<fixed<<setprecision(30)<<ans;
    return 0;
}