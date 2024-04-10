// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long long ll;
typedef int TYPE;
typedef pair<int,int> PII;
#define mod9 1000000009int
#define mod7 1000000007int 
#define INF 1023456789int
#define FI first
#define SE second
#define PB push_back
#define MP make_pair
#define eps 1e-7
ll getint(){
    ll _x=0,_tmp=1; char _tc=getchar();
    while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
    if( _tc == '-' ) _tc=getchar() , _tmp = -1;
    while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
    return _x*_tmp;
}
ll mypow( ll _a , ll _x , ll _mod ){
    if( _x == 0 ) return 1;
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
#define N 100010
void build(){

}
int n , k , p , x , y , a[ N ] , low , sum;
vector<int> ans;
void init(){
    n = getint(); k = getint(); p = getint();
    x = getint(); y = getint();
    for( int i = 1 ; i <= k ; i ++ ){
        a[ i ] = getint();
        if( a[ i ] < y )
            low ++;
        sum += a[ i ];
    }
}
void solve(){
    if( low > n / 2 || sum > x ){
        puts( "-1" );
        return;
    }
    for( int i = k + 1 ; i <= n ; i ++ )
        if( low + 1 <= n / 2 ){
            ans.PB( 1 );
            low ++;
            sum += 1;
        }else{
            ans.PB( y );
            sum += y;
        }
    if( sum > x ){
        puts( "-1" );
        return;
    }
    for( int i = 0 ; i < (int)ans.size() ; i ++ )
        printf( "%d " , ans[ i ] );
    puts( "" );
}
int main(){
    build();  
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}