//#pragma GCC optimize("O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma")
#include <bits/stdc++.h>
//#include <atcoder/all>
//using namespace atcoder;
//#include <bits/extc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/priority_queue.hpp>
#define fi first
#define se second
using namespace std;
using namespace __gnu_pbds;
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
const int N=105,M=2555,Q=1e6+5;
int n;
string s[N][N];
int p[N];
bool eq(int x,int y,int z){
	//d(x,y) = d(x,z)
	if(y==z) return true;
	if(y>z) swap(y,z);
	return s[y][z-y][x-1]=='1';
}
int Fi(int x){
	if(p[x]==x) return x;
	return p[x]=Fi(p[x]);
}
bool Union(int x,int y){
	x=Fi(x); y=Fi(y);
	if(x==y) return false;
	p[y]=x; return true;
}
int par[N]; bool vis[N];
int d[N];
vector<int> c[N];
bool ok;
void dfs(int u){
	for(int i=1;i<=n;i++) if(i!=par[u]&&eq(u,i,par[u])){
		if(par[i]){
			ok=false; return;
		}
		par[i]=u; c[u].emplace_back(i);
		dfs(i);
		if(!ok) return;
	}
}
void dfs2(int u){
	vis[u]=1;
	for(int v: c[u]) if(!vis[v]){
		d[v]=d[u]+1;
		dfs2(v);
	}
	if(u!=1&&!vis[par[u]]){
		d[par[u]]=d[u]+1;
		dfs2(par[u]);
	}
}
bool Do(int g){
	for(int i=1;i<=n;i++) par[i]=0;
	par[1]=-1;
	for(int i=1;i<=n;i++) c[i].clear();
	for(int i=1;i<=n;i++) if(Fi(i)==g){
		par[i]=1;
		c[1].emplace_back(i);
	}
	ok=true;
	for(int i=1;i<=n;i++) if(Fi(i)==g&&ok) dfs(i);
	for(int i=1;i<=n;i++) if(!par[i]) ok=false;
	if(!ok) return false;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) vis[j]=d[j]=0;
		dfs2(i);
		for(int j=1;j<=n;j++) for(int k=j+1;k<=n;k++) if((d[j]==d[k])!=eq(i,j,k)){
			return false;
		}
	}
	cout<<"Yes\n";
	for(int i=1;i<=n;i++) for(int j: c[i]) cout<<i<<" "<<j<<"\n";
	return true;
}
void solve(){
	cin>>n;
	for(int i=1;i<=n-1;i++) for(int j=1;j<=n-i;j++) cin>>s[i][j];
	for(int i=1;i<=n;i++) p[i]=i;
	for(int i=2;i<=n;i++) for(int j=i+1;j<=n;j++) if(eq(1,i,j)) Union(i,j);
	for(int i=2;i<=n;i++) if(Fi(i)==i){
		if(Do(i)) return;
	}
	cout<<"No\n";
}
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int t;
	cin>>t;
	//t=1;
	while(t--) solve();
	return 0;
}