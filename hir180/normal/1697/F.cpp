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
struct SAT{
	#define maxv 2000050
	int N;
	vector<int>edge[maxv*2];
	vector<int>redge[maxv*2];
	
	SAT(){
		N = 1;
		add_edge(0, 1);
	}
	void init(int sz=maxv){
		rep(i, sz*2){
			edge[i].clear();
			redge[i].clear();
		}
		N = 1;
		add_edge(0, 1);
		//0 -> false
		//1 -> true
	}
	
	int new_var(){
		assert(N < maxv);
		N++;
		return N*2-2;
	}
	
	int rev(int a){ return (a^1); }
	
	//u -> v 
	void add_edge(int u,int v){
		if(u<0||v<0) return;
		edge[u].pb(v);
		edge[rev(v)].pb(rev(u));
		redge[v].pb(u);
		redge[rev(u)].pb(rev(v));
	}
	
	void make_true(int u){
		add_edge(1, u);
	}
	void make_false(int u){
		add_edge(u, 0);
	}
	//uvtrue
	void make_or(int u,int v){
		add_edge(rev(u), v);
	}
	
	//uvtrue
	void make_only(int u,int v){
		add_edge(u,rev(v));
		return make_or(u,v);
	}
	
	
	int make_and_ret(int u,int v){
		if(u<0) return v;
		if(v<0) return u;
		int ret = new_var();
		add_edge(ret,u);
		add_edge(ret,v);
		return ret;
	}
	
	//uvtruetrue
	int make_or_ret(int u,int v){
		if(u<0) return v;
		if(v<0) return u;
		int ret = new_var();
		add_edge(u,ret);
		add_edge(v,ret);
		return ret;
	}
	
	//uvtrue + make_or_ret
	int make_only_ret(int u,int v){
		if(u<0) return v;
		if(v<0) return u;
		add_edge(u,rev(v));
		return make_or_ret(u,v);
	}
	
	//
	//scc
	vector<int>used, vert, comp;
	int id;
	void dfs(int v){
		if(used[v]) return;
		used[v] = 1;
		for(int i=0;i<edge[v].size();i++){
			if(!used[edge[v][i]]){
				dfs(edge[v][i]);
			}
		}
		vert[id++] = v;
	}
	void sfd(int v){
		if(used[v]) return;
		used[v] = 1; comp[v] = id;
		for(int i=0;i<redge[v].size();i++){
			if(!used[redge[v][i]]){
				sfd(redge[v][i]);
			}
		}
	}
	vector<int>ans;
	bool solve(){
		used.clear();
		vert.clear();
		comp.clear();
		used.resize(N*2+2, 0);
		vert.resize(N*2+2, 0);
		comp.resize(N*2+2, 0);
		id = 0;
		for(int i=0;i<N*2+2;i++){
			if(!used[i]){
				dfs(i);
			}
		}
		fill(used.begin(),used.end(),0);
		id = 0;
		for(int i=N*2+2-1;i>=0;i--){
			if(!used[vert[i]]){
				sfd(vert[i]);
				id++;
			}
		}
		ans.clear();
		ans.resize(N*2+2,0);
		for(int i=0;i<N+1;i++){
			if(comp[i*2] == comp[i*2+1]){
				return false;
			}
			if(comp[i*2] > comp[i*2+1]){
				ans[i*2] = 1;
			}
			else{
				ans[i*2+1] = 1;
			}
		}
		return true;
	}
}solver;

void solve(){
	int n, m, k;
	cin >> n >> m >> k;
	vc<vc<int>>up(n+1, vc<int>(k+1, 0));
	vc<vc<int>>dw(n+1, vc<int>(k+1, 0));
	solver.init(3*n*k+m+5);
	repn(i, n){
		repn(j, k){
			up[i][j] = solver.new_var();
			dw[i][j] = solver.new_var();
		}
		solver.make_true(up[i][1]);
		solver.make_true(dw[i][k]);
		
		repn(j, k-1){
			//up[i][j+1] -> up[i][j]
			solver.add_edge(up[i][j+1], up[i][j]);
			//dw[i][j] -> dw[i][j+1]
			solver.add_edge(dw[i][j], dw[i][j+1]);
			//up[i][j+1] <-> dw[i][j]
			solver.make_only(up[i][j+1], dw[i][j]);
		}
		if(i > 1){
			repn(j, k){
				//up[i-1][j] -> up[i][j]
				solver.add_edge(up[i-1][j], up[i][j]);
			}
		}
	}
	//return;
	repn(i, m){
		int id; cin >> id;
		if(id == 1){
			int pos, num; cin >> pos >> num;
			//up[pos][num] <-> dw[pos][num]
			solver.make_only(up[pos][num], dw[pos][num]);
		}
		else if(id == 2){
			int pos0, pos1, x; cin >> pos0 >> pos1 >> x;
			repn(i, k){
				//up[pos0][i] -> dw[pos1][min(k, x-i)]
				//if x-i <= 0 -> up[pos0][i] -> dum
				if(x-i <= 0) solver.make_false(up[pos0][i]);
				else solver.add_edge(up[pos0][i], dw[pos1][min(k, x-i)]);
			}
		}
		else{
			int pos0, pos1, x; cin >> pos0 >> pos1 >> x;
			repn(i, k){
				//dw[pos0][i] -> up[pos1][max(1, x-i)]
				//if x-i > k -> dw[pos0][i] -> dum
				if(x-i > k) solver.make_false(dw[pos0][i]);
				else solver.add_edge(dw[pos0][i], up[pos1][max(1LL, x-i)]);
			}
		}
	}
	
	//return;
	auto flag = solver.solve();
	if(!flag) o(-1);
	else{
		repn(i, n){
			int va = 0;
			int ok = 0;
			repn(j, k){
				int id0 = up[i][j];
				int id1 = dw[i][j];
				if(solver.ans[id0] and solver.ans[id1]){
					ok ++;
					va = j;
				}
			}
			assert(ok == 1);
			cout << va << (i==n?'\n':' ');
		}
	}
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	int t; cin >> t;
	while(t--) solve();
}