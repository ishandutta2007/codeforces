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
const int N=2e5+5,M=5e5+5,K=2005;
int n,m,p[N],dep[N],in[N],out[N],rev[N],cur,val;
int par[17][N];
pii e[N];
vector<pii> g[N],t[N];
int s[N];
bool inmst[N],ans[N];
int Find(int x){
	if(!p[x]) return x;
	return p[x]=Find(p[x]);
}
bool Union(int x,int y){
	x=Find(x); y=Find(y);
	if(x==y) return false;
	p[y]=x;
	return true;
}
void dfs(int u,int p=0){
	in[u]=++cur;
	for(auto [e,v]: t[u]) if(v!=p){
		dep[v]=dep[u]+1;
		par[0][v]=u;
		dfs(v,u);
	}
	out[u]=cur;
}
bool vis[N],ok;
void dfs2(int u){
	vis[u]=true;
	for(auto [e,v]: g[u]) if(!vis[v]){
		if(!inmst[e]){
			ok=false;
			return;
		}
		dfs2(v);
		if(!ok) return;
	}
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>e[i].fi>>e[i].se;
		g[e[i].fi].emplace_back(i,e[i].se);
		g[e[i].se].emplace_back(i,e[i].fi);
		if(Union(e[i].fi,e[i].se)){
			inmst[i]=true;
			t[e[i].fi].emplace_back(i,e[i].se);
			t[e[i].se].emplace_back(i,e[i].fi);
		}
	}
	for(int i=2;i<=n;i++) if(Find(i)!=Find(1)) return;
	dfs(1);
	for(int b=1;b<17;b++) for(int i=1;i<=n;i++) par[b][i]=par[b-1][par[b-1][i]];
	for(int i=1;i<=m;i++) if(!inmst[i]){
		int u=e[i].fi,v=e[i].se;
		if(dep[u]>dep[v]) swap(u,v);
		val++;
		if(in[u]<=in[v]&&in[v]<=out[u]){
			s[in[v]]++;
			s[out[v]+1]--;
			int d=dep[v]-dep[u]-1,w=v;
			for(int b=0;b<17;b++) if((d>>b)&1) w=par[b][w];
			s[1]++;
			s[in[w]]--;
			s[out[w]+1]++;
		} else{
			s[in[u]]++;
			s[out[u]+1]--;
			s[in[v]]++;
			s[out[v]+1]--;
		}
	}
	for(int i=1;i<=n;i++) s[i]+=s[i-1];
	for(int i=1;i<=n;i++) cout<<(s[in[i]]==val);
	cout<<"\n";
}
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}