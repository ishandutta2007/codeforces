// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long long ll;
typedef int TYPE;
typedef pair<int,int> PII;
#define mod9 1000000009ll
#define mod7 1000000007ll
#define INF 1023456789
#define FI first
#define SE second
#define PB push_back
#define MP make_pair
#define eps 1e-7
int getint(){
    int _x=0,_tmp=1; char _tc=getchar();
    while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
    if( _tc == '-' ) _tc=getchar() , _tmp = -1;
    while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
    return _x*_tmp;
}
bool equal( D _x ,  D _y ){
    return _x > _y - eps && _x < _y + eps;
}
int __ = 1 , cs;
/*********default*********/
ll x , y , k;
class Ma{
    public:
        ll arr[ 2 ][ 2 ];
        Ma(){
            memset( arr , 0 , sizeof( arr ) );
        }
        Ma operator*( const Ma &m ) const{
            Ma tmp;
            for( int i = 0 ; i < 2 ; i ++ )
                for( int j = 0 ; j < 2 ; j ++ )
                    for( int k = 0 ; k < 2 ; k ++ ){
                        tmp.arr[ i ][ j ] += ( arr[ i ][ k ] * m.arr[ k ][ j ] ) % mod7;
                        tmp.arr[ i ][ j ] %= mod7;
                    }
            return tmp;
        }
};
void build(){
    
}
void init(){
    x = getint(); y = getint(); k = getint();
    k -= 2;
}
// x a1 y a2
// 
void solve(){
    if( k == -1 ) printf( "%I64d\n" , ( x + mod7 ) % mod7 );
    else{
        Ma v , t;
        v.arr[ 0 ][ 0 ] = 0; v.arr[ 0 ][ 1 ] = 1; 
        v.arr[ 1 ][ 0 ] = -1; v.arr[ 1 ][ 1 ] = 1;
        t.arr[ 0 ][ 0 ] = 1; t.arr[ 0 ][ 1 ] = 0; 
        t.arr[ 1 ][ 0 ] = 0; t.arr[ 1 ][ 1 ] = 1;
        while( k ){
            if( k & 1 ) t = t * v;
            v = v * v;
            k >>= 1;
        }
        ll ans = ( x * t.arr[ 1 ][ 0 ] ) % mod7;
        ans += ( y * t.arr[ 1 ][ 1 ] ) % mod7;
        ans %= mod7;
        printf( "%I64d\n" , ( ans + mod7 ) % mod7 );
    }
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}