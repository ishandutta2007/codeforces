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

const int N = 100100;

using namespace std;

map < pair < int, int >, bool > us;
int n, m, i, j, h, k, l, r, x, y, mn = 1e9, mx;
int used[N];
vector < int > d1, d2;
lli d[N][2];

int main()
{
    sc( "%d%d", &n, &m );
    if( !m ){
        pr( "%d", n - 1 );
        return 0;
    }
    for( i = 1; i <= m; i++ ){
        sc( "%d%d", &x, &y );
        if( x > y )
            swap(x, y);
        if( used[x] ){
            if( used[x] == 1 ){
                pr( "0" );
                return 0;
            }
        }
        else
            used[x] = 2;
        if( used[y] ){
            if( used[y] == 2 ){
                pr( "0" );
                return 0;
            }
        }
        else
            used[y] = 1;
        mx = max(mx, x);
        mn = min(mn, y);
    }
    if( mx > mn ){
        pr( "0" );
        return 0;
    }
    pr( "%d", mn - mx );
}