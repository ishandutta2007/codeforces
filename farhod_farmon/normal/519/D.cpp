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

map < pair < char, lli >, lli > m;
lli cnt, i, ans, d[200];
string s;

int main()
{
    for( char c = 'a'; c <= 'z'; c++ )cin >> d[c];
    cin >> s;
    for( i = 0; i < s.size(); i++ ){
        ans += m[mp(s[i], cnt)];
        cnt += d[s[i]];
        m[mp(s[i], cnt)]++;
    }
    cout << ans << endl;
}