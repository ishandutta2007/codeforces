#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( int i = (t); i >= (s); -- i )
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
const int N = 5005 ; 
int n, m, f[N] ; 
char s[N] ; 
signed main()
{
	scanf("%s", s + 1), n = strlen(s + 1) ; 
	rep( i, 0, n ) f[i] = 1 ; 
	m = log2(n) ; int limit = (1 << m), ed = n - limit + 1 ; 
	rep( i, 1, ed ) {
		char ch = 'z' + 1 ;
		rep( j, 0, limit - 1 ) 
			if(f[j]) rep( l, 0, m - 1 ) f[j | (1 << l)] = 1;
		rep( j, 0, limit - 1 ) if(f[j]) ch = min(ch, s[i + j]) ; 
		rep( j, 0, limit - 1 ) f[j] &= (s[j + i] == ch) ; 
		cout << ch ; 
	}
	return 0 ;
}