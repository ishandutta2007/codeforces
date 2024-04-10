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

/*
f1 = x;
f2 = y;
f3 = y - x;
f4 = -x;
f5 = -y;
f6 = -y + x;
f7 = x
f8 = y
*/

lli x, y, mod = 1e9 + 7, n;

int main()
{
    cin >> x >> y >> n;
    lli d[7] = {0, x, y, y - x, - x, - y, - y + x};
    n = (n - 1) % 6 + 1;
    n = d[n];
    n %= mod;
    if( n < 0 )
        n += mod;
    cout << n << endl;
}