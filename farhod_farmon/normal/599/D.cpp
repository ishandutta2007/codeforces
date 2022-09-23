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
#define fin freopen( "division.in", "r", stdin );
#define fout freopen( "division.out", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
lli x, i, j, h, n, m, s[10000001];
vector < pair < lli, lli > > ans;

int main()
{
    cin >> x;
    for( i = 1; i <= min(x, 10000000ll); i++ ){
        s[i] = s[i - 1] + i * i;
        n = 2 * x - 2 * s[i - 1] - i * i + i * i * i;
        if( n % (i * i + i) == 0 ){
            m = n / (i * i + i);
            if( i <= m ){
                ans.pb(mp(i, m));
                if( i < m )ans.pb(mp(m, i));
            }
        }
    }    
    sort( ans.begin(), ans.end() );
    cout << ans.size() << endl;
    for( i = 0; i < ans.size(); i++ )cout << ans[i].fi << " " << ans[i].se << endl;
}