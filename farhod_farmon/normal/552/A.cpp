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

int main()
{
    int x1, x2, y1, y2, i, a, ans = 0;
    cin >> a;
    for( i = 1; i <= a; i++ ){
        cin >> x1 >> y1 >> x2 >> y2;
        ans += (x2 - x1 + 1) * (y2 - y1 + 1);
    }
    cout << ans;
}