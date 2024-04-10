#include<bits/stdc++.h>
using namespace std ;
#define rep( i, s, t ) for( int i = (s); i <= (t); ++ i )
#define re register
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
const int M = (1 << 20) + 5 ;  
const int N = 5000 + 5 ; 
char s[N] ; 
int n, A, B, limit, num, vis[150], d[150], L[22], R[22], cnt[22] ;
int c[N], Id[22], dp[M], g[M], ll[M], rr[M], sz[M] ; 
bool cmp(int x, int y) { return L[x] < L[y] ; }
signed main()
{	
	n = gi(), A = gi(), B = gi() ; 
	scanf("%s", s + 1), num = 0 ; 
	n = strlen(s + 1) ; 
	rep( i, 1, n ) vis[(int)s[i]] = 1 ; 
	rep( i, 'a', 'z' ) if(vis[i]) d[i] = ++ num ; 
	rep( i, 1, n ) c[i] = d[(int)s[i]] ; 
	rep( i, 1, num ) L[i] = n + 1, Id[i] = i ;
	rep( i, 1, n ) {
		int u = c[i] ; ++ cnt[u] ; 
		L[u] = min(L[u], i), R[u] = max(R[u], i) ; 
	}
	limit = (1 << num) - 1 ; 
	sort(Id + 1, Id + num + 1, cmp) ; 
	rep( S, 1, limit ) {
		ll[S] = n + 1 ; 
		rep( i, 1, num ) if((1 << (i - 1)) & S) 
			ll[S] = min(ll[S], L[i]), rr[S] = max(rr[S], R[i]), sz[S] += cnt[i] ;
		if(A * (rr[S] - ll[S] + 1) <= B * sz[S]) g[S] = 1 ; 
	}
	dp[0] = 1 ; 
	rep( S, 1, limit ) {
		if(g[S]) {
			rep( i, 1, num ) if((1 << (i - 1)) & S) 
				if(dp[S ^ (1 << (i - 1))]) dp[S] = 1 ; 
		}
		int u = 0 ; 
		rep( i, 1, num ) {
			u |= (1 << (Id[i] - 1)) ; 
			if(dp[S & u]) dp[S] |= dp[S ^ (S & u)] ; 
		}
	}
	int ans = 0 ; 
	rep( i, 'a', 'z' ) {
		if(!vis[i]) continue ; int u = d[i] ; 
		if(dp[limit ^ (1 << (u - 1))]) ++ ans ; 
	}
	printf("%d ", ans ) ; 
	rep( i, 'a', 'z' ) {
		if(!vis[i]) continue ; int u = d[i] ; 
		if(dp[limit ^ (1 << (u - 1))]) printf("%c ", i) ;
	}
	return 0 ;
}