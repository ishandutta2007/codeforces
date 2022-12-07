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
const int N = 505 ; 
int n ; 
char s[N] ; 
int query(int x, int y, int X, int Y) {
	printf("? %d %d %d %d\n", x, y, X, Y) ; 
	cout.flush() ; 
	cin >> s ; 
	if(s[0] == 'Y') return 1 ; 
	return 0 ; 
}
struct node {
	int x, y ; 
} ans[N * 2] ;
signed main()
{
	cin >> n ; 
	int nx = n, ny = n ; 
	int lim = 2 * n - 1, be = 1 ; 
	ans[lim] = (node){n, n} ; 
	rep( i, 1, n - 1 ) {
		int dx = 0, dy = 0 ; 
		if(nx > 1) {
			if(query(1, 1, nx - 1, ny)) dx = 1, dy = 0 ; 
		}
		if(ny > 1) {
			if(query(1, 1, nx, ny - 1)) dx = 0, dy = 1 ; 
		}
		nx -= dx, ny -= dy ; 
		ans[-- lim] = (node){nx, ny} ; 
	}
	nx = 1, ny = 1 ; 
	ans[be] = (node){1, 1} ; 
	rep( i, 1, n - 1 ) {
		int dx = 0, dy = 0 ; 
		if(ny < n) {
			if(query(nx, ny + 1, n, n)) dx = 0, dy = 1 ; 
		}
		if(nx < n) {
			if(query(nx + 1, ny, n, n)) dx = 1, dy = 0 ; 
		}
		nx += dx, ny += dy ; 
		ans[++ be] = (node){nx, ny} ; 
	}
	printf("! ") ;
	rep( i, 2, 2 * n - 1 ) {
		if(ans[i].x - ans[i - 1].x) printf("D") ; 
		else printf("R") ; 
	}
	return 0 ;
}