#include <set>
#include <map>
#include <queue>
#include <deque>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define N 110
int getint(){
    int x=0,tmp=1; char c=getchar();
    while( (c<'0'||c>'9')&&c!='-' ) c=getchar();
    if( c == '-' ) c=getchar() , tmp = -1;
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x*tmp;
}
int n;
char c[ N ][ 5 ];
int fl( char ctmp ){
    if( ctmp == 'R' ) return 0;
    if( ctmp == 'G' ) return 1;
    if( ctmp == 'B' ) return 2;
    if( ctmp == 'Y' ) return 3;
    return 4;
}
int tag[ N ];
void init(){
    n = getint();
    for( int i = 0 ; i < n ; i ++ )
        scanf( "%s" , c[ i ] );
}
bool flag;
void test( int now , int pc , int mk ){
    if( !flag ) return;
    if( now == 10 ){
        int pre = -1;
        for( int i = 0 ; i < n ; i ++ )
            if( tag[ i ] == mk ){
                if( pre == -1 ) pre = i;
                else if( c[ i ][ 0 ] != c[ pre ][ 0 ] || c[ i ][ 1 ] != c[ pre ][ 1 ] ){
                    flag = false;
                    return;
                }
            }
        return;
    }
    if( ( ( 1 << now ) & pc ) > 0 ){
        if( now < 5 ){
            for( int i = 0 ; i < n ; i ++ )
                if( tag[ i ] == mk && fl( c[ i ][ 0 ] ) == now )
                    tag[ i ] |= ( 1 << now );
            test( now + 1 , pc , mk | ( 1 << now ) );
            for( int i = 0 ; i < n ; i ++ )
                if( tag[ i ] == ( mk | ( 1 << now ) ) )
                    tag[ i ] ^= ( 1 << now );
                else if( tag[ i ] == mk )
                    tag[ i ] |= ( 1 << now );
            test( now + 1 , pc , mk | ( 1 << now ) );
            for( int i = 0 ; i < n ; i ++ )
                if( tag[ i ] == ( mk | ( 1 << now ) ) && fl( c[ i ][ 0 ] ) != now )
                    tag[ i ] ^= ( 1 << now );
        }else{
            for( int i = 0 ; i < n ; i ++ )
                if( tag[ i ] == mk && c[ i ][ 1 ] - '0' == now - 4 )
                    tag[ i ] |= ( 1 << now );
            test( now + 1 , pc , mk | ( 1 << now ) );
            for( int i = 0 ; i < n ; i ++ )
                if( tag[ i ] == ( mk | ( 1 << now ) ) && c[ i ][ 1 ] - '0' == now - 4 )
                    tag[ i ] ^= ( 1 << now );
                else if( tag[ i ] == mk )
                    tag[ i ] |= ( 1 << now );
            test( now + 1 , pc , mk | ( 1 << now ) );
            for( int i = 0 ; i < n ; i ++ )
                if( tag[ i ] == ( mk | ( 1 << now ) ) && c[ i ][ 1 ] - '0' != now - 4 )
                    tag[ i ] ^= ( 1 << now );
        }
    }else test( now + 1 , pc , mk );
}
void solve(){
    int ans = 10;

    for( int i = ( 1 << 10 ) - 1 ; i >= 0 ; i -- ){
        flag = true;
        test( 0 , i , 0 );

        if( flag ){
            int tmp = i , cnt = 0;
            while( tmp ){
                if( tmp & 1 )cnt ++;
                tmp >>= 1;
            }
            if( cnt < ans ) ans = cnt;
        }
    }
    printf( "%d\n" , ans );
}
int main(){
    init();
    solve();
}