#include<bits/stdc++.h>
using namespace std;
#define rep( i, s, t ) for( register int i = s; i <= t; ++ i )
#define re register
int gi() {
	char cc = getchar(); int cn = 0, flus = 1;
	while(cc < '0' || cc > '9') {  if( cc == '-' ) flus = -flus;  cc = getchar();  }
	while(cc >= '0' && cc <= '9')  cn = cn * 10 + cc - '0', cc = getchar();
	return cn * flus;
}
const int N = 20 ; 
int Ans, l, r, w[N] ;  
bool check( int x ) {
	int u = x ; memset( w, 0, sizeof(w) ) ;
	while(u) {
		++ w[u % 10], u /= 10 ; 
	}
	rep( i, 0, 9 ) if( w[i] > 1 ) return 0 ;
	return 1 ; 
}
signed main()
{
	l = gi(), r = gi() ;
	for( re int i = l; i <= r; ++ i ) {
		if( check(i) ){
			Ans = i ; break ;
		}
	}
	if( !Ans ) printf("-1\n") ;
	else printf("%d\n", Ans ) ;
	return 0 ;
}