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
#define fin freopen( "birthday.in", "r", stdin );
#define fout freopen( "birthday.out", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
int a, b, d[200000], i1, i2;
vector < int > v[200000];
bool used[200000];

void dfs( int x, int p )
{
    d[x] = d[p] + 1;
    for( int i = 0; i < v[x].size(); i++ ){
        if( v[x][i] != p )dfs( v[x][i], x );
    }
}

int get( int x, int p )
{
    int cnt = 0;
    for( int i = 0; i < v[x].size(); i++ ){
        if( v[x][i] != p )cnt += get(v[x][i], x);
    }
    if( used[x] || cnt )cnt++;
    return cnt;
}

int main()
{
    int x, y, i, j, h;
    sc( "%d%d", &a, &b );
    for( i = 1; i < a; i++ ){
        sc( "%d%d", &x, &y );
        v[x].pb(y);
        v[y].pb(x);
    }
    for( i = 1; i <= b; i++ ){
        sc( "%d", &x );
        used[x] = true;
    }
    dfs(1, 0);
    for( i = 1; i <= a; i++ ){
        if( used[i] && d[i] > d[i1] )i1 = i;
    }
    dfs(i1, 0);
    for( i = 1; i <= a; i++ ){
        if( used[i] && d[i] > d[i2] )i2 = i;
    }
    pr( "%d\n%d", min(i1, i2), (get(i2, 0) - 1) * 2 - d[i2] + 1 );
}