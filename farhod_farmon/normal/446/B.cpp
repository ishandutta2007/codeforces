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
#define fin freopen( "dfs.in", "r", stdin );
#define fout freopen( "dfs.out", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
priority_queue < lli > q, q1;
lli a, b, k, p, x, i, j, l[10000], r[10000], ans = -999999999999999ll, g, g1, ansl[1000001], ansr[1000001];

int main()
{
    cin >> a >> b >> k >> p;
    for( i = 1; i <= a; i++ ){
        for( j = 1; j <= b; j++ ){
            cin >> x;
            l[i] += x;
            r[j] += x;
        }
    }
    for( i = 1; i <= a; i++ )q.push(l[i]);
    for( i = 1; i <= b; i++ )q1.push(r[i]);
    for( i = 1; i <= k; i++ ){
        x = q.top();
        q.pop();
        q.push(x - b * p);
        ansl[i] = ansl[i - 1] + x;
        x = q1.top();
        q1.pop();
        q1.push(x - a * p);
        ansr[i] = ansr[i - 1] + x;
    }
    for( i = 0; i <= k; i++ )ans = max(ans, ansl[i] + ansr[k - i] - (long long)(i * (k - i)) * p);
    cout << ans;
}