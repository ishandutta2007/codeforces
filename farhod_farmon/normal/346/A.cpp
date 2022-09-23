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

int n, a, g, i, mx;

int main()
{
    cin >> n;
    for( i = 1; i <= n; i++ ){
        cin >> a;
        if( i == 1 )
            g = a;
        else
            g = __gcd(g, a);
        if( a > mx )
            mx = a;
    }
    mx = mx / g - n;
    if( mx % 2 )
        cout << "Alice" << endl;
    else
        cout << "Bob" << endl;
}