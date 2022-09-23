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

lli n, a[100001], l, r = 1e9, m, k;

lli M( lli x )
{
    lli cnt = 0;
    for( lli i = 1; i <= n; i++ )cnt += min(x, a[i]);
    return cnt;
}

int main()
{
    lli i;
    cin >> n >> k;
    for( i = 1; i <= n; i++ )cin >> a[i];
    if( M(1e9) < k ){
        cout << -1 << endl;
        return 0;
    }
    while( l < r ){
        m = (l + r) / 2;
        if( M(m + 1) <= k )l = m + 1;
        else r = m;
    }
    k -= M(l);
    for( i = 1; i <= n && k; i++ ){
        if( a[i] <= l )continue;
        a[i]--;
        k--;
    }
    for( ; i <= n; i++ ){
        if( a[i] > l )cout << i << " ";
        a[i] = 0;
    }
    for( i = 1; i <= n; i++ ){
        if( a[i] > l )cout << i << " ";
    }
}