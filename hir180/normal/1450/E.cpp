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
#include <bitset>
#include <complex>
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
 
 //https://codeforces.com/blog/entry/62393
struct custom_hash {
	static uint64_t splitmix64(uint64_t x) {
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}
 
	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
	
	size_t operator()(pair<int,int> x)const{
		return operator()(uint64_t(x.first)<<32|x.second);
	}
};
//unordered_set -> dtype, null_type
//unordered_map -> dtype(key), dtype(value)
using namespace __gnu_pbds;
template<class t,class u>
using hash_table=gp_hash_table<t,u,custom_hash>;

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
int n, m, col[205];
vc<P>edge[205];
void dfs(int v, int c){
	col[v] = c;
	for(auto a:edge[v]) if(col[a.a] == -1) dfs(a.a, c^1);
}
int dist[205][205];
void solve(){
	cin>>n>>m;
	vc<P1>e;
	rep(i, m){
		int a, b, c; cin >> a >> b >> c ;
		edge[a].eb(b, c);
		edge[b].eb(a, c);
		e.pb(mp(c, mp(a, b)));
	}
	memset(col, -1, sizeof(col));
	dfs(1, 0);
	repn(i,n)for(auto a:edge[i]) if(col[i] == col[a.a]){
		o("NO"); return;
	}
	rep(i, 205) rep(j, 205) if(i != j) dist[i][j] = INF;
	for(auto a:e){
		if(a.a == 1){
			if(col[a.b.a] == 0){
				dist[a.b.a][a.b.b] = 0;
				dist[a.b.b][a.b.a] = 0;
			}
			else{
				dist[a.b.a][a.b.b] = 1;
				dist[a.b.b][a.b.a] = -1;
			}
		}
		else{
			if(col[a.b.a] == 0){
				dist[a.b.a][a.b.b] = 0;
				dist[a.b.b][a.b.a] = 1;
			}
			else{
				dist[a.b.a][a.b.b] = 1;
				dist[a.b.b][a.b.a] = 0;
			}
		}
	}
	repn(k,n)repn(i,n)repn(j,n)chmin(dist[i][j],dist[i][k]+dist[k][j]);
	repn(k,n)repn(i,n)repn(j,n){
		if(dist[i][j] > dist[i][k]+dist[k][j]){
			o("NO");
			return;
		}
	}
	
	vc<int>ans(n+1), ret;
	int zan = -1;
	repn(k, n){
		repn(i,n)ans[i]=dist[k][i]*2+col[i];
		bool bad = 0;
		for(auto x:e){
			int v = ans[x.b.a], u = ans[x.b.b];
			if(x.a == 1){
				if(v+1 != u) bad = 1;
			}
			else if(abs(v-u) != 1) bad = 1;
		}
		if(bad == 1) continue;
		int mn = INF;
		repn(i,n)chmin(mn,ans[i]);
		repn(i,n)ans[i]-=mn;
		mn=-INF;
		repn(i,n)chmax(mn,ans[i]);
		if(zan < mn){
			zan = mn;
			ret = ans;
		}
	}
	if(zan == -1){
		o("NO"); return;
	}
	o("YES");
	o(zan); repn(i,n) cout<<ret[i]<<" "; cout<<endl;
	
}
signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	int t; t=1;//cin >> t;
	while(t--) solve();
}