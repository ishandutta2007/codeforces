//Let's join Kaede Takagaki Fan Club !!
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <iomanip>
#include <chrono>
#include <random>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
#define int long long
//#define L __int128
typedef long long ll;
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
#define rng(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
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
//const ll mod = 1000000007;
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
#define _sz 1
ll F[_sz],R[_sz];
void make(){
	F[0] = 1;
	for(int i=1;i<_sz;i++) F[i] = F[i-1]*i%mod;
	R[_sz-1] = modpow(F[_sz-1], mod-2);
	for(int i=_sz-2;i>=0;i--) R[i] = R[i+1] * (i+1) % mod;
}
ll C(int a,int b){
	if(b < 0 || a < b) return 0;
	return F[a]*R[b]%mod*R[a-b]%mod;
}
string ord = "ATGC";
pair<int, vc<string>>opt(vc<string>f){
	int n = f.size(), m = f[0].size();
	vc<int>p({0, 1, 2, 3});
	pair<int, vc<string>>ret = mp(INF, vc<string>());
	
	do{
		if(p[0] > p[1] or p[2] > p[3]) continue;
		int bad = 0;
		vc<string>tmp;
		rep(i, n){
			char x = ord[(i%2==0?p[0]:p[2])];
			char y = ord[(i%2==0?p[1]:p[3])];
			int t1 = 0, t2 = 0;
			//xyxyxy
			rep(j, m) if(f[i][j] != (j%2==0?x:y)) t1++;
			//yxyxyx
			rep(j, m) if(f[i][j] != (j%2==0?y:x)) t2++;
			
			bad += min(t1, t2);
			if(t1 <= t2) {
				string s; rep(j, m) s.pb((j%2==0?x:y));
				tmp.pb(s);
			}
			else{
				string s; rep(j, m) s.pb((j%2==1?x:y));
				tmp.pb(s);
			}
		}
		if(ret > mp(bad, tmp)) ret = mp(bad, tmp);
	}while(next_permutation(all(p)));
	return ret;
}
void solve(){
	int n, m; cin >> n >> m;
	vc<string>f(n);
	rep(i, n) cin >> f[i];
	auto x = opt(f);
	vc<string>g(m, string(n, 'a'));
	rep(i, n) rep(j, m) g[j][i] = f[i][j];
	auto y = opt(g);
	vc<string>h(n, string(m, 'a'));
	rep(i, n) rep(j, m) h[i][j] = (y.b)[j][i];
	
	//cerr<<x<<" "<<y<<endl;
	if(x.a <= y.a) {
		for(auto a:x.b) o(a);
	}
	else{
		for(auto a:h) o(a);
	}
	return;
}
signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	int t; t = 1; //cin >> t;
	while(t--) solve();
}