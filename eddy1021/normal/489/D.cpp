#include <bits/stdc++.h>
using namespace std;
#define N 3010
#define M 30
typedef long long ll;
int getint(){
    int x=0,tmp=1; char c=getchar();
    while( (c<'0'||c>'9')&&c!='-' ) c=getchar();
    if( c == '-' ) c=getchar() , tmp = -1;
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x*tmp;
}
int n , m , cnt[ N ];
vector<int> v[ N ];
ll ans;
void init(){
    n = getint(); m = getint();
    while( m -- ){
        int ta , tb;
        ta = getint(); tb = getint();
        v[ ta ].push_back( tb );
    }
}
void DFS( int lvl , int now ){
    if( lvl == 2 ){
        cnt[ now ] ++;
        return;
    }
    for( int i = 0 ; i < (int)v[ now ].size() ; i ++ )
        DFS( lvl + 1 , v[ now ][ i ] );
}
void solve(){
    for( int i = 1 ; i <= n ; i ++ ){
        for( int j = 1 ; j <= n ; j ++ )
            cnt[ j ] = 0;
        DFS( 0 , i );
        for( int j = 1 ; j <= n ; j ++ )
            if( i != j )
                ans += ( (ll)cnt[ j ] ) * ( (ll)cnt[ j ] - 1 ) / 2ll;
    }
    printf( "%I64d\n" , ans );
}
int main(){
    init();
    solve();
}