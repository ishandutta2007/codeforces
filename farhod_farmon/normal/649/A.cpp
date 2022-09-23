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

vector < lli > v;
lli n, a[101], i, j, x = 1;

int main()
{
    cin >> n;
    for( i = 1; i <= n; i++ )
        cin >> a[i];
    while( x <= 1000000000 ){
        bool b1 = false;
        for( i = 1; i <= n; i++ )
            if( a[i] % x == 0 )
                b1 = true;
        if( b1 ){
            v.clear();
            j = x;
            for( i = 1; i <= n; i++ )
                if( a[i] % x == 0 )
                    v.pb(a[i]);
        }
        x *= 2;
    }
    cout << j << " " << v.size() << endl;
}