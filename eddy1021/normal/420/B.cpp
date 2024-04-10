#include <vector>
#include <stdio.h>
using namespace std;
#define N 100010
int getint(){
    int x=0; char c=getchar();
    while( c<'0'||c>'9' ) c=getchar();
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x;
}
char c[ N ][ 2 ];
int n , m , k[ N ] , fk[ N ];
void init(){
    n = getint(); m = getint();
    for( int i = 0 ; i < m ; i ++ ){
        scanf( "%s" , c[ i ] );
        k[ i ] = getint();
    }
}
bool in[ N ] , got[ N ] , can[ N ];
int mn;
void prepare(){
    for( int i = 1 ; i <= n ; i ++ )
        can[ i ] = true;
    for( int i = 0 ; i < m ; i ++ ){
        if( c[ i ][ 0 ] == '+' ) fk[ i ] ++;
        if( !got[ k[ i ] ] ){
            if( c[ i ][ 0 ] == '-' )
                mn ++ , in[ k[ i ] ] == true;
        }
        got[ k[ i ] ] = true;
    }
    for( int i = m - 2 ; i >= 0 ; i -- )
        fk[ i ] += fk[ i + 1 ];
}
void solve(){
    bool pre = false;
    for( int i = 0 ; i < m ; i ++ )
        if( c[ i ][ 0 ] == '+' ){
            mn ++; in[ k[ i ] ] = true;
            if( mn > 1 ) can[ k[ i ] ] = false;
            if( pre && !( i > 0 && k[ i ] == k[ i - 1 ] && c[ i - 1 ][ 0 ] == '-' ) )
                can[ k[ i ] ] = false;
            pre = true;
        }else{
            mn --; in[ k[ i ] ] = false;
            if( mn > 0 ) can[ k[ i ] ] = false;
            else if( fk[ i ] && !( i < m - 1 && k[ i ] == k[ i + 1 ] &&
                        c[ i + 1 ][ 0 ] == '+' ) ) can[ k[ i ] ] = false;
            pre = true;
        }
}
void print(){
    vector<int> ans;
    for( int i = 1 ; i <= n ; i ++ )
        if( can[ i ] )
            ans.push_back( i );
    printf( "%d\n" , ans.size() );
    for( int i = 0 ; i < ans.size() ; i ++ )
        printf( "%d%c" , ans[ i ] , i == ans.size() - 1 ? '\n' : ' ' );
}
int main(){
    init();
    prepare();
    solve();
    print();
}