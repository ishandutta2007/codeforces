#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
#define pb push_back
#define vi vector<int>
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 5e5 + 5 ; 
const int M = 50 + 5 ; 
int n, top, cnt, num ;
struct node {
	int x, y ; 
} st[N] ; 
vi col[N], rev[N], lst[M] ;
vi merge( vi x, vi y ) {
	int m = x.size() ; vi ans ; ans.clear() ; 
	for(int i = 0; i < m; ++ i) {
		st[++ cnt] = (node){x[i], y[i]} ;
		ans.pb(x[i]), ans.pb(y[i]) ; 
	}
	return ans ; 
}
void output() {
	printf("%d\n", cnt ) ; 
	rep( i, 1, cnt ) printf("%d %d\n", st[i].x, st[i].y ) ; 
}
signed main()
{
	n = gi() ; 
	if( n <= 2 ) {
		puts("0") ; exit(0) ;  
	}
	rep( i, 1, n ) col[i].pb(i) ; 
	top = n ; 
	while(1) {
		int id = 0, bef = top ; 
		while(top >= 2) {
			++ id ; 
			rev[id] = merge(col[top], col[top - 1]) ; 
			top -= 2 ; 
		}
		if( top ) lst[++ num] = col[top] ; 
		if( id == 0 ) break ; 
		rep( i, 1, bef ) col[i].clear() ;  
		top = id ; 
		rep( i, 1, id ) col[i] = rev[i], rev[i].clear() ;  
	}
	if( num <= 2 ) output() ;
	else {
		int siz = lst[1].size(), bef = 0 ; 
		for( re int i = 2; i < num; ++ i ) {
			while( siz < lst[i].size() ) {
				vi tk ; tk.clear() ; 
				for(re int j = 0; j < siz; ++ j) {
					tk.pb(lst[1][j]), tk.pb(lst[num][j + bef]) ; 
					st[++ cnt] = (node){lst[1][j], lst[num][j + bef]} ;
				}
				lst[1].clear(), lst[1] = tk ; 
				bef += siz ; 
				siz *= 2 ; 
			}
			lst[1] = merge(lst[1], lst[i]) ;
			siz *= 2 ; 
		}
		output() ; 
	}
	return 0 ;
}
//1 + 2 + 4 + 8