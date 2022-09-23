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
int n, a[100001], i, ans, cnt;

int main()
{
    cin >> n;
    for( i = 1; i <= n; i++ ){
        cin >> a[i];
        if( i > 1 && a[i] >= a[i - 1] )cnt++;
        else cnt = 1;
        ans = max(ans, cnt);
    }
    cout << ans;
}