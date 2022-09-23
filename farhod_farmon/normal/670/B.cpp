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

lli n, a[100001], i, j, h, k;

int main()
{
    cin >> n >> k;
    for( i = 1; i <= n; i++ ){
        cin >> a[i];
        h += i;
        if( h >= k ){
            h -= i;
            cout << a[k - h] << endl;
            return 0;
        }
    }
}