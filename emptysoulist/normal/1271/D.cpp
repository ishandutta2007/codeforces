#include <bits/stdc++.h>
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
int n, m, k ;
const int N = 5005 ;
int vv[N] , rr[N];
struct Node {
	int a, b, c, id ;
	bool operator < ( const Node &x ) const {
		return ( c == x.c ) ? vv[id] > vv[x.id] : c > x.c ;
	}
} a[N] ;
int Aqwq[N], Bqwq[N], CQWQ[N] ;
void input() {
	n = gi() ; m = gi() ; k = gi() ;
	rep( i, 1, n ) {
		Aqwq[i] = gi() ; Bqwq[i] = gi() ; CQWQ[i] = gi() ;
		a[i] = { Aqwq[i] , Bqwq[i] , CQWQ[i] , i }, vv[i] = i ;
	} int sum = k ;
	rep( i, 1, m ) {
		int x = gi() , y = gi() ;
		vv[y] = max( vv[y] , x ) ;
	}
} 
void solve() {
	int sum = k ;
	rep( i, 1, n ) {
		if( sum < a[i].a ) { printf("-1") ; exit(0) ; }
		sum += a[i].b, rr[i] = sum ;
	}
	int ans = 0 ; sort( a + 1, a + n + 1) ;
	rep( i, 1, n ) {
		bool flag = 0 ;
		rep( j, vv[a[i].id], n ) {
			if( rr[j] <= Aqwq[j + 1] ) {
				flag = 1 ; break ;
			}
		}
		if( flag ) continue ; ans += a[i].c ;
		rep( j, vv[a[i].id], n ) -- rr[j];
	}
	cout << ans << endl ;
}
signed main() {
	input(), solve() ; 
	return 0 ;
}