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

const int N = 500002;

using namespace std;

lli n, q, d[N], a[N], ans, kol;
vector < lli > v[N];
bool used[N];

void add( lli x )
{
    used[x] = true;
    x = a[x];
    lli i, j, cnt = 0;
    for( i = 1; i < (1 << v[x].size()); i++ ){
        lli h = 0, y = 1;
        for( j = 0; j < v[x].size(); j++ ){
            if( i & (1 << j) )
                h++, y *= v[x][j];
        }
        if( h % 2 )
            cnt += d[y];
        else
            cnt -= d[y];
        d[y]++;
    }
    ans += kol - cnt;
    kol++;
}

void sub( lli x )
{
    used[x] = false;
    x = a[x];
    lli i, j, cnt = 0;
    for( i = 1; i < (1 << v[x].size()); i++ ){
        lli h = 0, y = 1;
        for( j = 0; j < v[x].size(); j++ ){
            if( i & (1 << j) )
                h++, y *= v[x][j];
        }
        d[y]--;
        if( h % 2 )
            cnt += d[y];
        else
            cnt -= d[y];
    }
    kol--;
    ans -= kol - cnt;
}

int main()
{
    lli i, j, x;
    for( i = 2; i < N; i++ ){
        if( !v[i].empty() )
            continue;
        for( j = i; j < N; j += i )
            v[j].pb(i);
    }
    sc( "%d%d", &n, &q );
    for( i = 1; i <= n; i++ )
        sc( "%d", &a[i] );
    for( i = 1; i <= q; i++ ){
        sc( "%d", &x );
        if( !used[x] )
            add(x);
        else
            sub(x);
        pr( "%I64d\n", ans );
    }
}