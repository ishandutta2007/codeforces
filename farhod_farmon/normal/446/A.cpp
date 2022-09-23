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
#define fin freopen( "dfs.in", "r", stdin );
#define fout freopen( "dfs.out", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
int a, b[100001], l[100011], r[100011], i, ans;

int main()
{
    cin >> a;
    for( i = 1; i <= a; i++ ){
        cin >> b[i];
        l[i] = r[i] = 1;
        if( b[i] > b[i - 1] )r[i] += r[i - 1];
        ans = max(ans, r[i - 1] + 1);
    }
    for( i = a - 1; i >= 1; i-- ){
        if( b[i] < b[i + 1] )l[i] += l[i + 1];
        ans = max(ans, l[i + 1] + 1);
    }
    for( i = 2; i < a; i++ ){
        if( b[i + 1] - b[i - 1] > 1 )ans = max(ans, r[i - 1] + l[i + 1] + 1);
    }
    cout << ans;
}