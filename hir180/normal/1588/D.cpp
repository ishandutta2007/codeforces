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

int go[1024][52][52];
int dp[1024][52];
int pre[1024][52];
int cvt(char c){
	if('a' <= c and c <= 'z') return c - 'a';
	return c - 'A' + 26;
}
void solve(){
	int n; cin >> n;
	vc<string>v(n); rep(i, n) cin >> v[i];
	
	vc<vc<P>>pos(n, vc<P>(52, P(-1, -1)));
	rep(i, n){
		rep(j, v[i].size()){
			int k = cvt(v[i][j]);
			if(pos[i][k].a == -1) pos[i][k].a = j;
			else pos[i][k].b = j;
		}
	}
	memset(go, -1, sizeof(go));
	vc<P1>info;
	rep(mask, (1<<n)){
		rep(c, 52){
			int bad = 0;
			vc<int>cur(n);
			rep(i, n){
				if(((mask>>i)&1)) {
					if(pos[i][c].b == -1) bad = 1;
					else cur[i] = pos[i][c].b;
				}
				else {
					if(pos[i][c].a == -1) bad = 1;
					else cur[i] = pos[i][c].a;
				}
			}
			if(bad) continue;
			int sum = 0;
			rep(i, n) sum += cur[i];
			info.eb(sum, mp(mask, c));
			rep(nxt, 52){
				int nmask = 0;
				rep(i, n){
					if(pos[i][nxt].a >= 0 and cur[i] < pos[i][nxt].a);
					else if(pos[i][nxt].b >= 0 and cur[i] < pos[i][nxt].b){
						nmask ^= (1<<i);
					}
					else{
						nmask = -1;
						break;
					}
				}
				go[mask][c][nxt] = nmask;
			}
		}
	}
	SORT(info);
	reverse(all(info));
	int ans = 0;
	rep(i, 1024) rep(j, 52) dp[i][j] = -INF;
	for(auto xx:info){
		int mask = xx.b.a, now = xx.b.b;
		//calc dp[mask][now]
		dp[mask][now] = 1;
		rep(i, 52){
			if(go[mask][now][i] == -1) continue;
			if(dp[mask][now] < dp[go[mask][now][i]][i] + 1){
				dp[mask][now] = dp[go[mask][now][i]][i] + 1;
				pre[mask][now] = i;
			}
		}
	}
	rep(i, 1024) rep(j, 52) chmax(ans, dp[i][j]);
	o(ans);
	rep(i, 1024) rep(j, 52){
		if(ans == dp[i][j]){
			string res = "";
			res.pb((j<26?'a'+j:'A'+(j-26)));
			int x = i, y = j;
			while(dp[x][y] > 1){
				int p = pre[x][y];
				x = go[x][y][p];
				y = p;
				res.pb((y<26?'a'+y:'A'+(y-26)));
			}
			//reverse(all(res));
			o(res);
			return;
		}
	}
	cout<<endl;
}
signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	int t; cin >> t;
	while(t--) solve();
}