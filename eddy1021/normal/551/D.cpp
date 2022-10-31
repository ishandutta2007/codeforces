// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
#define mod9 1000000009ll
#define mod7 1000000007ll 
#define INF  1023456789ll
#define INF16 10000000000000000ll
#define FI first
#define SE second
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define eps 1e-18
ll getint(){
    ll _x=0,_tmp=1; char _tc=getchar();    
    while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
    if( _tc == '-' ) _tc=getchar() , _tmp = -1;
    while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
    return _x*_tmp;
}
ull mypow( ull _a , ull _x , ull _mod ){
    if( _x == 0llu ) return 1llu;
    ull _tmp = mypow( _a , _x / 2llu , _mod );
    _tmp = ( _tmp * _tmp ) % _mod;
    if( _x & 1llu ) _tmp = ( _tmp * _a ) % _mod;
    return _tmp;
}
bool equal( D _x ,  D _y ){
    return _x > _y - eps && _x < _y + eps;
}
int __ = 1 , cs;
/*********default*********/
ull n , k , l , mod;
class matrix{
public:
    ull a[ 2 ][ 2 ];
    matrix(){
        a[ 0 ][ 0 ] = a[ 0 ][ 1 ] = a[ 1 ][ 0 ] = a[ 1 ][ 1 ] = 0;
    }
    matrix( ull a00 , ull a01 , ull a10 , ull a11 ){
        a[ 0 ][ 0 ] = a00 % mod; a[ 0 ][ 1 ] = a01 % mod;
        a[ 1 ][ 0 ] = a10 % mod; a[ 1 ][ 1 ] = a11 % mod;
    }
    matrix operator+( const matrix & m ) const{
        matrix tmp;
        for( int i = 0 ; i < 2 ; i ++ )
            for( int j = 0 ; j < 2 ; j ++ )
                tmp.a[ i ][ j ] = ( m.a[ i ][ j ] + a[ i ][ j ] ) % mod;
        return tmp;
    }
    matrix operator*( const matrix & m ) const{
        matrix tmp;
        for( int i = 0 ; i < 2 ; i ++ )
            for( int j = 0 ; j < 2 ; j ++ )
                for( int tk = 0 ; tk < 2 ; tk ++ )
                    tmp.a[ i ][ j ] = ( tmp.a[ i ][ j ] + a[ i ][ tk ] * m.a[ tk ][ j ] ) % mod;
        return tmp;
    }
};
void build(){

}
void init(){
    cin >> n >> k >> l >> mod;
}
void solve(){
    if( l < 64 && k >= ( 1llu << l ) ){
        puts( "0" );
        return;
    }
    if( l == 0 ){
        if( k == 0 ) cout << 1 % mod << endl;
        else cout << 0 << endl;
        return;
    }
    ull cnt0 = 0 , cnt1 = 0;
    for( ull i = 0 ; i < l ; i ++ )
        if( k & ( 1llu << i ) ) cnt1 ++;
        else cnt0 ++;
    matrix tmp( 1 , 1 , 1 , 0 );
    matrix tans( 1 , 0 , 0 , 1 );
    ull tn = n;
    while( tn ){
        if( tn % 2llu == 1llu ) tans = tans * tmp;
        tmp = tmp * tmp;
        tn /= 2llu;
    }
    ull tmpans = ( tans.a[ 0 ][ 0 ] + tans.a[ 0 ][ 1 ] ) % mod;
    ull ze = mypow( tmpans , cnt0 , mod );
    ull on = mypow( 2llu , n , mod );
    on = ( on - tmpans + mod ) % mod;
    on = mypow( on , cnt1 , mod );
    ull ans = ( ze * on ) % mod;
    cout << ans << endl;
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}