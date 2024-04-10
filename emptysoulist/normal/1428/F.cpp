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
const int N = 5e5 + 5 ; 
char s[N] ; 
int n, cnt, g[N], ww[N], f[N], w[N], top, Ans ; 
int S(int x) {
	return x * (x + 1) / 2 ; 
}
signed main()
{
	n = gi() ; 
	scanf("%s", s + 1 ) ; 
	s[0] = 0 ; 
	rep( i, 1, n ) {
		if( s[i] != s[i - 1] ) {
			f[++ top] = i, w[top] = 1 ; 
		}
		else ++ w[top] ;  
	}
	rep( i, 1, n ) s[i] -= '0' ; 
	rep( k, 1, n ) {
		int flag = 1 ; cnt = 0 ;
		for( re int j = 1; j <= top; ++ j) {
			if( (s[f[j]] == 1) && (w[j] >= k) ) {
				ww[++ cnt] = w[j], g[cnt] = f[j], flag = 1 ; 
			}
			else if( flag ) 
				flag = 0, ww[++ cnt] = w[j], g[cnt] = f[j], s[f[j]] = 0 ; 
			else ww[cnt] += w[j] ; 
		}
		top = cnt ; 
		for( re int j = 1; j <= top; ++ j) w[j] = ww[j], f[j] = g[j] ; 
		int l = n + 1, id = 0 ;
		for(re int j = 1; j <= top; ++ j) {
			id += w[j] ; 
			if( s[f[j]] ) {
				int len = w[j] ; 
				if( l != (n + 1) ) Ans += (k - 1) * l ; 
				Ans += (len - k + 1) * (id - w[j]) ; 
				Ans += S(len - k + 1) ; 
				l = id - k + 1 ; 
			}
			else {
				if( l == n + 1 ) continue ; 
				Ans += w[j] * l ; 
			}
		}
	}
	cout << Ans << endl ; 
	return 0 ;
}