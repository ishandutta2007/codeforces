#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 1000 + 5 ; 
struct E {
	int to, next ; 
} e[N << 1] ; 
int T, n, rt, st[N], fa[N], top, len, cnt, head[N] ; 
char s[N] ; 
void add( int x, int y ) {
	e[++ cnt] = (E){ y, head[x] }, head[x] = cnt,
	e[++ cnt] = (E){ x, head[y] }, head[y] = cnt ; 
}
void Dfs(int x, int f, int len, int dd) {
	fa[x] = f ; if( len == dd ) st[++ top] = x ; 
	Next(i, x) {
		int v = e[i].to ; 
		if(v ^ f) Dfs(v, x, len + 1, dd) ; 
	} 
}
int ll, ans, Ans ; 
int Get( int x, int d ) {
	top = 0 ; Dfs(x, x, 0, d) ; 
	if( !top ) return 0 ; 
	printf("? %d", top ) ;
	rep( i, 1, top ) printf(" %d", st[i] ) ; puts("") ; 
	cout.flush() ; 
	ans = gi() ; ll = gi() ; 
	return ll ; 
}
signed main()
{
	T = gi() ; 
	while(T --) {
		n = gi() ; int x, y ; 
		rep( i, 2, n ) x = gi(), y = gi(), add( x, y ) ; 
		printf("? %d ", n ) ; 
		rep( i, 1, n ) printf("%d ", i ) ; puts("") ; 
		cout.flush() ; 
		rt = gi(), len = gi() ; Ans = rt ; 
		int o = (len + 1) / 2, rr = len ; 
		Get(rt, o), Ans = ans ;
		for(re int i = 8; i >= 0; -- i ) {
			if(( o + (1 << i) <= rr) ){
				int x = Get(rt, o + (1 << i)) ;
				if(x == len) o += (1 << i), Ans = ans ;
			}
		}
		Get(Ans, len) ; int ans2 = ans ; 
		printf("! %d %d\n", Ans, ans2) ;
		cout.flush() ; 
		scanf("%s", s + 1 ) ; 
		if( s[1] == 'I' ) break ;  
		cnt = 0 ; 
		memset( head, 0, sizeof(head) ), memset( e, 0, sizeof(e) ), 
		memset( fa, 0, sizeof(fa) ), memset( st, 0, sizeof(st) ) ; 
	}
	return 0 ;
}