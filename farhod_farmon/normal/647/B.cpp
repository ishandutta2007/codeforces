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

int n, m, l, r, u, d, i, j;
char c;

int main()
{
    cin >> n >> m;
    l = 1e9;
    d = 1e9;
    for( i = 1; i <= n; i++ ){
        for( j = 1; j <= m; j++ ){
            cin >> c;
            if( c == '.' )
                continue;
            l = min(l, j);
            r = max(r, j);
            d = min(d, i);
            u = max(u, i);
        }
    }
    cout << max(0, max(r - l + 1, u - d + 1)) << endl;
}