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
#define fin freopen( "dfs.in", "r", stdin );
#define fout freopen( "dfs.out", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
int t, l, r, d[5000001];
lli s[5000001];

int rec( int x )
{
    int i, ans;
    if( d[x] )return d[x];
    for( i = 2; i * i <= x; i++ ){
        if( x % i == 0 )return rec(x / i) + 1;
    }
    return 1;
}

int main()
{
    int i;
    for( i = 2; i <= 5000000; i++ ){
        d[i] = rec(i);
        s[i] = s[i - 1] + d[i];
    }
    sc( "%d", &t );
    for( i = 1; i <= t; i++ ){
        sc( "%d%d", &r, &l );
        pr( "%d\n", s[r] - s[l] );
    }
}