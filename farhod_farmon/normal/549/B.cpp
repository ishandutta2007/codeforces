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
int a, b[111], i, j;
vector < int > ans;
char c[111][111];

int main()
{
    cin >> a;
    for( i = 1; i <= a; i++ ){
        for( j = 1; j <= a; j++ ){
            cin >> c[i][j];
        }
    }
    for( i = 1; i <= a; i++ ){
        cin >> b[i];
    }
    bool b1 = true;
    while( b1 ){
        b1 = false;
        for( i = 1; i <= a; i++ ){
            if( b[i] == 0 ){
                b1 = true;
                ans.pb(i);
                for( j = 1; j <= a; j++ ){
                    if( c[i][j] == '1' )b[j]--;
                }
            }
        }
    }
    cout << ans.size() << endl;
    for( i = 0; i < ans.size(); i++ )cout << ans[i] << " ";
}