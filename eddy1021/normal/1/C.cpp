//by tzupengwang
#include<bits/stdc++.h>
using namespace std;
#define eps ( 1e-6 )

double s[ 3 ][ 2 ] ;
const double PI = acos( 0 ) * 2.0 ;

void init() {
    for ( int i = 0 ; i < 3 ; i ++ )
        for ( int j = 0 ; j < 2 ; j ++ )
            scanf( "%lf" , &s[ i ][ j ] ) ;
}

void process() {
    double length[ 3 ] , angle[ 3 ] ;
    for ( int i = 0 ; i < 3 ; i ++ ) {
        length[ i ] = hypot( s[ i ][ 0 ] - s[ (i+1)%3 ][ 0 ] , s[ i ][ 1 ] - s[ (i+1)%3 ][ 1 ] ) ;
    }
    for ( int i = 0 ; i < 3 ; i ++ ) {
        int a = i , b = ( i + 1 ) % 3 , c = ( i + 2 ) % 3 ;
        angle[ i ] = ( length[ a ] * length[ a ] + length[ b ] * length[ b ] - length[ c ] * length[ c ] ) / ( 2 * length[ a ] * length[ b ] ) ;
        angle[ i ] = 2.0 * acos( angle[ i ] ) ;
    }
    int ans = 0 ;
    for ( int i = 3 ; i <= 100 ; i ++ ) {
        double sa = 2.0 * PI / (double)i ;
        int cnt = 0 ;
        for ( int j = 0 ; j < 3 ; j ++ ) {
            double tmp = angle[ j ] ;
            while ( tmp > eps ) tmp -= sa , cnt ++ ;
        }
        if ( cnt == i ) {
            ans = i ; break ;
        }
    }
    double hl = ( length[ 0 ] + length[ 1 ] + length[ 2 ] ) / 2.0 ;
    double area = sqrt( hl * ( hl - length[ 0 ] ) * ( hl - length[ 1 ] ) * ( hl - length[ 2 ] ) ) ;
    double radius = length[ 0 ] * length[ 1 ] * length[ 2 ] / ( 4.0 * area ) ;
    double sa = 2.0 * PI / (double)ans ;
    printf( "%.10f\n" , radius * radius * sin( sa ) * ans / 2.0 ) ;
}

int main() {
    init() ;
    process() ;
    return 0 ;
}