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
int a, i, j, h, p[100001], x, y;
bool used[100001];

int main()
{
    sc( "%d%d%d", &a, &x, &y );
    for( i = 1; i <= a; i++ )sc( "%d", &p[i] );
    while( x != y && !used[x] ){
        used[x] = true;
        x = p[x];
        h++;
    }
    if( x == y )cout << h << endl;
    else cout << -1 << endl;
}