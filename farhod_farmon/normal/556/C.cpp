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

using namespace std;

int i, j, x, ans, k, n, m;

int main()
{
    cin >> n >> m;
    ans = 2 * n - m + 1;
    for( i = 1; i <= m; i++ ){
        cin >> k;
        for( j = 1; j <= k; j++ ){
            cin >> x;
            if( x == j )ans -= 2;
        }
    }
    cout << ans << endl;
}