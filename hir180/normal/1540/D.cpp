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
//#define int long long
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
mt19937_64 mt(9);//chrono::steady_clock::now().time_since_epoch().count());
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
#define B 1500
//o(ans?"Yes":"No");
int n,q,b[100005],ty[100005],pos[100005],val[100005],ans[100005];
int info[3*B][3*B];
P que[100005];
vc<int>query[100005];
int lim[2][B+5];

void solve(){
	cin>>n;
	repn(i,n){
		cin>>b[i];
	}
	cin>>q;
	rep(i,q){
		cin>>ty[i]>>pos[i];
		if(ty[i]==1)cin>>val[i];
	}
	for(int beg=0;beg<q;beg+=B){
		vc<int>za{1, n+1};
		
		for(int i=beg;i<beg+B;i++) if(i<q){
			za.pb(pos[i]);
			za.pb(pos[i]+1);
			query[pos[i]].pb(i);
		}
		SORT(za); ERASE(za);
		vc<int>za2 = za;
		for(int i=1;i<za.size();i++){
			if(za[i]-za[i-1] > B){
				int sp = (za[i]-za[i-1]) / B + 1;
				int go = (za[i]-za[i-1]) / sp;
				int now = za[i-1];
				rep(j, sp-1) {
					now += go;
					za2.pb(now);
				}
			}
		}
		SORT(za2);
		za = za2;
		ERASE(za);
		//make info
		for(int i=1;i<za.size();i++){
			int lb = za[i-1], ub = za[i];
			//[lb, ub)
			if(lb+1 == ub) continue;
			info[i-1][0] = INF;
			for(int v=ub-1;v>=lb;v--){
				int beg = lower_bound(info[i-1], info[i-1]+ub-v, b[v])-info[i-1];
				
				for(int ii=ub-v;ii>=beg;ii--){
					if(ii == ub-v){
						info[i-1][ii] = INF;
						continue;
					}
					info[i-1][ii] = b[v]-1;
					if(ii and info[i-1][ii-1] > b[v]) info[i-1][ii] = info[i-1][ii-1]-1;
				}
			}
		}
		//simulation
		for(int i=1;i<za.size();i++){
			int lb = za[i-1], ub = za[i];
			//[lb, ub)
			if(lb+1 == ub){
				vc<P>bb;
				for(auto qq:query[lb]){
					if(ty[qq] == 1){
						bb.eb(qq, val[qq]);
					}
				}
				int idx=0;
				for(int x=beg;x<beg+B and x<q;x++){
					if(idx < bb.size() and bb[idx].a == x) idx ++;
					int realb = (idx<=0?b[lb]:bb[idx-1].b);
					
					if(ty[x] == 2) que[x].a += (que[x].a >= realb);
				}
				idx=0;
				for(auto qq:query[lb]){
					if(ty[qq] == 2){
						while(idx < bb.size() and bb[idx].a < qq) idx ++;
						int realb = (idx<=0?b[lb]:bb[idx-1].b);
						que[qq] = mp(realb, qq);
					}
				}
			}
			else{
				//info[i-1]
				for(int x=beg;x<beg+B and x<q;x++){
					if(ty[x] == 1) continue;
					int p = lower_bound(info[i-1], info[i-1]+ub-lb+1, que[x].a) - info[i-1];
					que[x].a += p;
				}
			}
		}
		
		for(int x=beg;x<beg+B and x<q;x++) ans[x] = n-que[x].a;
		for(int i=beg;i<beg+B;i++) if(i<q and ty[i] == 1){
			b[pos[i]] = val[i];
			query[pos[i]].clear();
		}
	}
	rep(i, q) if(ty[i] == 2){
		o(ans[i]);
	}
}
signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	int t; t = 1; //cin >> t;
	while(t--) solve();
}