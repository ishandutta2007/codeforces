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

int n, x[500005], ans;

void f( vector < int > v )
{
    int g = v.size();
    if( g == 0 )return;
    int i;
    ans = max(ans, (g + 1) / 2);
    for( i = 0; i < g / 2; i++ )x[v[i]] = x[v[0] - 1];
    for( i = g / 2; i < g; i++ )x[v[i]] = x[v.back() + 1];
}

int main()
{
    int i, j, h;
    vector < int > v;
    sc( "%d", &n );
    for( i = 1; i <= n; i++ )sc( "%d", &x[i] );
    for( i = 2; i < n; i++ ){
        if( x[i] != x[i - 1] && x[i] != x[i + 1] )v.pb(i);
        else{
            f(v);
            v.clear();
        }
    }
    f(v);
    pr( "%d\n", ans );
    for( i = 1; i <= n; i++ )pr( "%d ", x[i] );
}