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

#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back
#define p_b pop_back
#define pf push_front
#define p_f pop_front
#define mp make_pair
#define lli long long int
#define p_q priority_queue
#define fin freopen( "INPUT.TXT", "r", stdin );
#define fout freopen( "OUTPUT.TXT", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
int main()
{
    lli n, p1, p2, p3, t1, t2, i, j, t[5001]  = {}, ans = 0, l[101], r[101];
    cin >> n >> p1 >> p2 >> p3 >> t1 >> t2;
    for( i = 1; i <= 1440; i++ )t[i] = -1;
    for( i = 1; i <= n; i++ ){
        cin >> l[i] >> r[i];
        for( j = l[i]; j < r[i] + t1; j++ )t[j] = p1;
        for( j = r[i] + t1; j < r[i] + t1 + t2; j++ ){
            if( t[j] == -1 )t[j] = p2;
        }
    }
    for( i = l[1]; i < r[n]; i++ ){
        if( t[i] == -1 )t[i] = p3;
        ans += t[i];
    }
    cout << ans;
}