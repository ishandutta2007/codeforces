#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
#define mp make_pair
#define pi pair<int, int>
#define pb push_back
#define vi vector<int>
#define fi first
#define se second
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 5e5 + 5 ; 
const int inf = 1e9 + 7 ; 
int n, m, cnt, tot, ans[N], A[N], tree[N], D[N], T[N] ; 
struct node {
	int x, y, id ; 
	node(int _x = 0, int _y = 0, int _id = 0) 
	{ x = _x, y = _y, id = _id ; }
} p[N] ; 
bool cmp(node x, node y) {
	return (x.x == y.x) ? (x.y == y.y ? x.id < y.id : x.y < y.y) : x.x < y.x ; 
}
int lowbit(int x) { return x & (-x) ; }
void add(int x) {
	for(re int i = x; i <= tot; i += lowbit(i)) ++ tree[i] ; 
}
int qry(int x) {
	int sum = 0 ; 
	for(re int i = x; i; i -= lowbit(i)) sum += tree[i] ; 
	return sum ; 
}
map<pi, int> S ; 
signed main()
{
	n = gi(), m = gi(), cnt = n + m ; 
	rep( i, 1, n ) {
		int x = gi(), y = gi() ; S[mp(x, y)] = 1 ; 
		p[i] = node(x, y, 0), A[++ tot] = x, A[++ tot] = y ; 
	}
	rep( i, 1, m ) {
		int x = gi(), y = gi() ; ans[i] = S[mp(x, y)] ;
		p[i + n] = node(x, y, i), A[++ tot] = x, A[++ tot] = y ; 
	} 
	sort(A + 1, A + tot + 1) ; 
	rep( i, 1, cnt ) 
		p[i].x = lower_bound(A + 1, A + tot + 1, p[i].x) - A,
		p[i].y = lower_bound(A + 1, A + tot + 1, p[i].y) - A ; 
	sort(p + 1, p + cnt + 1, cmp) ; 
	rep( i, 1, tot ) T[i] = A[i] ; 
	int dx = 0, las = -1 ; 
	rep( i, 1, cnt ) {
		int x = T[p[i].x] - dx, y = T[p[i].y] - qry(p[i].y) ; 
		if(p[i].id) {
			if(!D[p[i].y] && (p[i].x != las)) ans[p[i].id] |= (x == y) ; 
		}
		else {
			if(x > y && p[i].x != las) las = p[i].x, ++ dx ; 
			if(y > x && !D[p[i].y]) add(p[i].y), D[p[i].y] = 1 ;  
		}
	}
	rep( i, 1, m ) (ans[i]) ? puts("LOSE") : puts("WIN") ; 
	return 0 ;
}