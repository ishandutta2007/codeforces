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
const int N=20005,M=5e5+5,K=2005;
int n,nxtu[N],dp[N],dpl[N],ans;
int d[N];
vector<int> v[N];
mi hsum[2][4][N],val[2]={2138171,3719587},ival[2],pw[2][N],spw[2][N],invpw[2][N];
string s;
bool chk(int l,int r,int k){
	int d=r-l+1;
	//UDLR
	if(k!=0&&l-d<1) return false;
	if(k!=2&&r+d>n) return false;
	for(int t=0;t<2;t++){
		mi vT=0,vM=0,vB=0;
		//[l - d, l - 1] | [l, r] | [r + 1, r + d]
		if(k!=0) vT=(hsum[t][1][l-1]-hsum[t][1][l-d-1])*pw[t][d];
		vM=hsum[t][2][r]-hsum[t][2][l-1]+hsum[t][3][r]-hsum[t][3][l-1];
		if(k!=2) vB=(hsum[t][0][r+d]-hsum[t][0][r])*invpw[t][d];
		if(vT+vM+vB!=spw[t][r]-spw[t][l-1]) return false;
	}
	return true;
}
int dps[N];
void solve(int x,int d){
	if(!x) x+=d;
	int e=x;
	if(x+d-1>n) return;
	while(e+2*d-1<=n) e+=d;
	dps[e]=0;
	for(int i=e,p=e;i>=x;i-=d){
		int j=i+d;
		if(i+2*dp[i]-(d-1)>0){
			int md=(i+2*dp[i]-(d-1))%d;
			if(md<=x) j=max(j,i+2*dp[i]-(d-1)+x-md);
			else j=max(j,i+2*dp[i]-(d-1)+d+x-md);
		}
		if(j<=n&&chk(i,i+d-1,0)) ans+=dps[j];
		if(i+d-1<=n&&!chk(i,i+d-1,1)){
			for(int j=i;j<=p;j+=d) dps[j]=0;
			p=i;
		}
		if(i!=e) dps[i]=dps[i+d];
		if(chk(i,i+d-1,2)) dps[i]++;
	}
}
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	cin>>s;
	n=s.size(); s="$"+s;
	nxtu[n+1]=n+1;
	for(int i=n;i>=1;i--){
		nxtu[i]=nxtu[i+1];
		if(s[i]=='U') nxtu[i]=i;
	}
	for(int i=n;i>=1;i--){
		dpl[i]=dpl[i+1];
		if(s[i]!='L') dpl[i]=0;
		if(s[i]=='L'&&!dpl[i]) dpl[i]=i;
	}
	for(int i=n-1;i>=1;i--){
		if(s[i]=='R'&&s[i+1]=='L') dp[i]=dp[i+2]+1;
		ans+=dp[i];
		if(i+2*dp[i]<=n){
			int x=i+2*dp[i];
			if(s[x]=='R'){
				int y=nxtu[x];
				if(y==n+1) continue;
				// |s|/(y-x) x (y-x)
				if(i+2*(y-x)-1>n) continue;
				d[i]=y-x;
				v[y-x].emplace_back(i%(y-x));
			} else if(s[x]=='D'){
				if(x==n) continue;
				int y=x,z=nxtu[x];
				if(s[x+1]=='L') y=dpl[x+1];
				if(z==n+1) continue;
				// |s|/(z-y) x (z-y)
				if(i+2*(z-y)-1>n) continue;
				d[i]=z-y;
				v[z-y].emplace_back(i%(z-y));
			}
		}
	}
	for(int t=0;t<2;t++){
		pw[t][0]=invpw[t][0]=1;
		ival[t]=1/val[t];
		for(int i=1;i<=n+1;i++){
			pw[t][i]=pw[t][i-1]*val[t];
			spw[t][i]=spw[t][i-1]+pw[t][i];
			invpw[t][i]=invpw[t][i-1]*ival[t];
		}
		for(int i=1;i<=n;i++){
			hsum[t][0][i]=hsum[t][0][i-1];
			if(s[i]=='U') hsum[t][0][i]+=pw[t][i];
			hsum[t][1][i]=hsum[t][1][i-1];
			if(s[i]=='D') hsum[t][1][i]+=pw[t][i];
			hsum[t][2][i]=hsum[t][2][i-1];
			if(s[i]=='L') hsum[t][2][i]+=pw[t][i-1];
			hsum[t][3][i]=hsum[t][3][i-1];
			if(s[i]=='R') hsum[t][3][i]+=pw[t][i+1];
		}
	}
	for(int d=1;d<=n;d++) if(v[d].size()){
		sort(v[d].begin(),v[d].end());
		v[d].resize(unique(v[d].begin(),v[d].end())-v[d].begin());
		for(int x: v[d]) solve(x,d);
	}
	cout<<ans;
	return 0;
}