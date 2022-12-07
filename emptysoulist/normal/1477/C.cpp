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
const int N = 5000 + 5 ; 
int n, x[N], y[N], vis[N], p[N] ; 
int dis(int x, int y) {
	return x * x + y * y ; 
}
signed main()
{
	n = gi() ; 
	rep( i, 1, n ) x[i] = gi(), y[i] = gi() ; 
	int now = 1 ; int bef = 1 ; 
	while(bef <= n) {
		vis[now] = bef, ++ bef ; 
		int go = 1, d = 0 ; 
		rep( i, 1, n ) if(!vis[i]) {
			int z = dis(x[i] - x[now], y[i] - y[now]) ; 
			if(z >= d) d = z, go = i ;
		}
		now = go ; 
	}
	rep( i, 1, n ) p[vis[i]] = i ;
	rep( i, 1, n ) printf("%lld ", p[i] ) ; 
	return 0 ;
}