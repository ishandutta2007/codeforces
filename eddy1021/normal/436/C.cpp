#include <queue>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;
#define L 12
#define N 1010
char c[ N ][ L ][ L ];
int st , n , m , k , w , p[ N ] , bxtp;
int find_p( int x ){
    return x == p[ x ] ? x : p[ x ] = find_p( p[ x ] );
}
void Union( int x , int y ){
    p[ x ] = y;
}
struct XD{
    int x , y , c;
}bx[ N * N ];
vector<int> v[ N ];
bool cmp( XD x , XD y ){
    return x.c < y.c;
}
int cost( int ti , int tj ){
    int cnt = 0;
    for( int i = 1 ; i <= n ; i ++ )
        for( int j = 1 ; j <= m ; j ++ )
            if( c[ ti ][ i ][ j ] != c[ tj ][ i ][ j ] )
                cnt ++;
    return cnt * w;
}
void init(){
    scanf( "%d%d%d%d" , &n , &m , &k , &w );
    st = k + 1;
    for( int i = 1 ; i <= k + 1 ; i ++ )
        p[ i ] = i;
    for( int i = 1 ; i <= k ; i ++ )
        for( int j = 1 ; j <= n ; j ++ )
            scanf( "%s" , c[ i ][ j ] + 1 );
    for( int i = 1 ; i <= k ; i ++ ){
        bx[ bxtp ].x = i;
        bx[ bxtp ].y = k + 1;
        bx[ bxtp ++ ].c = n * m;
    }
    for( int i = 1 ; i <= k ; i ++ )
        for( int j = 1 ; j < i ; j ++ ){
            bx[ bxtp ].x = i;
            bx[ bxtp ].y = j;
            bx[ bxtp ++ ].c = cost( i , j );
        }
    sort( bx , bx + bxtp , cmp );
}
void solve(){
    int ans = 0;
    for( int i = 0 ; i < bxtp && st > 1 ; i ++ )
        if( find_p( bx[ i ].x ) != find_p( bx[ i ].y ) ){
            ans += bx[ i ].c; st --;
            Union( find_p( bx[ i ].x ) , find_p( bx[ i ].y ) );
            v[ bx[ i ].x ].push_back( bx[ i ].y );
            v[ bx[ i ].y ].push_back( bx[ i ].x );
        }
    printf( "%d\n" , ans );
}
bool vst[ N ];
void print_sol(){
    queue<int> Q; vst[ k + 1 ] = true;
    for( int i = v[ k + 1 ].size() - 1 ; i >= 0 ; i -- ){
        printf( "%d 0\n" , v[ k + 1 ][ i ] );
        vst[ v[ k + 1 ][ i ] ] = true;
        Q.push( v[ k + 1 ][ i ] );
    }
    while( Q.size() ){
        int tn = Q.front(); Q.pop();
        for( int i = v[ tn ].size() - 1 ; i >= 0 ; i -- )
            if( !vst[ v[ tn ][ i ] ] ){
                printf( "%d %d\n" , v[ tn ][ i ] , tn );
                vst[ v[ tn ][ i ] ] = true;
                Q.push( v[ tn ][ i ] );
            }
    }
}
int main(){
    init();
    solve();
    print_sol();
}