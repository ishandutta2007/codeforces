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
#define fin freopen( "typo.in", "r", stdin );
#define fout freopen( "typo.out", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
lli a, b, c, i, j, h;
vector < lli > ans;

lli p( lli x, lli g )
{
    lli g1 = 1;
    for( lli i = 1; i <= g; i++ )g1 *= x;
    return g1;
}

lli s( lli x )
{
    lli g = 0;
    while( x ){
        g += x % 10;
        x /= 10;
    }
    return g;
}

int main()
{
    cin >> a >> b >> c;
    for( lli i = 1; i <= 81; i++ ){
        lli g = b * p(i, a) + c;
        if( s(g) == i && g < 1000000000 )ans.pb(g);
    }
    cout << ans.size() << endl;
    for( lli i = 0; i < ans.size(); i++ )cout << ans[i] << " ";
}