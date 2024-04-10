#include <bits/stdc++.h>
using namespace std;
#define N 110
int getint(){
    int x=0; char c=getchar();
    while( c<'0'||c>'9' ) c=getchar();
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x;
}
int n , k , a[ N ];
void init(){
    n = getint(); k = getint();
    for( int i = 1 ; i <= n ; i ++ )
        a[ i ] = getint();
}
vector< pair<int,int> > ans;
void solve(){
    while( k -- ){
        int tmin = a[ 1 ] , tidx = 1 , tmax = a[ 1 ] , tidx2 = 1;
        for( int i = 2 ; i <= n ; i ++ ){
            if( a[ i ] < tmin ) tmin = a[ i ] , tidx = i;
            if( a[ i ] > tmax ) tmax = a[ i ] , tidx2 = i;
        }
        if( tmin >= tmax - 1 ) break;
        ans.push_back( make_pair( tidx , tidx2 ) );
        a[ tidx ] ++;
        a[ tidx2 ] --;
    }
    int ttmin = a[ 1 ] , ttmax = a[ 1 ];
    for( int i = 2 ; i <= n ; i ++ ){
        if( a[ i ] < ttmin ) ttmin = a[ i ];
        if( a[ i ] > ttmax ) ttmax = a[ i ];
    }
    printf( "%d %d\n" , ttmax - ttmin , (int)ans.size() );
    for( int i = 0 ; i < (int)ans.size() ; i ++ )
        printf( "%d %d\n" , ans[ i ].second , ans[ i ].first );
}
int main(){
    init();
    solve();
}