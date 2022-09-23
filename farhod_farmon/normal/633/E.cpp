#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <map>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <iomanip>

#define lli long long int
#define sc scanf
#define pr printf
#define pb push_back
#define p_b pop_back
#define mp make_pair
#define fi first
#define se second
#define fin freopen( "input.txt", "r", stdin );
#define fout freopen( "output.txt", "w", stdout );

const int N = 1000002;

using namespace std;

pair < int, int > t[N][20];
int a[N], b[N], n, k, f[N];

pair < int, int > comb( pair < int, int > x, pair < int, int > y )
{
    return mp(max(x.fi, y.fi), min(x.se, y.se));
}

void build( )
{
    int i, j, h;
    for( i = n; i >= 1; i-- ){
        t[i][0] = mp(a[i], b[i]);
        for( j = 1; j < 20; j++ )t[i][j] = comb(t[i][j - 1], t[min(n, i + (1 << j) / 2)][j - 1]);
    }
}

pair < int, int > take( int l, int r )
{
    int g = f[r - l + 1];
    return comb(t[l][g], t[r - (1 << g) + 1][g]);
}

int main()
{
    int i, l, r, m;
    sc("%d%d", &n, &k);
    for( i = 1; i <= n; i++ )sc("%d", &a[i]);
    for( i = 1; i <= n; i++ )sc("%d", &b[i]);
    for( i = 2; i <= n; i++ )f[i] = f[i / 2] + 1;
    build();
    for( i = 1; i <= n; i++ ){
        l = i;
        r = n;
        while( l < r ){
            m = (l + r) / 2;
            pair < int, int > p = take(i, m);
            if( p.se >= p.fi * 100 )l = m + 1;
            else r = m;
        }
        pair < int, int > p = take(i, l);
        a[i] = min(p.fi * 100, p.se);
        if( l - 1 >= i ){
            l = l - 1;
            p = take(i, l);
            a[i] = max(a[i], min(p.fi * 100, p.se));
        }
    }
    sort( a + 1, a + n + 1 );
    long double ans = 0;
    long double g = 1. * k / n;
    for( i = 1; i <= n - k + 1; i++ ){
        ans += a[i] * g;
        g *= (1. * (n - k - i + 1) / (n - i));
    }
    pr("%.6lf\n", (double)ans);
}