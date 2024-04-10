#include <map>
#include <set>
#include <queue>
#include <math.h>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
#define N 100010
//#define ll long long
int getint(){
    int x=0,tmp=1; char c=getchar();
    while( (c<'0'||c>'9')&&c!='-' ) c=getchar();
    if( c == '-' ) c=getchar() , tmp = -1;
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x*tmp;
}
int min( int x , int y ){ return x<y?x:y; }
vector<int> r[ N ];
int n , m , sv[ N ] , p[ N ] , cnt[ N ];
pair<int,int> v[ N ];
double ans , bs;
int find_p( int x ){ return x == p[ x ] ? x : p[ x ] = find_p( p[ x ] ); }
void Union( int x , int y ){
    if( cnt[ x ] < cnt[ y ] ){
        p[ x ] = y;
        cnt[ y ] += cnt[ x ];
    }else{
        p[ y ] = x;
        cnt[ x ] += cnt[ y ];
    }
}
void init(){
    n = getint(); m = getint();
    for( int i = 1 ; i <= n ; i ++ ){
        sv[ i ] = v[ i ].first = getint();
        v[ i ].second = i;
        p[ i ] = i; cnt[ i ] = 1;
    }
    std::sort( v + 1 , v + n + 1 );
    while( m -- ){
        int a , b;
        a = getint(); b = getint();
        r[ a ].push_back( b );
        r[ b ].push_back( a );
    }
    bs = (double)n * ( n - 1 ) / 2.0;
}
bool tag[ N ];
void solve(){
    for( int i = n ; i >= 1 ; i -- ){
        int vl = v[ i ].first , tn = v[ i ].second;
//        printf( "%d %d\n" , vl , tn );
        vector<int> tmpv;
        tag[ tn ] = true;
        for( int j = 0 ; j < r[ tn ].size() ; j ++ )
            if( tag[ r[ tn ][ j ] ] ){
                if( find_p( r[ tn ][ j ] ) != find_p( tn ) ){
                    tmpv.push_back( cnt[ find_p( r[ tn ][ j ] ) ] );
                    Union( find_p( r[ tn ][ j ] ) , find_p( tn ) );
                }
            }
        int pre = 0;
        for( int i = 0 ; i < tmpv.size() ; i ++ ){
            ans += (double)tmpv[ i ] * (double)pre * ( double )vl;
            pre += tmpv[ i ];
        }
//        printf( "%d\n" , cnt[ find_p( tn ) ] - 1 );
        ans += (double)( cnt[ find_p( tn ) ] - 1 ) * (double)vl;
    }
    ans /= bs;
    printf( "%.20lf\n" , ans );
}
int main(){
    init();
    solve();
}