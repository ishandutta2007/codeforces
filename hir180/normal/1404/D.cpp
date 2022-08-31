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

void solve(){
	int n;cin >> n;
	if(n%2 == 1){
		cout << "Second" << endl;
		vc<vc<int>>ls(n);
		vc<vc<P>>go(n+1, vc<P>());
		for(int i=0;i<2*n;i++){
			int num;cin>>num;
			ls[num-1].pb(i+1);
		}
		vc<int>sel;
		vc<int>vis(n);
		rep(i, n){
			int x = ls[i][0];
			int y = ls[i][1];
			if(x%n == y%n){
				sel.pb(x);
				vis[x%n] = 1;
			}
			else{
				go[x%n].eb(y%n, i);
				go[y%n].eb(x%n, i);
			}
		}
		rep(i, n){
			if(vis[i]) continue;
			int zan = i;
			int pre = -1;
			while(1){
				for(auto to:go[zan]){
					int nxt = to.a;
					int id = to.b;
					if(vis[nxt]) continue;
					pre = id;
					rep(k, 2) if(ls[id][k]%n == zan){
						sel.pb(ls[id][k]);
					}
					vis[zan] = 1;
					zan = nxt;
					goto fut;
				}
				for(auto to:go[zan]){
					if(to.a == i and to.b != pre){
						rep(k, 2) if(ls[to.b][k]%n == zan){
							sel.pb(ls[to.b][k]);
						}
					}
				}
				break; fut:;
			}
		}
		//cout<<sel<<endl;
		assert(sel.size() == n);
		set<int>S;
		for(auto a:sel) S.insert(a%n);
		assert(S.size() == n);
		S.clear();
		for(auto a:sel) S.insert(a);
		
		int sum = 0;
		for(auto a:sel) sum += a;
		if(sum%2 == 1){
			rep(i, n){
				if(S.find(ls[i][0]) == S.end()){
					cout << ls[i][0] << (i==n-1?'\n':' ');
				}
				else{
					cout << ls[i][1] << (i==n-1?'\n':' ');
				}
			}
			cout.flush();
		}
		else{
			//cerr<<"OK"<<endl;
			rep(i, n) cout<<sel[i]<<(i==n-1?'\n':' ');
			cout.flush();
		}
		int x; cin >> x;
		return;
	}
	else{
		cout << "First" << endl;
		for(int i=1;i<=n;i++) cout<<i<<" ";
		for(int i=1;i<=n-1;i++) cout<<i<<" ";
		cout << n << endl;
		int x; cin >> x;
		return;
	}
}
signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	int t; t = 1; //cin >> t;
	while(t--) solve();
}