#include <math.h>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define N 1010
#define d double
using namespace std;
int getint(){
    int x=0,tmp=1; char c=getchar();
    while( (c<'0'||c>'9')&&c!='-' ) c=getchar();
    if( c == '-' ) c=getchar() , tmp = -1;
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x*tmp;
}
int n , s;
pair< d , int > p[ N ];
void init(){
    n = getint(); s = getint();
    for( int i = 0 ; i < n ; i ++ ){
        int tx = getint() , ty = getint() , k = getint();
        p[ i ] = make_pair( sqrt( tx * tx + ty * ty ) , k );
    }
    std::sort( p , p + n );
}
int cnta , cntb;
void solve(){
    for( int i = 0 ; i < n && s < 1000000 ; i ++ ){
        s += p[ i ].second;
        if( s >= 1000000 ){
            printf( "%.20lf\n" , p[ i ].first );
            return;
        }
    }
    puts( "-1" );
}
int main(){
    init();
    solve();
}