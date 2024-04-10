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

int n, m, i, j, h, x, y, a[5005], d[5005], cnt, l, r;

int main()
{
    cin >> n >> m;
    for( i = 1; i <= n; i++ ){
        double b;
        cin >> a[i] >> b;
        d[i] = 1e9;
    }
    for( i = 1; i <= n; i++ ){
        for( h = 1; h <= n; h++ ){
            if( d[h] > a[i] )
                break;
        }
        d[h] = a[i];
        cnt = max(cnt, h);
    }
    cout << n - cnt << endl;
}