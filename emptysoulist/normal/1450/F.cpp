#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
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
const int N = 1e5 + 5 ; 
int n, a[N], L[N], R[N], top, c[N] ;  
void solve() {
	n = gi(), top = 0 ; 
	rep( i, 1, n ) L[i] = R[i] = c[i] = 0 ;
	rep( i, 1, n ) a[i] = gi(), ++ c[a[i]] ; 
	int lim = (n + 1) / 2, mx = 0, k = 1 ; 
	rep( i, 1, n ) mx = max(mx, c[i]), c[i] = 0 ;
	if( lim < mx ) { puts("-1") ; return ; } 
	L[++ top] = 1 ; 
	rep( i, 2, n ) if(a[i] == a[i - 1]) ++ k, R[top] = i - 1, L[++ top] = i ; 
	R[top] = n, mx = 0 ; 
	rep( i, 1, top ) ++ c[a[L[i]]], ++ c[a[R[i]]] ;
	rep( i, 1, n ) mx = max(mx, c[i]) ;  
	printf("%d\n", max(mx - 1, k) - 1) ; 
}
signed main()
{
	int T = gi() ; 
	while( T-- ) solve() ; 
	return 0 ;
}