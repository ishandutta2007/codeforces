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
lli a, i, j, ans, g, d[1000001], x;

int main()
{
    cin >> a;
    for( i = 1; i <= a; i++ ){
        cin >> x;
        d[i] = d[i - 1] + x;
    }
    for( i = 1; i < a; i++ ){
        if( d[i] * 3 == d[a] * 2  )ans += g;
        if( d[i] * 3 == d[a]  )g++;
    }
    cout << ans << endl;
}