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

int n, k, a[33], x, i, j;
bool used[33 * 33];

int main()
{
    cin >> n >> k;
    for( i = 1; i <= k; i++ ){
        cin >> x;
        a[i] = x;
        used[x] = true;
    }
    for( i = 1; i <= k; i++ ){
        cout << a[i] << " ";
        int h = n - 1;
        for( j = 1; j <= n * k && h; j++ ){
            if( used[j] )
                continue;
            cout << j << " ";
            used[j] = true;
            h--;
        }
        cout << endl;
    }
}