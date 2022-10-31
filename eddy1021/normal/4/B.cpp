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
int getint(){
    int x=0,tmp=1; char tc=getchar();
    while( (tc<'0'||tc>'9')&&tc!='-' ) tc=getchar();
    if( tc == '-' ) tc=getchar() , tmp = -1;
    while(tc>='0'&&tc<='9') x*=10,x+=(tc-'0'),tc=getchar();
    return x*tmp;
}
int __ = 1;
/*********default*********/
#define N 40
int d , s , x[ N ] , y[ N ] , sx , sy;
void build(){

}
void init(){
    d = getint(); s = getint();
    for( int i = 0 ; i < d ; i ++ ){
        x[ i ] = getint();
        y[ i ] = getint();
        sx += x[ i ];
        sy += y[ i ];
    }
}
void solve(){
    if( sx > s || sy < s ) puts( "NO" );
    else{
        int dlt = s - sx;
        for( int i = 0 ; i < d && dlt > 0 ; i ++ ){
            int tdlt = min( dlt , y[ i ] - x[ i ] );
            x[ i ] += tdlt; dlt -= tdlt;
        }
        puts( "YES" );
        for( int i = 0 ; i < d ; i++ )
            printf( "%d%c" , x[ i ] , i == d - 1 ? '\n' : ' ' );
    }
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}