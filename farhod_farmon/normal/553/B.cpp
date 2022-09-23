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

lli n, k, i, j, d[55];
vector < lli > v;

int main()
{
    cin >> n >> k;
    d[0] = 0;
    d[1] = 1;
    for( i = 2; i <= n + 1; i++ )
        d[i] = d[i - 1] + d[i - 2];
    for( i = 1; i <= n; i++ ){
        if( k > d[n - i + 1] ){
            k -= d[n - i + 1];
            v.pb(i + 1);
            v.pb(i);
            i += 1;
        }
        else
            v.pb(i);
    }
    for( i = 0; i < v.size(); i++ )
        cout << v[i] << " ";
}