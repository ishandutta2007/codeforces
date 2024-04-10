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
#define fin freopen( "divide.in", "r", stdin );
#define fout freopen( "divide.out", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )

using namespace std;

int a, i, j;

int main()
{
    cin >> a;
    if( a % 2 )cout << 0 << endl;
    else{
        int ans = a / 4;
        if( a % 4 == 0 )ans--;
        cout << ans << endl;
    }
}