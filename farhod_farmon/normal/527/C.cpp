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
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )

const int N = 200002;

using namespace std;

lli n, w, h;
pair < lli, pair < lli, lli > > t[3][N * 4];

void bu( lli x, lli y, lli l, lli r )
{
    t[y][x] = mp(r - l, mp(r, l));
    if( l == r )return;
    lli m = (l + r) / 2;
    bu(x * 2, y, l, m);
    bu(x * 2 + 1, y, m + 1, r);
}

void up( lli x, lli y, lli l, lli r, lli g )
{
    if( l == r )return;
    lli m = (l + r) / 2;
    if( g <= m )up(x * 2, y, l, m, g);
    else up(x * 2 + 1, y, m + 1, r, g);
    t[y][x] = mp( max( t[y][x * 2 + 1].se.fi - t[y][x * 2].se.se, max( t[y][x * 2].fi, t[y][x * 2 + 1].fi ) ),
                 mp(min(t[y][x].se.fi, g), max(t[y][x].se.se, g)) );
}

int main()
{
    lli i, j, h, g, x, y;
    char c;
    cin >> w >> h >> n;
    swap(w, h);
    bu(1, 1, 0, w); bu(1, 2, 0, h);
    for( i = 1; i <= n; i++ ){
        cin >> c >> x;
        if( c == 'H' )up(1, 1, 0, w, x);
        else up(1, 2, 0, h, x);
        cout << t[1][1].fi * t[2][1].fi << endl;
    }
}