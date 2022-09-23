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

const int N = 500200;

using namespace std;

lli ans;
lli n, a[N], k;

bool f( lli x )
{
    lli i, h = k;
    for( i = 1; i <= n && h >= 0; i++ )
        if( a[i] < x )
            h -= x - a[i];
    return h >= 0;
}

bool f1( lli x )
{
    lli i, h = k;
    for( i = 1; i <= n && h >= 0; i++ )
        if( a[i] > x )
            h -= a[i] - x;
    return h >= 0;
}

int main()
{
    //fin
    //fout
    ios_base::sync_with_stdio(0);
    lli l = 0, r = 1e9, m, mn, mx, sum = 0;
    cin >> n >> k;
    for( lli i = 1; i <= n; i++ ){
        cin >> a[i];
        sum += a[i];
    }
    lli g = sum / n;
    lli h = 0;
    for( lli i = 1; i <= n; i++ )
        if( a[i] > g )
            h += a[i] - g;
    //cout << h << " " << g << endl;
    if( h <= k ){
        if( sum % n )
            cout << 1 << endl;
        else
            cout << 0 << endl;
        return 0;
    }
    while(l < r){
        m = (l + r) / 2;
        if( f(m + 1) )
            l = m + 1;
        else
            r = m;
    } mn = l;
    l = 0, r = 1e9;
    while(l < r){
        m = (l + r) / 2;
        if( f1(m) )
            r = m;
        else
            l = m + 1;
    } mx = l;
    //cout << mn << " " << mx << endl;
    cout << mx - mn << endl;
}