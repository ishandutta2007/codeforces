#include<bits/stdc++.h>
using namespace std;
#define rep( i, s, t ) for( register int i = s; i <= t; ++ i )
#define re register
#define int long long
int read() {
	char cc = getchar(); int cn = 0, flus = 1;
	while(cc < '0' || cc > '9') {  if( cc == '-' ) flus = -flus;  cc = getchar();  }
	while(cc >= '0' && cc <= '9')  cn = cn * 10 + cc - '0', cc = getchar();
	return cn * flus;
}
const int N = 1e6 + 5 ; 
int n, m, k, h[N] ;
bool solve() {
	int now = m, H, goH; 
	for( int i = 1; i < n; ++ i ) {
		now += h[i], H = 0 ; 
		goH = max( h[i + 1] - k, 0ll ) ;
		if( now >= goH ) now -= goH ;
		else return 0 ;
	}
	return 1 ; 
}
signed main()
{
	int T = read() ; 
	while( T-- ) {
		n = read(), m = read(), k = read() ; 
		rep( i, 1, n ) h[i] = read() ; 
		int flag = solve() ; 
		if( flag ) puts("YES");
		else puts("NO");
	}
	return 0;
}