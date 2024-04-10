#include <bits/stdc++.h>

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

map < int, int > a, b;
map < pair < int, int >, int > c;
pair < int, int > p[200002];
lli n, i, j, h, cnt;

int main()
{
    sc( "%d", &n );
    for( i = 1; i <= n; i++ ){
        sc( "%d%d", &p[i].fi, &p[i].se );
        c[p[i]]++;
        a[p[i].fi]++;
        b[p[i].se]++;
    }
    for( i = 1; i <= n; i++ ){
        cnt -= c[p[i]] * 1ll * (c[p[i]] - 1) / 2ll;
        cnt += a[p[i].fi] * 1ll * (a[p[i].fi] - 1) / 2ll;
        cnt += b[p[i].se] * 1ll * (b[p[i].se] - 1) / 2ll;
        c[p[i]] = 0;
        a[p[i].fi] = 0;
        b[p[i].se] = 0;
    }
    pr( "%I64d", cnt );
}