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
#define fin freopen( "input.txt", "r", stdin );
#define fout freopen( "output.txt", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
lli a, b, h, i, j, ans, g = 1;
char c = 'l';

lli pow( lli x, lli y )
{
    lli ss;
    for( lli ii = ss = 1; ii <= x; ii++ ) ss = ss * 2;
    return ss;
}
int main()
{
    cin >> h >> a;
    h++;
    while( g < h ){
        if( c == 'l' ){
            if( a <= pow( 2, h - g - 1 ) + b ){
                ans++;
                c = 'r';
            }
            else{
                b = pow( 2, h - g - 1 ) + b;
                ans += pow(2, h - g);
            }
        }
        else{
            if( a <= pow( 2, h - g - 1 ) + b ) ans += pow(2, h - g);
            else{
                b = pow( 2, h - g - 1 ) + b;
                c = 'l';
                ans++;
            }
        }
        g++;
    }
    cout << ans;
}