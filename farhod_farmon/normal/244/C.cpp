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

int n, a[N], i, j, h, k, l, r, m, f[N][21], cnt;
bool used[N * 10 * 10];

int main()
{
    sc( "%d", &n );
    for( i = 1; i <= n; i++ )
        sc( "%d", &a[i] );
    for( i = 0; i <= 20; i++ )
        f[n + 1][i] = n + 1;
    for( i = n; i >= 1; i-- )
        for( j = 0; j <= 20; j++ )
            if( a[i] & (1 << j) )
                f[i][j] = i;
            else
                f[i][j] = f[i + 1][j];
    for( i = 1; i <= n; i++ ){
        if( !used[a[i]] ){
            used[a[i]] = true;
            cnt++;
        }
        vector < int > v;
        for( j = 0; j <= 20; j++ )
            if( !(a[i] & (1 << j)) )
                v.pb(f[i][j]);
        sort(v.begin(), v.end());
        for( j = 0; j < v.size(); j++ ){
            if( v[j] > n )
                break;
            a[i] |= a[v[j]];
            if( !used[a[i]] ){
                used[a[i]] = true;
                cnt++;
            }
        }
    }
    pr( "%d\n", cnt );
}