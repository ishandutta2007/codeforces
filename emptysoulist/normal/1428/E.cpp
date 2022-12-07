#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
#define int long long
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 2e5 + 5 ; 
int n, K, a[N], Ans ; 
struct node {
	int w, c, k ; 
	bool operator < (const node &x) const {
		return w < x.w ; 
	}
} ;
priority_queue<node> q ; 
int G(int x) {
	return x * x ; 
} 
int f(int x, int k) {
	int z = x % k ; 
	int u = x / k ; 
	return z * G(u + 1) + (k - z) * G(u) ; 
}
signed main()
{
	n = gi(), K = gi() ; 
	rep( i, 1, n ) a[i] = gi() ; 
	rep( i, 1, n ) Ans += a[i] * a[i] ; 
	rep( i, 1, n ) q.push((node){ a[i] * a[i] - f(a[i], 2), a[i], 2 }) ; 
	K -= n ; 
	rep( i, 1, K ) {
		node u = q.top() ; q.pop() ; 
		Ans -= u.w ; 
		int k = u.k ; 
		q.push((node){ f(u.c, k) - f(u.c, k + 1), u.c, k + 1}) ;
	}
	cout << Ans << endl ; 
	return 0 ;
}