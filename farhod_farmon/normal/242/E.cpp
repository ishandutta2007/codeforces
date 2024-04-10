#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")

#define fi first
#define se second
#define LL long long

using namespace std;

const int B = 317;
const int N = 1e5 + 7;
const int maxn = 1e5 + 7;
const LL mod = 1e9 + 7;
const int inf = 1e9 + 100;

int n;
LL a[N];
LL q[22][4 * N];
LL t[22][4 * N];

void push( int x , int y, int l, int r )
{
    if( q[y][x] ){
        int m = (l + r) / 2;
        q[y][x * 2] ^= 1;
        t[y][x * 2] = (m - l + 1) - t[y][x * 2];
        q[y][x * 2 + 1] ^= 1;
        t[y][x * 2 + 1] = (r - m) - t[y][x * 2 + 1];
        q[y][x] = 0;
    }
}

void build( int x , int y , int l , int r )
{
    if( l == r ){
        t[y][x] = (a[l] >> y) & 1;
        return;
    }
    int m = (l + r) / 2;
    build( x * 2 , y , l , m );
    build( x * 2 + 1 , y , m + 1 , r );
    t[y][x] = t[y][x * 2] + t[y][x * 2 + 1];
}

LL get( int x , int y , int l , int r , int tl , int tr )
{
    if( tl > tr )return 0;
    if( tl == l && tr == r ){
        return t[y][x];
    }
    if( q[y][x] ){
        //t[y][x] = (r - l + 1) - t[y][x];
        push(x , y, l, r);
    }
    int m = (l + r) / 2;
    LL ff = get( x * 2 , y , l , m , tl , min(tr , m) ) +
        get( x * 2 + 1 , y , m + 1 , r , max(tl , m + 1) , tr );
    //t[y][x] = t[y][x * 2] + t[y][x * 2 + 1];
    return ff;
}

void upd( int x , int y , int l , int r , int tl , int tr )
{
    if( tl > tr )return;
    if( l == tl && r == tr ){
        q[y][x] ^= 1;
        t[y][x] = (r - l + 1) - t[y][x];
        //push(x , y);
        return;
    }
    if( q[y][x] ){
        //t[y][x] = (r - l + 1) - t[y][x];
        push(x , y, l, r);
    }
    int m = (l + r) / 2;
    upd( x * 2 , y , l , m , tl , min(tr , m ) );
    upd( x * 2 + 1 , y , m + 1 , r , max(tl , m + 1) , tr );
    t[y][x] = t[y][x * 2] + t[y][x * 2 + 1];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen( "input.txt" , "r" , stdin );
    //freopen( "output.txt" , "w" , stdout );

    cin >> n;
    for( int i = 1; i <= n; i++ ){
        cin >> a[i];
    }
    for( int i = 0; i < 21; i++ )build(1 , i , 1 , n);
    int q;
    cin >> q;
    for( int i = 1; i <= q; i++ ){
        int tp;
        cin >> tp;
        if( tp == 1 ){
            int l,r;
            cin >> l >> r;
            LL ans = 0;
            for( int j = 0; j < 21; j++ ){
                ans += (1LL << j) * 1LL * get( 1 , j , 1 , n , l , r );
            }
            cout << ans << "\n";
        }
        else{
            int l,r,x;
            cin >> l >> r >> x;
            LL res = 0;
            for( int j = 0; j < 21; j++ ){
                if( (x >> j) & 1 ){
                    upd( 1 , j , 1 , n , l , r );
                }
            }
        }
    }
}