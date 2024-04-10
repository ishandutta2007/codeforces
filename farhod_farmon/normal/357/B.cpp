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

int n, m, x, y, z, i, j, h, a[100001];
bool us[4];

int main()
{
    sc( "%d%d", &n, &m );
    for( i = 1; i <= n; i++ ){
        sc( "%d%d%d", &x, &y, &z );
        us[1] = us[2] = us[3] = false;
        us[a[x]] = true;
        us[a[y]] = true;
        us[a[z]] = true;
        h = 1;
        while( us[h] && !a[x] )
            h++;
        if( !a[x] )
            a[x] = h++;
        while( us[h] && !a[y] )
            h++;
        if( !a[y] )
            a[y] = h++;
        while( us[h] && !a[z] )
            h++;
        if( !a[z] )
            a[z] = h++;
    }
    for( i = 1; i <= n; i++ )
        pr( "%d ", a[i] );
}