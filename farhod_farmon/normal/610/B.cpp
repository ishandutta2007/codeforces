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
#define fin freopen( "divide.in", "r", stdin );
#define fout freopen( "divide.out", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )

using namespace std;

lli n, x[200001], i, minx = 1e9, l, r, ans;
vector < lli > v;

int main()
{
    cin >> n;
    for( i = 1; i <= n; i++ ){
        cin >> x[i];
        minx = min(minx, x[i]);
    }
    v.pb(0);
    for( i = 1; i <= n; i++ ){
        if( x[i] == minx )v.pb(i);
    }
    v.pb(n + 1);
    for( i = 1; i < v.size(); i++ )ans = max(ans, n * (minx - 1) + n - v[i - 1] + v[i] - 1);
    cout << max(ans, n * minx + n - v[v.size() - 2] + v[1] - 1) << endl;
}