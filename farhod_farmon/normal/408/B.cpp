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

#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back
#define p_b pop_back
#define pf push_front
#define p_f pop_front
#define mp make_pair
#define lli long long int
#define p_q priority_queue
#define fin freopen( "INPUT.TXT", "r", stdin );
#define fout freopen( "OUTPUT.TXT", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
#define INF 1000000000000000000ll
using namespace std;
int main()
{
    string s, t;
    int d[200] = {}, d1[200] = {}, i, ans = -1;
    cin >> s >> t;
    for( i = 0; i < s.size(); i++ )d[s[i]]++;
    for( i = 0; i < t.size(); i++ )d1[t[i]]++;
    for( char c = 'a'; c <= 'z'; c++ ){
        if( !d[c] && d1[c] )ans = -9999999999;
        ans += min(d[c], d1[c]);
    }
    if( ans > -1 )ans++;
    cout << max(-1, ans);
}