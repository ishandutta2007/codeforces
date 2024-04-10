#include <bits/stdc++.h>

#define lli long long int
#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define fin freopen( "input.txt", "r", stdin );
#define fout freopen( "output.txt", "w", stdout );

using namespace std;

lli t[400004], i, j, h, cnt, a[100001], n, k;

lli take( lli x, lli l, lli r, lli tl, lli tr )
{
    if( tl > tr )return 0;
    if( tl == l && tr == r )return t[x];
    lli m = (l + r) / 2;
    return take(x * 2, l, m, tl, min(m, tr)) + take(x * 2 + 1, m + 1, r, max(m + 1, tl), tr);
}

void update( lli x, lli l, lli r, lli g )
{
    if( l == r ){
        t[x] = 1;
        return;
    }
    lli m = (l + r) / 2;
    if( g <= m )update(x * 2, l, m, g);
    else update(x * 2 + 1, m + 1, r, g);
    t[x] = t[x * 2] + t[x * 2 + 1];
}

int main()
{
    cin >> n >> k;
    for( i = 1; i <= n; i++ )a[i] = i;
    for( i = 1; i <= min(n / 2, k); i++ )swap(a[i], a[n - i + 1]);
    for( i = 1; i <= n; i++ ){
        lli g = take(1, 1, n, a[i] + 1, n);
        cnt += g;
        update(1, 1, n, a[i]);
    }
    cout << cnt << endl;
}