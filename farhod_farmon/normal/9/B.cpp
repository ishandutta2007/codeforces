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

using namespace std;

int n, ans = 2, i, j;
long double vs, vb;

long double di( long double x, long double y, long double xx, long double yy )
{
    return sqrt((xx - x) * (xx - x) + (yy - y) * (yy - y));
}

int main()
{
    long double xu, yu, x[101];
    cin >> n >> vb >> vs;
    for( i = 1; i <= n; i++ ){
        cin >> x[i];
    }
    cin >> xu >> yu;
    for( i = 3; i <= n; i++ ){
        if( di(xu, yu, x[i], 0) / vs + x[i] / vb < di(xu, yu, x[ans], 0) / vs + x[ans] / vb )ans = i;
        else if( di(xu, yu, x[i], 0) / vs + x[i] / vb == di(xu, yu, x[ans], 0) / vs + x[ans] / vb &&
                 di(xu, yu, x[i], 0) < di(xu, yu, x[ans], 0) )ans = i;
    }
    cout << ans << endl;
}