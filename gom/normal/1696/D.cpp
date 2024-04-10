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
const ll mod=998244353,inf=1e18;
using mi=modnum<mod>;
const int N=5e5+5,M=2555,Q=1e6+5;
int n,a[N],d[N],nxt[2][N],bef[2][N];
int stk[N],sz;
queue<int> que;
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=2;i<=n;i++) d[i]=1e9;
	for(int i=1;i<=n;i++) bef[0][i]=bef[1][i]=0;
	for(int i=1;i<=n;i++) nxt[0][i]=nxt[1][i]=n+1;
	sz=0;
	for(int i=1;i<=n;i++){
		while(sz&&a[stk[sz]]<a[i]) sz--;
		if(sz) bef[0][i]=stk[sz];
		stk[++sz]=i;
	}
	sz=0;
	for(int i=1;i<=n;i++){
		while(sz&&a[stk[sz]]>a[i]) sz--;
		if(sz) bef[1][i]=stk[sz];
		stk[++sz]=i;
	}
	sz=0;
	for(int i=n;i>=1;i--){
		while(sz&&a[stk[sz]]<a[i]) sz--;
		if(sz) nxt[0][i]=stk[sz];
		stk[++sz]=i;
	}
	sz=0;
	for(int i=n;i>=1;i--){
		while(sz&&a[stk[sz]]>a[i]) sz--;
		if(sz) nxt[1][i]=stk[sz];
		stk[++sz]=i;
	}
	que.emplace(1);
	while(que.size()){
		int u=que.front(); que.pop();
		if(u>1){
			if(a[u]<a[u-1]){
				int v=u-1;
				while(v){
					if(bef[1][u]>v) break;
					if(d[v]!=1e9) break;
					d[v]=d[u]+1;
					que.emplace(v);
					v=bef[0][v];
				}
			} else{
				int v=u-1;
				while(v){
					if(bef[0][u]>v) break;
					if(d[v]!=1e9) break;
					d[v]=d[u]+1;
					que.emplace(v);
					v=bef[1][v];
				}
			}
		}
		if(u<n){
			if(a[u]<a[u+1]){
				int v=u+1;
				while(v!=n+1){
					if(nxt[1][u]<v) break;
					if(d[v]!=1e9) break;
					d[v]=d[u]+1;
					que.emplace(v);
					v=nxt[0][v];
				}
			} else{
				int v=u+1;
				while(v!=n+1){
					if(nxt[0][u]<v) break;
					if(d[v]!=1e9) break;
					d[v]=d[u]+1;
					que.emplace(v);
					v=nxt[1][v];
				}
			}
		}
	}
	cout<<d[n]<<"\n";
}
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin>>t;
	while(t--) solve();
	return 0;
}