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
//e -> (cost, (u, v)) any graph will do
//G -> (u, v) ... u is parent of v, they'll be united when cost = cs[u]
//cs[root] may be INF, when graph e isn't connect
struct merge_tree{
	
	vc<pair<int, P>>e;
	vc<P>G;
	int n, nxt, root;
	vc<int>zan, cs;
	vc<int>par, ran;
	merge_tree(){}
	
	int find(int x){ if(x == par[x]) return x; else return par[x] = find(par[x]); }
	void unite(int x, int y){
		x = find(x), y = find(y);
		if(x == y) return;
		if(ran[x] < ran[y]){
			par[x] = y;
			zan[y] = nxt++;
		}
		else{
			par[y] = x;
			zan[x] = nxt++;
			if(ran[x] == ran[y]) ran[x] ++;
		}
	}
	bool same(int x, int y){ return find(x) == find(y); }
	
	
	//1-indexed
	merge_tree(vc<pair<int, P>>vec, int x = 0){
		e = vec;
		nxt = 0;
      //connected -> it's ok to set n = 0
      //not connected -> n must be the "true" number of verticies
      	n = x;
		for(auto a:vec){
			chmax(n, a.b.a);
			chmax(n, a.b.b);
		}
		zan.assign(n+1, 0);
		cs.assign(2*n, INF+5);
		par.assign(n+1, 0); rep(i, n+1) par[i] = i;
		ran.assign(n+1, 0);
		
		map<ll, vc<P>>MM;
		rep(i, vec.size()){
			MM[vec[i].a].pb(vec[i].b);
		}
		repn(i, n) zan[i] = i;
		repn(i, n) cs[i] = -1;
		nxt = n+1;
		
		for(auto mm:MM){
			auto x = mm.b;
			vc<int>cmp;
			map<int,int>M;
			
			for(auto a:x){
				int u = a.a, v = a.b;
				if(this->same(u,v)) continue;
				
				cmp.pb(zan[find(u)]);
				M[cmp.back()] = u;
				cmp.pb(zan[find(v)]);
				M[cmp.back()] = v;
			}
			SORT(cmp); ERASE(cmp);
			for(auto a:x){
				int u = a.a;
				int v = a.b;
				this->unite(u, v);
			}
			for(auto a:cmp){
				int k = M[a];
				k = zan[find(k)];
				G.eb(k, a);
				cs[k] = mm.a;
			}
		}
		
		vc<int>top;
		repn(i, n) top.pb(zan[find(i)]);
		SORT(top); ERASE(top);
		
		if(top.size() > 1){
			for(auto x:top){
				G.eb(nxt, x);
			}
			nxt ++;
		}
		
		root = nxt-1;
	}
};
int cs[600005];
vc<int>edge[600005];
int root;

#define SZ 600005
int up[20][SZ],dep[SZ],in[SZ],rev[SZ],id;
struct dbling{
	bool ready = 0;
	void dfs(int v,int u,int d){
		up[0][v] = u; dep[v] = d; in[v] = id; rev[id] = v; id ++;
		rep(i,edge[v].size()){
			if(edge[v][i] == u) continue;
			dfs(edge[v][i], v, d+1);
		}
	}
	void prepare(){
	    dfs(root,-1,0);
		rep(j,19){
			rep(i,SZ){
				if(up[j][i] == -1) up[j+1][i] = up[j][i];
				else up[j+1][i] = up[j][up[j][i]];
			}
		}
		ready = 1;
	}
	int get(int a,int b){
		if(dep[a] > dep[b]) swap(a,b);
		int D = dep[b]-dep[a];
		rep(i,20){
			if(((D>>i)&1)) b = up[i][b];
		}
		if(a == b) return a;
		for(int i=19;i>=0;i--){
			if(up[i][a] != up[i][b]){
				a = up[i][a];
				b = up[i][b];
			}
		}
		return up[0][a];
	}
	int dist(int a,int b){
		int c = get(a,b);
		return dep[a]+dep[b]-2*dep[c];
	}
	int dist(int a,int b,int c){
		//assuming c is lca of (a,b)
		return dep[a]+dep[b]-2*dep[c];
	}
	int go_up(int v,int a){
	    if(dep[v] < a) return -1;
	    rep(i,20) if(((a>>i)&1)) v = up[i][v];
	    return v;
	}
	//a ---- b
	//x (1-indexed)
	//-1
	//verified : opencup Warsaw I
	int v_on_path(int a,int b,int x){
		int c = get(a,b);
		int d = dist(a,b,c);
		if(x <= 0 || x > d+1) return -1;
		if(x <= dep[a]-dep[c]+1){
			return go_up(a, x-1);
		}
		else{
			x = d+2-x;
			return go_up(b, x-1);
		}
	}
	vc<int>get_path(int a, int b){
		int upp = get(a, b);
		int cur;
		vc<int>ret;
		
		cur = a;
		while(1){
			ret.pb(cur);
			if(cur == upp) break;
			cur = up[0][cur];
		}
		vc<int>ret2;
		cur = b;
		while(1){
			if(cur == upp) break;
			ret2.pb(cur);
			cur = up[0][cur];
		}
		reverse(all(ret2));
		int geta = ret.size();
		ret.resize(ret.size()+ret2.size());
		rep(i, ret2.size()) ret[geta+i] = ret2[i];
		return ret;
	}
}kaede;

struct seg{
	#define szz (1<<19)
	int mxv[szz * 2];
	int mnv[szz * 2];
	int cmn[szz * 2];
	int cmx[szz * 2];
	int tmp[szz * 2];
	void recalc(int k){
		cmx[k] = max(cmx[k*2+1], cmx[k*2+2]);
		cmn[k] = min(cmn[k*2+1], cmn[k*2+2]);
	}
	void init(){ 
		memset(tmp, -1, sizeof(tmp));
		rep(i, szz*2){
			mxv[i] = cmx[i] = -INF;
			mnv[i] = cmn[i] = INF;
		}
	}
	void update(int k ,int a){
		k += szz-1;
		mxv[k] = cmx[k] = a;
		mnv[k] = cmn[k] = a;
		while(k){
			k = (k-1) / 2;
			mxv[k] = max(mxv[k*2+1], mxv[k*2+2]);
			mnv[k] = min(mnv[k*2+1], mnv[k*2+2]);
			recalc(k);
		}
	}
	void push(int k){
		if(tmp[k] == -1) return;
		repn(a,2){
			if(tmp[k] == 0){
				cmx[2*k+a] = -INF;
				cmn[2*k+a] = INF;
				tmp[2*k+a] = 0;
			}
			else{
				cmx[2*k+a] = mxv[2*k+a];
				cmn[2*k+a] = mnv[2*k+a];
				tmp[2*k+a] = 1;
			}
		}
		tmp[k] = -1;
	}
	void set(int a, int b,int k,int l,int r,int t){
		if(a > b or b < l or r < a) return;
		if(a <= l and r <= b){
			if(t == 0){
				cmx[k] = -INF, cmn[k] = INF, tmp[k] = 0;
			}
			else{
				cmx[k] = mxv[k], cmn[k] = mnv[k], tmp[k] = 1;
			}
			return;
		}
		push(k);
		set(a, b, k*2+1, l, (l+r)/2, t);
		set(a, b, k*2+2, (l+r)/2+1, r, t);
		recalc(k);
	}
	void set(int a, int b, int c){ set(a,b,0,0,szz-1,c); return; }
	int query_max(int a, int b, int k=0, int l=0, int r=szz-1){
		if(a > b or b < l or r < a) return -INF;
		if(a <= l && r <= b) return cmx[k];
		push(k);
		return max(query_max(a, b, k*2+1, l, (l+r)/2), query_max(a, b, k*2+2, (l+r)/2+1, r));
	}
	int query_min(int a, int b, int k=0, int l=0, int r=szz-1){
		if(a > b or b < l or r < a) return INF;
		if(a <= l && r <= b) return cmn[k];
		push(k);
		return min(query_min(a, b, k*2+1, l, (l+r)/2), query_min(a, b, k*2+2, (l+r)/2+1, r));
	}
}fuyu;

void solve(){
	int n, q; cin >> n >> q;
	vc<pair<int,P>>v;
	rep(i,n-1){
		int a,b,c;cin>>a>>b>>c;
		v.eb(c,mp(a,b));
	}
	merge_tree f(v);
	root = f.root;
	rep(i, f.cs.size()) cs[i] = f.cs[i];
	for(auto x:f.G) edge[x.a].pb(x.b);
	repn(i,n) cs[i] = -1;
	
	kaede.prepare();
	fuyu.init();
	repn(i, n){
		fuyu.update(i, in[i]);
	}
	fuyu.set(1, n, 0);
	while(q--){
		int t; cin >> t;
		if(t <= 2){
			int l, r; cin >> l >> r;
			fuyu.set(l, r, 2-t);
		}
		else{
			int v; cin >> v; int ans = -1;
			int x = fuyu.query_min(1,n);
			if(0 <= x and x <= n*2+2) chmax(ans, cs[kaede.get(rev[x], v)]);
			x = fuyu.query_max(1,n);
			if(0 <= x and x <= n*2+2) chmax(ans, cs[kaede.get(rev[x], v)]);
			
			o(ans);
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