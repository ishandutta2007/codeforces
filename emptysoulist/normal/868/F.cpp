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
const int N = 2e5 + 5 ; 
const int inf = 1e14 ; 
int n, m, ll, rr, num, a[N], c[N], dp[25][N], qwq ; 
void add(int x) { num += c[a[x]], ++ c[a[x]], ++ qwq ; }
void del(int x) { -- c[a[x]], num -= c[a[x]], ++ qwq ; }
void solve(int x, int l, int r, int L, int R) {
	if(l > r) return ; 
	int mid = (l + r) >> 1 ; 
	int l2 = L, r2 = mid ; 
	while(ll > l2) -- ll, add(ll) ; 
	while(rr < r2) ++ rr, add(rr) ; 
	while(ll < l2) del(ll), ++ ll ;
	while(rr > r2) del(rr), -- rr ; 
//	cout << "now solve " << l << " " << r << " " << L << ' ' << R << " " << ll << " " << rr << " " << qwq << endl ;  
	int mx = inf, p = L ; 
	for(int i = l2; i <= min(R, mid); ++ i) {
		del(ll), ++ ll ; 
		int val = dp[x - 1][i] + num ; 
		if(val <= mx) mx = val, p = i ; 
	} dp[x][mid] = mx ;
	solve(x, l, mid - 1, L, p), solve(x, mid + 1, r, p, R) ; 
} 
signed main()
{
	n = gi(), m = gi() ; 
	rep( i, 1, n ) a[i] = gi() ; 
	rep( i, 0, m ) rep( j, 0, n ) dp[i][j] = inf ; 
	dp[0][0] = 0, ll = 1, rr = 0 ; 
	rep( i, 1, m ) solve(i, i, n, 0, n) ; 
	cout << dp[m][n] << endl ; 
	return 0 ;
}