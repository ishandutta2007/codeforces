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

lli n, m, k;

lli f( lli x )
{
    lli i, cnt = 0;
    for( i = 1; i <= n; i++ )
        cnt += min(x / i, m);
    return cnt;
}

int main()
{
    cin >> n >> m >> k;
    lli l = 1, r = n * m;
    while( l < r )
        if( f(l + r >> 1) < k )
            l = (l + r >> 1) + 1;
        else
            r = (l + r >> 1);
    cout << l << endl;
}