#include <bits/stdc++.h>
using namespace std;
#define N 100010
#define D double
#define ll long long
int getint(){
    int x=0,tmp=1; char c=getchar();
    while( (c<'0'||c>'9')&&c!='-' ) c=getchar();
    if( c == '-' ) c=getchar() , tmp = -1;
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x*tmp;
}
int n , l , x , y , a[ N ];
set<int> S;
void init(){
    n = getint(); l = getint();
    x = getint(); y = getint();
    for( int i = 0 ; i < n ; i ++ ){
        a[ i ] = getint();
        S.insert( a[ i ] );
    }
}
set<int> S2 , S3;
void find_ans(){
    for( int i = 0 ; i < n ; i ++ ){
        int ndx = a[ i ] - x;
        if( ndx >= 0 ) S2.insert( ndx );
    }
    for( int i = n - 1 ; i >= 0 ; i -- ){
        int ndx = a[ i ] + x;
        if( ndx <= l ) S3.insert( ndx );
    }
    for( int i = 0 ; i < n ; i ++ ){
        int ndy = a[ i ] - y;
        if( S2.count( ndy ) > 0 || S3.count( ndy ) > 0 ){
            printf( "1\n%d\n" , ndy );
            return;
        }
    }
    for( int i = n - 1 ; i >= 0 ; i -- ){
        int ndy = a[ i ] + y;
        if( S3.count( ndy ) > 0 || S2.count( ndy ) > 0 ){
            printf( "1\n%d\n" , ndy );
            return;
        }
    }
    printf( "2\n" );
    printf( "%d %d\n" , x , y );
}
void solve(){
    bool canx = false , cany = false;
    for( int i = 0 ; i < n ; i ++ ){
        int ndx = a[ i ] - x;
        int ndy = a[ i ] - y;
        if( S.count( ndx ) ) canx = true;
        if( S.count( ndy ) ) cany = true;
    }
    if( canx && cany ) puts( "0" );
    else if( canx ) printf( "1\n%d\n" , y );
    else if( cany ) printf( "1\n%d\n" , x );
    else find_ans();
}
int main(){
    init();
    solve();
}