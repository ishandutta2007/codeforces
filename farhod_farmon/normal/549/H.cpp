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
#define fin freopen( "msched.in", "r", stdin );
#define fout freopen( "msched.out", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
double a, b, c, d, x1, x2, x3, x4;

int main()
{
    cin >> a >> b >> c >> d;
    if( a * d == b * c ){
        cout << 0.0;
        return 0;
    }
    x1 = (- a * d + b * c) / (a + b + c + d);
    x2 = (- a * d + b * c) / (a + b - c - d);
    x3 = (- a * d + b * c) / (- a + b - c + d);
    x4 = (- a * d + b * c) / (- a + b + c - d);
    pr( "%.9f", min(min(fabs(x1),fabs(x2)),min(fabs(x3),fabs(x4))) );
}