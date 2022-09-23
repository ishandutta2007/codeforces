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

int n, m, i, j, h, d[10002], mod = 1e9 + 7;
map < int, int > used;
string s, t[100001];

int main()
{
    cin >> n >> s >> m;
    for( i = 1; i <= m; i++ ){
        cin >> t[i];
        string te = t[i];
        int g = t[i].size();
        int h1 = 0;
        int p1 = 1;
        for( j = 0; j < g; j++ ){
            if( 'A' <= te[j] && te[j] <= 'Z' )te[j] = te[j] - 'A' + 1;
            else te[j] = te[j] - 'a' + 1;
            h1 = (h1 + te[j] * p1) % mod;
            p1 = (p1 * 31) % mod;
        }
        used[h1] = i;
    }
    for( i = 0; i < n; i++ )s[i] = s[i] - 'a' + 1;
    s = ' ' + s;
    d[0] = 1;
    for( i = 1; i <= n; i++ ){
        int g = max(1, i - 1000);
        int h1 = 0;
        int p1 = 1;
        for( j = i; j >= g; j-- ){
            h1 = (h1 + s[j] * p1) % mod;
            p1 = (p1 * 31) % mod;
            if( d[j - 1] && used[h1] ){
                d[i] = used[h1];
                break;
            }
        }
    }
    vector < string > ans;
        while( n > 0 ){
        ans.pb(t[d[n]]);
        n -= t[d[n]].size();
    }
    for( i = ans.size() - 1; i >= 0; i-- )cout << ans[i] << " ";
}