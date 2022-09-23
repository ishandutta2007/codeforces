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

int n, m, k, i, j, h, cnt, x, y, p[101];

int main()
{
    cin >> n >> m >> k;
    for( i = 1; i <= k; i++ )
        cin >> p[i];
    for( i = 1; i <= n; i++ ){
        for( j = 1; j <= m; j++ ){
            cin >> x;
            for( h = 1; h <= k; h++ ){
                if( p[h] == x )
                    break;
            }
            cnt += h;
            while( h > 1 ){
                swap(p[h], p[h - 1]);
                h--;
            }
        }
    }
    cout << cnt << endl;
}