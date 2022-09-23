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
#define fin freopen( "blocks.in", "r", stdin );
#define fout freopen( "blocks.out", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )

using namespace std;

int n, m, x, y, i, j;
bool used[101];

int main()
{
    cin >> n >> m;
    for( i = 1; i <= n; i++ ){
        cin >> x;
        for( j = 1; j <= x; j++ ){
            cin >> y;
            used[y] = true;
        }
    }
    for( i = 1; i <= m; i++ ){
        if( !used[i] ){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}