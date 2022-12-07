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
const int inf = 1e10 ; 
const int N = 4e5 + 5 ; 
int n, l[N], r[N], b[N * 2], top, sum[N * 2], c[N * 2] ;
signed main()
{
	int T = gi() ; 
	while( T-- ) {
		n = gi(), top = 0 ;
		rep( i, 1, n ) {
			l[i] = gi(), r[i] = gi() ; 
			b[++ top] = l[i], b[++ top] = r[i] ;
		} sort(b + 1, b + top + 1) ; int Mx = 0 ;
		top = unique( b + 1, b + top + 1 ) - b - 1 ;
		rep( i, 1, n ) {
			l[i] = (std::lower_bound(b + 1, b + top + 1, l[i]) - b) * 2 ;
			r[i] = (std::lower_bound(b + 1, b + top + 1, r[i]) - b) * 2 ;
			Mx = max( Mx, r[i] + 1 ) ;
			++ c[l[i]], -- c[r[i] + 1] ; 
		}
		int Ans = -1, de = 0 ;
		rep( i, 1, Mx ) c[i] += c[i - 1], de += ( c[i] > 0 && c[i - 1] == 0 ) ; 
		rep( i, 1, Mx ) c[i] = ( c[i] > 1 ) ; 
		rep( i, 1, Mx ) sum[i] = sum[i - 1] + ( c[i] == 1 && c[i - 1] == 0 ) ;
		rep( i, 1, n ) {
			Ans = max( Ans, sum[r[i]] - sum[l[i] - 1] + ( c[l[i]] != 0 && c[l[i] - 1] != 0 ) - 1 ) ;
		}
		printf("%I64d\n", de + Ans ) ;
		rep( i, 1, Mx ) c[i] = sum[i] = 0 ;
		rep( i, 0, top ) b[i] = 0 ;
	}
	return 0 ;
}
/*
00--00--00
*/