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

const int mx = 1e7;

using namespace std;

int n, l, r, d[mx + 1], i, j, h, co[mx + 1], m;
bool used[mx + 1];

int main()
{
    sc( "%d", &n );
    for( i = 1; i <= n; i++ ){
        sc( "%d", &h );
        co[h]++;
    }
    for( i = 2; i <= mx; i++ ){
        d[i] = d[i - 1];
        if( used[i] )continue;
        for( j = i; j <= mx; j += i ){
            d[i] += co[j];
            used[j] = true;
        }
    }
    sc( "%d", &m );
    for( i = 1; i <= m; i++ ){
        sc( "%d%d", &l, &r );
        pr( "%d\n", d[min(r, mx)] - d[min(l - 1, mx)] );
    }
}