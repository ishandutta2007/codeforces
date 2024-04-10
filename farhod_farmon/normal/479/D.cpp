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
#define fin freopen( "milk.in", "r", stdin );
#define fout freopen( "input.txt", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
lli a, l, x, y, i, j, h, z, r, m, c[100001], g1, g2;
bool b1, b2;
vector < lli > xx, yy;

lli fd( lli l1, lli r1, lli x1 )
{
    while( l1 < r1 ){
        lli m1 = (l1 + r1) / 2;
        if( x1 > c[m1] )l1 = m1 + 1;
        else r1 = m1;
    }
    return l1;
}

int main ()
{
    b1 = b2 = false;
    sc( "%I64d%I64d%I64d%I64d", &a, &l, &x, &y );
    for( i = 1; i <= a; i++ )sc( "%I64d", &c[i] );
    for( i = 1; i <= a; i++ ){
        if( c[i] >= x ){
            g1 = fd(1, i - 1, c[i] - x);
            if( c[i] == x || c[g1] == c[i] - x )b1 = true;
            else xx.pb(c[i] - x);
        }
        if( c[i] >= y ){
            g1 = fd(1, i - 1, c[i] - y);
            if( c[i] == y || c[g1] == c[i] - y )b2 = true;
            else yy.pb(c[i] - y);
        }
        if( c[i] + x <= l ){
            g1 = fd(1, a, c[i] + x);
            if( c[g1] == c[i] + x )b1 = true;
            else xx.pb(c[i] + x);
        }
        if( c[i] + y <= l ){
            g1 = fd(1, a, c[i] + y);
            if( c[g1] == c[i] + y )b2 = true;
            else yy.pb(c[i] + y);
        }
    }
    if( b1 && b2 )pr("0");
    else if( b1 && !b2 )pr("1\n%I64d", yy[0]);
    else if( !b1 && b2 )pr("1\n%I64d", xx[0]);
    else{
        sort( xx.begin(), xx.end() );
        sort( yy.begin(), yy.end() );
        for( i = j = 0; i < xx.size(); i++ ){
            while( j < yy.size() - 1 && xx[i] > yy[j] )j++;
            if( yy[j] == xx[i] ){
                pr("1\n%I64d", yy[j]);
                return 0;
            }
        }
        pr("2\n%I64d %I64d", xx[0], yy[0]);
    }
}