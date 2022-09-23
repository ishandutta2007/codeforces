#include <bits/stdc++.h>

#define lli long long int
#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin freopen( "input.txt", "r", stdin );
#define fout freopen( "output.txt", "w", stdout );

using namespace std;

int n, t[1200000];

void push( int x )
{
    if( !t[x * 2] )
        t[x * 2] = t[x];
    if( !t[x * 2 + 1] )
        t[x * 2 + 1] = t[x];
    t[x] = 0;
}

void up( int x, int l, int r, int tl, int tr, int g )
{
    if( tl > tr )
        return;
    if( l == tl && r == tr ){
        if( !t[x] )
            t[x] = g;
        return;
    }
    push(x);
    int m = (l + r) / 2;
    up(x * 2, l, m, tl, min(m, tr), g);
    up(x * 2 + 1, m + 1, r, max(m + 1, tl), tr, g);
}

int take( int x, int l, int r, int g )
{
    if( l == r )
        return t[x];
    push(x);
    int m = (l + r) / 2;
    if( g <= m )
        return take(x * 2, l, m, g);
    else
        return take(x * 2 + 1, m + 1, r, g);
}

int main()
{
    int m, i, j, h, l, r, x;
    sc( "%d%d", &n, &m );
    for( i = 1; i <= m; i++ ){
        sc( "%d%d%d", &l, &r, &x );
        up(1, 1, n, l, x - 1, x);
        up(1, 1, n, x + 1, r, x);
    }
    for( i = 1; i <= n; i++ )
        pr( "%d ", take(1, 1, n, i) );
}