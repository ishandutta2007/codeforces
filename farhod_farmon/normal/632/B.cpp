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

lli l[500005], r[500005], cnt, i, j, h, ans, a[500005], n, d;
string s;

int main()
{
    cin >> n;
    for( i = 1; i <= n; i++ )cin >> a[i];
    cin >> s;
    for( i = 1; i <= n; i++ ){
        l[i] = l[i - 1];
        if( s[i - 1] == 'B' )l[i] += a[i];
    }
    for( i = n; i >= 1; i-- ){
        r[i] = r[i + 1];
        if( s[i - 1] == 'B' )r[i] += a[i];
    }
    ans = max(r[1], l[n]); // :)
    for( i = 1; i <= n; i++ ){
        if( s[i - 1] == 'A' )cnt += a[i];
        ans = max(ans, cnt + r[i + 1]);
    }cnt = 0;
    for( i = n; i >= 1; i-- ){
        if( s[i - 1] == 'A' )cnt += a[i];
        ans = max(ans, cnt + l[i - 1]);
    }
    cout << ans << endl;
}