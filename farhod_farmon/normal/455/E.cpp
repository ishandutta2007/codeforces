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

const int N = 100100;

using namespace std;

int a[N], n, pre[N], k[N], b[N];
vector < int > v[4 * N];

long double ix( int x, int y )
{
    return (1.0 * (b[y] - b[x])) / (1.0 * (k[x] - k[y]));
}

void build( int t, int l, int r )
{
    if( l == r ){
        v[t].pb(a[l]);
        return;
    }
    int m = (l + r) / 2;
    build(t * 2, l, m);
    build(t * 2 + 1, m + 1, r);
    vector < int > g;
    int j = m + 1;
    for( int i = l; i <= m; i++ ){
        while( j <= r && (k[a[j]] > k[a[i]] || k[a[j]] == k[a[i]] && b[a[j]] < b[a[i]]) )
            g.pb(a[j++]);
        g.pb(a[i]);
    }
    while( j <= r )
        g.pb(a[j++]);
    for( int i = 0; i < g.size(); i++ )
        a[l + i] = g[i];
    for( int i = l; i <= r; i++ ){
        if( v[t].size() && k[a[i]] == k[v[t].back()] )
            continue;
        while( v[t].size() > 1 && ix(v[t][v[t].size() - 2], a[i]) <= ix(v[t][v[t].size() - 2], v[t][v[t].size() - 1]) )
            v[t].pop_back();
        v[t].pb(a[i]);
    }
}

int bin( vector < int > h, int x )
{
    int l = 0, r = h.size() - 1;
    while( l < r ){
        int m = (l + r) / 2;
        if( ix(h[m], h[m + 1]) < (long double)x )
            l = m + 1;
        else
            r = m;
    }
    return k[h[l]] * x + b[h[l]];
}

int get( int t, int l, int r, int tl, int tr, int x )
{
    if( tl > tr )
        return 1e18;
    if( l == tl && r == tr )
        return bin(v[t], x);
    int m = (l + r) / 2;
    return min(get(t * 2, l, m, tl, min(m, tr), x), get(t * 2 + 1, m + 1, r, max(tl, m + 1), tr, x));
}

int main()
{
    sc( "%d", &n );
    for( int i = 1; i <= n; i++ ){
        sc ( "%d", &a[i] );
        pre[i] = pre[i - 1] + a[i];
        k[i] = a[i];
        b[i] = a[i] * i - pre[i];
        a[i] = i;
    }
    build(1, 1, n);
    int m;
    sc( "%d", &m );
    for( int i = 1; i <= m; i++ ){
        int x, y;
        sc( "%d%d", &x, &y );
        pr( "%d\n", pre[y] + get(1, 1, n, y - x + 1, y, x - y) );
    }
}