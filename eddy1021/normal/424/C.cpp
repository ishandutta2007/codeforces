#include <math.h>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define N 1000010
#define d double
using namespace std;
int getint(){
    int x=0,tmp=1; char c=getchar();
    while( (c<'0'||c>'9')&&c!='-' ) c=getchar();
    if( c == '-' ) c=getchar() , tmp = -1;
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x*tmp;
}
int n , pi , q , mod[ N ];
void init(){
    n = getint();
    for( int i = 1 ; i < N ; i ++ )
        mod[ i ] = mod[ i - 1 ] ^ i;
}
int cnta , cntb;
void solve(){
    for( int i = 1 ; i <= n ; i ++ ){
        pi = getint();
        q ^= pi;
    }
    for( int i = 2 ; i <= n ; i ++ )
        if( ( n % i ) == 0 ){
            if( ( n / i ) % 2 == 1 ){
                q ^= mod[ i - 1 ];
//                q ^= mod[ 1 ][ i - 1 ];
//                q ^= mod1[ i - 1 ];
//                for( int j = 1 ; j < i ; j ++ )
//                    q ^= j;
            }
        }else if( ( ( n / i ) + ( n % i != 0 ) ) % 2 == 1 ){
            q ^= mod[ n % i ];
//            q ^= mod[ 1 ][ n % i ];
//            q ^= mod1[ n % i ];
//            for( int j = 1 ; j <= n % i ; j ++ )
//                q ^= j;
        }else{
            q ^= mod[ i - 1 ];
            q ^= mod[ ( n % i ) ];
//            q ^= mod[ ( n % i ) + 1 ][ i - 1 ];
//            q ^= mod2[  ]
//            for( int j = ( n % i ) + 1 ; j <= i ; j ++ )
//                q ^= ( j % i );
        }
    printf( "%d\n" , q );
}
int main(){
    init();
    solve();
}