#pragma GCC optimize("O3")
//#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma")
#include <bits/stdc++.h>
//#include <bits/extc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/priority_queue.hpp>
#define fi first
#define se second
using namespace std;
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
const int N=3e5+5;
const ll mod=1e9+7,inf=1e16;
int n,m,tc;
ll a[N],s[N],b[N];
ll ans;
set<int> S[N];
struct SEG{
	pii T[2*N];
	pii mrg(pii A,pii B){
		return pii(min(A.fi,B.fi),max(A.se,B.se));
	}
	void init(int nd,int l,int r){
		if(l==r){
			if(l%2) T[nd]=pii(s[l],-1e9);
			else T[nd]=pii(1e9,s[l]);
			return;
		}
		int m=(l+r)>>1;
		init(nd+1,l,m); init(nd+2*(m-l+1),m+1,r);
		T[nd]=mrg(T[nd+1],T[nd+2*(m-l+1)]);
	}
	pii qry(int nd,int l,int r,int s,int e){
		if(r<s||e<l) return pii(1e9,-1e9);
		if(s<=l&&r<=e) return T[nd];
		int m=(l+r)>>1;
		return mrg(qry(nd+1,l,m,s,e),qry(nd+2*(m-l+1),m+1,r,s,e));
	}
}T;
void solve(){
	cin>>n;
	s[0]=0; b[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i%2) s[i]=s[i-1]+a[i];
		else s[i]=s[i-1]-a[i];
		b[i]=s[i];
	}
	sort(b,b+1+n); m=unique(b,b+1+n)-b;
	for(int i=0;i<=m+1;i++) S[i].clear();
	for(int i=0;i<=n;i++) s[i]=lower_bound(b,b+1+m,s[i])-b;
	T.init(1,1,n);
	ans=0;
	for(int l=n;l>=1;l--){
		// S_{l-1} = S_{r}
		// for l <= i < r, 
		// if i even: S_i <= S_{l-1}
		// if i odd: S_{l-1} <= S_i
		S[s[l]].emplace(l);
		while(S[s[l-1]].size()){
			auto iter=S[s[l-1]].end(); iter--;
			int r=*iter;
			pii Q=T.qry(1,1,n,l,r);
			if(s[l-1]>Q.fi||s[l-1]<Q.se) S[s[l-1]].erase(iter);
			else break;
		}
		ans+=S[s[l-1]].size();
	}
	cout<<ans<<"\n";
}
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	cin>>tc;
	while(tc--) solve();
	return 0;
}