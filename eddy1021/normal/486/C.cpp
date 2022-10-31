#include <bits/stdc++.h>
using namespace std;
#define N 100010
char c[ N ];
int n , p , ans;
void modify(){
    for( int i = 1 ; i <= n / 2 ; i ++ )
        swap( c[ i ] , c[ n - i + 1 ] );
    p = n - p + 1;
}
void init(){
    scanf( "%d%d" , &n , &p );
    scanf( "%s" , c + 1 );
    if( p > n / 2 ) modify();
}
int dif( char s , char t ){
    s -= 'a'; t -= 'a';
    if( s < t ) return min( t - s , s + 26 - t );
    return min( s - t , t + 26 - s );
}
int find_left(){
    for( int i = 1 ; i <= p ; i ++ )
        if( c[ i ] != c[ n - i + 1 ] )
            return i;
    return -1;
}
int find_right(){
    for( int i = n / 2 ; i >= p ; i -- )
        if( c[ i ] != c[ n - i + 1 ] )
            return i;
    return -1;
}
void cal( int tl , int tr ){
    for( int i = tl ; i <= tr ; i ++ )
        if( c[ i ] != c[ n - i + 1 ] )
            ans += dif( c[ i ] , c[ n - i + 1 ] );
}
void solve(){
    int l , r;
    l = find_left();
    r = find_right();
    if( l == -1 && r == -1 ){
        puts( "0" );
        return;
    }else if( l == -1 ) cal( p , r ) , ans += abs( p - r );
    else if( r == -1 ) cal( l , p ) , ans += abs( p - l );
    else{
        cal( l , r );
        ans += r - l;
        ans += min( abs( p - l ) , abs( p - r ) );
    }
    printf( "%d\n" , ans );
}
int main(){
    init();
    solve();
}