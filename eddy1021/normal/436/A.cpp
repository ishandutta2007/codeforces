#include <set>
#include <map>
#include <queue>
#include <vector>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define N 2010
int getint(){
    int x=0,tmp=1; char c=getchar();
    while( (c<'0'||c>'9')&&c!='-' ) c=getchar();
    if( c == '-' ) c=getchar() , tmp = -1;
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x*tmp;
}
struct XD{
    int h , m;
}bx1[ N ] , bx2[ N ];
bool cmp( XD x , XD y ){
    if( x.m != y.m ) return x.m > y.m;
    return x.h < y.h;
}
int t , n , x , a[ N ] , h[ N ] , n1 , n2 , ans;
bool got1[ N ] , got2[ N ];
void init(){
    n = getint(); x = getint();
    for( int i = 0 ; i < n ; i ++ ){
        t = getint();
        if( !t ){
            bx1[ n1 ].h = getint();
            bx1[ n1 ++ ].m = getint();
        }else{
            bx2[ n2 ].h = getint();
            bx2[ n2 ++ ].m = getint();
        }
    }
    std::sort( bx1 , bx1 + n1 , cmp );
    std::sort( bx2 , bx2 + n2 , cmp );
}
void solve(){
    int nh = x , div = 0 , cnt = 0;
    while( 1 ){
        bool got = false;
        if( !div ){
            for( int i = 0 ; i < n1 ; i ++ )
                if( !got1[ i ] && nh >= bx1[ i ].h ){
                    nh += bx1[ i ].m;
                    cnt ++;
                    got1[ i ] = true;
                    got = true;
                    break;
                }
        }else{
            for( int i = 0 ; i < n2 ; i ++ )
                if( !got2[ i ] && nh >= bx2[ i ].h ){
                    nh += bx2[ i ].m;
                    cnt ++;
                    got2[ i ] = true;
                    got = true;
                    break;
                }
        }
        if( !got ) break;
        div = 1 - div;
    }
    ans = cnt;
    nh = x; div = 1; cnt = 0;
    memset( got1 , 0 , sizeof( got1 ) );
    memset( got2 , 0 , sizeof( got2 ) );
    while( 1 ){
        bool got = false;
        if( !div ){
            for( int i = 0 ; i < n1 ; i ++ )
                if( !got1[ i ] && nh >= bx1[ i ].h ){
                    nh += bx1[ i ].m;
                    cnt ++;
                    got1[ i ] = true;
                    got = true;
                    break;
                }
        }else{
            for( int i = 0 ; i < n2 ; i ++ )
                if( !got2[ i ] && nh >= bx2[ i ].h ){
                    nh += bx2[ i ].m;
                    cnt ++;
                    got2[ i ] = true;
                    got = true;
                    break;
                }
        }
        if( !got ) break;
        div = 1 - div;
    }
    if( cnt > ans ) ans = cnt;
}
int main(){
    init();
    solve();
    printf( "%d\n" , ans );
}