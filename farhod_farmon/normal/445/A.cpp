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

char c[111][111];
int i, j, h, n, m;

int main()
{
    cin >> n >> m;
    for( i = 1; i <= n; i++ ){
        for( j = 1; j <= m; j++ ){
            cin >> c[i][j];
            if( c[i][j] == '-' )
                continue;
            if( (i + j) % 2 )
                c[i][j] = 'B';
            else
                c[i][j] = 'W';
        }
    }
    for( i = 1; i <= n; i++ ){
        for( j = 1; j <= m; j++ ){
            cout << c[i][j];
        }
        cout << endl;
    }
}