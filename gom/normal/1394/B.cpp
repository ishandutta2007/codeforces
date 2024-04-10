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
const int N=5e5+5,M=205,K=1e5+5;
int n,m,k,cur[N],yes[N],ans,has[N][55];
bool ok[N];
vector<pii> g[N];
vector<int> no[N],to[N];
ll arr[N];
int idx(int a,int b){
	return (a-1)*a/2+b;
}
void Do(int x){
	if(x==k+1){
		for(int i=1;i<=k;i++) for(auto x : no[cur[i]]){
			if(yes[x]) return;
		}
		ans++; return;
	}
	for(int i=1;i<=x;i++){
		int j=idx(x,i);
		cur[x]=j; yes[j]=1;
		Do(x+1);
		cur[x]=0; yes[j]=0;
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin>>n>>m>>k;
	for(int u,v,w,i=1;i<=m;i++){
		cin>>u>>v>>w;
		g[u].emplace_back(w,v);
	}
	for(int u=1;u<=n;u++){
		sort(g[u].begin(),g[u].end());
		for(int j=0;j<g[u].size();j++){
			auto [w,v]=g[u][j];
			int c=idx(g[u].size(),j+1);
			if(has[v][c]){
				if(!ok[c]) no[c].emplace_back(c);
				ok[c]=1;
				continue;
			}
			has[v][c]=1;
			to[c].emplace_back(v);
			arr[v]|=(1ll<<c);
		}
	}
	for(ll i=1;i<=k*(k+1)/2;i++){
		ll r=0;
		for(auto j : to[i]) r|=arr[j];
		for(ll j=1;j<=k*(k+1)/2;j++) if(i!=j){
			if(r&(1ll<<j)){
				no[i].emplace_back(j);
			}
		}
	}
	Do(1);
	cout<<ans;
	return 0;
}