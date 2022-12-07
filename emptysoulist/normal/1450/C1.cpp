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
const int N = 300 + 5 ; 
char s[N][N] ; 
int n, A[10] ; 
void solve() {
	n = gi() ; 
	rep( i, 0, 2 ) A[i] = 0 ; 
	rep( i, 1, n ) scanf("%s", s[i] + 1) ; 
	rep( i, 1, n ) rep( j, 1, n ) {
		if(s[i][j] == 'X') ++ A[(i + j) % 3] ; 
		if(s[i][j] == 'O') ++ A[(i + j + 1) % 3] ; 
	}
	int mi = n * n, id = 0 ; 
	rep( i, 0, 2 ) if(A[i] <= mi) mi = A[i], id = i ; 
	rep( i, 1, n ) rep( j, 1, n ) {
		if(s[i][j] == 'X') {
			if((i + j) % 3 == id) s[i][j] = 'O' ;
		}
		if(s[i][j] == 'O') {
			if((i + j + 1) % 3 == id) s[i][j] = 'X' ;
		}
	}
	rep( i, 1, n ) { printf("%s", s[i] + 1) ; puts("") ; }
}
signed main()
{
	int T = gi() ; 
	while( T-- ) solve() ; 
	return 0 ; 
}