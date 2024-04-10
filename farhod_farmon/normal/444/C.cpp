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

lli n, q;
pair < lli, lli > t[4 * N];
set < pair < pair < lli, lli >, lli > > s;
set < pair < pair < lli, lli >, lli > > :: iterator it;

void push( lli x, lli l, lli r )
{
    if( !t[x].se )
        return;
    lli m = (l + r) / 2;
    t[x * 2].se += t[x].se;
    t[x * 2].fi += t[x].se * (m - l + 1);
    t[x * 2 + 1].se += t[x].se;
    t[x * 2 + 1].fi += t[x].se * (r - m);
    t[x].se = 0;
}

void upd( lli x, lli l, lli r, lli tl, lli tr, lli y )
{
    if( tl > tr )
        return;
    if( l == tl && r == tr ){
        t[x].se += y;
        t[x].fi += y * (r - l + 1);
        return;
    }
    push(x, l, r);
    lli m = (l + r) / 2;
    upd(x * 2, l, m, tl, min(m, tr), y);
    upd(x * 2 + 1, m + 1, r, max(m + 1, tl), tr, y);
    t[x].fi = t[x * 2].fi + t[x * 2 + 1].fi;
}

lli get( lli x, lli l, lli r, lli tl, lli tr )
{
    if( tl > tr )
        return 0;
    if( l == tl && r == tr )
        return t[x].fi;
    lli m = (l + r ) / 2;
    push(x, l, r);
    t[x].fi = t[x * 2].fi + t[x * 2 + 1].fi;
    return get(x * 2, l, m, tl, min(tr, m)) + get(x * 2 + 1, m + 1, r, max(m + 1, tl), tr);
}

int main()
{
    lli i, j, h, x, y, z, l, r, m, type;
    sc( "%I64d%I64d", &n, &q );
    for( i = 1; i <= n; i++ )
        s.insert(mp(mp(i, i), i));
    for( i = 1; i <= q; i++ ){
        sc( "%I64d", &type );
        if( type == 2 ){
            sc( "%I64d%I64d", &l, &r );
            pr( "%I64d\n", get(1, 1, n, l, r) );
        }
        else{
            sc( "%I64d%I64d%I64d", &l, &r, &x );
            //continue;
            lli pl = l, pr = r;
            pair < pair < lli, lli >, lli > p;
            while( l <= r ){
                it = s.lower_bound(mp(mp(l, l), -1));
                if( it == s.end() || it->fi.fi > l )
                    it--;
                p = *it;
                s.erase(it);
                lli tr = min(r, p.fi.se);
                lli tl = max(l, p.fi.fi);
                //cout << i << " " << p.fi.fi << " " << p.fi.se << endl;
                if( tl > p.fi.fi ){
                    s.insert(mp(mp(p.fi.fi, tl - 1), p.se));
                }
                upd(1, 1, n, tl, tr, abs(x - p.se));
                l = tr + 1;
            }
            s.insert(mp(mp(pl, pr), x));
            if( r < p.fi.se )
                s.insert(mp(mp(r + 1, p.fi.se), p.se));
        }
    }
    /*it = s.begin();
    while( it != s.end() ){
        cout << it->fi.fi << " " << it->fi.se << " " << it->se << endl;
        it++;
    }*/
}