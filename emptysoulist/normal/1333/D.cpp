#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = s; i <= t; ++ i )
#define re register
#define int long long
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 3e5 + 5 ; 
int n, K, a[N], b[N] ;
char s[N] ; 
vector<int> step[N] ; 
signed main()
{
	n = gi(), K = gi() ;
	scanf("%s", s + 1 ) ;
	rep( i, 1, n ) a[i] = ( s[i] == 'R' ) ? 1 : 0 ; 
	a[n + 1] = -1 ; 
	for( re int i = 1; i <= n + 1; ++ i ) b[i] = a[i] ;
	int cnt = 0, num = 0 ;
	while(1) {
		++ cnt ; 
		rep( i, 1, n ) {
			if( b[i] == 1 && b[i + 1] == 0 ) {
				step[cnt].push_back(i) ; 
				swap( b[i], b[i + 1] ), ++ i, ++ num ;
			}
		}
		if( step[cnt].empty() ) break ; 
	}
	-- cnt ; 
	if( K < cnt || K > num ) {
		puts("-1") ; exit(0) ; 
	}
	int txt = K - cnt ; 
	rep( i, 1, cnt ) {
		int j = 0, siz = step[i].size() ; 
		while( txt ) {
			if( j == siz - 1 ) break ; 
			printf("1 %I64d\n", step[i][j] ) ;
			++ j, -- txt ; 
		}
		printf("%I64d", step[i].size() - j ) ;
		for( re int k = j; k < step[i].size(); ++ k ) {
			printf(" %I64d", step[i][k] ) ;
		}
		puts("") ; 
	}
	return 0 ;
}