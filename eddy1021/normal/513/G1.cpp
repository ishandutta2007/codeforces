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
#define N 110
int n , k , p[ N ];
D ans , tbs , bs;
void build(){

}
void init(){
    n = getint(); k = getint();
    for( int i = 1 ; i <= n ; i ++ )
        p[ i ] = getint();
    bs = 1.0; tbs = (D)n * (D)( n + 1 ) * 0.5;
    for( int i = 0 ; i < k ; i ++ )
        bs *= tbs;
}
void cal(){
    int cnt = 0;
    for( int i = 1 ; i <= n ; i ++ )
        for( int j = i + 1 ; j <= n ; j ++ )
            if( p[ i ] > p[ j ] )
                cnt ++;
    ans += cnt;
}
void inv( int ti , int tj ){
    while( ti < tj ){
        swap( p[ ti ] , p[ tj ] );
        ti ++; tj --;
    }
}
void DFS( int now ){
    if( now == k ){
        cal();
        return;
    }
    for( int i = 1 ; i <= n ; i ++ )
        for( int j = i ; j <= n ; j ++ ){
            inv( i , j );
            DFS( now + 1 );
            inv( i , j );
        }
}
void solve(){
    DFS( 0 );
    printf( "%.15f\n" , ans / bs );
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}