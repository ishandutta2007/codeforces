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
#define fin freopen( "division.in", "r", stdin );
#define fout freopen( "division.out", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
int a, b, i, j, h, k, f, d, ans[100001];
vector < int > v[100001];
bool b1 = true;

int main()
{
    sc( "%d%d", &a, &b );
    for( i = 1; i <= a; i++ ){
        sc( "%d", &f );
        v[f].pb(i);
    }
    for( i = 1; i <= b; i++ ){
        sc( "%d", &d );
        if( !v[d].size() ){
            pr( "Impossible\n" );
            return 0;    
        }
        if( v[d].size() > 1 )b1 = false;
        ans[i] = v[d][0];
    }
    if( !b1 ){
        pr( "Ambiguity\n" );
        return 0;
    }
    pr( "Possible\n" );
    for( i = 1; i <= b; i++ )pr( "%d ", ans[i] ); 
}