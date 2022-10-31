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
#define d double
int getint(){
    int x=0,tmp=1; char c=getchar();
    while( (c<'0'||c>'9')&&c!='-' ) c=getchar();
    if( c == '-' ) c=getchar() , tmp = -1;
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x*tmp;
}
int n;
d a[ N ];
void init(){
    n = getint();
    for( int i = 0 ; i < n ; i ++ )
        scanf( "%lf" , &a[ i ] );
    std::sort( a , a + n );
}
void solve(){
    double ans = a[ n - 1 ];
//    if( ans < 0.5 ){
//        ans = 0;
        for( int i = n - 1 ; i >= 0 ; i -- ){
            d tans = a[ i ];
            for( int j = i - 1 ; j >= 0 ; j -- ){
                d ttans = 0;
                for( int k = j ; k <= i ; k ++ ){
                    d tttans = a[ k ];
                    for( int l = j ; l <= i ; l ++ )
                        if( l != k )
                            tttans *= ( 1 - a[ l ] );
                    ttans += tttans;
                }
                if( ttans > tans ) tans = ttans;
//                else break;
            }
            if( tans > ans ) ans = tans;
        }
//    }
    printf( "%.20lf\n" , ans );
}

int main(){
    init();
    solve();
}