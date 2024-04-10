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
int dp[505][505], dpall[505][505], n, m, a[1000005], ran[505], rev[505];
int mn[505], mx[505], nxtdif[1000005];
vc<int>pos[505];
void solve(){
	cin>>n>>m;
	repn(i,m)cin>>a[i];
	repn(i,n){
		mn[i] = INF;
		mx[i] = 0;
	}
	repn(i,m) {
		chmin(mn[a[i]], i);
		chmax(mx[a[i]], i);
		pos[a[i]].pb(i);
	}
	repn(i,n) rev[i] = i;
	sort(rev+1, rev+n+1, [](int a, int b){
		return mn[a] < mn[b];
	});
	repn(i, n) ran[rev[i]] = i;
	nxtdif[m] = m+1;
	for(int i=m-1;i>=1;i--){
		if(a[i] != a[i+1]) nxtdif[i] = i+1;
		else nxtdif[i] = nxtdif[i+1];
	}
	//repn(i, m) cout << nxtdif[i] << endl;
	for(int i=1;i<505;i++){
		dp[i][i-1] = 1;
		dpall[i][i-1] = 1;
	}
	for(int len=1;len<=n;len++){
		//dpall
		for(int i=1;i+len-1<=n;i++){
			//ran: [i, i+len-1]
			int cut=INF;
			rep(j,len) chmin(cut,rev[i+j]);
			//
			int lb = INF, ub = 0, sum = 0;
			rep(j, len){
				chmin(lb, mn[rev[i+j]]);
				chmax(ub, mx[rev[i+j]]);
				sum += pos[rev[i+j]].size();
			}
			if(sum != ub-lb+1) continue;
			int mul = 1;
			bool fail = 0;
			bool used[505] = {};
			used[ran[cut]] =1;
			while(lb <= ub){
				if(a[lb] == cut){
					lb = nxtdif[lb];
				}
				else{
					int nxtcut = POSL(pos[cut], lb), en;
					if(nxtcut == pos[cut].size()) en = ub+1;
					else en = pos[cut][nxtcut];
					//[lb, en)
					int sm = ran[a[lb]];
					int bg = sm;
					while(bg <= i+len-1 and mn[rev[bg]] < en) bg ++;
					bg --;
					for(int i=sm;i<=bg;i++){
						if(used[i]){fail = 1; break;} else used[i] = 1;
					}
					if(fail) break;
					mul = mul * dp[sm][bg] % mod;
					if(en <= ub) {
						assert(a[en] == cut);
						lb = nxtdif[en];
					}
					else break;
				}
			}
			for(int a=i;a<=i+len-1;a++) if(used[a] == false) fail = 1;
			rep(ii, 505) if(!(i<=ii and ii<=i+len-1)){
				assert(!used[ii]);
			}
			if(fail) continue;
			dpall[i][i+len-1] = mul;
		}
		//dp
		for(int i=1;i+len-1<=n;i++){
			//[i, i+len-1]
			int cut=INF;
			rep(j,len) chmin(cut,rev[i+j]);
			//
			int lb = INF, ub = 0, sum = 0, aval = 0;
			rep(j, len){
				chmin(lb, mn[rev[i+j]]);
				chmax(ub, mx[rev[i+j]]);
				sum += pos[rev[i+j]].size();
				if(sum == ub-lb+1){
					//[i, i+j] -> ok
					add(aval, dpall[i][i+j] * dp[i+j+1][i+len-1] % mod);
				}
			}
			if(sum != ub-lb+1) continue;
			dp[i][i+len-1] = aval;
		}
	}
	o(dp[1][n]);
}
signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	int t; t = 1; //cin >> t;
	while(t--) solve();
}