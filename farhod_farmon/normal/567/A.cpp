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
int a, b[100001], i, j, mn, mx;

int main()
{
    sc( "%d", &a );
    for( i = 1; i <= a; i++ ){
        sc( "%d", &b[i] );
    }
    for( i = 1; i <= a; i++ ){
        if( i == 1 )mn = b[i + 1] - b[i];
        else if( i == a )mn = b[i] - b[i - 1];
        else mn = min( abs( b[i] - b[i - 1] ), abs( b[i] - b[i + 1] ) );
        mx = max( abs( b[i] - b[1] ), abs( b[i] - b[a] ) );
        pr( "%d %d\n", mn, mx );
    }
}