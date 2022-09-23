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

using namespace std;

lli ans, i, n, f[8], x, j;
bool used[8];

int main()
{
    cin >> n;
    f[1] = 1;
    for( i = 2; i <= 7; i++ )f[i] = f[i - 1] * i;
    for( x = n - 4, i = n - 3; i <= n; i++ ){
        x *= i;
    }
    ans += x / f[5];
    for( x = n - 5, i = n - 4; i <= n; i++ ){
        x *= i;
    }
    ans += x / f[6];
    for( x = n - 6, i = n - 5; i <= n; i++ ){
        lli g = i;
        for( j = 2; j <= 7; j++ ){
            if( used[j] )continue;
            if( g % j == 0 ){
                g /= j;
                used[j] = true;
            }
        }
        x *= g;
        for( j = 2; j <= 7; j++ ){
            if( used[j] )continue;
            if( x % j == 0 ){
                x /= j;
                used[j] = true;
            }
        }
    }
    for( i = 2; i <= 7; i++ ){
        if( !used[i] )x /= i;
    }
    ans += x;
    cout << ans << endl;
}