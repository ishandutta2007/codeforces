// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long long ll;
typedef int TYPE;
typedef pair<int,int> PII;
#define mod9 1000000009
#define mod7 1000000007
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
#define N 610
int n , l[ N ] , r[ N ];
bool vst[ N ][ N ];
bool can[ N ][ N ];
int nxt[ N ][ N ];
char c[ N * 2 ];
void build(){
    
}
void init(){
    n = getint();
    for( int i = 1 ; i <= n ; i ++ ){
        l[ i ] = getint();
        r[ i ] = getint();
        if( l[ i ] % 2 == 0 ) l[ i ] ++;
    }
}
bool DP( int nl , int nr ){
    if( nl > nr ) return true;
    if( vst[ nl ][ nr ] ) return can[ nl ][ nr ];
    vst[ nl ][ nr ] = true;
    for( int i = l[ nl ] ; i <= r[ nl ] ; i += 2 ){
        bool canl = false , canr = false;
        int lft = i / 2;
        if( lft == 0 ) canl = true;
        else if( lft > nr - nl ) break;
        else canl = DP( nl + 1 , nl + lft );
        if( lft == nr - nl ) canr = true;
        else canr = DP( nl + lft + 1 , nr );
        if( canl && canr ){
            nxt[ nl ][ nr ] = i;
            return can[ nl ][ nr ] = true;
        }
    }
    return can[ nl ][ nr ] = false;
}
int ptr;
void build_ans( int nl , int nr ){
    if( nl > nr ) return;
    while( c[ ptr ] == '(' || c[ ptr ] == ')' ) ptr ++;
    c[ ptr ] = '('; c[ ptr + nxt[ nl ][ nr ] ] = ')';
    int lft = nxt[ nl ][ nr ] / 2;
    if( lft > 0 && lft <= nr - nl ) build_ans( nl + 1 , nl + lft );
    if( lft < nr - nl ) build_ans( nl + lft + 1 , nr );
}
void solve(){
    if( !DP( 1 , n ) ) puts( "IMPOSSIBLE" );
    else{
        build_ans( 1 , n );
        c[ n * 2 ] = '\0';
        puts( c );
    }
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}