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

const int N = 100101;

using namespace std;

lli n, ans[N], t[4 * N];
pair < pair < lli, lli >, pair < lli, lli > > p[N];
vector < lli > timem;
map < lli, lli > tim;

void add( lli x, lli l, lli r, lli g )
{
    if( l == r ){
        t[x] = 1;
        return;
    }
    lli m = (l + r) / 2;
    if( g <= m )
        add(x * 2, l, m, g);
    else
        add(x * 2 + 1, m + 1, r, g);
    t[x] = t[x * 2] + t[x * 2 + 1];
}

bool sub( lli x, lli l, lli r, lli g )
{
    if( l == r ){
        t[x] = -1;
        return true;
    }
    lli m = (l + r) / 2;
    if( g <= m ){
        sub(x * 2, l, m, g);
        t[x] = t[x * 2] + t[x * 2 + 1];
        return true;
    }
    else{
        sub(x * 2 + 1, m + 1, r, g);
        t[x] = t[x * 2] + t[x * 2 + 1];
        return true;
    }
}

void cl( lli x, lli l, lli r, lli g )
{
    if( l == r ){
        t[x] = 0;
        return;
    }
    lli m = (l + r) / 2;
    if( g <= m )
        cl(x * 2, l, m, g);
    else
        cl(x * 2 + 1, m + 1, r, g);
    t[x] = 0;
}

lli get( lli x, lli l, lli r, lli g )
{
    if( l > g )
        return 0;
    if( r <= g )
        return t[x];
    lli m = (l + r) / 2;
    return get(x * 2, l, m, g) + get(x * 2 + 1, m + 1, r, g);
}

int main()
{
    sc( "%I64d", &n );
    for( lli i = 1; i <= n; i++ ){
        sc( "%I64d%I64d%I64d", &p[i].se.se, &p[i].se.fi, &p[i].fi.fi );
        p[i].fi.se = i;
        ans[i] = -1;
        timem.pb(p[i].se.fi);
    }
    sort( p + 1, p + n + 1 );
    sort( timem.begin(), timem.end() );
    for( lli i = 0; i < timem.size(); i++ )
        tim[timem[i]] = i + 1;
    for( lli i = 1; i <= n; i++ ){
        vector < pair < lli, pair < lli, lli > > > v;
        lli j;
        for( j = i; j <= n && p[i].fi.fi == p[j].fi.fi; j++ )
            v.pb(mp(tim[p[j].se.fi], mp(p[j].se.se, p[j].fi.se)));
        i = j - 1;
        for( j = 0; j < v.size(); j++ )
            if( v[j].se.fi == 3 )
                ans[v[j].se.se] = get(1, 1, n, v[j].fi);
            else if( v[j].se.fi == 1 )
                add(1, 1, n, v[j].fi);
            else
                sub(1, 1, n, v[j].fi);
        for( j = 0; j < v.size(); j++ )
            if( v[j].se.fi != 3 )
                cl(1, 1, n, v[j].fi);
    }
    for( lli i = 1; i <= n; i++ )
        if( ans[i] != -1 )
            pr( "%I64d\n", ans[i] );
}