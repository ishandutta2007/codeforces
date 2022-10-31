// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long long ll;
typedef pair<int,int> PII;
#define mod9 1000000009ll
#define mod7 1000000007ll 
#define INF  1023456789ll
#define INF16 10000000000000000ll
#define FI first
#define SE second
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define eps 1e-13
ll getint(){
    ll _x=0,_tmp=1; char _tc=getchar();    
    while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
    if( _tc == '-' ) _tc=getchar() , _tmp = -1;
    while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
    return _x*_tmp;
}
ll mypow( ll _a , ll _x , ll _mod ){
    if( _x == 0 ) return 1ll;
    ll _tmp = mypow( _a , _x / 2 , _mod );
    _tmp = ( _tmp * _tmp ) % _mod;
    if( _x & 1 ) _tmp = ( _tmp * _a ) % _mod;
    return _tmp;
}
bool equal( D _x ,  D _y ){
    return _x > _y - eps && _x < _y + eps;
}
int __ = 1 , cs;
/*********default*********/
#define N 110
int n , mid;
vector< PII > v;
void build(){

}
void init(){
    n = getint();
    for( int i = 0 ; i < n ; i ++ ){
        int x , a;
        x = getint(); a = getint();
        v.PB( MP( x , a ) );
    }
    sort( v.begin() , v.end() );
}
int cal(){
    mid = -1;
    for( int i = 0 ; i < n ; i ++ )
        if( v[ i ].FI > 0 ){
            mid = i;
            break;
        }
    if( mid == -1 ) return v[ n - 1 ].SE;
    if( mid == 0 ) return v[ 0 ].SE;
    int l = mid , r = n - mid;
    int tmp = min( l , r );
    int sum = 0 , extra = 0;
    for( int i = 0 , j = mid - 1 , k = mid ; i <= tmp ; i ++ , j -- , k ++ ){
        if( i == tmp ){
            if( j >= 0 ) extra = max( extra , v[ j ].SE );
            if( k < n ) extra = max( extra , v[ k ].SE );
        }else{
            if( j >= 0 ) sum += v[ j ].SE;
            if( k < n ) sum += v[ k ].SE;
        }
    }
    return sum + extra;
}
void solve(){
    printf( "%d\n" , cal() );
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}