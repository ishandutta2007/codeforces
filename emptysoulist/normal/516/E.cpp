#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
#define vi vector<int>
#define int long long
#define pb push_back
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 2e5 + 5 ; 
int n, m, B, G, g[N], b[N], A[N], cnt, cnt1, cnt2, _a, _b, Ai, Bi ;
vi f[N], h[N] ; 
struct node {
	int d, c ; 
	node(int _d = 0, int _c = 0) { d = _d, c = _c ; }
} A1[N], A2[N] ;
void out() { puts("-1") ; exit(0) ; }
int gcd(int x, int y) { return (!y) ? x : gcd(y, x % y) ; }
int exgcd(int x, int y) {
	if(y == 0) { _a = 1, _b = 0 ; return x ; }
	int d = exgcd(y, x % y), ia = _b, ib = _a - (x / y) * _b ;
	_a = ia, _b = ib ; return d ; 
}
//Ai * n + Bi * m = d
//(Ai + m) * n + (Bi - n) * m = d
int Get(int x, int type) { //type == 1 return k * n % m = i(kn + bm = i)
	int fa = Ai * x, fb = Bi * x ; 
	fa %= m ; if( fa < 0 ) fa += m ;
	fb %= n ; if( fb < 0 ) fb += n ;
	return (type) ? fa : fb ; 
}
bool cmp(node x, node y) {
	return ( x.d == y.d ) ? (x.c > y.c) : (x.d < y.d) ; 
}
int Go(int x, int y, int mod) {//x to y mod m
	return (x < y) ? y - x - 1 : (mod - 1 - x + y) ;
}
map<int, int> m1, m2 ; 
int solve(int x) {//k * m % n = i 
	cnt = cnt1 = cnt2 = 0, m1.clear(), m2.clear() ; int ans = 0 ; 
	if( (f[x].size() == n) && (h[x].size() == m) ) return -1 ; 
	for(int v : f[x]) A[++ cnt] = v, m1[v] = 1 ; 
	for(int v : h[x]) A[++ cnt] = v, m2[v] = 1 ;
	for(int v : f[x]) if(!m2[v % m]) ans = max(ans, v), m2[v % m] = 1 ;
	for(int v : h[x]) if(!m1[v % n]) ans = max(ans, v), m1[v % n] = 1 ; 
	rep( i, 1, cnt ) 
		A1[++ cnt1] = node(Get(A[i], 0), A[i]), //0 mean k * m % n = x
		A2[++ cnt2] = node(Get(A[i], 1), A[i]) ; 
	sort(A1 + 1, A1 + cnt1 + 1, cmp), sort(A2 + 1, A2 + cnt2 + 1, cmp) ;
	A1[cnt1 + 1] = A1[1], A2[cnt2 + 1] = A2[1] ; 
	rep( i, 1, cnt1 ) {
		int dis = A1[i].c + Go(A1[i].d, A1[i + 1].d, n) * m ;
		if( (A1[i + 1].d - A1[i].d < 2) && (i != cnt1) ) continue ;  
		ans = max(ans, dis) ; 
	} 
	rep( i, 1, cnt2 ) {
		int dis = A2[i].c + Go(A2[i].d, A2[i + 1].d, m) * n ; 
		if( (A2[i + 1].d - A2[i].d < 2) && (i != cnt2) ) continue ;  
		ans = max(ans, dis) ; 
	} 
	return ans ; 
}
signed main()
{
	n = gi(), m = gi() ; int d = gcd(n, m) ; 
	B = gi() ; rep( i, 1, B ) b[i] = gi() ; sort(b + 1, b + B + 1) ;
	G = gi() ; rep( i, 1, G ) g[i] = gi() ; sort(g + 1, g + G + 1) ; 
	if( d > B + G ) out() ; int ans = 0 ;  
	n /= d, m /= d, exgcd(n, m), Ai = _a, Bi = _b, Ai %= m, Bi %= n ; 
	rep( i, 1, B ) f[b[i] % d].pb(b[i] / d) ; 
	rep( i, 1, G ) h[g[i] % d].pb(g[i] / d) ;
	rep( i, 0, d - 1 ) if(!f[i].size() && !h[i].size()) out() ; 
	rep( i, 0, d - 1 ) ans = max(ans, solve(i) * d + i) ; 
	cout << ans << endl ; 
	return 0 ;
}