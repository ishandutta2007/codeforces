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

#define lli long long int
#define sc scanf
#define pr printf
#define pb push_back
#define p_b pop_back
#define mp make_pair
#define fi first
#define se second
#define fin freopen( "typo.in", "r", stdin );
#define fout freopen( "typo.out", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
lli a, i, j, ans, d[11], g, b;
int main()
{
    cin >> a;
    b = a;
    while( b ){
        g++;
        b /= 10;
    }
    int x = 1;
    for( i = 1; i < g; i++ ){
        x *= 10;
        int f = (x - 1) - (x / 10 - 1);
        ans += f * i;
    }
    cout << ans + (a - x + 1) * i;
}