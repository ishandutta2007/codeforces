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
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )

const int N = 200002;

using namespace std;

int n, t[4 * N];
lli a[N], b[N];

void FF( int x, int l, int r, int tl, int tr )
{
    if( tl > tr )return;
    if( l == tl && r == tr ){
        t[x]++;
        return;
    }
    int m = (l + r) / 2;
    FF(x * 2, l, m, tl, min(tr, m));
    FF(x * 2 + 1, m + 1, r, max(m + 1, tl), tr);
}

void FM( int x, int l, int r )
{
    if( l == r ){
        b[l] = t[x];
        return;
    }
    int m = (l + r) / 2;
    t[x * 2] += t[x];
    t[x * 2 + 1] += t[x];
    FM(x * 2, l, m);
    FM(x * 2 + 1, m + 1, r);
}

int main()
{
    int i, j, l, r, q;
    lli ans = 0;
    sc("%d%d", &n, &q);
    for( i = 1; i <= n; i++ )sc("%I64d", &a[i]);
    for( i = 1; i <= q; i++ ){
        sc("%d%d", &l, &r);
        FF(1, 1, n, l, r);
    }
    FM(1, 1, n);
    sort( a + 1, a + n + 1 );
    sort( b + 1, b + n + 1 );
    for( i = 1; i <= n; i++ )ans += a[i] * b[i];
    pr("%I64d", ans);
}