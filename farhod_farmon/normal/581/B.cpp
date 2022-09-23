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
int a, b[100001], i, j, d[100002];

int main()
{
    cin >> a;
    for( i = 1; i <= a; i++ )cin >> b[i];
    d[a] = b[a];
    for( i = a - 1; i >= 1; i-- )d[i] = max(b[i], d[i + 1]);
    for( i = 1; i <= a; i++ ){
        if( d[i] == b[i] && d[i + 1] == b[i] )cout << 1 << " ";
        else if( d[i] == b[i] )cout << 0 << " ";
        else cout << d[i] - b[i] + 1 << " ";
    }
}