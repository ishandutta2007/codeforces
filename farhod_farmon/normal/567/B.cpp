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

char c;
int x, i, j, cr, ans, a;
bool used[1000001];

int main()
{
    cin >> a;
    for( i = 1; i <= a; i++ ){
        cin >> c >> x;
        if( c == '-' ){
            if( !used[x] ){
                ans++;
            }
            else{
                cr--;
            }
            used[x] = false;
        }
        else{
            used[x] = true;
            cr++;
        }
        ans = max(ans, cr);
    }
    cout << ans;
}