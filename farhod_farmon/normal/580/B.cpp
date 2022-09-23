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
lli a, i, j, h, ans, d1[100001], l, r, m, d;
pair < lli, lli > p[100001];

int main()
{
    sc( "%I64d%I64d", &a, &d );
    for( i = 1; i <= a; i++ ){
        sc( "%I64d%I64d", &p[i].fi, &p[i].se );
    }
    sort( p + 1, p + a + 1 );
    for( i = 1; i <= a; i++ ){
        d1[i] = d1[i - 1] + p[i].se;
    }
    for( i = 1; i <= a; i++ ){
        l = i;
        r = a;
        while( l < r ){
            m = (l + r) / 2;
            if( p[i].fi + d <= p[m].fi )r = m;
            else l = m + 1;
        }
        if( p[i].fi + d <= p[r].fi  )r--;
        ans = max(ans, d1[r] - d1[i - 1]);
    }
    pr( "%I64d", ans );
}