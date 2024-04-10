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

#define lli long long int
#define sc scanf
#define pr printf
#define pb push_back
#define p_b pop_back
#define mp make_pair
#define fi first
#define se second
#define fin freopen( "typo.in", "r", stdin );
#define fout freopen( "typo.out", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
int n, l[100011], d[100011], t[411111], get2, ans, t1[411111];
pair < int, pair < int, int > > p[100011];
pair < int, int > p1[100011];

void dd( int v, int l, int r, int g, int x )
{
    if( l == r ){
        t[v] = x;
        return;
    }
    int m = (l + r) / 2;
    if( g <= m )dd( v * 2, l , m, g, x );
    else dd( v * 2 + 1, m + 1, r, g, x );
    t[v] = t[v * 2] + t[v * 2 + 1];
}

void get( int x, int l, int r, int l1, int r1 )
{
    if( l1 > r1 )return;
    if( l == l1 && r == r1 ){
        get2 += t[x];
        return;
    }
    int m = (l + r) / 2;
    get( x * 2, l, m, l1, min(m, r1) );
    get( x * 2 + 1, m + 1, r, max(m + 1, l1), r1 );
}

void dd1( int v, int l, int r, int g )
{
    if( l == r ){
        t1[v] = 1;
        return;
    }
    int m = (l + r) / 2;
    if( g <= m )dd1( v * 2, l , m, g );
    else dd1( v * 2 + 1, m + 1, r, g );
    t1[v] = t1[v * 2] + t1[v * 2 + 1];
}

void get1( int x, int l, int r, int l1, int r1 )
{
    if( l1 > r1 )return;
    if( l == l1 && r == r1 ){
        get2 += t1[x];
        return;
    }
    int m = (l + r) / 2;
    get1( x * 2, l, m, l1, min(m, r1) );
    get1( x * 2 + 1, m + 1, r, max(m + 1, l1), r1 );
}


int main()
{
    ans = 999999999;
    int i, j, h, g, l, r, m, fr = 0;
    sc( "%d", &n );
    for( i = 1;  i <= n; i++ ){
        sc( "%d", &p[i].fi );
    }
    for( i = 1;  i <= n; i++ ){
        sc( "%d", &p[i].se.fi );
    }
    sort( p + 1, p + n + 1 );
    for( i = 1; i <= n; i++ ){
        p1[i].fi = p[i].se.fi;
        p1[i].se = i;
    }
    sort( p1 + 1, p1 + n + 1 );
    for( i = 1; i <= n; i++ ){
        p[p1[i].se].se.se = i;
        d[i] = d[i - 1] + p1[i].fi;
    }
    for( i = n; i >= 1; i-- ){
        j = i;
        while( p[i].fi == p[j].fi ){
            dd1( 1, 1, n, p[i].se.se );
            dd( 1, 1, n, p[i].se.se, p[i].se.fi );
            i--;
        }
        int nj = j - i;
        nj = nj + nj - 1;
        nj = max(0, j - nj);

        l = 0;
        r = n;
        while( l < r ){
            m = (l + r) / 2;
            get2 = 0;
            get1( 1, 1, n, 1, m );
            get2 = m - get2;
            if( get2 >= nj )r = m;
            else l = m + 1;
        }
        get2 = 0;
        get( 1, 1, n, 1, l );
        ans = min(ans, d[l] - get2 + fr );
        for( h = i + 1; h <= j; h++ )fr += p[h].se.fi;
        i = i + 1;
    }
    cout << ans;
}