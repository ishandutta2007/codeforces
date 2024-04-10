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
#define int long long
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 1e5 + 5 ; 
int n, a[100], b[100] ; 
signed main()
{
	int q = gi() ; 
	while(q--) {
		int x = gi(), y = gi() ; 
		int flag1 = (x <= y) ; 
		rep( i, 0, 30 ) a[i] = ((x >> i) & 1) ;
		rep( i, 0, 30 ) b[i] = ((y >> i) & 1) ; 
		rep( i, 1, 30 ) a[i] += a[i - 1], b[i] += b[i - 1] ; 
		rep( i, 0, 30 ) flag1 &= (a[i] >= b[i]) ; 
		if(flag1) puts("YES") ; 
		else puts("NO") ; 
	}
	return 0 ;
}