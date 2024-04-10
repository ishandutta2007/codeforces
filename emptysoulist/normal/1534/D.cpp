#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( int i = (t); i >= (s); -- i )
#define mp make_pair
#define pi pair<int, int>
#define pb push_back
#define vi vector<int>
#define cf() cout.flush()
const int N = 2000 + 5 ; 
int n, dis[N], vis[N], a[N][N] ;
void Qry(int x) {
	cout << "? " << x << endl ; cout.flush() ; 
	rep( i, 1, n ) cin >> dis[i] ;
} 
void add(int x, int y) { a[x][y] = a[y][x] = 1 ; }
signed main() {
	cin >> n ; 
	Qry(1) ; 
	int A = 0, B = 0, type = 0 ; 
	rep( i, 1, n ) if(dis[i] == 1) add(1, i) ; 
	rep( i, 2, n ) vis[i] = (dis[i] & 1) ;
	rep( i, 2, n ) (vis[i]) ? ++ A : ++ B ; 
	if(A < B) type = 1 ; 
	rep( i, 2, n ) if(vis[i] == type) {
		Qry(i) ;
		rep( j, 1, n ) if(dis[j] == 1) add(j, i) ; 
	}
	cout << "!" << endl ; 
	rep( i, 1, n ) rep( j, i + 1, n ) 
		if(a[i][j]) cout << i << " " << j << endl ; 
	return 0 ;
}