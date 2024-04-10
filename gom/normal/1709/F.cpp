//#pragma GCC optimize("O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
//#include <atcoder/all>
//using namespace atcoder;
//#include <bits/extc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/priority_queue.hpp>
#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()
//using namespace std;
//using namespace __gnu_pbds;
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
const ll mod=998244353,inf=1e18;
using mi=modnum<mod>;
const int N=20,M=5e5+5,K=2005;
int n,k,f;
vector<mi> dp[N];
void fft(vector<mi> &a,bool inv){
	int n=a.size(),j=0;
	vector<mi> roots(n/2);
	for(int i=1;i<n;i++){
		int bit=n>>1;
		while(j>=bit){
			j-=bit;
			bit>>=1;
		}
		j+=bit;
		if(i<j) swap(a[i],a[j]);
	}
	mi ang=pow((mi)3,(mod-1)/n);
	if(inv) ang=1/ang;
	for(int i=0;i<n/2;i++) roots[i]=i?roots[i-1]*ang:1;
	for(int i=2;i<=n;i<<=1){
		int step=n/i;
		for(int j=0;j<n;j+=i) for(int k=0;k<i/2;k++){
			mi u=a[j+k],v=a[j+k+i/2]*roots[step*k];
			a[j+k]=u+v;
			a[j+k+i/2]=u-v;
		}
	}
	mi invn=(mi)1/n;
	if(inv) for(int i=0;i<n;i++) a[i]*=invn;
}
vector<mi> multiply(vector<mi> &a,vector<mi> &b){
	vector<mi> fa(a.begin(),a.end()),fb(b.begin(),b.end());
	int n=2;
	while(n<a.size()+b.size()) n<<=1;
	fa.resize(n); fb.resize(n);
	fft(fa,false); fft(fb,false);
	for(int i=0;i<n;i++) fa[i]*=fb[i];
	fft(fa,true);
	return fa;
}
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	cin>>n>>k>>f;
	if(f>2*k){
		cout<<0;
		return 0;
	}
	dp[0].resize(k+1);
	for(int i=0;i<=k;i++) dp[0][i]=1;
	for(int i=1;i<=n;i++){
		dp[i]=multiply(dp[i-1],dp[i-1]);
		if(i!=n){
			mi s=0;
			for(int j=2*k;j>k;j--) s+=dp[i][j];
			for(int j=k;j>=0;j--){
				s+=dp[i][j];
				dp[i][j]=dp[i][j]*(k-j)+s;
			}
			dp[i].resize(k+1);
		}
	}
	cout<<dp[n][f];
	return 0;
}