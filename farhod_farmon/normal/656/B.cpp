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

double a, b;
vector < int > v;
int n, i, j, h = 1, c[17], d[17];

int main()
{
    cin >> n;
    for( i = 1; i <= n; i++ ){
        cin >> c[i];
        h = h * c[i] / __gcd(h, c[i]);
    }
    for( i = 1; i <= n; i++ )
        cin >> d[i];
    for( i = 0; i < h; i++ ){
        bool b1 = false;
        for( j = 1; j <= n; j++ ){
            if( i % c[j] == d[j] )
                b1 = true;
        }
        a += b1;
    }
    cout << a * 1. / h << endl;
}