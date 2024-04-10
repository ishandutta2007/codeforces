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

using namespace std;

int n, l[10011][511], r[10011][511], i, j, h, p[511], m, q, cnt;
bool used[511];

int take1( int x, int y )
{
    if( l[x][y] == y )return y;
    else return (l[x][y] = take1(x, l[x][y]));
}

int take2( int x, int y )
{
    if( r[x][y] == y )return y;
    else return (r[x][y] = take2(x, r[x][y]));
}

int take( int x )
{
    if( p[x] == x )return x;
    else return p[x] = take(p[x]);
}

int main()
{
    int x[10011], y[10011];
    sc( "%d%d", &n, &m );
    for( i = 1; i <= m; i++ )sc( "%d%d", &x[i], &y[i] );
    for( i = 1; i <= n; i++ )l[0][i] = r[m + 1][i] = i;
    for( i = 1; i <= m; i++ ){
        for( j = 1; j <= n; j++ )l[i][j] = l[i - 1][j];
        int xx = take1(i, x[i]);
        int yy = take1(i, y[i]);
        if( xx != yy )l[i][xx] = yy;
    }
    for( i = m; i >= 1; i-- ){
        for( j = 1; j <= n; j++ )r[i][j] = r[i + 1][j];
        int xx = take2(i, x[i]);
        int yy = take2(i, y[i]);
        if( xx != yy )r[i][xx] = yy;
    }
    int ll, rr;
    sc( "%d", &q );
    for( i = 1; i <= q; i++ ){
        sc( "%d%d", &ll, &rr );
        for( j = 1; j <= n; j++ )p[j] = take1(ll - 1, j);
        for( j = 1; j <= n; j++ ){
            int xx = p[j];
            int yy = take2(rr + 1, j);
            xx = take(xx);
            yy = take(yy);
            if( xx != yy )p[xx] = yy;
            used[j] = false;
        }
        cnt = 0;
        for( j = 1; j <= n; j++ ){
            take(j);
            if( used[p[j]] )continue;
            used[p[j]] = true;
            cnt++;
        }
        pr( "%d\n", cnt );
    }
}