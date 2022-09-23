#include <bits/stdc++.h>

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

const int N = 100101;

using namespace std;

int n, m;
vector < int > v[N];

int main()
{
    int i, j, x, y;
    sc( "%d%d", &n, &m );
    for( i = 1; i <= m; i++ ){
        sc( "%d%d", &x, &y );
        v[x].pb(y);
        v[y].pb(x);
    }
    int g, f1 = 0, f2 = 0, f3;
    for( i = 1; i <= n; i++ ){
        if( v[i].size() == 1 )f1++, g = i;
        if( v[i].size() == 2 )f2++;
        if( v[i].size() > 1 )f3++;
    }
    if( f1 == 2 && f2 == n - 2 )
        pr( "bus topology" );
    else if( f2 == n )
        pr( "ring topology" );
    else if( f1 == n - 1 && f3 )
        pr( "star topology" );
    else
        pr( "unknown topology" );
}