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
#define N 9
int n , l[ N ] , r[ N ] , tl , tr;
double ans;
void build(){

}
void init(){
    n = getint(); tl = INF; tr = 0;
    for( int i = 1 ; i <= n ; i ++ ){
        l[ i ] = getint();
        r[ i ] = getint();
        tl = min( l[ i ] , tl );
        tr = max( r[ i ] , tr );
    }
}
D po( int idx , int ti , int tj ){
    D tp = 1.0;
    for( int i = 1 ; i <= n ; i ++ )
        if( i == ti ){
            if( r[ i ] <= idx ) tp = 0;
            if( l[ i ] > idx ) continue;
            tp *= (D)( r[ i ] - idx ) / (D)( r[ i ] - l[ i ] + 1 );
        }else if( i == tj ){
            if( r[ i ] < idx || l[ i ] > idx ) tp = 0;
        }else{
            if( l[ i ] >= idx ) tp = 0;
            if( r[ i ] < idx ) continue;
            tp *= (D)( idx - l[ i ] ) / (D)( r[ i ] - l[ i ] + 1 );
        }
    return tp;
}
int cnt( int idx ){
    int tcnt = 0;
    while( idx ){
        if( idx % 2 ) tcnt ++;
        idx >>= 1;
    }
    return tcnt;
}
D cal1( int num , int idx ){
    int ti = 1;
    D tp = 0;
    for( int i = 1 ; i <= n ; i ++ )
        if( idx & ( 1 << ( i - 1 ) ) ){
            ti = i;
            break;
        }
    for( int j = 1 ; j <= n ; j ++ )
        if( ti != j ) 
            tp += po( num , j , ti );
    return tp;
}
D cal2( int num , int idx ){
    D tp = 1.0;
    for( int i = 1 ; i <= n ; i ++ )
        if( idx & ( 1 << ( i - 1 ) ) ){
            if( l[ i ] > num || r[ i ] < num ) tp = 0.0;
            else tp *= 1.0 / (D)( r[ i ] - l[ i ] + 1 );
        }else{
            if( l[ i ] >= num ) tp = 0.0;
            else if( r[ i ] < num ) continue;
            else tp *= (D)( num - l[ i ] ) / (D)( r[ i ] - l[ i ] + 1 );
        }
    return tp;
}
D cal4( int num , int idx , int ti ){
    D tp = 1.0;
//    printf( "***    %d\n" , ti );
    for( int i = 1 ; i <= n ; i ++ ){
        if( idx & ( 1 << ( i - 1 ) ) ){
            if( l[ i ] > num || r[ i ] < num ) tp = 0.0;
            else tp *= 1.0 / (D)( r[ i ] - l[ i ] + 1 );            
        }else if( i == ti ){
            if( r[ i ] <= num ) tp = 0.0;
            else if( l[ i ] > num ) continue;
            else tp *= (D)( r[ i ] - num ) / (D)( r[ i ] - l[ i ] + 1 );
        }else{
//            puts( "JIZZ" );
            if( l[ i ] >= num ) tp = 0.0;
            else if( r[ i ] < num ) continue;
            else tp *= (D)( num - l[ i ] ) / (D)( r[ i ] - l[ i ] + 1 );
//            puts( "JIZZ" );
        }
//if( num == 10 )        printf( "    %d %.5f\n" , i , tp );
    }
    return tp;
}
D cal3( int num , int idx ){
    D tp = 0.0;
    for( int i = 1 ; i <= n ; i ++ )
        if( ( idx & ( 1 << ( i - 1 ) ) ) == 0 )
            tp += cal4( num , idx , i );
    return tp;
}
double p( int idx ){
    D tp = 0.0;
//    printf( "%d\n" , idx );
    for( int i = 1 ; i < ( 1 << n ) ; i ++ ){
//if( idx == 10 )        printf( "==== %d\n" , cnt( i ) );
        if( cnt( i ) != 1 )
            tp += cal2( idx , i );
//if( idx == 10 )        printf( "  %d %.10f\n" , i , tp );
        tp += cal3( idx , i );
//if( idx == 10 )        printf( "     %.10f\n" , tp );
    }
//    printf( "%d %.10f\n" , idx , tp );
    return tp;
}
void solve(){
    for( int i = tl ; i <= tr ; i ++ )
        ans += (D)i * p( i );
    printf( "%.15f\n" , ans );
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}