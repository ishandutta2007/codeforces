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

int n, i, x[1001];
vector < int > v;

int main()
{
    cin >> n;
    for( i = 1; i <= n; i++ )
        cin >> x[i];
    for( i = 1; i < n; i++ ){
        v.pb(x[i]);
        if( __gcd(x[i], x[i + 1]) != 1 )
            v.pb(1);
    }
    v.pb(x[i]);
    cout << v.size() - n << endl;
    for( i = 0; i < v.size(); i++ )
        cout << v[i] << " ";
}