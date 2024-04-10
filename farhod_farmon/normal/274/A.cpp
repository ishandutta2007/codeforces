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
lli a, k, b[100001], i, ans;
map < lli, bool > used;

int main()
{
    sc( "%d%d", &a, &k );
    for( i = 1; i <= a; i++ )sc( "%d", &b[i] );
    sort( b + 1, b + a + 1 );
    for( i = 1; i <= a; i++ ){
        if( used[b[i]] )continue;
        used[b[i] * k] = true;
        ans++;
    }
    pr( "%d", ans );
}