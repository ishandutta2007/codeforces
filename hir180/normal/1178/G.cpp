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
mt19937_64 mt(0);//chrono::steady_clock::now().time_since_epoch().count());
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
//
//2018-19 shenyang regional
bool Q = 0;
struct L{
	//slope, y-intercept, last-optimal x
	ll k, m, p;
	bool operator < (const L& l) const{
		return !Q ? k < l.k : p < l.p;
	}
};
struct monotone_CHT{
	vector<L>cht;
	int it = 0;
	ll dv(ll a, ll b){
		assert(b > 0);
		if(a >= 0) return a / b;
		else return -((-a + b - 1) / b);
	}
	void make(L &b, L &c){
		if(b.k == c.k){
			b.p = (b.m > c.m) ? 1e18 : -1e18;
		}
		else{
			b.p = dv(b.m - c.m, c.k - b.k);
		}
	}
	//b.p, b
	bool check(L &a, L &b, L &c){
		make(b, c);
		return a.p >= b.p;
	}
	void add(L nw){
		nw.p = 1e18;
		if(cht.empty()) {
			cht.pb(nw); return ;
		}
		if(cht.back().k == nw.k && cht.back().m >= nw.m) return;
		
		while(cht.size() >= 2 && check(cht[cht.size()-2], cht.back(), nw)) cht.pop_back();
		make(cht.back(), nw); cht.pb(nw);
	}
	ll query(ll a){
		if(cht.empty()) return -1e18;
		//Q = 1;
		//auto it = lower_bound(cht.begin(), cht.end(), (L){0, 0, a}) - cht.begin();
		//Q = 0;
		while(cht[it].p < a) it ++;
		return a * cht[it].k + cht[it].m;
	}
};

const int B = 4004;
int n, q;
vc<int>edge[200005];
int sa[200005], sb[200005];
int in[200005], out[200005], id;
void dfs(int v, int u, int upa, int upb){
	upa += sa[v]; sa[v] = upa;
	upb += sb[v]; sb[v] = upb;
	in[v] = id ++;
	for(auto a:edge[v]){
		if(a == u) continue;
		dfs(a, v, upa, upb);
	}
	out[v] = id - 1;
}
P slp[200005][2];
int lazy[B*2+5], qu[100005][3], ans[100005];
void solve(){
	cin >> n >> q;
	rep(i, n-1){
		int p; cin >> p;
		edge[p].pb(i+2);
	}
	repn(i, n) cin >> sa[i];
	repn(i, n) cin >> sb[i];
	dfs(1, -1, 0, 0);
	repn(i, n) sb[i] = abs(sb[i]);
	repn(i, n){
		{
			slp[in[i]][0] = mp(sb[i], sa[i] * sb[i]);
			slp[in[i]][1] = mp(-sb[i], -sa[i] * sb[i]);
		}
	}
	rep(_, q){
		cin>>qu[_][0];
		if(qu[_][0] == 1) cin >> qu[_][1] >> qu[_][2];
		else cin >> qu[_][1];
	}
	vc<int>p(n);
	rep(i, n) p[i] = i;
	sort(all(p), [&](int a, int b){
		return slp[a][0].a > slp[b][0].a;
	});
	
	for(int L=0;L<q;L+=B){
		int lb = L;
		int ub = L+B-1; if(ub >= q) ub = q-1;
		
		//[lb, ub]
		vc<int>za;
		for(int x=lb;x<=ub;x++){
			za.pb(in[qu[x][1]]);
			za.pb(out[qu[x][1]]+1);
		}
		SORT(za); ERASE(za);
		vc<monotone_CHT>slps(za.size());
		vc<int>bel(n, -1);
		for(int i=1;i<za.size();i++){
			for(int u=za[i-1];u<za[i];u++) bel[u] = i;
		}
		vc<vc<int>>x(za.size(), vc<int>());
		for(int i=1;i<za.size();i++) x[i].resize(za[i] - za[i-1]);
		vc<int>ptr(za.size(), 0);
		for(auto a:p) if(bel[a] >= 1) x[bel[a]][ptr[bel[a]]++] = a;
		
		for(int i=1;i<za.size();i++){
			//za[i-1], za[i]-1
			for(auto a:x[i]) slps[i-1].add({slp[a][1].a, slp[a][1].b, 0LL});
			reverse(all(x[i]));
			for(auto a:x[i]) slps[i-1].add({slp[a][0].a, slp[a][0].b, 0LL});
		}
		memset(lazy, 0, sizeof(lazy));
		
		for(int x=lb;x<=ub;x++){
			if(qu[x][0] == 1){
				int le = in[qu[x][1]], ri = out[qu[x][1]]+1;
				le = POSL(za, le);
				ri = POSL(za, ri) - 1;
				//[le, ri] -> add x
				for(int i=le;i<=ri;i++) lazy[i] += qu[x][2];
			}
			else{
				int le = in[qu[x][1]], ri = out[qu[x][1]]+1;
				le = POSL(za, le);
				ri = POSL(za, ri) - 1;
				ans[x] = -8e18;
				for(int i=le;i<=ri;i++){
					chmax(ans[x], slps[i].query(lazy[i]));
				}
			}
		}
		
		for(int i=1;i<za.size();i++){
			for(int u=za[i-1];u<za[i];u++){
				rep(j,2)slp[u][j].b += slp[u][j].a * lazy[i-1];
			}
		}
	}
	rep(i, q){
		if(qu[i][0] == 2) o(ans[i]);
	}
}
signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	int t; t = 1; //cin >> t;
	while(t--) solve();
}