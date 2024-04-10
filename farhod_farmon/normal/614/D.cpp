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

const int N = 100101;

using namespace std;

lli n, A, cf, cm, k, pre[N], suf[N], ans = -1, m1, m2, m3, a[N];
pair < lli, lli > p[N];

int main()
{
    lli i, j, h, l, r, m;
    cin >> n >> A >> cf >> cm >> k;
    for( i = 1; i <= n; i++ ){
        cin >> p[i].fi;
        p[i].se = i;
    }
    sort( p + 1, p + n + 1 );
    for( i = 1; i <= n; i++ )suf[i] = suf[i - 1] + p[i].fi;
    for( i = n + 1; i >= 1; i-- ){
        pre[i] = pre[i + 1] + p[i].fi;
        lli g = k - ((n - i + 1) * A - pre[i]);
        if( g < 0 )break;
        if( i == 1 ){
            if( n * cf + A * cm > ans ){
                ans = n * cf + A * cm;
                m1 = 0;
                m3 = 1;
            }
            break;
        }
        l = 1;
        r = i - 1;
        while( l < r ){
            m = (l + r) / 2;
            if( p[m + 1].fi * (m + 1) - suf[m + 1] <= g )l = m + 1;
            else r = m;
        }
        h = p[l].fi * l - suf[l];
        g -= h;
        if( cf * (n - i + 1) + cm * min(A, p[l].fi + g / l) > ans ){
            ans = cf * (n - i + 1) + cm * min(A, p[l].fi + g / l);
            m1 = l;
            m2 = min(A, p[l].fi + g / l);
            m3 = i;
        }
    }
    for( i = 1; i <= m1; i++ )a[p[i].se] = m2;
    for( i = m1 + 1; i < m3; i++ )a[p[i].se] = p[i].fi;
    for( i = m3; i <= n; i++ )a[p[i].se] = A;
    cout << ans << endl;
    for( i = 1; i <= n; i++ )cout << a[i] << " ";
}