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
#define fin freopen( "sochi.in", "r", stdin );
#define fout freopen( "sochi.out", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
lli n, x, a, b, m, y, i, f;

int main()
{
    cin >> n >> x;
    for( i = 1; i <= n; i++ ){
        cin >> f;
        a = a * x + f;
    }
    cin >> m >> y;
    for( i = 1; i <= m; i++ ){
        cin >> f;
        b = b * y + f;
    }
    if( a == b )cout << "=";
    else if( a < b )cout << "<";
    else cout << ">";
}