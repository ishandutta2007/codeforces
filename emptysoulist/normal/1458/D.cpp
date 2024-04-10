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
const int N = 1e6 + 5 ; 
int n, cnt, a[N], L[N], R[N] ; 
char s[N], ans[N] ; 
void add(int x, int y) {
	if(x > y) swap(x, y) ; 
	++ R[x], ++ L[y] ;  
}
void Dfs(int x) {
	while(L[x]) -- L[x], -- R[x - 1], Dfs(x - 1), ans[cnt --] = '0' ; 
	while(R[x]) -- R[x], -- L[x + 1], Dfs(x + 1), ans[cnt --] = '1' ; 
}
signed main()
{
	int T = gi() ; 
	while( T-- ) {
		scanf("%s", s + 1) ; n = strlen(s + 1) ; 
		rep( i, 1, n ) a[i] = (s[i] == '1') ? 1 : -1 ; 
		rep( i, 1, n ) a[i] += a[i - 1] ;  
		rep( i, 1, n ) a[i] += n ; 
		add(n, a[1]) ; 
		rep( i, 1, n - 1 ) add(a[i], a[i + 1]) ; 
		cnt = n, Dfs(n) ; 
		printf("%s\n", ans + 1) ;
		rep( i, 1, n ) ans[i] = '\0' ;  
		rep( i, 1, 2 * n ) L[i] = R[i] = 0 ; 
	}
	return 0 ;
}