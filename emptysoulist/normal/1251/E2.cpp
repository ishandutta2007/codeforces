#include<bits/stdc++.h>
using namespace std ;
#define rep( i, s, t ) for( register int i = s; i <= t; ++ i )
#define re register
#define int long long
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 2e5 + 5 ; 
priority_queue< int, vector<int>, greater<int> > q ; 
struct Point {
	int m, c ; 
} p[N] ;
int Ans, n, cnt, Maxm, Pre[N] ;
vector<int> Q[N] ; 
signed main()
{
	int T = gi() ; 
	while( T-- ) {
		n = gi(), cnt = 0, Ans = 0 ;
		rep( i, 1, n ) p[i].m = gi(), Maxm = max( Maxm, p[i].m ),
		p[i].c = gi(), Q[p[i].m].push_back(p[i].c) ;
		rep( i, 1, Maxm ) Pre[i] = Pre[i - 1] + Q[i - 1].size() ; 
		for( re int i = Maxm; i >= 0; -- i ) {
			if( !Q[i].size() ) continue ;
			for( re int j = 0; j < Q[i].size(); ++ j ) q.push(Q[i][j]) ;
			if( cnt + Pre[i] < i ) {
				while( cnt + Pre[i] < i ) 
				Ans += q.top(), q.pop(), ++ cnt ; 
			} 
			Q[i].clear() ; 
		}
		while( !q.empty() ) q.pop() ; 
		printf("%I64d\n", Ans ) ;
	}
	return 0 ;
}