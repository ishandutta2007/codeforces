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
#define fin freopen( "cipher.in", "r", stdin );
#define fout freopen( "cipher.out", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
vector < int > ans;
int a, k, i;

int main()
{
    cin >> a >> k;
    ans.pb(a - k);
    for( i = 2; i <= a - k; i++ ){
        ans.pb(i - 1);
    }
    for( i = max(1, a - k) + 1; i <= a; i++ ){
        ans.pb(i);
        k--;
    }
    if( k ){
        cout << -1;
        return 0;
    }
    for( i = 0; i < ans.size(); i++ )cout << ans[i] << " ";
}