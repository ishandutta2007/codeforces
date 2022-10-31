#include <set>
#include <map>
#include <queue>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define N 25
int getint(){
    int x=0,tmp=1; char c=getchar();
    while( (c<'0'||c>'9')&&c!='-' ) c=getchar();
    if( c == '-' ) c=getchar() , tmp = -1;
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x*tmp;
}
int n , a[ N ];
void init(){
    n = getint();
    for( int i = 1 ; i <= n ; i ++ )
        a[ i ] = getint();
    std::sort( a + 1 , a + n + 1 );
}
bool tk[ N ];
bool solve(){
    if( a[ n ] != n ) return false;
    for( int i = n ; i >= 1 ; i -- )
        if( a[ i ] > 1 ){
            int nd = a[ i ] - 1 , got = 0;
            for( int j = i - 1 ; j >= 1 && nd > 0 ; j -- )
                if( !tk[ j ] && a[ j ] <= nd ){
                    nd -= a[ j ];
                    tk[ j ] = true;
                    got ++;
                }
            if( got <= 1 ) return false;
        }
    return true;
}
int main(){
    init();
    puts( solve() ? "YES" : "NO" );
}