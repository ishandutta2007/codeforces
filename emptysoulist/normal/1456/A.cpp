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
const int N = 4e5 + 5 ;  
int n, p, k, X, Y, nxt[N] ; 
char a[N] ; 
vector<int> Id[N] ; 
signed main()
{
	int T = gi() ; 
	while( T-- ) {
		n = gi(), p = gi(), k = gi() ; 
		scanf("%s", a + 1)  ;
		rep( i, 1, n ) a[i] -= '0' ; 
		X = gi(), Y = gi() ; 
		rep( i, 1, n ) Id[i % k].pb(i) ; 
		drep( i, 1, n ) nxt[i] = nxt[i + k] + (!a[i]) ; 
		int Ans = X * n ;  
		for(re int i = 0; i < k; ++ i) {
			for(int v : Id[i]) {
				if(v >= p) Ans = min( Ans, (v - p) * Y + nxt[v] * X) ; 
			}
		}
		cout << Ans << endl ; 
		rep( i, 0, k ) Id[i].clear() ; 
		rep( i, 1, n ) nxt[i] = 0 ; 
	}
	return 0 ;
}