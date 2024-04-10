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
lli n, i, j, k, w, ans = 0;
int main()
{
    cin >> k >> n >> w;
    for( i = 1; i <= w; i++ )ans += i * k;
    cout << max(0ll, ans - n);
}