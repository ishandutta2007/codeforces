#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long long ll;
#define mod9 1000000009
#define mod7 1000000007
#define N 4010
#define P 40010
#define inf 1000000000
int getint(){
    int x=0,tmp=1; char c=getchar();
    while( (c<'0'||c>'9')&&c!='-' ) c=getchar();
    if( c == '-' ) c=getchar() , tmp = -1;
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x*tmp;
}
bool p[ P + 10 ];
vector<int> pset;
void build(){
    for( int i = 2 ; i < P ; i ++ ) if( !p[ i ] ){
        pset.push_back( i );
        for( int j = P / i ; j >= i ; j -- )
            p[ i * j ] = true;
    }
}
int n , m , a[ N ] , pt , my[ N ] , idx[ 2 ];
vector< pair<int,int> > v[ N ];
vector<int> r[ N ];
void init(){
    n = getint(); m = getint();
    for( int i = 1 ; i <= n ; i ++ )
        a[ i ] = getint();
    pt = (int)pset.size();
}
void presolve(){
    for( int i = 1 ; i <= n ; i ++ ){
        int ta = a[ i ];
        for( int j = 0 ; j < pt && pset[ j ] <= ta ; j ++ )
            if( !( ta % pset[ j ] ) ){
                while( !( ta % pset[ j ] ) ){
                    ++ idx[ i % 2 ];
                    v[ i ].push_back( make_pair( pset[ j ] , idx[ i % 2 ] ) );
                    ta /= pset[ j ];
                }
            }
        if( ta > 1 ){
            ++ idx[ i % 2 ];
            v[ i ].push_back( make_pair( ta , idx[ i % 2 ] ) );
        }
        sort( v[ i ].begin() , v[ i ].end() );
//        for( int k = 0 ; k < (int)v[ i ].size() ; k ++ )
//            printf( "(%d %d) " , v[ i ][ k ].first , v[ i ][ k ].second ); puts( "" );
    }
}
void connect( int ta , int tb ){
    if( tb % 2 ) swap( ta , tb );
    int bsz = (int)v[ tb ].size();
    for( int i = 0 ; i < (int)v[ ta ].size() ; ){
        int tidx = i;
        int idxb = upper_bound( v[ ta ].begin() , v[ ta ].end() , make_pair( v[ ta ][ i ].first , inf ) ) - v[ ta ].begin();
        int idxl = lower_bound( v[ tb ].begin() , v[ tb ].end() , make_pair( v[ ta ][ i ].first , -inf ) ) - v[ tb ].begin();
        int idxr = upper_bound( v[ tb ].begin() , v[ tb ].end() , make_pair( v[ ta ][ i ].first , inf ) ) - v[ tb ].begin();
        if( idxl >= bsz ) break;
        for( int j = tidx ; j < idxb ; j ++ )
            for( int k = idxl ; k < idxr ; k ++ )
                r[ v[ ta ][ j ].second ].push_back( v[ tb ][ k ].second );
        i = idxb;
    }
}
bool tag[ N ];
bool DFS( int now ){
    tag[ now ] = true;
    for( int i = 0 ; i < (int)r[ now ].size() ; i ++ ){
        int tmh = my[ r[ now ][ i ] ];
        if( tmh == 0 || ( !tag[ tmh ] && DFS( tmh ) ) ){
            my[ r[ now ][ i ] ] = now;
            return true;
        }
    }
    return false;
}
void solve(){
    while( m -- ){
        int ta , tb;
        ta = getint(); tb = getint();
        connect( ta , tb );
    }
    int ans = 0;
    for( int i = 1 ; i <= idx[ 1 ] ; i ++ ){
        for( int j = 1 ; j <= idx[ 1 ] ; j ++ ) tag[ j ] = false;
        if( DFS( i ) ) ans ++;
    }
    printf( "%d\n" , ans );
}
int main(){
    build();
    init();
    presolve();
    solve();
}