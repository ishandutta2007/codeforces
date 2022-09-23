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
#define fin freopen( "input.txt", "r", stdin );
#define fout freopen( "output.txt", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
lli a, i, ans, b[300001];

int main()
{
    sc( "%I64d", &a );
    for( i = 1; i <= a; i++ )sc( "%I64d", &b[i] );
    sort( b + 1, b + a + 1 );
    for( i = 1; i <= a; i++ )ans += min(abs(i - b[i]), abs(b[i] - i));
    pr( "%I64d\n", ans );
}