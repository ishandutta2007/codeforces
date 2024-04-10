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

const int N = 1000011;

using namespace std;

int l[N], r[N], n, t[N];
lli ans;
pair < int, int > a[N];

void cn( int tl, int tr, int tm )
{
    int i, j;
    for( i = j = 0; i + tl < tm; i++ ){
        while( r[j + tm] < l[i + tl] && j + tm <= tr )
            j++;
        //cout << i << " " << j << " " << l[i + tl] << " " << r[j + tm] << endl;
        ans += j;
    }
    int h = tl;
    for( i = tl, j = tm; i < tm; i++ ){
        while( l[j] <= l[i] && j <= tr )
            t[h++] = l[j++];
        t[h++] = l[i];
    }
    while( j <= tr )
        t[h++] = l[j++];
    for( i = tl; i <= tr; i++ )
        l[i] = t[i];
    h = tl;
    for( i = tl, j = tm; i < tm; i++ ){
        while( r[j] <= r[i] && j <= tr )
            t[h++] = r[j++];
        t[h++] = r[i];
    }
    while( j <= tr )
        t[h++] = r[j++];
    for( i = tl; i <= tr; i++ )
        r[i] = t[i];
}

void dv( int tl, int tr )
{
    if( tl >= tr )
        return;
    int tm = tl + tr >> 1;
    dv(tl, tm);
    dv(tm + 1, tr);
    //cout << tl << " " << tr << " " << tm + 1 << " " << ans << endl;
    //cout << "   V\n";
    cn(tl, tr, tm + 1);
    //cout << "-----------------------------------------------" << endl;
}

int main()
{
    int i;
    sc( "%d", &n );
    for( i = 1; i <= n; i++ ){
        sc( "%d", &a[i].fi );
        a[i].se = i;
    }
    sort( a + 1, a + n + 1 );
    int cnt;
    for( i = 1; i <= n; i++ ){
        if( a[i].fi != a[i - 1].fi )
            cnt = 1;
        else
            cnt++;
        l[a[i].se] = cnt;
    }
    for( i = n; i >= 1; i-- ){
        if( a[i].fi != a[i +  1].fi )
            cnt = 1;
        else
            cnt++;
        r[a[i].se] = cnt;
    }
    dv(1, n);
    pr( "%I64d\n", ans );
}