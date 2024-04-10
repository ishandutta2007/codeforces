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
const int N = 2e5 + 5 ; 
int n, m, a[N], l[N], r[N], w[N] ; 
set<int> S ; 
set<int>::iterator it ; 
signed main()
{
	n = gi(), m = gi() ;
	rep( i, 1, n ) S.insert(i) ;  
	rep( i, 1, m ) l[i] = n + 1;  
	rep( i, 1, n ) a[i] = gi(), r[a[i]] = i ; 
	drep( i, 1, n ) l[a[i]] = i ; 
	vector<int> De ; 
	rep( i, 1, n ) w[i] = 1 ; 
	drep( i, 1, m ) if(l[i] <= r[i]) {
		De.clear() ;  
		it = S.lower_bound(l[i]) ; 
		while(it != S.end()) {
			if((*it) > r[i]) break ; 
			w[(*it)] = i, De.pb((*it)), ++ it ; 
		}
		for(int v : De) S.erase(v) ; 
	} 
	int flag = 0, fl = 1 ; 
	rep( i, 1, n ) if(w[i] == m) flag = 1 ; 
	rep( i, 1, n ) if(a[i] == 0) fl = 0 ; 
	if(!flag && fl) {
		puts("NO") ; exit(0) ; 
	}
	rep( i, 1, n ) {
		if(a[i]) {
			if(a[i] != w[i]) { puts("NO") ; exit(0) ; }
		}
		else {
			if(!flag) w[i] = m, flag = 1 ; 
			a[i] = w[i] ; 
		}
	}
	puts("YES") ; 
	rep( i, 1, n ) printf("%d ", a[i]) ; 
	return 0 ;
}