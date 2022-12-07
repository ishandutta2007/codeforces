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
const int N = 3e5 + 5 ; 
int n, Ans, flag ; 
char s[N] ; 
signed main()
{
	scanf("%s", s + 1 ) ; 
	n = strlen(s + 1), Ans = n * (n + 1) / 2 ; 
	for(re int i = 1; i <= n; ++ i) {
		flag = 1 ; 
		for(re int j = i; j >= max(i - 10, 1ll); -- j) {
			for(re int k = j + 1; k <= i; ++ k) {
				int d = k - j ; 
				if( s[k] == s[j] && (s[k + d] == s[j]) && (k + d <= i) ) flag = 0 ;  
			}
			Ans -= flag ; 
		} 
	}
	cout << Ans << endl ; 
	return 0 ;
}