#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#define fi first
#define se second
using namespace std;
using namespace __gnu_pbds;
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
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> oset;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); //shuffle(a+1,a+1+n,rng)
uniform_int_distribution<> gen(1,100); //gen(rng)
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
};
using mi=modnum<1000000007>;
const int N=105;
const ll mod=1e9+7,inf=1e18;
int n,m,k,p;
int fact[N],dp[N][N][N],ncr[N][N];
bool vis[N][N][N];
int f(int n,int m,int k){
	vector<int> v;
	int res=0;
	for(int i=0;i<n;i++) v.emplace_back(i);
	do{
		int cnt=0;
		for(int i=0;i<n;i++){
			int ttl=1;
			for(int j=i+1,val=v[i];j<n;j++){
				if(val<v[j]){
					val=v[j];
					ttl++;
				}
			}
			for(int j=i-1,val=v[i];j>=0;j--){
				if(val<v[j]){
					val=v[j];
					ttl++;
				}
			}
			if(ttl==m) cnt++;
		}
		if(cnt==k) res++;
	}while(next_permutation(v.begin(),v.end()));
	return res;
}
int Get(int n,int m,int k){
	if(n==1){
		if(m==1&&k==1) return 1%p;
		if(1<m&&k==0) return 1%p;
		return 0;
	}
	if(n<k) return 0;
	if(m==1){
		if(k==1) return fact[n];
		return 0;
	}
	if(n<m){
		if(k==0) return fact[n];
		return 0;
	}
	if(vis[n][m][k]) return dp[n][m][k];
	vis[n][m][k]=true;
	int &res=dp[n][m][k];
	for(int i=1;i<=n;i++){
		if(i==1||i==n){
			(res+=Get(n-1,m-1,k))%=p;
		} else{
			for(int j=0;j<=k;j++) if(j<=i-1&&k-j<=n-i) (res+=(ll)Get(i-1,m-1,j)*Get(n-i,m-1,k-j)%p*ncr[n-1][i-1]%p)%=p;
		}
	}
	return res;
}
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	cin>>n>>m>>k>>p;
	for(int i=0;i<=100;i++){
		ncr[i][0]=ncr[i][i]=1;
		for(int j=1;j<i;j++) ncr[i][j]=(ncr[i-1][j-1]+ncr[i-1][j])%p;
		if(i) fact[i]=(ll)fact[i-1]*i%p;
		else fact[i]=1;
	}
	cout<<Get(n,m,k);
	return 0;
}