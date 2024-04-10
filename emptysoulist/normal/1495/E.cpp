#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( int i = (t); i >= (s); -- i )
#define mp make_pair
#define pi pair<int, int>
#define pb push_back
#define int long long
#define vi vector<int>
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int mod = 1e9 + 7 ; 
const int N = 2e5 + 5 ; 
const int M = 5e6 + 5 ; 
using namespace std;
int seed = 0;
int base = 0;

int rnd() {
    int ret = seed;
    seed = (seed * base + 233) % mod;
    return ret;
}

int n, m, p[N], k[N], b[N], w[N] ; 
int a[M], t[M], ans[M], anss = 1, cntw, cntb, a0[M] ;
signed main() {
	n = gi(), m = gi() ; 
    for (int i = 1; i <= m; i++)
        p[i] = gi(), k[i] = gi(), b[i] = gi(), w[i] = gi() ; 

    p[0] = 0;

    for (int i = 1; i <= m; i++) {
        seed = b[i];
        base = w[i];

        for (int j = p[i - 1] + 1; j <= p[i]; j++) {
            t[j] = (rnd() % 2) + 1;
            a[j] = (rnd() % k[i]) + 1;
        }
    }

    if (t[1] == 2)
        for (int i = 1; i <= n; i++)
            t[i] = 3 - t[i];

    for (int i = 1; i <= n; i++)
        if (t[i] == 1)
            cntw += a[i];
        else
            cntb += a[i];

    memcpy(a0, a, sizeof(a));

    if (cntw > cntb) {
        int tmp(0);
        --a[1];

        for (int i = 1; i <= n; i++)
            if (t[i] == 2)
                tmp += a[i], a[i] = 0;
            else if (tmp >= a[i])
                tmp -= a[i], a[i] = 0;
            else
                a[i] -= tmp, tmp = 0;

        for (int i = 1; i <= n; i++)
            if (t[i] == 2)
                tmp += a[i], a[i] = 0;
            else if (tmp >= a[i])
                tmp -= a[i], a[i] = 0;
            else
                a[i] -= tmp, tmp = 0;

        memcpy(ans, a, sizeof(a));
    } else {
        int tmp(0);

        rep( i, 1, n ) 
            if (t[i] == 1)
                tmp += a[i], a[i] = 0 ;
            else if (tmp >= a[i])
                tmp -= a[i], a[i] = 0 ;
            else
                a[i] -= tmp, tmp = 0 ;

        rep( i, 1, n ) 
            if (t[i] == 1)
                tmp += a[i], a[i] = 0 ; 
            else if (tmp >= a[i])
                tmp -= a[i], a[i] = 0 ;
            else
                a[i] -= tmp, tmp = 0 ;

        memcpy(ans, a, sizeof(a)) ;
    } 
    rep( i, 1, n ) 
        (anss *= (((a0[i] - ans[i]) ^ (i * i)) + 1) % mod) %= mod;

    printf("%lld", anss);
    return 0;
}