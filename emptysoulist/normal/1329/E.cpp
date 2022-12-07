#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
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
const int N = 4e5 + 5 ; 
const int inf = 1e16 ; 
int top, n, m, K, a[N], L, R ; 
struct node { int a, b ; } b[N] ;
int Ceil(double x) { int ans = (int)x ; return ans + (x > ans) ; }
int Floor(double x) { return (int)x ; }
int check1(int x) {
	int ans = 0 ; 
	rep( i, 1, m ) ans += Ceil(1.0 * a[i] / x) ;
	return ans <= K ; 
}
int check2(int x) {
	int ans = 0 ;
	rep( i, 1, m ) ans += Floor(1.0 * a[i] / x) ;
	return ans >= K ; 
}
multiset<int> S ; multiset<int>::iterator it ; 
bool cmp(node x, node y) { return x.a > y.a ; }
void solve() {
	n = gi(), m = gi(), K = gi() ; 
	int bef = 0, x ; 
	rep( i, 1, m ) x = gi(), a[i] = x - bef, bef = x ; 
	a[++ m] = n - bef, K += m ;  
	int l = 1, r = n ; L = 1 ; 
	while(l <= r) {
		int mid = (l + r) >> 1 ; 
		if(check2(mid)) L = mid, l = mid + 1 ; 
		else r = mid - 1 ; 
	}
	l = 1, r = n, R = n ; 
	while(l <= r) {
		int mid = (l + r) >> 1 ; 
		if(check1(mid)) R = mid, r = mid - 1 ; 
		else l = mid + 1 ; 
	}
	if(R <= L) return puts("0"), void() ; 
	int Ans = n ; S.clear(), top = 0, S.insert(R) ; 
	rep( i, 1, m ) {
		int ll = Ceil(1.0 * a[i] / R) ; 
		int rr = Floor(1.0 * a[i] / L) ; 
		if(ll <= rr) continue ; 
		int u = a[i] / ll, v = inf ; // u - l, v - r
		if(rr) v = Ceil(1.0 * a[i] / rr) ; 
		b[++ top] = (node){u, v}, S.insert(v) ; 
	}
	sort(b + 1, b + top + 1, cmp), it = S.end() ; -- it ; 
	Ans = min(Ans, (*it) - L) ; 
	for(int i = 1; i <= top; ++ i) {
		S.erase(S.find(b[i].b)), it = S.end(), -- it ;
		Ans = min(Ans, (*it) - b[i].a) ; 
	}
	printf("%lld\n", Ans ) ; 
} 
signed main()
{
	int T = gi() ; 
	while(T--) solve() ; 
	return 0 ;
}