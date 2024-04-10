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
#include <iomanip>

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

int n, i, j, h, x, y, ans[55], d[55];
vector < pair < int, int > > v[55];
bool used[55];

int main()
{
    cin >> n;
    for( i = 1; i <= n; i++ ){
        for( j = 1; j <= n; j++ ){
            cin >> x;
            if( i < j ){
                v[x].pb(mp(i, j));
            }
        }
    }
    for( i = 1; i <= n; i++ ){
        for( j = 0; j < v[i].size(); j++ ){
            x = v[i][j].fi;
            y = v[i][j].se;
            d[x]++;
            d[y]++;
        }
        x = 0; int cnt = 0;
        for( j = 1; j <= n; j++ ){
            if( d[j] > cnt ){
                cnt = d[j];
                x = j;
            }
            d[j] = 0;
        }
        if( x )used[i] = true;
        ans[x] = i;
    }
    for( i = 1; i <= n; i++ ){
        if( used[i] )continue;
        for( j = 0; j < v[i].size(); j++ ){
            x = v[i][j].fi;
            y = v[i][j].se;
            if( !ans[x] ){
                ans[x] = i;
                used[i] = true;
                break;
            }
            if( !ans[y] ){
                ans[y] = i;
                used[i] = true;
                break;
            }
        }
    }
    for( i = j = 1; i <= n; i++ ){
        if( used[i] )continue;
        while( ans[j] )j++;
        ans[j] = i;
    }
    for( i = 1; i <= n; i++ )cout << ans[i] << " ";
}