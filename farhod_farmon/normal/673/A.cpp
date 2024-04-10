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

int n, a[99], i;

int main()
{
    cin >> n;
    for( i = 1; i <= n; i++ )
        cin >> a[i];
    a[n + 1] = 90;
    for( i = 0; i <= n; i++ ){
        if( a[i] + 15 < a[i + 1] ){
            cout << a[i] + 15 << endl;
            return 0;
        }
    }
    cout << 90 << endl;
}