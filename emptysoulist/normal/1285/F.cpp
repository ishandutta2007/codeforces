#include<bits/stdc++.h>
using namespace std ;
#define rep( i, s, t ) for( register int i = s; i <= t; ++ i )
#define re register
#define int long long 
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 1e5 + 5 ; 
int n, A[N], D[N], mu[N], p[N], cnt[N], st[N], top, Ans ;
bool isp[N] ;
vector<int> d[N] ; 
inline int gcd( int a, int b ) {
	return ( a == 0 ) ? b : gcd( b % a, a ) ;
}
inline void init( int x ) {
	isp[1] = 1, mu[1] = 1 ; 
	for( re int i = 2; i <= x; ++ i ) {
		if( !isp[i] ) p[++ top] = i, mu[i] = -1 ; 
		for( re int j = 1; j <= top && p[j] * i <= x; ++ j ) {
			isp[i * p[j]] = 1 ;
			if( i % p[j] == 0 ) break ;
			mu[i * p[j]] = -mu[i] ; 
		}
	}
}
bool check( int x ) {
	int ans = 0 ;
	for( re int i = 0; i < d[x].size(); ++ i ) ans += mu[d[x][i]] * cnt[d[x][i]] ; 
	return ( ans != 0 ) ;
}
void update( int x, int k ) {
	for( re int i = 0; i < d[x].size(); ++ i ) cnt[d[x][i]] += k ; 
}
signed main()
{
	n = gi(), init( 1e5 ), top = 0 ;
	rep( i, 1, n ) A[i] = gi(), D[A[i]] = 1 ; 
	rep( i, 1, 1e5 ) for( re int j = i; j <= 1e5; j += i ) d[j].push_back(i) ; 
	rep( i, 1, 1e5 ) for( re int j = i; j <= 1e5; j += i ) D[i] |= D[j] ; 
	for( re int i = 1e5; i >= 1; -- i ) {
		if( !D[i] ) continue ; 
		while( check(i) ) {
			Ans = max( Ans, 1ll * i * st[top] ) ;
			update( st[top], -1 ), -- top ; 
		}
		update( i, 1 ), st[++ top] = i ;
	}
	printf("%lld\n", Ans ) ;
	return 0 ;
}