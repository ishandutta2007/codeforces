
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

int d[1001], i, j, p[1001], cnt, n, ans, mod = 1e9 + 7;

int main()
{
    cin >> n;
    for( i = 1; i <= n; i++ )cin >> p[i];
    for( i = 1; i <= n; i++ ){
        cnt = 2;
        for( j = p[i]; j < i; j++ )cnt = (cnt + d[j]) % mod;
        d[i] = cnt;
        ans = (ans + cnt) % mod;
    }
    cout << ans << endl;
}