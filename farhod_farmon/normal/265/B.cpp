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
lli ans, x[100001], i, a;

int main()
{
    cin >> a;
    for( i = 1; i <= a; i++ ){
        cin >> x[i];
        ans++;
        if( i > 1 )ans += abs(x[i] - x[i - 1]) + 1;
    }
    cout << ans + x[1] << endl;
}