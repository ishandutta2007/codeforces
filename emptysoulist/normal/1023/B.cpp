#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( int i = (t); i >= (s); -- i )
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
int n, m ; 
signed main()
{
	n = gi(), m = gi() ; 
	if(n < m / 2) {
		puts("0") ; exit(0) ; 
	}
	if(n >= m) {
		cout << (m - 1) / 2 << endl ; exit(0) ; 
	}
	cout << n - ((m + (!(m & 1))) / 2) << endl ; 
	return 0 ;
}