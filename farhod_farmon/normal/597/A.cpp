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
#define fin freopen( "shield.in", "r", stdin );
#define fout freopen( "shield.out", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
lli a, b, k;

int main()
{
    cin >> k >> a >> b;
    if( a > 0 && b > 0 )cout << b / k - (a - 1) / k << endl;
    else if( a < 0 && b < 0 )cout << (-a) / k - (-b - 1) / k << endl;
    else cout << (-a) / k + b / k + 1 << endl;
}