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
const int N = 4e5 + 5 ;
int n, I, a[N], limit, Len = 0, L[N], R[N] ; 
signed main()
{
	n = read(), I = read() ; 
	I = I * 8 / n ; limit = 1 ; 
	while( limit <= n ) ++ Len, limit <<= 1 ; 
	-- Len; 
	if( I <= Len ) I = 1 << I ;
	else return puts("0"), 0 ;
	rep( i, 1, n ) a[i] = read() ; 
	sort( a + 1, a + n + 1 ) ;
	int Now = 0, flag = 1 ; 
	rep( i, 1, n ) {
		if( ( a[i] != a[i - 1] ) && flag || i == 1 ) ++ Now, L[Now] = i, flag = 0 ;
		if( ( a[i] != a[i + 1] ) && !flag || i == n ) R[Now] = i, flag = 1 ; 
	}
	L[Now + 1] = n + 1 ;
	int Ans = n ;
	rep( i, 1, Now ) Ans = min( Ans, L[i] - 1 + n - L[min( Now + 1, i + I)] + 1 ) ;
	printf("%I64d\n", Ans ) ;
	return 0;
}