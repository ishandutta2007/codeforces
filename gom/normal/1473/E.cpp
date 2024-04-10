#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
//typedef __int128 l2;
//typedef long long l2;
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
typedef vector<vector<ll>> mat;
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
const ll mod=1e9+7,inf=1e18;
using mi=modnum<1000000007>;
const int N=3e5+5,M=2505;
int n,m;
ll d[4][N];
vector<pll> g[N];
priority_queue<tll,vector<tll>,greater<tll>> pq;
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	cin>>n>>m;
	for(int u,v,w,i=1;i<=m;i++){
		cin>>u>>v>>w;
		g[u].emplace_back(v,w);
		g[v].emplace_back(u,w);
	}
	for(int j=0;j<4;j++) for(int i=1;i<=n;i++) d[j][i]=inf;
	d[0][1]=0; pq.emplace(0,1,0);
	while(pq.size()){
		auto [di,u,c]=pq.top(); pq.pop();
		if(d[c][u]!=di) continue;
		for(auto [v,w] : g[u]){
			if(d[c][v]>di+w){
				d[c][v]=di+w; pq.emplace(di+w,v,c);
			}
		}
		if(!(c&1)){
			for(auto [v,w] : g[u]){
				if(d[c|1][v]>di){
					d[c|1][v]=di; pq.emplace(di,v,c|1);
				}
			}
		}
		if(!(c&2)){
			for(auto [v,w] : g[u]){
				if(d[c|2][v]>di+w+w){
					d[c|2][v]=di+w+w; pq.emplace(di+w+w,v,c|2);
				}
			}
		}
		if(!c){
			for(auto [v,w] : g[u]){
				if(d[3][v]>di+w){
					d[3][v]=di+w; pq.emplace(di+w,v,3);
				}
			}
		}
	}
	for(int i=2;i<=n;i++) cout<<d[3][i]<<" ";
	return 0;
}