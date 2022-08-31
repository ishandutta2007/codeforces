//Let's join Kaede Takagaki Fan Club !!
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

//verified: yosupo judge (x3), AOJ 2450, Hackerrank white falcon, IJPC2012-3A, yukicoder (x2)

//.....
struct dat {
	ll sum;
	pair<ll,int>max1, max2;
	//reverse
	void rv(){
		swap(max1, max2);
	}
};
struct node{
	node *l, *r, *p;
	int id, rev;
	dat D, S;
	multiset<pair<ll,int>, greater<pair<ll,int>>>L;
	pair<ll,int>Lmax;
	node(int i, ll w) : l(0), r(0), p(0), id(i), rev(0){
		D = S = {w, mp(w, -i), mp(w, -i)};
		Lmax = mp(-1, -1);
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
	//cout << n->id << endl;
	//
	push(n);
	
	n->D.sum = n->S.sum + (n->l? n->l->D.sum : 0) + (n->r? n->r->D.sum : 0);
	n->D.max1 = mp(n->S.sum+(n->l?n->l->D.sum:0), -(n->id));
	if(n->l) chmax(n->D.max1, n->l->D.max1);
	if(n->r) chmax(n->D.max1, mp(n->r->D.max1.fi+n->S.sum+(n->l?n->l->D.sum:0) , n->r->D.max1.sc));
	if(n->Lmax.fi >= 0) chmax(n->D.max1, mp(n->Lmax.fi+n->S.sum+(n->l?n->l->D.sum:0) , n->Lmax.sc));
	n->D.max2 = mp(n->S.sum+(n->r?n->r->D.sum:0), -(n->id));
	if(n->r) chmax(n->D.max2, n->r->D.max2);
	if(n->l) chmax(n->D.max2, mp(n->l->D.max2.fi+n->S.sum+(n->r?n->r->D.sum:0) , n->l->D.max2.sc));
	if(n->Lmax.fi >= 0) chmax(n->D.max2, mp(n->Lmax.fi+n->S.sum+(n->r?n->r->D.sum:0) , n->Lmax.sc));
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
		if(m->r) m -> L.insert(m->r->D.max1);
		m -> r = last;
		if(m->r) m -> L.erase(m->r->D.max1);
		m->Lmax = (m->L.empty()? mp(-1LL, -1) : *(m->L.begin()));
		last = m;
	}
	splay(n);
	return last;
}
inline void link(node *m, node *n){
	//cout << m->id << " " << n->id << endl;
	expose(m), expose(n);
	m -> p = n;
	n -> r = m;
	update(n);
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
inline node* cut(node *n){
	expose(n);
	node *ret = n->l;
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

const int MAXN = 100005;
node *V[MAXN * 2];
int nxt = 100005, n, q;
ll w, last = 0;

int main(){
	scanf("%d%d%lld",&n,&q,&w);
	repn(i,n) V[i] = new node(i, 0);
	rep(i, n-1){
		int a, b; ll c; scanf("%d%d%lld",&a,&b,&c);
		V[nxt+i] = new node(nxt+i, c);
		evert(V[a]);
		link(V[a], V[nxt+i]); link(V[nxt+i], V[b]);
	}
	int curv = 1;
	rep(i, q){
		int d; ll e; scanf("%d%lld",&d,&e);
		d = (d+(last%(n-1)))%(n-1);
		e = (e+last)%w;
		evert(V[nxt+d]);
		V[nxt+d]->S = {e, mp(e, -nxt-d),  mp(e, -nxt-d)};
		update(V[nxt+d]);
		int far_v = - (V[nxt+d]->D.max1.sc);
		evert(V[far_v]);
		printf("%lld\n", V[far_v]->D.max1.fi);
		last = V[far_v]->D.max1.fi;
	}
}