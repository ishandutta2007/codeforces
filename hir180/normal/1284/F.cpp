//Let's join Kaede Takagaki Fan Club !!
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
#define all(x) x.begin(),x.end()
template<class T>
void dmp(T a){
	rep(i,a.size()) cout << a[i] << " ";
	cout << endl;
}
template<class T>
bool chmax(T&a, T b){
	if(a < b){
		a = b;
		return 1;
	}
	return 0;
}
template<class T>
bool chmin(T&a, T b){
	if(a > b){
		a = b;
		return 1;
	}
	return 0;
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
const ll mod = 998244353;
template<class T>
void add(T&a,T b){
	a+=b;
	if(a >= mod) a-=mod;
}

struct dat {
	P mn, mx;
	//reverse
	void rv(){
		swap(mn, mx);
	}
};
//
dat dt(int a, int b){
	return {P(a,b), P(a,b)};
}
//a, b 
dat mrg(dat a, dat b){
	dat ret;
	if(a.mn.fi != -1) ret.mn = a.mn; else ret.mn = b.mn;
	if(b.mx.fi != -1) ret.mx = b.mx; else ret.mx = a.mx;
	return ret;
}
struct node{
	node *l, *r, *p;
	int id, rev;
	dat D;
	P S;
	node(int i, int u = -1, int v = -1) : l(0), r(0), p(0), id(i), rev(0){
		//D
		D = dt(u, v);
		S = mp(u, v);
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
			n->l->D.rv();
		}
		if(n->r){
			n->r->rev ^= 1;
			n->r->D.rv();
		}
		n->rev = 0;
	}
}

//
inline void update(node *n){
	//
	push(n);
	
	dat slf = dt(n->S.fi, n->S.sc);
	if(n->l) slf = mrg(n->l->D, slf);
	if(n->r) slf = mrg(slf, n->r->D);
	n->D = slf;
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
	else n -> p = g;
	connect(p, n, !l);
	update(p), update(n);
}
inline void splay(node *n){
	while(!is_root(n)){
		node *p = n -> p, *g = p -> p;
		//
		if(!is_root(p)) push(g);
		push(p), push(n);
		if(!is_root(p)) rotate(left(n) ^ left(p) ? n : p);
		rotate(n);
	}
	//
	push(n);
}
//n
inline node* expose(node *n){
	node *last = NULL;
	for(node *m = n; m; m = m -> p){
		splay(m);
		m -> r = last;
		last = m;
	}
	splay(n);
	return last;
}
inline void link(node *m, node *n){
	expose(m), expose(n);
	m -> p = n;
}
inline node* find_root(node *n){
	if(!n) return (node*)NULL;
	while(n -> r){
		push(n);
		n = n -> r;
	}
	return n;
}
inline node* cut(node *n){
	expose(n);
	node *ret = n -> l;
	n -> l -> p = NULL;
	n -> l = NULL;
	update(n);
	return find_root(ret);
}
//n
//update
inline void evert(node *n){
	expose(n);
	n->rev ^= 1;
	n->D.rv();
}

//u-v: evert(V[u]) cut(V[v])
//u-v: evert(V[u]) link(V[u], V[v])
//: evert(V[v]) update(V[x])
//u-v: evert(V[u]) expose(V[v]) update(V[v]) V[v]->D

const int MAXN = 250005;
node *V[MAXN];
int n;
vector<int>edge[250005];

void dfs(int v,int u){
	rep(i,edge[v].size()){
		if(edge[v][i] == u) continue;
		dfs(edge[v][i], v);
	}
	rep(i,edge[v].size()){
	    if(edge[v][i] == u) continue;
		int a = v, b = edge[v][i];
		evert(V[a]); expose(V[b]); update(V[b]);
		assert(V[b]->D.mx.fi >= 1);
		int c = V[b]->D.mx.fi, d = V[b]->D.mx.sc;
		printf("%d %d %d %d\n", a, b, c, d);
		evert(V[c]); node *mid = cut(V[d]);
		evert(mid); cut(V[c]);
		node *nwmid = new node(-1, -1, -1);
		evert(V[a]); link(V[a], nwmid); link(nwmid, V[b]);
	}
}
int main(){
	scanf("%d",&n);
	rep(i,n-1){
		int a, b; scanf("%d%d",&a,&b);
		edge[a].pb(b);
		edge[b].pb(a);
	}
	repn(i,n){
		V[i] = new node(i);
	}
	rep(i,n-1){
		int a,b; scanf("%d%d",&a,&b);
		node *mid = new node(-1, a, b);
		evert(V[a]); link(V[a], mid); link(mid, V[b]);
	}
	printf("%d\n", n-1);
	dfs(1, -1);
}