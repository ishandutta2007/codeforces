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
const int N = 505 ; 
int n, k, ans, vis[N], bef[N], dp[N][N] ; 
void Count(int x, int m) {
	if(x == 0) return ; 
	rep( l, 0, min(m, k) ) {
		int d = (k - l) + (m - l) ; 
		if((k - l) > (n - m)) continue ;
		if(dp[x - 1][d]) {
			int a = l, b = k - l ;vi S;
			rep(i,1,n)bef[i]=vis[i]; 
			rep(i,1,n)if(bef[i]&&a)--a,vis[i]^=1,S.pb(i);
			rep(i,1,n)if(!bef[i]&&b)--b,vis[i]^=1,S.pb(i); 
			cout<<"? "; 
			for(int x:S) cout<<x<<" ";
			cout<<endl; cout.flush();
			int y;cin>>y,ans^=y;
			Count(x - 1, d) ; return ; 
		}
	}
}
signed main() {
	cin >> n >> k ; 
	dp[0][0] = 1 ; 
	rep( i, 1, n ) {
		rep( j, 0, n ) {
			rep( l, 0, min(j, k) ) {
				int d = j - l + (k - l) ;
				if((k - l) > (n - j)) continue ;
				dp[i][d] |= dp[i - 1][j] ;
			}
		}
		if(dp[i][n]) {
			rep( l, 1, n ) vis[l] = 1 ; 
			Count(i, n), cout << "! " << ans << endl, exit(0) ; 
		}
	}
	puts("-1") ; 
	return 0 ;
}