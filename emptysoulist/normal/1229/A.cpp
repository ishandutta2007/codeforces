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
const int N = 7000 + 5 ; 
int n, Ans, a[N], b[N] ; 
map<int, int> S ; 
map<int, int> ok ; 
signed main()
{
	n = gi() ; 
	rep( i, 1, n ) a[i] = gi(), ++ S[-a[i]] ; 
	rep( i, 1, n ) b[i] = gi() ; 
	for(auto z : S) {
		if(z.second <= 1) continue ; 
		int u = -z.first ; 
		rep( j, 1, n ) if((u & a[j]) == a[j]) ++ S[-a[j]] ;
		ok[u] = 1 ; 
	}
	rep( i, 1, n ) if(ok[a[i]]) Ans += b[i] ;
	cout << Ans << endl ;  
	return 0 ;
}