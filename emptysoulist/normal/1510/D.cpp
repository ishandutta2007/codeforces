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
const int N = 1e5 + 5 ; 
long double g[N], f[N][10] ; 
int tran[N][10] ; 
int n, d, a[N] ; 
signed main()
{
	rep( i, 0, 9 ) f[0][i] = -100000 ; 
	f[0][1] = 0, n = gi(), d = gi() ; 
	rep( i, 1, n ) a[i] = gi(), g[i] = log2(a[i]) ; 
	rep( i, 1, n ) {
		rep( j, 0, 9 ) tran[i][j] = -1, f[i][j] = f[i - 1][j] ; 
		rep( j, 0, 9 ) {
			int u = j * a[i] % 10 ; 
			if(f[i][u] < f[i - 1][j] + g[i]) {
				f[i][u] = f[i - 1][j] + g[i],
				tran[i][u] = j ; 
			}
		}
	} 
	int b = d ; 
	if(f[n][d] <= 0) {
		puts("-1") ; exit(0) ; 
	}
	vector<int> st ; 
	for(int i = n; i >= 1; -- i) {
		if(tran[i][b] == -1) {
			b = b ; 
		} 
		else {
			b = tran[i][b] ; 
			st.pb(a[i]) ; 
		}
	}
	if(st.empty()) {
		puts("-1") ; exit(0) ; 
	}
	cout << st.size() << endl ; 
	for(int z : st) printf("%d ", z) ;  
	return 0 ; 
}