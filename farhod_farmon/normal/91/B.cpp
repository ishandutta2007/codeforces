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

#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back
#define p_b pop_back
#define pf push_front
#define p_f pop_front
#define mp make_pair
#define lli long long int
#define p_q priority_queue
#define fin freopen( "milk.in", "r", stdin );
#define fout freopen( "input.txt", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
int a, b[100001], t[444444], ans;

void build( int l, int r, int v )
{
    if( l == r ){
        t[v] = b[l];
        return;
    }
    int m = (l + r) / 2;
    build( l, m, v * 2 );
    build( m + 1, r, v * 2 + 1 );
    t[v] = min(t[v * 2], t[v * 2 + 1]);
}

int get( int x, int l, int r, int v )
{
    if( l == r ) return l;
    int m = (l + r) / 2;
    if( t[v * 2 + 1] < x )return get(x, m + 1, r, v * 2 + 1);
    else if( t[v * 2] < x )return get(x, l, m, v * 2);
    else return -1;
}

int main()
{
    sc("%d", &a);
    for( int i = 1; i <= a; i++ )sc("%d", &b[i]);
    build(1, a, 1);
    for( int i = 1; i <= a; i++ )pr( "%d ", max(-1, get(b[i], 1, a, 1) - i - 1));
}