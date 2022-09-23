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

lli d[27], n, cnt, x, i;

int main()
{
    cin >> n;
    for( i = 1; i <= n; i++ )cin >> d[i];
    sort( d + 1, d + n + 1 );
    cnt = x = d[n];
    for( i = n - 1; i >= 1; i-- ){
        x = min(x - 1, d[i]);
        cnt += max(x, 0ll);
    }
    cout << cnt << endl;
}