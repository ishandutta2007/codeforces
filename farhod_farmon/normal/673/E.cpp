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

const int N = 200200;

using namespace std;

long double d[55][N], p[N], k[N], b[N];
lli n, s[N], a[N];
vector < lli > v;

long double in( lli i, lli j )
{
    return (b[j] - b[i]) / (k[i] - k[j]);
}

void add( lli h )
{
    while( v.size() > 1 && in(v[v.size() - 2], v[v.size() - 1]) > in(v[v.size() - 2], h) )
        v.pop_back();
    v.pb(h);
}

long double get( long double x )
{
    lli l = 0, r = v.size() - 1, m;
    while( l < r ){
        m = (l + r) / 2;
        if( in(v[m], v[m + 1]) < x )
            l = m + 1;
        else
            r = m;
    }
    return k[v[l]] * x + b[v[l]];
}

int main()
{
    lli m;
    sc( "%I64d%I64d", &n, &m );
    for( lli i = 1; i <= n; i++ ){
        sc( "%I64d", &a[i] );
        s[i] = s[i - 1] + a[i];
        p[i] = p[i - 1] + 1.0 / a[i];
        d[1][i] = d[1][i - 1] + 1.0 * s[i] / a[i];
    }
    for( lli i = 2; i <= m; i++ ){
        v.clear();
        for( lli j = i; j <= n; j++ ){
            k[j - 1] = -s[j - 1];
            b[j - 1] = d[i - 1][j - 1] - d[1][j - 1] + p[j - 1] * s[j - 1];
            add(j - 1);
            d[i][j] = d[1][j] + get(p[j]);
        }
    }
    pr( "%.7f", (double)d[m][n] );
}