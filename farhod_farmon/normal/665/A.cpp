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

int a, ta, b, tb, i, j, h, cnt, x, y;

int main()
{
    cin >> a >> ta >> b >> tb;
    sc( "%d:%d", &x, &y );
    x = x * 60 + y;
    for( i = 5 * 60; i < 24 * 60; i += b )
        if( max(i, x) < min(x + ta, i + tb) )
            cnt++;
    cout << cnt << endl;
}