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
const int N = 1e6 + 5 ; 
int n, flg, c[N], a[N], b[N] ; 
int vis[N], ll[N], rr[N] ; 
signed main() {
	n = gi() ; 
	rep( i, 1, n ) a[i] = gi(), a[i] += a[i - 1] ; 
	rep( i, 1, n ) b[i] = gi(), b[i] += b[i - 1] ; 
	if(a[n] > b[n]) { flg = 1 ; rep( i, 1, n ) swap(a[i], b[i]) ; }
	vis[0] = 1 ; 
	rep( i, 1, n ) {
		c[i] = c[i - 1] ; while(b[c[i]] < a[i]) ++ c[i] ; 
		int d = b[c[i]] - a[i] ; 
		if(!vis[d]) vis[d] = 1, ll[d] = i, rr[d] = c[i] ;
		else {
			if(!flg) {
				cout << i - ll[d] << endl ; 
				for(int j = ll[d] + 1; j <= i; ++ j)
				cout << j << " " ; puts("") ; 
				cout << c[i] - rr[d] << endl ; 
				for(int j = rr[d] + 1; j <= c[i]; ++ j)
				cout << j << " " ; puts("") ; 
			}
			else {
				cout << c[i] - rr[d] << endl ; 
				for(int j = rr[d] + 1; j <= c[i]; ++ j)
				cout << j << " " ; puts("") ; 
				cout << i - ll[d] << endl ; 
				for(int j = ll[d] + 1; j <= i; ++ j)
				cout << j << " " ; puts("") ; 
			}
			exit(0) ; 
		} 
	}
	return 0 ;
}