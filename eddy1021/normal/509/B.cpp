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
#define N 110
vector<int> ans[ N ];
int n , k , a[ N ] , usd[ N ] , nk , mt;
void build(){
    
}
void init(){
    n = getint(); k = getint();
    for( int i = 1 ; i <= n ; i ++ ){
        a[ i ] = getint();
        mt = max( mt , a[ i ] );
    }
}
bool okay(){
    int pre = 0;
    for( int i = 1 ; i <= mt ; i ++ ){
        int cnt = 0;
        for( int j = 1 ; j <= n ; j ++ )
            if( a[ j ] >= i ) cnt ++;
        if( cnt != pre ){
            nk ++; if( nk > k ) nk = 1;
            if( usd[ nk ] ) return false;
            if( cnt != n ) usd[ nk ] = 1;
        }
        for( int j = 1 ; j <= n ; j ++ )
            if( a[ j ] >= i )
                ans[ j ].PB( nk );
    }
    return true;
}
void solve(){
    if( okay() ){
        puts( "YES" );
        for( int i = 1 ; i <= n ; i ++ , puts( "" ) )
            for( int j = 0 ; j < a[ i ] ; j ++ )
                printf( "%d " , ans[ i ][ j ] );
    }else puts( "NO" );
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}