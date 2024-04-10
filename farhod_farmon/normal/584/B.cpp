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
#define fin freopen( "cordon.in", "r", stdin );
#define fout freopen( "cordon.out", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
lli a, i, inf = 1e9 + 7, x = 1, y = 1;

int main()
{
    cin >> a;
    for( i = 1; i <= a * 3; i++ )x = (x * 3) % inf;
    for( i = 1; i <= a; i++ )y = (y * 7) % inf;
    x -= y;
    while( x < 0 )x += inf;
    cout << x << endl;
}