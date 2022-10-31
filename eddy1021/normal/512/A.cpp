// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long long ll;
typedef int TYPE;
typedef pair<int,int> PII;
#define mod9 1000000009ll
#define mod7 1000000007ll
#define INF 1023456789
#define FI first
#define SE second
#define PB push_back
#define MP make_pair
#define eps 1e-7
int getint(){
    int _x=0,_tmp=1; char _tc=getchar();
    while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
    if( _tc == '-' ) _tc=getchar() , _tmp = -1;
    while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
    return _x*_tmp;
}
bool equal( D _x ,  D _y ){
    return _x > _y - eps && _x < _y + eps;
}
int __ = 1 , cs;
/*********default*********/
#define N 110
int n , indeg[ N ] , len[ N ];
char c[ N ][ N ];
bool flag;
vector<int> v[ N ];
void build(){
    
}
void init(){
    n = getint();
    for( int i = 0 ; i < n ; i ++ ){
        scanf( "%s" , c[ i ] );
        len[ i ] = strlen( c[ i ] );
    }
}
void build_edge( int s , int t ){
    indeg[ t ] ++;
    v[ s ].PB( t );
}
void compare( int idx ){
    for( int i = 0 ; i < min( len[ idx - 1 ] , len[ idx ] ) ; i ++ )
        if( c[ idx - 1 ][ i ] != c[ idx ][ i ] ){
            build_edge( c[ idx - 1 ][ i ] - 'a' , c[ idx ][ i ] - 'a' );
            return;
        }
    if( len[ idx - 1 ] > len[ idx ] ) flag = true;
}
queue<int> Q;
string ans;
void solve(){
    for( int i = 1 ; i < n ; i ++ )
        compare( i );
    if( flag ){
        puts( "Impossible" );
        return;
    }
    for( int i = 0 ; i < 26 ; i ++ )
        if( indeg[ i ] == 0 )
            Q.push( i );
    while( Q.size() ){
        int tn = Q.front(); Q.pop();
        ans += ( tn + 'a' );
        for( int i = 0 ; i < (int)v[ tn ].size() ; i ++ ){
            indeg[ v[ tn ][ i ] ] --;
            if( indeg[ v[ tn ][ i ] ] == 0 )
                Q.push( v[ tn ][ i ] );
        }
    }
    if( ans.length() != 26 ) puts( "Impossible" );
    else cout << ans << endl;
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}