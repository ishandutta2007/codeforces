// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long long ll;
typedef int TYPE;
typedef pair<int,int> PII;
#define mod9 1000000009
#define mod7 1000000007
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
#define N 3100
int m , t , r;
bool lt[ N * 2 ];
vector<int> v;
void build(){
    
}
void init(){
    m = getint(); t = getint(); r = getint();
    for( int i = 0 ; i < m ; i ++ )
        v.PB( getint() );
}
bool notgood(){
    for( int i = 0 ; i < m ; i ++ ){
        int got = 0;
        for( int j = v[ i ] ; j > v[ i ] - t && got < r ; j -- )
            if( lt[ N + j ] ) got ++;
        if( got >= r ) continue;
        for( int j = v[ i ] ; j > v[ i ] - t && got < r ; j -- )
            if( !lt[ N + j ] ) lt[ N + j ] = true , got ++;
        if( got < r ) return true;
    }
    return false;
}
void solve(){
    if( notgood() ) puts( "-1" );
    else{
        int ans = 0;
        for( int i = 0 ; i < N * 2 ; i ++ )
            if( lt[ i ] ) ans ++;
        printf( "%d\n" , ans );
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