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
#define N 64
bool tag[ N ][ N ];
int n , deg[ N ][ N ];
vector<PII> v[ N ][ N ];
vector<bool> vst[ N ][ N ];
char c[ 5 ];
int chg( char ctmp ){
    if( ctmp >= 'a' ) return ctmp - 'a';
    if( ctmp <= '9' ) return ctmp - '0' + 52;
    return ctmp - 'A' + 26;
}
char rchg( int itmp ){
    if( itmp >= 52 ) return itmp - 52 + '0';
    if( itmp >= 26 ) return itmp - 26 + 'A';
    else return itmp + 'a';
}
vector<PII> a;
void build(){
    
}
void Add( char ctmp1 , char ctmp2 ){
    int idx1 = chg( ctmp1 );
    int idx2 = chg( ctmp2 );
    if( !tag[ idx1 ][ idx2 ] ){
        tag[ idx1 ][ idx2 ] = true;
        a.PB( MP( idx1 , idx2 ) );
    }
}
void build_edge(){
    Add( c[ 0 ] , c[ 1 ] );
    Add( c[ 1 ] , c[ 2 ] );
    int idx1 = chg( c[ 0 ] ) , idx2 = chg( c[ 1 ] ) , idx3 = chg( c[ 2 ] );
    v[ idx1 ][ idx2 ].PB( MP( idx2 , idx3 ) );
    vst[ idx1 ][ idx2 ].PB( false );
    deg[ idx1 ][ idx2 ] ++;
    deg[ idx2 ][ idx3 ] --;
}
void init(){
    n = getint();
    for( int i = 0 ; i < n ; i ++ ){
        scanf( "%s" , c );
        build_edge();
    }
//    for( int i = 0 ; i < (int)v[ 0 ][ 1 ].size() ; i ++ )
//        printf( "%d %d\n" , v[ 0 ][ 1 ][ i ].FI , v[ 0 ][ 1 ][ i ].SE );
}
vector<int> ans;
int sidx[ N ][ N ];
void DFS( int nowi , int nowj ){
    for(  ; sidx[ nowi ][ nowj ] < (int)v[ nowi ][ nowj ].size() ; sidx[ nowi ][ nowj ] ++ ){
        int i = sidx[ nowi ][ nowj ];
        int nxti = v[ nowi ][ nowj ][ i ].FI;
        int nxtj = v[ nowi ][ nowj ][ i ].SE;
        if( !vst[ nowi ][ nowj ][ i ] ){
            vst[ nowi ][ nowj ][ i ] = true;
            DFS( nxti , nxtj );
            ans.PB( nxtj );
        }
    }
}
void solve(){
    int odd = 0 , oidx = -1;
    bool flag = true;
    for( int i = 0 ; i < (int)a.size() ; i ++ ){
        if( deg[ a[ i ].FI ][ a[ i ].SE ] % 2 ){
            odd ++;
            if( deg[ a[ i ].FI ][ a[ i ].SE ] > 0 )
                oidx = i;
//            printf( "%d %d %d %d\n" , i , a[ i ].FI , a[ i ].SE , deg[ a[ i ].FI ][ a[ i ].SE ] );
        }else if( deg[ a[ i ].FI ][ a[ i ].SE ] != 0 ) flag = false;
    }
//    printf( "%d %d\n" , odd , oidx );
    if( flag && ( odd == 0 || ( odd == 2 && oidx != -1 ) ) ){
        int sti = 0 , stj = 0;
        if( oidx == -1 ) sti = a[ 0 ].FI , stj = a[ 0 ].SE;
        else sti = a[ oidx ].FI , stj = a[ oidx ].SE;
//        printf( "%d %d\n" , sti , stj );
        DFS( sti , stj );
        if( (int)ans.size() != n ) puts( "NO" );
        else{
            puts( "YES" );            
            putchar( rchg( sti ) );            
            putchar( rchg( stj ) );
            for( int i = n - 1 ; i >= 0 ; i -- )
                putchar( rchg( ans[ i ] ) );
            puts( "" );            
        }
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