#include <bits/stdc++.h>
using namespace std;
#define N 1010
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
int n , m , cnt;
char c[ N ][ N ];
vector< pii > v[ 2 ];
void init(){
    scanf( "%d%d" , &n , &m );
    for( int i = 1 ; i <= n ; i ++ )
        scanf( "%s" , c[ i ] + 1 );
    v[ 1 ].push_back( make_pair( 1 , n ) );
}
void DFS( int idx ){
    if( idx > m ) return;
    int now = idx & 1 , nxt = 1 - now;
    bool flag = true;
    v[ nxt ].clear();
    for( int i = 0 ; i < (int)v[ now ].size() ; i ++ ){
        for( int j = v[ now ][ i ].first ; j < v[ now ][ i ].second ; j ++ )
            if( c[ j ][ idx ] > c[ j + 1 ][ idx ] ){
                flag = false; break;
            }
        if( !flag ) break;
    }
    if( !flag ){
        cnt ++;
        for( int i = 0 ; i < (int)v[ now ].size() ; i ++ )
            v[ nxt ].push_back( v[ now ][ i ] );
        DFS( idx + 1 );
    }else{
        for( int i = 0 ; i < (int)v[ now ].size() ; i ++ ){
            int st = v[ now ][ i ].first;
            for( int j = v[ now ][ i ].first + 1 ; j <= v[ now ][ i ].second ; j ++ )
                if( c[ j ][ idx ] != c[ st ][ idx ] ){
                    v[ nxt ].push_back( make_pair( st , j - 1 ) );
                    st = j;
                }
            v[ nxt ].push_back( make_pair( st , v[ now ][ i ].second ) );
        }
        DFS( idx + 1 );
    }
}
void solve(){
    DFS( 1 );
    printf( "%d\n" , cnt );
}
int main(){
    init();
    solve();
}