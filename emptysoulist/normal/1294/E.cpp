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
const int N = 2e5 + 5 ; 
int n, m, b[N << 1], f[N << 1], Ans ;
vector<int> rm[N] ;
map<int, int> Mp ;
signed main()
{
	n = gi(), m = gi() ; int tm = n << 1 ; 
	rep( i, 1, n ) { int x ;
		rep( j, 1, m ) x = gi(), rm[j].push_back(x) ;
	}
	rep( i, 1, m ) {
		int num = n ;
		for( re int j = 1; j <= n; ++ j ) {
			b[j] = rm[i][j - 1] ; 
			if( b[j] >= i ) {
				if( ( b[j] - i ) % m == 0 ) b[j] = ( b[j] - i ) / m ;
				else b[j] = -1 ;
			}
			else b[j] = -1 ;
		}
		for( re int j = n + 1; j <= tm; ++ j ) b[j] = b[j - n] ;
		for( re int j = 1; j <= n; ++ j ) if( b[j] != -1 ) ++ Mp[j - b[j]] ;
		for( re int j = 1; j <= n; ++ j ) {
			num = min( num, j - 1 + n - Mp[j] ) ;
			if( b[j] != -1 ) -- Mp[j - b[j]], ++ Mp[j + n - b[j]] ;
		}  
		Ans += num, Mp.clear() ;
		//(k - j) = b[k]
	} printf("%I64d\n", Ans ) ;
	return 0 ;
}