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
const int N = 1000 + 5 ; 
const int M = 1e5 + 5 ; 
int T, n, m ; 
int a[N][N], b[N][N], c[5], t[5] ; 
char s[M] ; 
struct node {
	int id, b ; 
} p[5] ;
void solve() {
	n = gi(), m = gi() ; 
	rep( i, 1, n ) rep( j, 1, n ) a[i][j] = gi() ; 
	rep( i, 1, 3 ) p[i].id = i, p[i].b = 0 ; 
	scanf("%s", s + 1) ; 
	rep( i, 1, m ) {
		if(s[i] == 'L') -- p[2].b ; 
		if(s[i] == 'R') ++ p[2].b ; 
		if(s[i] == 'D') ++ p[1].b ; 
		if(s[i] == 'U') -- p[1].b ; 
		if(s[i] == 'I') swap(p[2], p[3]) ;
		if(s[i] == 'C') swap(p[1], p[3]) ; 
	}
	rep( i, 1, n ) rep( j, 1, n ) {
		c[1] = i, c[2] = j, c[3] = a[i][j] ; 
		rep( k, 1, 3 ) t[k] = ((c[p[k].id] + p[k].b - 1) % n + n) % n + 1 ; 
		b[t[1]][t[2]] = t[3] ; 
	}
	rep( i, 1, n ) {
		rep( j, 1, n ) {
			printf("%d ", b[i][j] ) ; 
		} puts("") ; 
	}
}
signed main()
{
	int T = gi() ; 
	while( T-- ) solve() ; 
	return 0 ;
}