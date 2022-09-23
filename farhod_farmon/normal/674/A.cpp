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

int n, i, j, h, a[5005], d[5005], ans[5005];

int main()
{
    cin >> n;
    for( i = 1; i <= n; i++ )
        cin >> a[i];
    for( i = 1; i <= n; i++ ){
        h = i;
        d[a[i]]++;
        ans[a[i]]++;
        for( j = i + 1; j <= n; j++ ){
            d[a[j]]++;
            if( d[a[j]] > d[a[h]] || d[a[j]] == d[a[h]] && a[h] > a[j] )
                h = j;
            ans[a[h]]++;
        }
        for( j = i; j <= n; j++ )
            d[a[j]] = 0;
    }
    for( i = 1; i <= n; i++ )
        cout << ans[i] << " ";
}