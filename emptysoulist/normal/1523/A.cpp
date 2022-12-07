#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( int i = (t); i >= (s); -- i )
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
const int N = 1005 ; 
int T, m, n, a[N], b[N] ; 
char s[N] ; 
signed main() {
	T = gi() ; 
	while( T-- ) {
		n = gi(), m = gi(), m = min(n, m) ; 
		cin >> s + 1 ; 
		rep( i, 1, n ) a[i] = s[i] - '0' ; 
		rep( i, 1, m ) {
			rep( j, 1, n ) {
				b[j] = max(a[j], (int)((a[j - 1] + a[j + 1]) == 1)) ; 
			}
			rep( j, 1, n ) a[j] = b[j] ; 
		}
		rep( i, 1, n ) printf("%d", a[i]), a[i] = 0 ; puts("") ; 
	}
	return 0 ;
}