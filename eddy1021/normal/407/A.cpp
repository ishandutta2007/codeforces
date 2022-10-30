#include <stdio.h>
int a , b;
int gcd( int x , int y ){
    int r;
    while( y ) r = x % y , x = y , y = r;
    return x;
}
bool find_ans(){
    bool got = false;
    int g = gcd( a , b ) , ua , ub;
    for( int i = 1 ; i <= g && !got ; i ++ )
        for( int j = i + 1 ; j <= g && !got ; j ++ )
            if( i * i + j * j == g * g ){
                got = true;
                ua = i; ub = j;
            }
    if( !got ) return false;
    int xa = ua * ( a / g ) , ya = ub * ( a / g );
    int xb = ub * ( b / g ) , yb = ua * ( b / g );
    puts( "YES" );
    puts( "0 0" );
    if( xa != xb ){
        printf( "%d %d\n" , -ya , xa );
        printf( "%d %d\n" , yb , xb );
    }else{
        printf( "%d %d\n" , -xa , ya );
        printf( "%d %d\n" , xb , yb );
    }
    return true;
}
int main(){
    scanf( "%d%d" , &a , &b );
    if( !find_ans() ) puts( "NO" );
}