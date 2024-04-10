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

int h1, h2, a, b;

int main()
{
    cin >> h1 >> h2 >> a >> b;
    h1 += 8 * a;
    if( h1 >= h2 ){
        cout << 0 << endl;
        return 0;
    }
    if( b >= a ){
        cout << -1 << endl;
        return 0;
    }
    a = a - b;
    a = 12 * a;
    cout << (h2 - h1 - 1) / a + 1 << endl;
    return 0;
}