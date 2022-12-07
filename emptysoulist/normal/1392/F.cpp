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
signed main() {
    int n = gi(), sum = 0;
    for (int i = 1; i <= n; i++) sum += gi();
    int x = ((((sum * 2) / n) - n + 1) / 2 ) ;
	int y = sum - ((((x * 2) + n - 1) * n) / 2 ) ;
    for (int i = 1; i <= n; i++)
        if (i <= y)
            printf("%lld ", i + x);
        else
            printf("%lld ", i + x - 1);
    return 0;
}