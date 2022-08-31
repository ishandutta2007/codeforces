//Let's join Kaede Takagaki Fan Club !!
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//#define int long long
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define a first
#define b second
#define fi first
#define sc second
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
#define all(x) x.begin(),x.end()
#define si(x) int(x.size())

#ifdef LOCAL
#define dmp(x) cerr<<__LINE__<<" "<<#x<<" "<<x<<endl
#else
#define dmp(x) void(0)
#endif

template<class t,class u> bool chmax(t&a,u b){if(a<b){a=b;return true;}else return false;}
template<class t,class u> bool chmin(t&a,u b){if(b<a){a=b;return true;}else return false;}

template<class t> using vc=vector<t>;

template<class t,class u>
ostream& operator<<(ostream& os,const pair<t,u>& p){
	return os<<"{"<<p.fi<<","<<p.sc<<"}";
}

template<class t> ostream& operator<<(ostream& os,const vc<t>& v){
	os<<"{";
	for(auto e:v)os<<e<<",";
	return os<<"}";
}

template<class T>
void g(T &a){
	cin >> a;
}
template<class T>
void o(const T &a,bool space=false){
	cout << a << (space?' ':'\n');
}
//ios::sync_with_stdio(false);
const ll mod = 998244353;
mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());
template<class T>
void add(T&a,T b){
	a+=b;
	if(a >= mod) a-=mod;
}
ll modpow(ll x,ll n){
	ll res=1;
	while(n>0){
		if(n&1) res=res*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return res;
}
pair<vc<int>, vc<int>>find(vc<int>vec){
	int sum = 0;
	for(auto at:vec) sum += at;
	if(sum&1) return mp(vc<int>(), vc<int>());
	vc<bool>dp(sum/2+1, 0);
	dp[0] = 1;
	vc<int>in(sum/2+1, INF);
	in[0] = 0;
	rep(i, vec.size()){
		for(int j=sum/2-vec[i];j>=0;j--){
			if(!dp[j+vec[i]] && dp[j]){
				dp[j+vec[i]] = 1;
				in[j+vec[i]] = i;
			}
		}
	}
	if(in[sum/2] == INF) return mp(vc<int>(), vc<int>());
	vc<bool>use(vec.size(), 0);
	ll z = sum/2;
	while(z){
		int t = in[z];
		assert(!use[t]);
		use[t] = 1;
		z -= vec[t];
		assert(z >= 0);
	}
	vc<int>x, y;
	rep(i, vec.size()){
		if(use[i]) x.pb(vec[i]);
		else y.pb(vec[i]);
	}
	return mp(x, y);
}
void solve(){
	int n, m; cin >> n;
	vc<int>a(n); rep(i, n) cin >> a[i];
	cin >> m;
	vc<int>b(m); rep(i, m) cin >> b[i];
	if(n != m){
		cout << "No" << endl;
		return;
	}
	auto X = find(a);
	auto Y = find(b);
	if(X.a.empty() || Y.a.empty()){
		cout << "No" << endl;
		return;
	}
	if((X.a).size() > (X.b).size()) swap(X.a, X.b);
	if((Y.a).size() < (Y.b).size()) swap(Y.a, Y.b);
	SORT(X.a); reverse(all(X.a));
	SORT(X.b); reverse(all(X.b));
	SORT(Y.a);
	SORT(Y.b);
	cout << "Yes" << endl;
	vc<P>go(2*n);
	rep(i, (X.a).size()) go[i*2] = mp((X.a)[i], 0);
	rep(i, (X.b).size()) go[(i+(X.a).size())*2] = mp(-(X.b)[i], 0);
	rep(i, (Y.a).size()) go[i*2+1] = mp(0, (Y.a)[i]);
	rep(i, (Y.b).size()) go[(i+(Y.a).size())*2+1] = mp(0, -(Y.b)[i]);
	int zx = 0, zy = 0;
	rep(i, 2*n){
		zx += go[i].a;
		zy += go[i].b;
		cout << zx << " " << zy << '\n';
	}
	assert(zx == 0 && zy == 0);
	return;
}
signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	int t; cin >> t;
	while(t--) solve();
}