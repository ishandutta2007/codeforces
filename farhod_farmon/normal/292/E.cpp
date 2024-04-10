#include <bits/stdc++.h>

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

const int N = 100001;

using namespace std;

int n, t[4 * N], a[N], b[N];

void push( int x, int l, int r )
{
    if( !t[x] )return;
    t[x * 2] = t[x];
    int m = (l + r) / 2;
    t[x * 2 + 1] = t[x] + m - l + 1;
    t[x] = 0;
}

void chan( int x, int l, int r, int tl, int tr, int y )
{
    if( tl > tr )return;
    if( l == tl && r == tr ){
        t[x] = y;
        return;
    }
    int m = (l + r) / 2;
    push(x, l, r);
    chan(x * 2, l, m, tl, min(m, tr), y);
    chan(x * 2 + 1, m + 1, r, max(m + 1, tl), tr, y + max(0, m - tl + 1));
}

int take( int x, int l, int r, int g )
{
    if( l == r ){
        if( !t[x] )return b[l];
        return a[t[x]];
    }
    int m = (l + r) / 2;
    push(x, l, r);
    if( g <= m )return take(x * 2, l, m, g);
    else return take(x * 2 + 1, m + 1, r, g);
}

int main()
{
    int i, j, x, m, l, r;
    sc( "%d%d", &n, &m );
    for( i = 1; i <= n; i++ )sc( "%d", &a[i] );
    for( i = 1; i <= n; i++ )sc( "%d", &b[i] );
    for( i = 1; i <= m; i++ ){
        sc( "%d", &j );
        if( j == 1 ){
            sc( "%d%d%d", &l, &r, &x );
            chan(1, 1, n, r, r + x - 1, l);
        }
        else{
            sc( "%d", &x );
            pr( "%d\n", take(1, 1, n, x) );
        }
    }
}