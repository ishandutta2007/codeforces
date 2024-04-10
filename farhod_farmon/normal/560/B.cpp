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
int main()
{
    int i, j, W, H, w[3], h[3];
    cin >> W >> H;
    cin >> w[1] >> h[1];
    cin >> w[2] >> h[2];
    for( i = 1; i <= 2; i++ ){
        for( j = 1; j <= 2; j++ ){
            if( w[1] + w[2] <= W && max(h[1], h[2]) <= H ){
                cout << "YES";
                return 0;
            }
            if( w[1] + w[2] <= H && max(h[1], h[2]) <= W ){
                cout << "YES";
                return 0;
            }
            swap(w[2], h[2]);
        }
        swap(w[1], h[1]);
    }
    cout << "NO";
}