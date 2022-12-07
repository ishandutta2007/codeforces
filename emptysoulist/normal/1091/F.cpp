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
const int N = 1e5 + 5 ; 
int n, l[N] ; 
char s[N] ; 
signed main()
{
	n = gi() ; 
	rep( i, 1, n ) l[i] = gi() ; 
	scanf("%s", s + 1 ) ; 
	int cost = 0, gs = 0, wt = 0, fw = 0 ; 
	rep( i, 1, n ) {
		if( s[i] == 'G' ) {
			int ch = min( l[i], wt ) ;
			wt -= ch, l[i] -= ch, gs += ch * 2, cost += ch * 2 ;
			cost += l[i] * 3, gs += l[i] ; 
		}
		if( s[i] == 'W' ) {
			cost += 2 * l[i],
			wt += l[i], fw = 1 ; 
		}
		if( s[i] == 'L' ) {
			cost += l[i] ; 
			int ch = min( l[i], wt ) ; 
			wt -= ch, l[i] -= ch, cost += 1 * ch ;
			ch = min( l[i], gs ),
			gs -= ch, l[i] -= ch, cost += 2 * ch ;
			if( l[i] ) {
				if( fw ) cost += 3 * l[i], l[i] = 0 ;
				else cost += 5 * l[i], l[i] = 0 ; 
			} 
		}
	//	printf("%lld %lld %lld\n", i, cost, gs ) ; 
	}
	cout << cost << endl ; 
	return 0 ;
}