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
#include <iomanip>

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

int d[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6}, cnt, l, r, i;

int F( int x )
{
    int g = 0;
    while( x ){
        g += d[x % 10];
        x /= 10;
    }
    return g;
}

int main()
{
    cin >> l >> r;
    for( i = l; i <= r; i++ )cnt += F(i);
    cout << cnt << endl;
}