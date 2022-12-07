#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = s; i <= t; ++ i )
#define re register
#define int long long
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 1e3 + 5 ;
int n, X[N], Y[N], bx[N], by[N], e[2][2] ; 
signed main() {
	n = gi() ; 
	rep( i, 1, n ) bx[i] = X[i] = gi(), by[i] = Y[i] = gi() ; 
	while(1) {
		memset( e, 0, sizeof(e) ) ;
		rep( i, 1, n ) {
			int xt = X[i] & 1, yt = Y[i] & 1 ; 
			++ e[xt][yt] ; 
		}
		int odd0 = e[0][0] + e[1][1], odd1 = e[0][1] + e[1][0] ; 
		if( odd0 != n && odd0 != 0 ) {
			printf("%d\n", odd0 ) ;
			rep( i, 1, n ) {
				int xt = X[i] & 1, yt = Y[i] & 1 ; 
				if( ( xt + yt ) % 2 == 0 ) printf("%d ", i ) ;
			} exit(0) ; 
		}
		else if( odd0 != 0 && ( e[0][0] != 0 ) && ( e[0][0] != n ) ) {
			printf("%d\n", e[0][0] ) ;
			rep( i, 1, n ) {
				int xt = X[i] & 1, yt = Y[i] & 1 ; 
				if( ( xt + yt ) == 0 ) printf("%d ", i ) ;
			} exit(0) ; 
		}
		else if( odd1 != 0 && ( e[1][0] != 0 ) && ( e[1][0] != n ) ) {
			printf("%d\n", e[1][0] ) ;
			rep( i, 1, n ) {
				int xt = X[i] & 1, yt = Y[i] & 1 ; 
				if( ( xt ) == 1 ) printf("%d ", i ) ;
			} exit(0) ; 
		}
		else {
			rep( i, 1, n ) {
				int xt = X[i] & 1, yt = Y[i] & 1 ; 
				X[i] = ( X[i] - xt ) / 2, Y[i] = ( Y[i] - yt ) / 2 ; 
			}
		}
	}
	return 0;
}