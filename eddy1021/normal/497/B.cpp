#include <bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
typedef double D;
typedef pair<int,int> pii;
int getint(){
    int x=0,tmp=1; char c=getchar();
    while( (c<'0'||c>'9')&&c!='-' ) c=getchar();
    if( c == '-' ) c=getchar() , tmp = -1;
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x*tmp;
}
int n , a[ N ] , cnt[ 2 ] , d[ 2 ][ N * 2 ] , sum[ 2 ][ N * 2 ];
vector< pair<int,int> > ans;
void init(){
    n = getint();
    for( int i = 1 ; i <= n ; i ++ ){
        int tmp = getint() - 1;
        a[ i ] = tmp;
        cnt[ tmp ] ++;
        d[ tmp ][ cnt[ tmp ] ] = i;
        sum[ 0 ][ i ] = sum[ 0 ][ i - 1 ] + ( tmp == 0 );
        sum[ 1 ][ i ] = sum[ 1 ][ i - 1 ] + ( tmp == 1 );
    }
}
void check_ans( int tt ){
    int now = 0 , s0 = 0 , s1 = 0;
    do{
        int d0 = d[ 0 ][ sum[ 0 ][ now ] + tt ];
        int d1 = d[ 1 ][ sum[ 1 ][ now ] + tt ];
//        printf( "=%d %d\n" , d0 , d1 );
        if( d0 == 0 && d1 == 0 ) return;
        if( d1 == 0 || ( d0 != 0 && d0 < d1 ) ) now = d[ 0 ][ sum[ 0 ][ now ] + tt ] , s0 ++;
        else now = d[ 1 ][ sum[ 1 ][ now ] + tt ] , s1 ++;
//        printf( "%d : %d\n" , tt , now );
    }while( now != n );
    if( s0 == s1 ) return;
    if( s0 > s1 && a[ n ] == 1 ) return;
    if( s1 > s0 && a[ n ] == 0 ) return; 
    ans.push_back( make_pair( max( s0 , s1 ) , tt ) );
}
void solve(){
    for( int i = 1 ; i <= n ; i ++ )
        check_ans( i );
    sort( ans.begin() , ans.end() );
    printf( "%d\n" , (int)ans.size() );
    for( int i = 0 ; i < (int)ans.size() ; i ++ )
        printf( "%d %d\n" , ans[ i ].first , ans[ i ].second );
}
int main(){
    init();
    solve();
}