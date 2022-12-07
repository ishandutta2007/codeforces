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
const int N = 6000 + 5 ; 
const int P = 1e9 + 7 ; 
int n, m, s[N], f[N], h[N], L[N], R[N], wl[N], wr[N], Dec[N] ; 
int Num, Ans ; 
signed main()
{
	n = gi(), m = gi() ; 
	rep( i, 1, n ) s[i] = gi() ; 
	rep( i, 1, m ) {
		f[i] = gi(), h[i] = gi() ; int fl = 0 ;
		for( re int j = 1; j <= n; ++ j ) {
			fl += ( s[j] == f[i] ) ;
			if( fl == h[i] ) { L[i] = j ; break ; }
		}
		if( !L[i] ) L[i] = n + 1 ; 
		fl = 0 ;
		drep( j, 1, n ) {
			fl += ( s[j] == f[i] ) ;
			if( fl == h[i] ) { R[i] = j ; break ; }
		}
		if( !R[i] ) R[i] = 0 ;
	}
	rep( i, 1, n ) {
		memset( wl, 0, sizeof(wl) ) ;
		memset( Dec, 0, sizeof(Dec) ) ;
		memset( wr, 0, sizeof(wr) ) ;
		int r = 0 ;
		rep( j, 1, m ) {
			if( s[i] == f[j] ) {
				int fl = 2 ; 
				if( L[j] == i ) ++ wl[f[j]], -- fl ;
				if( R[j] > i ) ++ wr[f[j]], -- fl ; 
				if( !fl ) ++ Dec[f[j]] ; 
			}
			else {
				int fl = 2 ; 
				if( L[j] < i ) ++ wl[f[j]], -- fl ;
				if( R[j] > i ) ++ wr[f[j]], -- fl ;
				if( !fl ) ++ Dec[f[j]] ; 
			}
		}
		int num = 0, ans = 1 ;
		rep( j, 1, n ) {
			int u = ( wl[j] * wr[j] - Dec[j] ) ;
			if( j == s[i] ) {
				if( ( !u ) && ( !wl[j] ) ) { ans = 0, num = -n ; continue ; }
				else if( !u ) num += 1, ans = ans * wl[j] % P ; 
				else num += 2, ans = ans * ( u % P ) % P ;
			}
			else {
				if( (!u) && !wl[j] && !wr[j] ) continue ; 
				if( ( !u ) && ( wl[j] || wr[j] ) ) ++ num, ans = ans * ( wl[j] + wr[j] ) % P ;
				else num += 2, ans = ans * ( u % P ) % P ; 
			}
		}
		if( num > Num ) Ans = ans % P, Num = num ; 
		else if( num == Num ) Ans = ( Ans + ans ) % P, Num = num ; 
	}
	int num = 0, ans = 1 ; memset( wl, 0, sizeof(wl) ) ;
	rep( i, 1, m ) {
		if( R[i] > 0 ) ++ wl[f[i]] ; 
	}
	rep( i, 1, n ) if( wl[i]) ++ num, ans = ans * wl[i] % P ;
	if( num > Num ) Ans = ans % P, Num = num ; 
	else if( num == Num ) Ans = ( Ans + ans ) % P, Num = num ; 
	printf("%lld %lld\n", Num, Ans ) ;
	return 0 ;
}