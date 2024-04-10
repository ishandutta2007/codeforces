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
const int N=55;
const ll mod=1e9+7,inf=1e16;
int n,v1[N][N],v2[N][N],tc;
string s[N];
map<vector<int>,int> dp;
map<vector<int>,pair<vector<int>,int>> par;
int Get(vector<int> v){
	if(dp.count(v)) return dp[v];
	int val=0;
	for(int c=1;c<=52;c++){
		vector<int> nv;
		for(int i=1;i<=n;i++){
			if(v[i-1]<v1[i][c]) nv.emplace_back(v1[i][c]);
			else if(v[i-1]<v2[i][c]) nv.emplace_back(v2[i][c]);
			else break;
		}
		if(nv.size()==n){
			int nval=Get(nv)+1;
			if(val<nval){
				val=nval;
				par[v]=make_pair(nv,c);
			}
		}
	}
	dp[v]=val;
	return val;
}
void track(vector<int> v){
	if(!dp[v]) return;
	auto P=par[v];
	if(P.se<=26) cout<<(char)(P.se+'a'-1);
	else cout<<(char)(P.se+'A'-27);
	track(P.fi);
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		for(int j=1;j<=52;j++) v1[i][j]=v2[i][j]=0;
		for(int k=0;k<s[i].size();k++){
			char c=s[i][k];
			int val;
			if('a'<=c&&c<='z'){
				val=c-'a'+1;
			} else{
				val=c-'A'+27;
			}
			if(v1[i][val]) v2[i][val]=k+1;
			else v1[i][val]=k+1;
		}
	}
	vector<int> V;
	for(int i=1;i<=n;i++) V.emplace_back(0);
	dp.clear(); par.clear();
	cout<<Get(V)<<"\n";
	track(V);
	cout<<"\n";
}
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int tc;
	cin>>tc;
	while(tc--) solve();
	return 0;
}