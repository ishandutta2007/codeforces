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
const int N = 2e5 + 5 ; 
int n, a[N], Ans, st[N], top ; 
map<int, bool> f ;
void check( int x ) {
	if( x < 1 ) return ; 
	for( re int j = 2; j <= sqrt(x); ++ j ) {
		if( x % j ) continue ; st[++ top] = j ;
		while( ( x % j ) == 0 ) x /= j ;
	}
	st[++ top] = x ; 
}
void solve( int x ) {
	int ans = 0 ; if( x <= 1 ) return ;
	rep( i, 1, n ) {
		if( a[i] >= x ) ans += min( a[i] % x, ( x - a[i] % x ) ) ;
		else ans += ( x - a[i] % x ) ;
	}
	Ans = min( Ans, ans ) ;
} 
int sd( int x ) {
	return ( ( ( 1ll * rand() ) << 13 ) | rand() ) % x + 1 ;
}
signed main() 
{
	srand(time(NULL)), n = gi(), Ans = n ;
	rep( i, 1, n ) a[i] = gi() ; 
	random_shuffle( a + 1, a + n + 1 ) ;
	rep( i, 1, 60 ) {
		int u = a[sd(n)] ; top = 0 ;
		check(u), check(u - 1), check(u + 1) ;
		sort( st + 1, st + top + 1 ) ; 
		rep( j, 1, top ) if( !f[st[j]] ) solve(st[j]), f[st[j]] = 1 ; 
	}
	printf("%lld\n", Ans ) ;
	return 0 ;
}