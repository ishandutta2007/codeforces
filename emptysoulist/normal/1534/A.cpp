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
const int N = 55 ; 
int n, m, a[N][N] ;  
char s[N][N] ; 
signed main() {
	int T = gi() ; 
	while(T--) {
		n = gi(), m = gi() ; 
		rep( i, 1, n ) scanf("%s", s[i] + 1) ; 
		int flag1 = 1, flag2 = 1 ; 
		rep( i, 1, n ) rep( j, 1, m ) {
			if(s[i][j] == '.') continue ;
			if((s[i][j] == 'W') ^ ((i + j) & 1)) flag1 = 0 ;
			else flag2 = 0 ; 
		}
		if(flag1) {
			puts("YES") ; 
			rep( i, 1, n ) {
				rep( j, 1, m ) {
					if((i + j) & 1) printf("W") ;
					else printf("R") ; 
				} puts("") ; 
			}
		}
		else if(flag2) {
			puts("YES") ; 
			rep( i, 1, n ) {
				rep( j, 1, m ) {
					if((i + j) & 1) printf("R") ;
					else printf("W") ; 
				} puts("") ; 
			}
		}
		else puts("NO") ; 
	}
	return 0 ;
}