//Let's join Kaede Takagaki Fan Club !!
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//#define int long long
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
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
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

template<class T>
void g(T &a){
	cin >> a;
}
template<class T>
void o(const T &a,bool space=false){
	cout << a << (space?' ':'\n');
}
//ios::sync_with_stdio(false);
const ll mod = 1000000007;//998244353
//mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());
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

int n, m, up[100005], go[100005];
ll dep[100005];
vc<P>edge[100005];
//verified: yosupo judge (x3), AOJ 2450, Hackerrank white falcon, IJPC2012-3A, yukicoder (x2)

struct node{
	node *l, *r, *p;
	int id, rev;
	node(int i) : l(0), r(0), p(0), id(i), rev(0){
	}
};

inline bool is_root(node *n){
	return n -> p == NULL || n -> p -> l != n && n -> p -> r != n;
}

inline bool left(node *n){
	return n == n -> p -> l;
}

//
//push(n)n->l  n->r 
inline void push(node *n){
	if(n->rev){
		swap(n->l, n->r);
		if(n->l){
			n->l->rev ^= 1;
		}
		if(n->r){
			n->r->rev ^= 1;
		}
		n->rev = 0;
	}
}

//
inline void update(node *n){
	//
	push(n);
}
inline void connect(node *n, node *p, bool l){
	(l ? p -> l : p -> r) = n;
	if(n) n -> p = p;
}
//rotate
inline void rotate(node *n){
	node *p = n -> p, *g = p -> p;
	bool l = left(n);
	connect(l ? n -> r : n -> l, p, l);
	if(!is_root(p)) connect(n, g, left(p));
	else{
		// (g...p - n  g...n - p)
		n -> p = g;
	}
	connect(p, n, !l);
	update(p), update(n);
}
inline void splay(node *n){
    if(is_root(n)){
        update(n);
        return;
    }
	while(!is_root(n)){
		node *p = n -> p, *g = p -> p;
		//
		if(!is_root(p)) push(g);
		push(p), push(n);
		if(!is_root(p)) rotate(left(n) ^ left(p) ? n : p);
		rotate(n);
	}
}
//n
//
vc<int>ch;
int find_fst(node *n){
    if(!n->l) return n->id;
    return find_fst(n->l);
}
int find_lst(node *n){
    if(!n->r) return n->id;
    return find_lst(n->r);
}
inline node* expose(node *n){
	node *last = NULL;
	for(node *m = n; m; m = m -> p){
		splay(m);
		ch.pb(find_fst(m));
		m -> r = last;
		last = m;
	}
	splay(n);
	return last;
}
//
inline void link(node *m, node *n){
	splay(m), splay(n);
	m -> p = n;
}
inline node* find_root(node *n){
	if(!n) return (node*)NULL;
	while(1){
		push(n);
		if(n->r) n = n->r;
		else break;
	}
	return n;
}
inline void cut(node *n){
	expose(n);
	n -> l -> p = NULL;
	n -> l = NULL;
	update(n);
}
//n
//update
inline void evert(node *n){
	expose(n);
	n->rev ^= 1;
}
//-1
int LCA(node *a,node *b){
	expose(a);
	node *ret = expose(b);
	if(a->p == (node*)NULL) return -1;
	else return ret->id;
}
//u-v: evert(V[u]) cut(V[v])
//u-v: evert(V[u]) link(V[u], V[v])
//: evert(V[v]) update(V[x])
//u-v: evert(V[u]) expose(V[v]) V[v]->D

node *V[100005];
vc<int>L;
int beg[100005], en[100005], nxt;
void dfs(int v){
    beg[v] = nxt++;
	bool in = 0;
	rep(i, edge[v].size()){
		if(i+1 == edge[v].size()){
			link(V[edge[v][i].a], V[v]);
			go[v] = edge[v][i].a;
		}
		dep[edge[v][i].a] = dep[v] + edge[v][i].b;
		up[edge[v][i].a] = v;
		dfs(edge[v][i].a);
		in = 1;
	}
	if(!in){
		expose(V[v]);
	}
	en[v] = nxt-1;
}
pair<ll, ll>solve(vc<pair<ll,ll>>Q){
    if(Q.empty()) return mp(-1ll, 0ll);
	vc<ll>za;
	rep(i, Q.size()){
		za.pb(Q[i].a);
		za.pb(Q[i].b+1);
	}
	SORT(za);
	ERASE(za);
	priority_queue<ll>que;
	vc<vc<ll>>add;
	add.resize(za.size(), vc<ll>());
	rep(i, Q.size()){
		add[POSL(za, Q[i].a)].pb(-Q[i].b);
	}
	ll tm = 1e18;
	rep(i, za.size()-1){
		for(auto at:add[i]) que.push(at);
		ll num = za[i+1] - za[i];
		if(num > que.size()) num = que.size();
		rep(j, (int)num){
			ll v = que.top(); que.pop();
			if(-v < za[i]+j){
				chmin(tm, -v);
			}
		}
	}
	while(!que.empty()){
	    chmin(tm, -que.top()); que.pop();
	}
	
	int use = 0;
	add.clear();
	add.resize(za.size(), vc<ll>());
	rep(i, Q.size()){
		if(Q[i].b >= tm) continue;
		add[POSL(za, Q[i].a)].pb(-Q[i].b);
	}
	rep(i, za.size()-1){
		for(auto at:add[i]) que.push(at);
		ll num = za[i+1] - za[i];
		if(num > que.size()) num = que.size();
		rep(j, (int)num){
			ll v = que.top(); que.pop();
			assert(-v >= za[i]+j);
			use ++;
		}
	}
	assert(que.empty());
	
	if(tm > 5e17) tm = -1;
	return mp(tm, use);
}
template<typename F, typename T>
struct segtree{
	int sz;
	vector<T>seg;
	const F f;
	const T e;
	segtree(int n, const F f, const T e): f(f), e(e) {
		sz = 1;
		while(sz < n) sz <<= 1;
		seg.assign(2*sz, e);
	}
	void init(int n){
		sz = 1;
		while(sz < n) sz <<= 1;
		seg.assign(2*sz, e);
	}
	//ok...
	void update(int a, T p, bool ok){
		a += sz-1;
		if(ok) seg[a] = f(seg[a], p);
		else seg[a] = p;
		while(a){
			a = (a-1)/2;
			seg[a] = f(seg[a*2+1], seg[a*2+2]);
		}
	}
	void make(vector<T>a){
		rep(i, a.size()) seg[i+sz-1] = a[i];
		for(int i=sz-2;i>=0;i--) seg[i] = f(seg[i*2+1], seg[i*2+2]);
	}
	T query(int a, int b){
		a += sz-1, b += sz-1;
		T L = e, R = e;
		while(a <= b){
			if((a&1) == 0) { L = f(L, seg[a++]); }
			if((b&1) == 1) { R = f(seg[b--], R); }
			if(a > b) break;
			a = (a-1) >> 1;
			b = (b-1) >> 1;
		}
		return f(L, R);
	}
	
};
//
//f, e
//segtree<decltype(f), decltype(e)>seg(, f, e); 
//auto f = [](int a, int b){ return min(a, b); };
//int e = INF; 
auto f = [](ll a, ll b){ return max(a, b); };
ll e = 0;
segtree<decltype(f), decltype(e)>kaede((1<<17), f, e);

void solve(){
	cin >> n >> m;
	rep(i, n-1){
		int a, b, c; cin >> a >> b >> c;
		edge[a].eb(b, c);
	}
	repn(i, n) V[i] = new node(i);
	dfs(1);
	repn(i, n){
		rep(j, si(edge[i])-1){
			link(V[edge[i][j].a], V[i]);
		}
	}
	vc<pair<ll,ll>>Q;
	rep(i, m){
	    int v; ll t; cin >> v >> t;
	    ch.clear();
	    splay(V[v]);
	    int x = find_lst(V[v]);
	    expose(V[x]);
	    rep(j, si(ch)-1){
	    	int z = ch[j];
	    	int x = up[z];
	    	int y = go[x];
	    	assert(y != z);
	    	assert(z != 1);
	    	ll las = kaede.query(beg[x]+1, en[x]);
	    	Q.pb(mp((las?las+dep[x]:0)+1, t+dep[x]));
	    	go[x] = z;
	    }
	    kaede.update(beg[v], t, 1);
	}
	auto ans = solve(Q);
	cout << ans.a << " " << ans.b << endl;
}
signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	int t; t = 1; //cin >> t;
	while(t--) solve();
}