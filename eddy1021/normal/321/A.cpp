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
#define N 110
ll a , b , n;
char c[ N ];
ll dx[]={0,0,-1,1};
ll dy[]={1,-1,0,0};
ll x[ N ] , y[ N ];
int type( char ctmp ){
    if( ctmp == 'U' ) return 0;
    if( ctmp == 'D' ) return 1;
    if( ctmp == 'L' ) return 2;
    if( ctmp == 'R' ) return 3;
    return -1;
}
void build(){

}
void init(){
    a = getint(); b = getint();
    scanf( "%s" , c );
    n = strlen( c );
}
bool good( ll ta , ll tb , ll da , ll db ){
    bool cana = false , canb = false;
    ll dlta = -1 , dltb = -1;
    if( da == 0 ){
        if( ta == 0 ) cana = true;
    }else if( ta % da == 0 && ta * da >= 0 )
        cana = true, dlta = ta / da;
    if( db == 0 ){
        if( tb == 0 ) canb = true;
    }else if( tb % db == 0 && tb * db >= 0 )
        canb = true, dltb = tb / db;
    if( !cana || !canb ) return false;
//    cout << ta << " " << tb << " " << da << " " << db << endl;
//    cout << dlta << " " << dltb << endl;
    if( dlta >= 0 && dltb >= 0 )
        return dlta == dltb;
    return true;
}
bool can(){
    if( a == 0 && b == 0 ) return true;
    ll nx = 0 , ny = 0;
    for( int i = 0 ; i < n ; i ++ ){
        int tp = type( c[ i ] );
        nx += dx[ tp ];
        ny += dy[ tp ];
        x[ i ] = nx;
        y[ i ] = ny;
    }
    if( good( a , b , nx , ny ) ) return true;
    for( int i = 0 ; i < n ; i ++ )
        if( good( a - x[ i ] , b - y[ i ] , nx , ny ) ) return true;
    return false;
}
void solve(){
    puts( can() ? "Yes" : "No" );
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}