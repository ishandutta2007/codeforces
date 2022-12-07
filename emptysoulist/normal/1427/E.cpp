#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
#define int long long
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 1e5 + 5 ; 
int n, top ; 
struct node {
	int x, y, z ;
	node(int _x = 0, int _y = 0, int _z = 0) { x = _x, y = _y, z = _z ; }
} opt[N] ;
void f(int x, int y, int z) {
	opt[++ top] = node(x, y, z) ; 
}
signed main()
{
	n = gi() ; int x = n ; 
	for(re int i = 20; i >= 1; -- i) {
		if( !((1 << i) & x) ) continue ; 
		int y = x ; 
		rep( j, 1, i ) f(y, y, 1), y <<= 1 ;
		int by = y ; 
		int z = y ^ x ; f(x, y, 0) ;
		int r = z + y ; f(z, y, 1) ; 
		int u = r ^ x ; f(r, x, 0) ; 
		int t = y + y ; f(y, y, 1) ;
		int w = t ^ u ; f(t, u, 0) ;
		while(by >= w) {
			if(by & w) f(by, w, 0), by ^= w ;
			f(w, w, 1), w <<= 1 ; 
		}
		f(by, x, 0), x ^= by ;
	}
	cout << top << endl ; 
	rep( i, 1, top ) {
		if( opt[i].z ) printf("%lld + %lld\n", opt[i].x, opt[i].y ) ; 
		else printf("%lld ^ %lld\n", opt[i].x, opt[i].y ) ; 
	}
	return 0 ;
}