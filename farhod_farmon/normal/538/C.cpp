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
int main()
{
    bool b1 = true;
    int a, i, j, b, x[100001], y[100001], ans = 0;
    cin >> a >> b;
    for( i = 1; i <= b; i++ ){
        sc( "%I64d%I64d", &x[i], &y[i] );
        if( i > 1 ){
            if( abs( x[i - 1] - x[i] ) < abs( y[i -1] - y[i] ) ) b1 = false;
            int l = x[i - 1], r = x[i];
            while( l < r ){
                int m = (l + r) / 2;
                if( (m - x[i - 1]) + y[i - 1] - (x[i] - m) <= y[i] && ((m + 1) - x[i - 1]) + y[i - 1] - (x[i] - (m + 1)) <= y[i] )l = m + 1;
                else r = m;
            }
            ans = max( ans, y[i - 1] + l - x[i - 1] );
        }
    }
    if( !b1 )cout << "IMPOSSIBLE";
    else cout << max( ans, max( y[1] + x[1] - 1, y[b] + a - x[b] ) );
}