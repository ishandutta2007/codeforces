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

using namespace std;

int n, i, j, h, k, mask[2505][2505 / 30 + 5], a[2505][2505], x;
vector < pair < pair < int, int >, pair < int, int > > > v;

int main()
{
    sc( "%d", &n );
    for( i = 1; i <= n; i++ ){
        for( j = 1; j <= n; j++ ){
            sc( "%d", &a[i][j] );
        }
    }
    for( i = 1; i <= n; i++ ){
        for( j = 1; j <= n; j++ ){
            if( i == j ){
                if( a[i][j] ){
                    pr( "NOT MAGIC" );
                    return 0;
                }
            }
            else{
                if( a[i][j] != a[j][i] ){
                    pr( "NOT MAGIC" );
                    return 0;
                }
                v.pb(mp(mp(a[i][j], 1), mp(i, j)));
                v.pb(mp(mp(a[i][j], 2), mp(i, j)));
            }
        }
    }
    sort( v.begin(), v.end() );
    for( i = 0; i < v.size(); i++ ){
        if( v[i].fi.se == 2 ){
            x = v[i].fi.fi;
            j = v[i].se.fi;
            h = v[i].se.se;
            mask[j][h / 30] += (1 << h % 30);
            if( j != h )mask[h][j / 30] += (1 << j % 30);
        }
        else{
            x = v[i].fi.fi;
            j = v[i].se.fi;
            h = v[i].se.se;
            for( int y = 0; y <= n / 30; y++ ){
                if( mask[j][y] & mask[h][y] ){
                    pr( "NOT MAGIC" );
                    return 0;
                }
            }
        }
    }
    pr( "MAGIC" );
    return 0;
}