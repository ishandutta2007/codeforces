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
int n, q, cnt, a[N], b[N] ; 
priority_queue<int> Q ; 
signed main()
{
	n = gi(), q = gi() ; 
	rep( i, 1, n ) a[i] = gi() ; 
	drep( i, 1, n ) {
		if( a[i] < 0 ) { Q.push(a[i]) ; continue ; }
		while( !Q.empty() ) {
			int u = Q.top() ; Q.pop() ; 
			if( a[i] + u >= 0 ) a[i] += u ; 
			else { u += a[i], Q.push(u) ; break ; }
		}
	}
	while( !Q.empty() ) { b[++ cnt] = - Q.top() ; Q.pop() ; }
	rep( i, 1, cnt ) b[i] += b[i - 1] ; 
	while( q-- ) {
		int x = gi(), flag = 0 ; 
		rep( j, 1, cnt ) {
			if( b[j] <= x ) { ++ flag ; } 
			else break ; 
		}
		cout << cnt - flag << endl ; 
	}
	return 0 ;
}