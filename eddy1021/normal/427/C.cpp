#include <vector>
#include <stdio.h>
using namespace std;
#define N 100010
#define mod 1000000007
int getint(){
    int x=0,tmp=1; char c=getchar();
    while( (c<'0'||c>'9')&&c!='-' ) c=getchar();
    if( c == '-' ) c=getchar() , tmp = -1;
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x*tmp;
}
vector<int> g[ N ] , rg[ N ] , st;
int n , c[ N ] , m , tans , tcnt;
long long ans1 , ans2 = 1;
bool v1[ N ] , v2[ N ];
void build_edge( int tu , int tv ){
    g[ tu ].push_back( tv );
    rg[ tv ].push_back( tu );
}
void init(){
    n = getint();
    for( int i = 1 ; i <= n ; i ++ )
        c[ i ] = getint();
    m = getint(); while( m -- ){
        int u , v;
        u = getint(); v = getint();
        build_edge( u , v );
    }
}
void DFS1( int now ){
    v1[ now ] = true;
    for( int i = g[ now ].size() - 1 ; i >= 0 ; i -- )
        if( !v1[ g[ now ][ i ] ] )
            DFS1( g[ now ][ i ] );
    st.push_back( now );
}
void DFS2( int now ){
    v2[ now ] = true;
    if( tans == -1 || c[ now ] < tans ){
        tans = c[ now ];
        tcnt = 1;
    }else if( c[ now ] == tans )
        tcnt ++;
    for( int i = rg[ now ].size() - 1 ; i >= 0 ; i -- )
        if( !v2[ rg[ now ][ i ] ] )
            DFS2( rg[ now ][ i ] );
}
void solve(){
    for( int i = 1 ; i <= n ; i ++ )
        if( !v1[ i ] )
            DFS1( i );
    for( int i = st.size() - 1 ; i >= 0 ; i -- )
        if( !v2[ st[ i ] ] ){
            tans = -1; tcnt = 0;
            DFS2( st[ i ] );
            ans1 += (long long)tans;
            ans2 *= (long long)tcnt;
            ans2 %= mod;
        }
    printf( "%I64d %I64d\n" , ans1 , ans2 );
}
int main(){
    init();
    solve();
}