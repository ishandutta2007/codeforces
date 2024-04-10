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

#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back
#define p_b pop_back
#define pf push_front
#define p_f pop_front
#define mp make_pair
#define lli long long int
#define p_q priority_queue
#define fin freopen( "INPUT.TXT", "r", stdin );
#define fout freopen( "OUTPUT.TXT", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
#define INF 1000000000000000000ll
using namespace std;
lli a, b, i, j, l, r, m;
char s[1000001];
vector < lli > v;

lli hsh( string y )
{
    lli ans = 0, p = 1;
    for( int h = 0; h < y.size(); h++ ){
        ans = (ans + (y[h] - 'a' + 1) * p) % INF;
        p = (p * 3) % INF;
    }
    return ans;
}

bool fd( lli x )
{
    l = 0;
    r = v.size() - 1;
    while( l < r ){
        m = (l + r) / 2;
        if( v[m] <= x && v[m + 1] <= x ) l = m + 1;
        else r = m;
    }
    if( v[l] == x )return true;
    return false;
}

int main()
{
    sc( "%d%d", &a, &b );
    for( i = 1; i <= a; i++ ){
        sc( "%s", &s );
        v.pb(hsh(s));
    }
    sort( v.begin(), v.end() );
    for( i = 1; i <= b; i++ ){
        bool b1 = false;
        sc( "%s", &s );
        lli x = hsh(s);
        lli p = 1;
        int len = strlen(s);
        for( j = 0; j < len; j++  ){
            lli y = x - (s[j] - 'a' + 1) * p;
            if( y < 0 )y += 4 * INF;
            if( s[j] != 'a' && fd((y + p * 1) % INF) )b1 = true;
            if( s[j] != 'b' && fd((y + p * 2) % INF) )b1 = true;
            if( s[j] != 'c' && fd((y + p * 3) % INF) )b1 = true;
            p = (p * 3) % INF;
        }
        if( b1 )pr( "YES\n" );
        else pr( "NO\n" );
    }
}