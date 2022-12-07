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
const int N = 1e5 + 5 ; 
int n, a[N], st[N], top ; 
signed main() {
	int t = gi() ; 
	while( t-- ) {
		n = gi() ; 
		rep( i, 1, n ) a[i] = gi() ; 
		st[top = 1] = 1 ; 
		puts("1") ; 
		rep( i, 2, n ) {
			if(a[i] == 1) {
				st[++ top] = 1 ; 
			} 
			else {
				while((st[top] + 1) != a[i]) -- top ; 
				++ st[top] ; 
			}
			printf("%d", st[1]) ; 
			rep( j, 2, top ) printf(".%d", st[j]) ; puts("") ; 
		}
	} 
	return 0 ;
}