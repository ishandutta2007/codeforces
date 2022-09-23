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
#define fin freopen( "pwgen.in", "r", stdin );
#define fout freopen( "pwgen.out", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
#define INF 1000000000000000000ll
using namespace std;
int main()
{
    lli a, x, y, i, cnt, d[100001], ans = 0;
    cin >> a >> x >> y;
    for( i = 1; i < a; i++ )d[i] = 1;
    d[i] = y - a + 1;
    if( d[a] * d[a] + a - 1 >= x && y - a + 1 > 0 ){
        for( i = 1; i <= a; i++ )cout << d[i] << endl;
    }
    else{
        cout << -1;
    }
}