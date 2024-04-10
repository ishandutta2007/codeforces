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
double cnt, x[6], y[6];
int i, j, f1, f2;

int main()
{
    for( i = 1; i <= 5; i++ )cin >> x[i];
    for( i = 1; i <= 5; i++ ){
        cin >> y[i];
        cnt += max(0.3 * 500 * i, (1 - x[i] / 250) * 500 * i - 50 * y[i] );
    }
    cin >> f1 >> f2;
    cout << cnt + f1 * 100 - f2 * 50 << endl;
}