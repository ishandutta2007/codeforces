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
const int N = 2e5 + 5 ; 
int n, k, num ; 
char s[N], A[N] ; 
signed main()
{
	n = gi(), k = gi() ; 
	scanf("%s", s + 1) ; 
	int m = k ; k = (n - k) / 2 ; 
	rep( i, 1, n ) {
		if(s[i] == '(') A[++ num] = '(' ;
		if(s[i] == ')') {
			if(k) -- k, -- num ; 
			else A[++ num] = ')' ; 
		}
	}
	rep( i, 1, m ) printf("%c", A[i]) ; 
	return 0 ;
}