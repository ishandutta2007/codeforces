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
int a, b[100001], d1[100001], d2[100002], i, ans;

int main()
{
    sc( "%d", &a );
    for( i = 1; i <= a; i++ ){
        sc( "%d", &b[i] );
        d1[i] = min( b[i], min( d1[i - 1] + 1, i ) );
    }
    for( i = a; i >= 1; i-- ){
        d2[i] = min( b[i], min( d2[i + 1] + 1, a - i + 1 ) );
        ans = max( ans, min( d1[i], d2[i] ) );
    }
    cout << ans;
}