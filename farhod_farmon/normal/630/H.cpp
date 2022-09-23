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

lli n, i, j, h, d[100][6], ans;

int main()
{
    cin >> n;
    d[0][0] = 1;
    for( i = 1; i <= n; i++ ){
        for( j = 1; j <= min(i, 5ll); j++ ){
            d[i][j] = n - j + 1;
            lli cnt = 0;
            for( h = 0; h < i; h++ )cnt += d[h][j - 1];
            d[i][j] = cnt * (n - j + 1);
        }
        ans += d[i][5];
    }
    cout << ans << endl;
}