#include<bits/stdc++.h>
using namespace std ;
#define rep( i, s, t ) for( int i = (s); i <= (t); ++ i )
#define pb push_back
#define vi vector<int>
#define int long long
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 3e5 + 5 ; 
int n, qwq, cnt1, cnt2, cnt3, num, c[N], b[N], d[N], dep[N], a[N], f[N] ; 
vi G[N] ; 
bool cmp(int x, int y) { return a[x] < a[y] ; }
void Out() { puts("NO") ; exit(0) ; }
void DFS(int x) {
	d[x] = ++ cnt1, dep[x] = dep[f[x]] + 1 ; vector<int> st ; 
	if(a[x] < num) qwq += dep[x] ; 
	else b[x] = cnt3 ++, b[x] += num ;  
	for(int v : G[x]) st.pb(v) ; 
	sort(st.begin(), st.end(), cmp) ; 
	for(int v : st) DFS(v) ; 
	c[x] = ++ cnt2 ; 
}
signed main()
{
	n = gi(), dep[0] = -1 ; int x, y ; 
	rep( i, 1, n ) a[i] = gi() ; 
	rep( i, 2, n ) x = gi(), y = gi(), G[x].pb(y), f[y] = x ; 
	num = a[1] ; 
	if(num != 1) {
		int u = 0 ; -- num ; 
		rep( i, 1, n ) if(a[i] == num) u = i ; 
		while(u != 1) {
			x = f[u], swap(a[u], a[f[u]]) ; if(a[u] < a[f[u]]) Out() ; 
			for(int v : G[x]) if((a[v] > num) && (a[v] < a[u])) Out() ; 
			u = x, ++ qwq ; 
		}
	} DFS(1) ; 
	rep( i, 1, n ) if((a[i] < num) && (a[i] != c[i])) Out() ; 
	rep( i, 1, n ) if((a[i] >= num) && (a[i] != b[i])) Out() ; 
	puts("YES") ; 
	cout << qwq << endl ; 
	rep( i, 1, n ) printf("%lld ", d[i]) ; 
	return 0 ; 
}