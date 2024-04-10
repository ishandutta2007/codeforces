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

set < pair < lli, lli > > s;
set < pair < lli, lli > > :: iterator it;
lli n, m, i, j, h, x, l[N], r[N], ans[N];
pair < pair < lli, lli >, lli > p[N];

int main()
{
    cin >> n >> m;
    for( i = 1; i <= n; i++ ){
        cin >> l[i] >> r[i];
        if( i > 1 )p[i - 1] = mp(mp(r[i] - l[i - 1], l[i] - r[i - 1]), i - 1);
    }
    for( i = 1; i <= m; i++ ){
        cin >> x;
        s.insert(mp(x, i));
    }
    if( m < n - 1 ){
        cout << "No" << endl;
        return 0;
    }
    sort( p + 1, p + n );
    for( i = 1; i < n; i++ ){
        it = s.lower_bound(mp(p[i].fi.se, 0));
        if( it == s.end() || it->fi > p[i].fi.fi ){
            cout << "No" << endl;
            return 0;
        }
        ans[p[i].se] = it->se;
        s.erase(it);
    }
    cout << "Yes" << endl;
    for( i = 1; i < n; i++ )cout << ans[i] << " ";
}