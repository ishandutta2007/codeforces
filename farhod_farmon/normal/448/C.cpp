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

int n, a[5005];

int f( int l, int r, int h )
{
    if( l > r    )
        return 0;
    int mn = l;
    for( int i = l + 1; i <= r; i++ )
        if( a[i] < a[mn] )
            mn = i;
    return min(r - l + 1, f(l, mn - 1, a[mn]) + f(mn + 1, r, a[mn]) + a[mn] - h);
}

int main()
{
    cin >> n;
    for( int i = 1; i <= n; i++ )
        cin >> a[i];
    cout << f(1, n, 0) << endl;
}