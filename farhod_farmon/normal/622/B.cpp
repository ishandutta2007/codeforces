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

using namespace std;

int x, y, i, j, n;

int main()
{
    sc( "%d:%d", &x, &y );
    sc( "%d", &n );
    for( i = 1; i <= n; i++ ){
        y++;
        if( y == 60 ){
            y = 0;
            x++;
        }
        if( x == 24 )x = 0;
    }
    if( x < 10 )pr("0");
    pr("%d:", x);
    if( y < 10 )pr("0");
    pr("%d", y);
}