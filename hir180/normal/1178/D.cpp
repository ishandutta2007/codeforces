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
bool pr[10005];
bool dp[1005][2005];
P pre[1005][2005];
void solve(){
	pr[1] = 1;
	for(int i=2;i<10005;i++){
		if(pr[i]) continue;
		for(int j=i+i;j<10005;j+=i) pr[j]= 1;
	}
	dp[0][0] = 1;
	for(int v=2;v<105;v++){
		//if(pr[v]) continue;
		//v+1 & v+1
		//v+1 & v+1 c 2
		rep(x, 1004-(v+1)){
			for(int j=0;j<2005;j++){
				if(j+v+1 >= 2005) break;
				dp[x+v+1][j+v+1] |= dp[x][j];
				if(dp[x][j]){
					pre[x+v+1][j+v+1] = mp(x, j);
				}
			}
			if(pr[v]) continue;
			for(int j=0;j<2005;j++){
				if(j+(v+1)*v/2 >= 2005) break;
				dp[x+v+1][j+(v+1)*v/2] |= dp[x][j];
				if(dp[x][j]){
					pre[x+v+1][j+(v+1)*v/2] = mp(x, j);
				}
			}
			if(v == 3) {
				for(int j=0;j<2000;j++){
					dp[x+4][j+5] |= dp[x][j];
					if(dp[x][j]){
						pre[x+4][j+5] = mp(x, j);
					}
				}
			}
			if(v == 5) {
				for(int j=0;j<1998;j++){
					dp[x+6][j+7] |= dp[x][j];
					if(dp[x][j]){
						pre[x+6][j+7] = mp(x, j);
					}
				}
			}
		}
	}
	int n; cin >> n;
	{
		int i = n;
		for(int j=2;j<2005;j++){
			if(dp[i][j] and !pr[j]){
				cout << j << endl;
				while(mp(i, j) != mp(0LL, 0LL)){
					int ni = pre[i][j].a, nj = pre[i][j].b;
					if(i-ni == 4 and j-nj == 5){
						for(int x=i-3;x<=i-1;x++) cout<<x<<" "<<x+1<<endl;
						cout<<i<<" "<<i-3<<endl;
						cout<<i-3<<" "<<i-1<<endl;
						i = ni, j = nj;
					}
					else if(i-ni == 6 and j-nj == 7){
						for(int x=i-5;x<=i-1;x++) cout<<x<<" "<<x+1<<endl;
						cout<<i<<" "<<i-5<<endl;
						cout<<i-3<<" "<<i-1<<endl;
						i = ni, j = nj;
					}
					else if(i-ni == j-nj){
						for(int x=ni+1;x<i;x++) cout<<x<<" "<<x+1<<endl;
						cout<<i<<" "<<ni+1<<endl;
						i = ni, j = nj;
					}
					else{
						for(int x=ni+1;x<i;x++){
							for(int y=x+1;y<=i;y++) cout<<x<<" "<<y<<endl;
						}
						i = ni, j = nj;
					}
				}
				return ;
			}
		}
	}
}
signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	int t; t = 1; //cin >> t;
	while(t--) solve();
}