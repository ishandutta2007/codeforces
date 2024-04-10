//by tzupengwang
#include<bits/stdc++.h>
using namespace std;

#define FO(it,c) for (__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
typedef long long ll;
typedef pair<int,int> ii;

char s[ 40 ] ;
int type , l ;

void init() {
    scanf( "%s" , s ) ;
    type = 0 ;
    l = strlen( s ) ;
    for ( int i = 1 ; i < l ; i ++ )
        if ( s[ i ] >= '0' && s[ i ] <= '9' && s[ i - 1 ] >= 'A' && s[ i - 1 ] <= 'Z' ) type ++ ;
}

void process() {
    if ( type == 1 ) {
        int pt = 0 , a = 0 , b = 0 ;
        while ( s[ pt ] >= 'A' && s[ pt ] <= 'Z' )
            a = a * 26 + s[ pt ] - 'A' + 1 , pt ++ ;
        while ( s[ pt ] >= '0' && s[ pt ] <= '9' )
            b = b * 10 + s[ pt ] - '0' , pt ++ ;
        printf( "R%dC%d\n" , b , a ) ;
    } else {
        int pt = 1 , a = 0 , b = 0 ;
        while ( s[ pt ] >= '0' && s[ pt ] <= '9' )
            b = b * 10 + s[ pt ] - '0' , pt ++ ;
        pt ++ ;
        while ( s[ pt ] >= '0' && s[ pt ] <= '9' )
            a = a * 10 + s[ pt ] - '0' , pt ++ ;
        stack< char > st ;
        while ( a ) {
            a -- ;
            st.push( 'A' + a % 26 ) ;
            a /= 26 ;
        } while ( !st.empty() ) putchar( st.top() ) , st.pop() ;
        printf( "%d\n" , b ) ;
    }
}

int main() {
    int t ; scanf( "%d" , &t ) ;
    while ( t -- ) {
        init() ;
        process() ;
    }
    return 0 ;
}