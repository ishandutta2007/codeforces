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
int a, b, c, x, y, z, g;

int main()
{
    cin >> a >> b >> c >> x >> y >> z;
    g = max(0, (a - x) / 2) + max(0, (b - y) / 2) + max(0, (c - z) / 2);
    g -= max(0, x - a) + max(0, y - b) + max(0, z - c);
    if( g >= 0 )cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}