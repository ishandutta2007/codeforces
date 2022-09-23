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
#define fin freopen( "cipher.in", "r", stdin );
#define fout freopen( "cipher.out", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
lli a, k, x, i, j, h, d[200001], d1[200002], ans, b[200001], g = 1;

int main()
{
    sc( "%I64d%I64d%I64d", &a, &k, &x );
    for( i = 1; i <= a; i++ ){
        sc( "%I64d", &b[i] );
        d[i] = d[i - 1] | b[i];
    }
    for( i = a; i >= 1; i-- ){
        d1[i] = d1[i + 1] | b[i];
    }
    for( i = 1; i <= k; i++ )g *= x;
    for( i = 1; i <= a; i++ ){
        ans = max(ans, d[i - 1] | d1[i + 1] | (b[i] * g));
    }
    pr( "%I64d", ans );
}