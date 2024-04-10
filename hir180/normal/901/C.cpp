#include <bits/stdc++.h>
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

//verified: yosupo judge (x3), AOJ 2450, Hackerrank white falcon, IJPC2012-3A, yukicoder (x2)

struct dat {
	int mx, mn;
	//reverse
	void rv(){
		
	}
};
//
dat dt(int a){
	return {a, a};
}
//a, b 
dat mrg(dat a, dat b){
	return {max(a.mx, b.mx), min(a.mn, b.mn)};
}
struct node{
	node *l, *r, *p;
	int id, rev;
	dat D, S;
	node(int i) : l(0), r(0), p(0), id(i), rev(0){
		D = S = dt(i);
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
	
	dat slf = n->S;
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
//
inline void link(node *m, node *n){
	expose(m), expose(n);
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
	n->D.rv();
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

const int MAXN = 300005;
node *V[MAXN];
int n, m;
vector<int>G[300005], edge[300005];
vector<P>add;
int rui[300005], dep[300005];
ll sum[300005];
bool vis[300005];

void dfs(int v, int d){
	if(vis[v]) return; vis[v] = 1;
	dep[v] = d;
	rep(i, G[v].size()){
		int to = G[v][i];
		if(vis[to]){
			if(dep[to] > dep[v]) add.pb(mp(to, v));
			continue;
		}
		edge[to].pb(v);
		dfs(to, d+1);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i, m){
		int a, b; scanf("%d%d", &a, &b);
		G[a].pb(b); G[b].pb(a);
	}
	repn(i, n) if(!vis[i]) dfs(i, 0);
	repn(i, n) V[i] = new node(i);
	repn(i, n){
		rep(j, edge[i].size()){
			int to = edge[i][j];
			evert(V[i]);
			link(V[i], V[to]);
		}
	}
	rep(i, MAXN) rui[i] = n+1;
	rep(i, add.size()){
		int a = add[i].fi, b = add[i].sc;
		evert(V[a]); expose(V[b]);
		int mn = V[b]->D.mn, mx = V[b]->D.mx;
		rui[mn] = min(rui[mn], mx);
	}
	for(int i=n;i>=1;i--) rui[i] = min(rui[i], rui[i+1]);
	repn(i, n){
		sum[i] = sum[i-1] + rui[i];
	}
	int q; scanf("%d",&q);
	rep(i, q){
		int a, b; scanf("%d%d",&a, &b);
		int x = upper_bound(rui+a, rui+b+1, b) - rui;
		//[a, x) + [x, b]
		ll ans = sum[x-1] - sum[a-1] - 1LL * (a+x-1) * (x-a) / 2 + 1LL*(b-x+2)*(b-x+1)/2 ;
		printf("%lld\n", ans);
	}
}