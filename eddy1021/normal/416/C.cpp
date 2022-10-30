#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;
#define N 1010
int getint(){
    int x=0; char c=getchar();
    while( c<'0'||c>'9' ) c=getchar();
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x;
}
struct XD{
    int ci , pi , no;
}a[ N ];
bool cmp( XD x , XD y ){
    if( x.pi != y.pi ) return x.pi > y.pi;
    return x.ci < y.ci;
}
struct XP{
    int ci , no;
}t[ N ];
bool cmp2( XP x , XP y ){
    return x.ci < y.ci;
}
bool opy[ N ];
int n , m , sum;
void init(){
    n = getint();
    for( int i = 0 ; i < n ; i ++ ){
        a[ i ].ci = getint();
        a[ i ].pi = getint();
        a[ i ].no = i;
    }
    std::sort( a , a + n , cmp );
    m = getint();
    for( int i = 0 ; i < m ; i ++ ){
        t[ i ].ci = getint();
        t[ i ].no = i;
    }
    std::sort( t , t + m , cmp2 );
}
void process(){
    vector< pair<int,int> > v;
    for( int i = 0 ; i < n ; i ++ )
        for( int j = 0 ; j < m ; j ++ )
            if( t[ j ].ci >= a[ i ].ci && !opy[ j ] ){
                v.push_back( make_pair( a[ i ].no + 1 , t[ j ].no + 1 ) );
                opy[ j ] = true; sum += a[ i ].pi;
                break;
            }
    printf( "%d %d\n" , v.size() , sum );
    for( int i = 0 ; i < v.size() ; i ++ )
        printf( "%d %d\n" , v[ i ].first , v[ i ].second );
}
int main(){
    init();
    process();
}