#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5 ; 
#define rep( i, s, t ) for( register int i = s; i <= t; ++ i )
int n, a[N], flag ; 
char s[N] ; 
signed main()
{
	cin >> n ; 
	scanf("%s", s ) ; 
	rep( i, 1, n ) a[i] = s[i - 1] - 'a' + 1 ; 
	int ll = 1, rr = 0 ;
	rep( i, 2, n ) {
		if( a[i] >= a[ll] ) ll = i ; 
		else {
			rr = i; break ; 
		}
	}
	if( rr ) {
		puts("YES"); printf("%d %d\n", ll, rr ) ;
	}
	else puts("NO") ; 
	return 0 ;
}