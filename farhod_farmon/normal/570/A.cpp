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
int a, b, i, j, ans, c[111][111], d[111], x, k;

int main()
{
    cin >> a >> b;
    for( i = 1; i <= b; i++ ){
        x = 1;
        for( j = 1; j <= a; j++ ){
            cin >> c[i][j];
            if( c[i][j] > c[i][x] )x = j;
        }
        d[x]++;
    }
    ans = 1;
    for( i = 2; i <= a; i++ )if( d[i] > d[ans] )ans = i;
    cout << ans;
}