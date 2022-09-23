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

const int N = 100100;
const int L = 317;

using namespace std;

int a[N], n, lastans;
int sz[N / L + 5];
int ct[N / L + 5][N];
int val[N / L + 5][L + L + 5];

void build()
{
    for( int i = 1; i <= (n - 1) / L + 1; i++ ){
        int l = (i - 1) * L + 1;
        int r = min(n, l + L - 1);
        for( int j = l; j <= r; j++ ){
            val[i][++sz[i]] = a[j];
            ct[i][a[j]]++;
        }
    }
}

void rebuild()
{
    int h = 1;
    for( int i = 1; i <= (n - 1) / L + 1; i++ ){
        for( int j = 1; j <= sz[i]; j++ ){
            ct[i][val[i][j]] = 0;
            a[h++] = val[i][j];
        }
        sz[i] = 0;
    }
    build();
}

int getx( int g )
{
    int cnt = 0;
    for( int i = 1; i <= (n - 1) / L + 1; i++ ){
        cnt += sz[i];
        if( cnt >= g ){
            int h = sz[i] - (cnt - g);
            int x = val[i][h];
            for( int j = h; j < sz[i]; j++ )
                val[i][j] = val[i][j + 1];
            ct[i][x]--;
            sz[i]--;
            return x;
        }
    }
}

void upd( int l, int r )
{
    if( l == r )
        return;
    int x = getx(r);
    int cnt = 0;
    for( int i = 1; i <= (n - 1) / L + 1; i++ ){
        cnt += sz[i];
        if( cnt >= l ){
            int h = sz[i] - (cnt - l);
            sz[i]++;
            ct[i][x]++;
            for( int j = sz[i]; j > h; j-- )
                val[i][j] = val[i][j - 1];
            val[i][h] = x;
            break;
        }
    }
}

int get( int g, int x )
{
    int cnt = 0, kol = 0;
    for( int i = 1; i <= (n - 1) / L + 1; i++ ){
        cnt += sz[i];
        if( cnt <= g )
            kol += ct[i][x];
        else{
            cnt -= sz[i];
            for( int j = 1; cnt + j <= g; j++ )
                if( val[i][j] == x )
                    kol++;
            break;
        }
    }
    return kol;
}

int main()
{
    sc( "%d", &n );
    for( int i = 1; i <= n; i++ )
        sc( "%d", &a[i] );
    build();
    int q, gg = 1;
    sc( "%d", &q );
    while( q-- ){
        int t, l, r, x;
        sc( "%d%d%d", &t, &l, &r );
        l = (l + lastans - 1) % n + 1;
        r = (r + lastans - 1) % n + 1;
        if( l > r )
            swap(l, r);
        if( t == 2 ){
            sc( "%d", &x );
            x = (x + lastans - 1) % n + 1;
            lastans = get(r, x) - get(l - 1, x);
            pr( "%d\n", lastans );
        }
        else{
            upd(l, r);
            gg++;
        }
        if( gg % L == 0 ){
            rebuild();
            gg++;
        }
    }
}