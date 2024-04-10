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

int n, m, i, j, h, l = 1, k, d[1000001], a[1000001];
vector < int > v;

int main()
{
    sc( "%d%d", &n, &m );
    for( i = 1; i <= n; i++ ){
        sc( "%d", &a[i] );
        if( a[i] <= m )d[a[i]]++;
    }
    for( i = m; i >= 1; i-- ){
        for( j = i + i; j <= m; j += i ){
            d[j] += d[i];
        }
    }
    for( i = 1; i <= m; i++ ){
        if( d[i] > d[l] )l = i;
    }
    for( i = 1; i <= n; i++ ){
        if( l % a[i] == 0 )v.pb(i);
    }
    pr( "%d %d\n", l, v.size() );
    for( i = 0; i < v.size(); i++ )pr( "%d ", v[i] );
}