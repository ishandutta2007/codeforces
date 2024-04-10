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

int n, a[1001], i;

int main()
{
    cin >> n;
    for( i = 1; i <= n; i++ )
        cin >> a[i];
    sort( a + 1, a + n + 1 );
    for( i = 1; i <= n / 2; i++ )
        cout << a[i] << " " << a[n - i + 1] << " ";
    if( n % 2 )
        cout << a[i] << endl;
    else
        cout << endl;
}