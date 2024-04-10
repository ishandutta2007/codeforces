#include <bits/stdc++.h>
using namespace std;
#define N 10010
int getint(){
    int x=0; char c=getchar();
    while( c<'0'||c>'9' ) c=getchar();
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x;
}
vector< pair<int,int> > v[ 2 ];
int n , a[ 2 ][ N ];
void XOR( int i , int j , int idx ){
    v[ idx ].push_back( make_pair( i , j ) );
    a[ idx ][ i ] ^= a[ idx ][ j ];
}
void init(){
    n = getint();
    for( int j = 0 ; j < 2 ; j ++ )
        for( int i = 0 ; i < n ; i ++ )
            a[ j ][ i ] = getint();
}
void Gauss( int idx ){
    int pre = 0;
    for( int i = 30 ; i >= 0 ; i -- )
        for( int j = pre ; j < n ; j ++ )
            if( a[ idx ][ j ] & ( 1 << i ) ){
                if( j != pre ){
                    XOR( j , pre , idx );
                    XOR( pre , j , idx );
                    XOR( j , pre , idx );
                }
                for( int k = 0 ; k < n ; k ++ )
                    if( k != pre && ( a[ idx ][ k ] & ( 1 << i ) ) )
                        XOR( k , pre , idx );
                pre ++;
                break;
            }
}
void solve(){
    for( int i = 0 ; i < 2 ; i ++ )
        Gauss( i );
    for( int i = 0 ; i < n ; i ++ )
        if( a[ 0 ][ i ] ){
            int bs = ( 1 << 30 );
            while( ( a[ 0 ][ i ] & bs ) == 0 ) bs >>= 1;
            for( int j = 0 ; j <= 30 && j < n ; j ++ )
                if( ( a[ 0 ][ j ] ^ a[ 1 ][ j ] ) & bs )
                    XOR( j , i , 0 );
        }else break;
    for( int i = 0 ; i < n ; i ++ )
        if( a[ 0 ][ i ] != a[ 1 ][ i ] ){
            puts( "-1" );
            return;
        }
    printf( "%d\n" , (int)v[ 0 ].size() + (int)v[ 1 ].size() );
    for( int i = 0 ; i < (int)v[ 0 ].size() ; i ++ )
        printf( "%d %d\n" , v[ 0 ][ i ].first + 1 , v[ 0 ][ i ].second + 1 );
    for( int i = (int)v[ 1 ].size() - 1 ; i >= 0 ; i -- )
        printf( "%d %d\n" , v[ 1 ][ i ].first + 1 , v[ 1 ][ i ].second + 1 );
}
int main(){
    init();
    solve();
}