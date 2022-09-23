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
#define fin freopen( "sochi.in", "r", stdin );
#define fout freopen( "sochi.out", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
int d[4][10000001], i, j, n, inf = 1e9 + 7;

int main()
{
    cin >> n;
    d[0][0] = 1;
    for( i = 1; i <= n; i++ ){
        d[0][i] = ((d[1][i - 1] + d[2][i - 1]) % inf + d[3][i - 1]) % inf;
        d[1][i] = ((d[0][i - 1] + d[2][i - 1]) % inf + d[3][i - 1]) % inf;
        d[2][i] = ((d[1][i - 1] + d[0][i - 1]) % inf + d[3][i - 1]) % inf;
        d[3][i] = ((d[1][i - 1] + d[2][i - 1]) % inf + d[0][i - 1]) % inf;
    }
    cout << d[0][n] << endl;
}