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
using namespace std;
int n, i, l, r, m, ans = 1e9, x[111111];

int main()
{
    fin
    fout
    cin >> n;
    for( i = 1; i <= n; i++ )cin >> x[i];
    sort( x + 1, x + n + 1 );
    for( i = 1; i <= n; i++ ){
        l = i;
        r = n;
        while( l < r ){
            m = (l + r) / 2;
            if( x[m + 1] <= x[i] * 2 )l = m + 1;
            else r = m;
        }   
        ans = min(ans, i - 1 + n - r);
    }
    cout << ans << endl;
}