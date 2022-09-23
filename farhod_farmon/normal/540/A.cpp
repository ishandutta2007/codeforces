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
    int a, i, cnt = 0;
    string s, t;
    cin >> a >> s >> t;
    for( i = 0; i < s.size(); i++ ){
        int x = s[i] - 48;
        int y = t[i] - 48;
        if( y > x )swap(y, x);
        cnt += min( x - y, (y + 9) - x + 1 );
    }
    cout << cnt;
}