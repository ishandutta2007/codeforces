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
int a, b, i, j, d[1000][1000], ans;

int main()
{
    cin >> a >> b;
    for( i = 1; i <= a; i++ ){
        for( j = 1; j <= 2 * b; j++ )cin >> d[i][j];
        for( j = 1; j <= b; j++ ){
            if( d[i][j * 2 - 1] || d[i][j * 2] )ans++;
        }
    }    
    cout << ans << endl;  
}