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
#define fin freopen( "cordon.in", "r", stdin );
#define fout freopen( "cordon.out", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
int a, b, i;

int main()
{
    cin >> a >> b;
    if( b == 10 && a < 2 ){
        cout << -1;
        return 0;
    }
    cout << b;
    if( b == 10 )a -= 2;
    else a--;
    for( i = 1; i <= a; i++ )cout << 0;
}