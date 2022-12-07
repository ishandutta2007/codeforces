#include<bits/stdc++.h>
using namespace std ;
#define rep( i, s, t ) for( register int i = s; i <= t; ++ i )
#define re register
int gi() {
    char cc = getchar() ; int cn = 0, flus = 1 ;
    while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
    while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
    return cn * flus ;
}
const int N = 1000 + 5 ; 
const int M = 40 + 5 ; 
int n, m, k, a[N][N], dis[M][N][N], Ans[M][M], vis[M] ; 
struct node { int x, y ; } ;
queue<node> q ; 
vector<node> Go[M] ;
void init( int t ) {
    rep( i, 1, n ) rep( j, 1, m ) if( a[i][j] == t ) q.push((node){i, j}), dis[t][i][j] = 0 ;
    memset( vis, 0, sizeof(vis) ), vis[t] = 0 ;
    while( !q.empty() ) {
        node u = q.front() ; q.pop() ; int D = dis[t][u.x][u.y] ;
        if( !vis[a[u.x][u.y]] ) {
            vis[a[u.x][u.y]] = 1 ; 
            for( auto i : Go[a[u.x][u.y]] ) if( dis[t][i.x][i.y] > D + 1 ) dis[t][i.x][i.y] = D + 1, q.push(i) ;
        }
        if( u.x > 0 && dis[t][u.x - 1][u.y] > D + 1 ) dis[t][u.x - 1][u.y] = D + 1, q.push((node){ u.x - 1, u.y }) ;
        if( u.x < n && dis[t][u.x + 1][u.y] > D + 1 ) dis[t][u.x + 1][u.y] = D + 1, q.push((node){ u.x + 1, u.y }) ;
        if( u.y > 0 && dis[t][u.x][u.y - 1] > D + 1 ) dis[t][u.x][u.y - 1] = D + 1, q.push((node){ u.x, u.y - 1 }) ;
        if( u.y < m && dis[t][u.x][u.y + 1] > D + 1 ) dis[t][u.x][u.y + 1] = D + 1, q.push((node){ u.x, u.y + 1 }) ;
    }
}
signed main()
{
    n = gi(), m = gi(), k = gi() ;
    rep( i, 1, n ) rep( j, 1, m ) a[i][j] = gi(), Go[a[i][j]].push_back((node){ i, j }) ; 
    int Q = gi() ; memset( dis, 63, sizeof(dis) ) ;
    rep( i, 1, k ) init(i) ;
    rep( i, 1, Q ) {
        int r1 = gi(), c1 = gi(), r2 = gi(), c2 = gi() ;
        int Ans = abs(r1 - r2) + abs(c1 - c2) ;
        rep( t, 1, k ) Ans = min( Ans, dis[t][r1][c1] + dis[t][r2][c2] + 1 ) ;
        cout << Ans << endl ;
    }
    return 0 ;
}