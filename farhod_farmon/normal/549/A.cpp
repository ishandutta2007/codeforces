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
#define fin freopen( "msched.in", "r", stdin );
#define fout freopen( "msched.out", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
int main()
{
    int a, b, i, j, d[200], ans = 0;
    char c[100][100];
    cin >> a >> b;
    for( i = 1; i <= a; i++ ){
        for( j = 1; j <= b; j++ ){
            cin >> c[i][j];
        }
    }
    for( i = 1; i <= a; i++ ){
        for( j = 1; j <= b; j++ ){
            d['f'] = d['a'] = d['c'] = d['e'] = 0;
            d[c[i][j]]++;
            d[c[i + 1][j]]++;
            d[c[i][j + 1]]++;
            d[c[i + 1][j + 1]]++;
            if( d['f'] && d['a'] && d['c'] && d['e'] )ans++;
        }
    }
    cout << ans;
    return 0;
}