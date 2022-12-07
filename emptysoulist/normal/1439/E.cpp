#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
#define pb push_back
#define pi pair<int, int>
#define mp make_pair
#define vi vector<int>
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 4e5 + 5 ; 
map<pi, int> val, fval ; 
int low(int x) {
	int ans = 0 ; if( !x ) return 100 ; 
	for(; !(x & 1); x >>= 1) ++ ans ;
	return ans ; 
}
int st0[50], st1[50], sz0, sz1 ; 
struct node {
	int x, y, k ; 
	node(int _x = 0, int _y = 0, int _k = 0) { x = _x, y = _y, k = _k ; }
	bool operator < (const node a) const {
		if( (!(x + y)) || (!(a.x + a.y)) ) return (x + y) < (a.x + a.y) ; 
		sz0 = 0, sz1 = 0 ; 
		int tmp0 = x + y, tmp1 = a.x + a.y, flag0 = 0, flag1 = 0, las0 = 0, las1 = 0 ; 
	//	printf("now compaer (%d %d) (%d %d)\n", x, y, a.x, a.y ) ; 
		for(re int i = 30; i >= 0; -- i) if( (1 << i) & tmp0 ) {
			int f = 0 ; 
			if( (1 << i) & x ) { if( !flag0 ) flag0 = 1 ; f = 1 ; }
			else { if( !flag0 ) flag0 = 2 ; f = 2 ; }
			if( f ^ las0 ) las0 = f, st0[++ sz0] = (1 << i) ; 
			else st0[sz0] += (1 << i) ; 
		}
		for(re int i = 30; i >= 0; -- i) if( (1 << i) & tmp1 ) {
			int f = 0 ; 
			if( (1 << i) & a.x ) { if( !flag1 ) flag1 = 1 ; f = 1 ; }
			else { if( !flag1 ) flag1 = 2 ; f = 2 ; }
			if( f ^ las1 ) las1 = f, st1[++ sz1] = (1 << i) ; 
			else st1[sz1] += (1 << i) ; 
		}
		if( flag1 != flag0 ) return flag0 < flag1 ; 
		for(int i = 1; ; ++ i) {
		//	printf("in the end %d (%d %d) (%d %d)\n", i, st0[i], st1[i], sz0, sz1 ) ; 
			if( (i == sz0) && (i == sz1) ) return st0[i] < st1[i] ;
			else if( i == sz0 ) return ((flag1 == 1) ^ (i & 1)) ? 1 : (st0[i] <= st1[i]) ; 
			else if( i == sz1 ) return ((flag1 == 1) ^ (i & 1)) ? 0 : (st0[i] < st1[i]) ;
			if( st1[i] != st0[i] ) 
				return ((flag1 == 1) ^ (i & 1)) ? st0[i] > st1[i] : st0[i] < st1[i] ; 
		} return 0 ; 
	}
} ; vector<node> sad ; node st[N] ; int flag, top ; 
int dep(node x) { return x.x + x.y ; }
node fa(node x) {
	int lx = low(x.x), ly = low(x.y) ;
	return (lx < ly) ? node(x.x - 1, x.y) : node(x.x, x.y - 1) ; 
}
bool operator != (node x, node y) {
	return (x.x != y.x) | (x.y != y.y) | (x.k != y.k) ; 
}
bool operator == (node x, node y) {
	return (x.x == y.x) & (x.y == y.y) ; 
}
node LCA(node p, node q) {
	node ans = (node){0 , 0}; int vp = p.x | p.y , vq = q.x | q.y , upp = 30 , upq = 30;
	while(~upp && !(vp >> upp & 1)) --upp;
	while(~upq && !(vq >> upq & 1)) --upq;
	while(upp != -1 && upq != -1){
		bool fl = p.x >> upp & 1 , fr = q.x >> upq & 1; if(fl != fr) break;
		int mn = min(upp , upq); (fl ? ans.x : ans.y) |= 1 << mn;
		if(mn == upp) --upp;
		if(mn == upq) --upq;
		while(~upp && !(vp >> upp & 1)) --upp;
		while(~upq && !(vq >> upq & 1)) --upq;
	}
	return ans;
}
vector<int> D ; 
void add(node x, node y) {
	val[mp(x.x, x.y)] += val[mp(y.x, y.y)] ; 
//	printf("add (%d %d) -> (%d %d) (%d) (%d)\n", x.x, x.y, y.x, y.y, val[mp(x.x, x.y)], val[mp(y.x, y.y)]) ;
	if( val[mp(y.x, y.y)] > 0 ) {
		D.pb(dep(y) + 1), D.pb(dep(x) + 1) ; 
	//	printf("Add %d %d\n", dep(y) + 1, dep(x) + 1 ) ; 
	}
}
void insert(node x) {
	node lca = LCA( st[top], x ) ; if( lca == x ) return ; 
//	printf("now insert (%d %d) | (%d %d)\n", x.x, x.y, lca.x, lca.y ) ; 
	while( top > 1 && lca < st[top - 1] ) add( st[top - 1], st[top] ), -- top ; 
	if( lca < st[top] ) add(lca, st[top]), -- top ; 
	if( st[top] < lca ) st[++ top] = lca ; 
	st[++ top] = x ; 
}
void build() {
	st[top = 1] = node(0, 0) ; 
	for(node z : sad) insert(z) ; 
	while( top > 1 ) add( st[top - 1], st[top] ), -- top ; 
	if( val[mp(0, 0)] ) flag = 1, D.pb(0), D.pb(1) ; 
}
signed main()
{
//	freopen("test.in", "r", stdin ) ;
//	freopen("test.out", "w", stdout ) ;
	int n = gi(), a, b, c, d ; node u, v ; 
	rep( i, 1, n ) {
		a = gi(), b = gi(), c = gi(), d = gi() ; 
		u = node(a, b), v = node(c, d) ; node z = LCA(u, v) ; 
		sad.pb(u), sad.pb(v), sad.pb(z), 
		++ val[mp(a, b)], ++ val[mp(c, d)], -- val[mp(z.x, z.y)] ; 
		if(dep(z)) sad.pb(fa(z)), -- val[mp(fa(z).x, fa(z).y)] ;
	//	printf("Line %d %d %d %d\n", dep(u), dep(v), dep(z), dep(fa(z)) ) ; 
	}
	
	sort(sad.begin(), sad.end()) ; 
//	for(node z : sad) printf("sort (%d %d)\n", z.x, z.y ) ; 
	build() ; 
	sort(D.begin(), D.end()) ;
	//for(int z : D) printf("%d ", z ) ; puts("") ; 
	int bef = -1, ans = 0, Ans = 0 ; 
	for(int z : D) {
		if( z != bef ) Ans += ans, ans = 1, bef = z ;
		else ans ^= 1 ; 
	} Ans += ans ; 
	if( Ans > 1 ) cout << Ans - flag << endl ; 
	else cout << Ans << endl ; 
	return 0 ;
}