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

int n, m, i, j, h, k, l, a[5][101], g;

int main()
{
    cin >> n >> m;
    k = m;
    g = 1;
    for( i = 1; i <= n && k; i++ ){
        a[1][i] = g++;
        k--;
        if( k ){
            a[4][i] = g++;
            k--;
        }
    }
    for( i = 1; i <= n && k; i++ ){
        a[2][i] = g++;
        k--;
        if( k ){
            a[3][i] = g++;
            k--;
        }
    }
    for( i = 1; i <= n; i++ ){
        if( a[2][i] )
            cout << a[2][i] << " ";
        if( a[1][i] )
            cout << a[1][i] << " ";
        if( a[3][i] )
            cout << a[3][i] << " ";
        if( a[4][i] )
            cout << a[4][i] << " ";
    }
}