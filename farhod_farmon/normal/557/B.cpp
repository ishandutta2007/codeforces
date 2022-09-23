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
int a, i, j;
float b[200011], ans, w;

int main()
{
    cin >> a >> w;
    for( i = 1; i <= a * 2; i++ ){
        sc( "%f", &b[i] );
    }
    sort( b + 1, b + a + a + 1 );
    ans = w / (3 * a);
    ans = min(ans, min(b[1], b[a + 1] / 2));
    pr( "%.6f", ans * a + ans * a * 2 );
}