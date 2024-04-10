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
const int N = 1e6 + 5 ; 
const int P = 998244353 ; 
int n, f[N], S[N], d[N] ; 
signed main()
{
	n = gi() ; 
	S[0] = f[0] = 0 ; 
	for(int i = 1; i <= n; ++ i)
	for(int j = i; j <= n; j += i) ++ d[j] ; 
	rep( i, 1, n ) {
		f[i] = S[i - 1] + d[i] ; 
		S[i] = (S[i - 1] + f[i]) % P ; 
	}
	cout << f[n] << endl ; 
	return 0 ;
}