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
int a, b, c[100001], d[100001], i, n, m;

int main()
{
    cin >> a >> b;
    cin >> n >> m;
    for( i = 1; i <= a; i++ )cin >> c[i];
    for( i = 1; i <= b; i++ )cin >> d[i];
    if( c[n] < d[b - m + 1] )cout << "YES";
    else cout << "NO";
}