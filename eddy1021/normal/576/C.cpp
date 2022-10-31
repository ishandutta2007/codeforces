// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long long ll;
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
#define eps 1e-9
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
ll getint(){
    ll _x=0,_tmp=1; char _tc=getchar();    
    while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
    if( _tc == '-' ) _tc=getchar() , _tmp = -1;
    while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
    return _x*_tmp;
}
ll mypow( ll _a , ll _x , ll _mod ){
    if( _x == 0 ) return 1ll;
    ll _tmp = mypow( _a , _x / 2 , _mod );
    _tmp = ( _tmp * _tmp ) % _mod;
    if( _x & 1 ) _tmp = ( _tmp * _a ) % _mod;
    return _tmp;
}
bool equal( D _x ,  D _y ){
    return _x > _y - eps && _x < _y + eps;
}
int __ = 1 , cs;
/*********default*********/
#define N 1000010
#define K 1001
ll sum , n , x[ N ] , y[ N ];
vector<int> v[ K + 10 ][ K + 10 ];
void build(){

}
vector<int> ans;
ll dis( int tu , int tv ){
    return abs( x[ tu ] - x[ tv ] ) + abs( y[ tu ] - y[ tv ] );
}
void init(){
    n = getint();
    for( int i = 1 ; i <= n ; i ++ ){
        x[ i ] = getint();
        y[ i ] = getint();
        v[ x[ i ] / K ][ y[ i ] / K ].PB( i );
    }
    for( int i = 0 ; i <= N / K ; i ++ )
        if( i & 1 ){
            for( int j = 0 ; j <= N / K ; j ++ )
                for( int k = 0 ; k < (int)v[ i ][ j ].size() ; k ++ )
                    ans.PB( v[ i ][ j ][ k ] );
        }else{
            for( int j = N / K ; j >= 0 ; j -- )
                for( int k = 0 ; k < (int)v[ i ][ j ].size() ; k ++ )
                    ans.PB( v[ i ][ j ][ k ] );
        }
    for( int i = 1 ; i < n ; i ++ )
        sum += dis( ans[ i - 1 ] , ans[ i ] );
}
void solve(){
    srand( 514514 );
    while( sum > 2500000000ll ){
        int tx = ( (ll)rand() * (ll)rand() ) % n;
        int ty = ( (ll)rand() * (ll)rand() ) % n;
        if( tx == ty ) continue;
        ll tsum = sum;
        if( tx ) tsum -= dis( ans[ tx - 1 ] , ans[ tx ] );
        if( tx < n - 1 ) tsum -= dis( ans[ tx ] , ans[ tx + 1 ] );
        if( ty && tx != ty - 1 ) tsum -= dis( ans[ ty - 1 ] , ans[ ty ] );
        if( ty < n - 1 &&
                tx != ty + 1 ) tsum -= dis( ans[ ty ] , ans[ ty + 1 ] );
        swap( ans[ tx ] , ans[ ty ] );
        if( tx ) tsum += dis( ans[ tx - 1 ] , ans[ tx ] );
        if( tx < n - 1 ) tsum += dis( ans[ tx ] , ans[ tx + 1 ] );
        if( ty && tx != ty - 1 ) tsum += dis( ans[ ty - 1 ] , ans[ ty ] );
        if( ty < n - 1 &&
                tx != ty + 1 ) tsum += dis( ans[ ty ] , ans[ ty + 1 ] );
        if( tsum >= sum ) swap( ans[ tx ] , ans[ ty ] );
        else sum = tsum;
    }
    for( int i = 0 ; i < n ; i ++ )
        printf( "%d%c" , ans[ i ] , i == n - 1 ? '\n' : ' ' );
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}