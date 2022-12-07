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
const int inf = 1e9 ; 
const int N = 8e5 + 5 ; 
int n, a[N], b[N], id[N], Mi, L, R, tl, tr ; 
bool cmp(int x, int y) { return a[x] < a[y] ; }
multiset<int> Sl, Sr ; 
multiset<int>::iterator it ; 
signed main() { 
	n = gi() ; int x, y ; 
	rep( i, 1, n ) x = gi(), y = gi(), a[i] = x + y, b[i] = x - y ; 
	rep( i, 1, n ) id[i] = i ;  
	sort(id + 1, id + n + 1, cmp) ; 
	rep( i, 0, n ) Sl.insert(0) ; Sl.insert(inf) ;
	rep( i, 0, n ) Sr.insert(0) ; Sr.insert(inf) ; 
	int ans = 0 ; 
	for(int i = 1; i <= n; ++ i) {
		int d = a[id[i]] - a[id[i - 1]] ;
		L -= d, R += d, tl -= d, tr += d, y = b[id[i]] ; 
		if(y <= L) {
			Sl.insert(tl - y), Sl.insert(tl - y), it = Sl.begin() ; 
			int v = tl - (*it) ;  
			Sl.erase(it), Sr.insert(R - tr), 
			ans += abs(L - y), R = L, L = v ; 
		} else if(y <= R) {
			Sl.insert(tl - L), Sr.insert(R - tr), L = y, R = y ; 
		} else {
			Sr.insert(y - tr), Sr.insert(y - tr), it = Sr.begin() ; 
			int v = (*it) + tr ; 
			Sr.erase(it), Sl.insert(tl - L),
			ans += abs(R - y), L = R, R = v ; 
		}
	}
	cout << ans / 2 << endl ; 
	return 0 ; 
}