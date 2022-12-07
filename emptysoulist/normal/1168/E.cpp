#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i < (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
#define mp make_pair
#define pi pair<int, int>
#define pb push_back
#define vi vector<int>
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = (1 << 12) + 5 ; 
int k, n, a[N], v[N], p[N], q[N], Id[N] ; 
void fix(int x, int y) {
	int u = q[x] ^ v[x] ;
	if(Id[u] == x) return ; 
	if(Id[u] == y) { swap(p[x], p[y]), swap(Id[p[x]], Id[p[y]]) ; return ; }
	int k = Id[u] ; 
	swap(p[x], p[k]), swap(Id[p[x]], Id[p[k]]), swap(q[k], q[y]) ;  
	fix(k, y) ; 
}
signed main()
{
	k = gi(), n = (1 << k) ; int t = 0 ;
	rep( i, 0, n ) a[i] = gi(), t ^= a[i] ; 
	rep( i, 0, n ) p[i] = q[i] = Id[i] = i ; 
	if(t) { puts("Fou") ; exit(0) ; }
	rep( i, 0, n - 1 ) {
		if(a[i] != v[i]) 
			v[i + 1] ^= (a[i] ^ v[i]), v[i] = a[i], fix(i, i + 1) ; 
	}
	puts("Shi") ; 
	rep( i, 0, n ) printf("%d ", p[i] ) ; puts("") ; 
	rep( i, 0, n ) printf("%d ", q[i] ) ; 
	return 0 ;
}