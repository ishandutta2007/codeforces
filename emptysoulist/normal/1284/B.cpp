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
const int M = 1e6 + 5 ;
const int inf = 1e7 + 7 ;
int n, m, Mi[N], Mx[N], L0[N], book[M], Ans ;
signed main()
{
	n = gi() ; //lxl
	int uuu = 0 ;
	rep( i, 1, n ) {
		int x = gi(), k ; int mi = inf ; Mi[i] = inf, Mx[i] = 0;
		rep( j, 1, x ) {
			k = gi() ; if( k > mi ) L0[i] = 1 ;
			Mi[i] = min( Mi[i], k ), Mx[i] = max( Mx[i], k ), mi = min( k, mi ) ;
		} 
	} 
	int num = 0, sz = 0 ;
	rep( i, 1, n ) {
		if( !L0[i] ) ++ book[Mx[i]], num = max( num, Mx[i] ) ;
		else ++ sz ;
	}
	for( re int i = num; i >= 1; -- i ) book[i] += book[i + 1] ;
	rep( i, 1, n ) {
		if( L0[i] ) Ans += n ;
		else {
			Ans += ( sz + book[Mi[i] + 1] ) ;
		}
	}
	printf("%lld\n", Ans ) ;
	return 0 ;
}