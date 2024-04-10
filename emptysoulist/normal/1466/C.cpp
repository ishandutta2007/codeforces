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
const int N = 3e5 + 5 ; 
int n, f[N] ; 
char s[N] ; 
signed main()
{
	int T = gi() ; 
	while( T-- ) {
		scanf("%s", s + 1) ; 
		n = strlen(s + 1) ; 
		rep( i, 2, n ) {
			if(s[i] == s[i - 1] && (!f[i - 1])) f[i] = 1 ; 
			if(s[i] == s[i - 2] && (!f[i - 2])) f[i] = 1 ; 
		}
		int ans = 0 ; 
		rep( i, 1, n ) ans += f[i] ; 
		rep( i, 1, n ) f[i] = 0 ; 
		printf("%d\n", ans ) ; 
	}
	return 0 ;
}