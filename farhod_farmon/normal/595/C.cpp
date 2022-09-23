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
#define fin freopen( "shield.in", "r", stdin );
#define fout freopen( "shield.out", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
int n, i, ans = 1e9, b[200001];

int main()
{
    sc( "%d", &n );
    for( i = 1; i <= n; i++ )sc( "%d", &b[i] );
    sort( b + 1, b + n + 1 );
    for( i = 1; i <= n / 2; i++ )ans = min(ans, b[i + n / 2] - b[i]);
    pr( "%d\n", ans );
}