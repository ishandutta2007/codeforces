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
const int N = 4e5 + 5 ; 
int n, K, top, st[N], Win ; 
char s[N] ; 
signed main()
{
	int T = gi() ; 
	while( T-- ) {
		n = gi(), K = gi() ; Win = 0, top = 0 ; 
		scanf("%s", s + 1 ) ; 
		st[++ top] = n + 100, s[0] = 'L' ; 
		rep( i, 1, n ) 
			if(s[i] == 'W') ++ Win ; 
			else {
				if(s[i - 1] != 'L') st[++ top] = 1 ;
				else st[top] ++ ; 
			}
		Win += K ;
		if( Win >= n ) {
			cout << n * 2 - 1 << endl ; 
		}
		else {
			if(s[n] == 'L' && top != 1) st[top] = 0, -- top ;
			sort(st + 1, st + top + 1) ;
			int z = 0, cut = 0 ;
			rep( i, 1, top ) {
				if( st[i] <= K ) K -= st[i] ;
				else ++ cut ; 
			} 
			if( Win == 0 ) puts("0") ; 
			else cout << Win * 2 - cut << endl ; 
		}
		rep( i, 1, top ) st[i] = 0 ; 
		top = 0 ; 
	}
	return 0 ;
}