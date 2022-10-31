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
#define N 12
int a[ N ][ N ] , n;
void build(){
    
}
void init(){
    n = getint();
    for( int i = 1 ; i <= n ; i ++ ) a[ i ][ 1 ] = a[ 1 ][ i ] = 1;
    for( int i = 2 ; i <= n ; i ++ )
        for( int j = 2 ; j <= n ; j ++ )
            a[ i ][ j ] = a[ i - 1 ][ j ] + a[ i ][ j - 1 ];
}
void solve(){
    printf( "%d\n" , a[ n ][ n ] );
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}