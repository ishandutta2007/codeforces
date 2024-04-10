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

lli x, i, j, cnt, n;
vector < lli > v;

int main()
{
    cin >> n;
    for( i = 1; i <= n; i++ ){
        cin >> x;
        if( x % 2 == 0 )cnt += x;
        else v.pb(x);
    }
    sort( v.begin(), v.end() );
    for( i = int(v.size()) - 1; i > 0; i -= 2 )cnt += v[i] + v[i - 1];
    cout << cnt << endl;
}