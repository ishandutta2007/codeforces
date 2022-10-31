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
template< class T>
T getint( T& _____ ){
    T _=0,___=1; char tc=getchar();
    while( (tc<'0'||tc>'9')&&tc!='-' ) tc=getchar();
    if( tc == '-' ) tc=getchar() , ___ = -1;
    while(tc>='0'&&tc<='9') _*=10,_+=(tc-'0'),tc=getchar();
    return _*___;
}
int __ = 1;
/*********default*********/
#define eps 1e-6
#define MAGIC 0.618
D x[ 3 ] , y[ 3 ] , r[ 3 ] , mx , my , ax , ay;
D dx[]={0,0,1,-1};
D dy[]={1,-1,0,0};
D sqr( D u ){ return u * u; }
D dist( D x1 , D y1 , D x2 , D y2 ){
    return sqrt( sqr( x1 - x2 ) + sqr( y1 - y2 ) );
}
void init(){
    for( int i = 0 ; i < 3 ; i ++ ){
        scanf( "%lf%lf%lf" , &x[ i ] , &y[ i ] , &r[ i ] );
        mx += x[ i ]; my += y[ i ];
    }
    mx /= 3.0; my /= 3.0;
}
D cal( D tx , D ty ){
    D sum = 0 , p[ 3 ];
    for( int i = 0 ; i < 3 ; i ++ )
        p[ i ] = dist( x[ i ] , y[ i ] , tx , ty ) / r[ i ];
    for( int i = 0 ; i < 3 ; i ++ )
        sum += sqr( p[ i ] - p[ ( i + 1 ) % 3 ] ); 
    return sum;
}
void solve(){
    ax = mx; ay = my; D dir = 1.0;
    while( dir > eps ){
        bool flag = true;
        for( int i = 0 ; i < 4 ; i ++ )
            if( cal( ax + dx[ i ] * dir , ay + dy[ i ] * dir ) < cal( ax , ay ) ){
//                printf( "%.10f -> %.10f\n" , cal( ax , ay ) , cal( ax + dx[ i ] * dir , ay + dy[ i ] * dir ) );
                ax += dx[ i ] * dir , ay += dy[ i ] * dir , flag = false;
            }
        if( flag ) dir *= MAGIC;
//        printf( "%.20f %.20f " , ax , ay );
//        printf( "%.20f\n" , dir );
    }
    if( cal( ax , ay ) < eps ) printf( "%.5f %.5f\n" , ax , ay );
}
int main(){
//    __ = getint( __ );
    while( __ -- ){
        init();
        solve();
    }
}