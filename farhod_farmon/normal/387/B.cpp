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
int n, m, i, j, h, cnt, c[3333], d[3333];

int main()
{
    cin >> n >> m;
    for( i = 1; i <= n; i++ )cin >> c[i];
    for( i = 1; i <= m; i++ )cin >> d[i];
    sort( c + 1, c + n + 1 );
    sort( d + 1, d + m + 1 );
    for( i = j = 1; i <= n; i++ ){
        while( j < m && c[i] > d[j] )j++;
        if( c[i] > d[j] )cnt++;
        else j++;
    }    
    cout << cnt << endl;
}