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
//#define rng(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
#define all(x) x.begin(),x.end()
#define si(x) int(x.size())
#define pcnt(x) __builtin_popcountll(x)

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
	//don't make x negative!
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
//o(ans?"Yes":"No");
string str;
string base = "LRDU";
short n, rui[20005][4], col[20005];
short inter_rui[20005];

void solve(){
	cin >> str;
	n = str.size();
	rep(i, n){
		rep(j, 4) rui[i+1][j] = rui[i][j];
		rep(j, 4) if(str[i] == base[j]) rui[i+1][j] ++;
	}
	int ans = 0;
	rep(beg, n){
		int now = 1;
		int C = -1, nxt = -1;
		for(int i=beg;i<n;i++){
			if(base[now] != str[i]){
				if(now){
					if(str[i] == 'U' or str[i] == 'L') break;
					else if(str[i] == 'D'){
						int pos = i;
						for(int j=i+1;j<n;j++) {
							if(str[j] == 'L') pos = j;
							else break;
						}
						int pos2 = INF;
						for(int j=pos+1;j<n;j++) {
							if(str[j] == 'U') {
								pos2 = j;
								break;
							}
						}
						if(pos2 == INF) break;
						C = pos2-pos;
						nxt = i;
						break;
					}
				}
				else{
					int pos;
					for(int j=i;j<n;j++){
						if(str[j] == 'U'){
							pos = j;
							break;
						}
					}
					C = pos-i+1;
					nxt = i;
					break;
				}
			}
			now ^= 1;
			if(now) ans ++;
		}
		if(C == -1) continue;
		inter_rui[beg] = 0;
		short idx = 0;
		for(int x=beg;x<n;x++){
			col[x] = idx++;
			if(idx == C) idx = 0;
		}
		for(int x=beg;x<n;x++){
			inter_rui[x+1] = 0;
			if(x > beg+C and col[x]){
				if(str[x] == 'U' and str[x-C-1] == 'R') inter_rui[x+1] ++;
				if(str[x] == 'L' and str[x-C-1] == 'D') inter_rui[x+1] ++;
			}
			if(x >= beg+C and col[x+1]){
				if(str[x] == 'R' and str[x-C+1] == 'D') inter_rui[x+1] ++;
				if(str[x] == 'U' and str[x-C+1] == 'L') inter_rui[x+1] ++;
			}
			if(x >= beg+2 and col[x] > 1){
				if(str[x-2] == 'R' and str[x] == 'L') inter_rui[x+1] ++;
			}
			if(x >= beg+C+C){
				if(str[x-C-C] == 'D' and str[x] == 'U') inter_rui[x+1] ++;
			}
			inter_rui[x+1] += inter_rui[x];
		}
		//non-trivial
		for(int j=beg;j+C-1<n;j+=C){
			//add [j, j+C)
			if(j == beg){
				if(rui[j+C][3] != rui[j][3]){
					//fail
					break;
				}
			}
			if(str[j] == 'L' or str[j+C-1] == 'R') break;
			if(inter_rui[j+C] != inter_rui[j]) break;
			
			if(rui[j+C][2] == rui[j][2] and j+C-1 >= nxt) {
				ans ++;
			}
		}
	}
	o(ans);
}
signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	int t; t = 1; //cin >> t;
	while(t--) solve();
}