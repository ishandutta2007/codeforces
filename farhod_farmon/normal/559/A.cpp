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
lli x[10], i, ans, g;

int main()
{
    for( i = 1; i <= 6; i++ )cin >> x[i];
    for( i = x[1]; i < x[1] + min(x[2], x[6]); i++ )ans += (i * 2 + 1);
    for( i = x[4]; i < x[4] + min(x[3], x[5]); i++ )ans += (i * 2 + 1);
    g = max(x[2], x[6]) - min(x[2], x[6]);
    cout << ans + g * (x[1] + min(x[2], x[6])) * 2;
}