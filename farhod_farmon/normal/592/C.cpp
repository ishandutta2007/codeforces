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
#define fin freopen( "birthday.in", "r", stdin );
#define fout freopen( "birthday.out", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
lli a, b, c, d, e;

int main()
{
    cin >> a >> b >> c;
    d = (long double)c * b / __gcd(c, b);
    if( d > a )e = a + 1;
    else e = d;
    e = a / d * min(b, c) + min(min(b, c) - 1, a % d);
    d = __gcd(a, e);
    cout << e / d << "/" << a / d;
}