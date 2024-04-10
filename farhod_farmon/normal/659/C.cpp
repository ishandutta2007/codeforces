#include <bits/stdc++.h>

#define lli long long int
#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin freopen( "input.txt", "r", stdin );
#define fout freopen( "output.txt", "w", stdout );

using namespace std;

map < int, bool > used;
int n, m, i, x;
vector < int > v;

int main()
{
    sc( "%d%d", &n, &m );
    for( i = 1; i <= n; i++ ){
        sc( "%d", &x );
        used[x] = true;
    }
    for( i = 1; i <= m; i++ ){
        if( used.find(i) == used.end() ){
            v.pb(i);
            m -= i;
        }
    }
    pr( "%d\n", v.size() );
    for( i = 0; i < v.size(); i++ )
        pr( "%d ", v[i] );
}