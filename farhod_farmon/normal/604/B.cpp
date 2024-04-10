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
int n, k, i, j, h, l, r = 2000000, m, x[100001];

bool f( int g )
{
    int k1 = k, h1 = 1, h2 = n;
    while( k1 && h1 <= h2 ){
        if( x[h2] > g )return false;
        if( x[h1] + x[h2--] <= g )h1++;
        k1--;
    }
    return h1 > h2;
}

int main()
{
    sc( "%d%d", &n, &k );
    for( i = 1; i <= n; i++ ){
        sc( "%d", &x[i] );
    } 
    while( l < r ){
        m = (l + r) / 2;
        if( !f(m) )l = m + 1;
        else r = m;
    }
    pr( "%d", l );
}