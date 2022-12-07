#include<bits/stdc++.h>
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
const int N = 1005 ;

int n, st[N][N], a[N], b[N], top[N], vis[N] ;
char s[N] ;
int ans = 1 ; 
bool check() {
	int flag = 0, l = 1, r = n ;
	while( l < r ) {
		
		int qwq = r - l + 1 ; 
		while( l < r && (vis[l] || s[l] == ')') ) -- qwq, ++ l ;
		//
		//
		while( l < r && (vis[r] || s[r] == '(') ) -- r, ++ qwq ;
		if( l < r ) st[ans][++ top[ans]] = l, st[ans][++ top[ans]] = r, 
		flag = 1, vis[l] = vis[r] = 1, ++ l, -- r, -- qwq ;
	}
	return flag ;
}
void input() {
	scanf( "%s", s + 1 ), n = strlen(s + 1) ;
}
void solve() {
	while( check() ) ++ ans ;
	for( re int i = 1; i < ans; ++ i ) 
	sort( st[i] + 1, st[i] + top[i] + 1 ) ;
	printf("%lld\n", ans - 1 ) ;
}
signed main() {
	input(), solve() ; 
	for( re int i = 1; i < ans; ++ i ) {
		printf("%lld\n", top[i] ) ;
		rep( j, 1, top[i] ) printf("%lld ", st[i][j] ) ;
		puts("") ;
	}
	return 0;
}