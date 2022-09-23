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
lli n, m, i, a, b, g, cnt, d[200], ans;
string s, t;

int main()
{
    cin >> n >> m;
    cin >> s >> t;
    g = __gcd(s.size(), t.size());
    for( int h = 0; h < g; h++ ){
        for( char c = 'a'; c <= 'z'; c++ )d[c] = cnt = 0;
        for( i = h; i < s.size(); i += g ){
            cnt++;
            d[s[i]]++;
        }
        for( i = h; i < t.size(); i += g ){
            ans += (cnt - d[t[i]]) * (n / (t.size() / g));
        }
    }
    cout << ans;
}