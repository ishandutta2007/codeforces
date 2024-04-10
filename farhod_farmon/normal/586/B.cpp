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
pair < int, int > p[55];
int i, j, h, k, a, c[55][55], d[55];
vector < int > v;

int main()
{
    cin >> a;
    for( i = 1; i <= a - 1; i++ )cin >> c[1][i];
    for( i = 1; i <= a - 1; i++ )cin >> c[2][i];
    for( i = 1; i <= a; i++ ){
        cin >> d[i];
    }
    for( i = 2; i <= a; i++ ){
        p[i].fi = p[i - 1].fi + c[1][i - 1];
    }
    for( i = a - 1; i >= 1; i-- ){
        p[i].se = p[i + 1].se + c[2][i];
    }
    for( i = 1; i <= a; i++ ){
        v.pb(p[i].fi + p[i].se + d[i]);
    }
    sort(v.begin(), v.end());
    cout << v[0] + v[1];
}