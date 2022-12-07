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
const int N = 1e6 + 5 ; 
int n, m ; 
char s[N], t[N] ; 
signed main()
{
	n = gi(), m = gi() ; 
	scanf("%s", s + 1),
	scanf("%s", t + 1) ;
	int f = n + 1, ff = 0 ;  
	rep( i, 1, n ) {
		if(s[i] == '*') f = i ; 
	}
	if(f != n + 1) ff = 1 ; 
	if(ff && (n - 1 > m)) { puts("NO") ; exit(0) ; }
	if((!ff) && (n != m)) { puts("NO") ; exit(0) ; }
	for(int i = 1; i < f; ++ i) 
		if(s[i] != t[i]) { puts("NO") ; exit(0) ; }
	for(int i = n; i > f; -- i) {
		if(s[i] != t[m]) { puts("NO") ; exit(0) ; }
		-- m ; 
	}
	puts("YES") ; 
	return 0 ;
}