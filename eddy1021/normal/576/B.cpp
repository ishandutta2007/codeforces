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
#define eps 1e-9
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
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
#define N 100010
int n , p[ N ];
bool got[ N ];
vector<PII> v;
void build(){

}
void init(){
    n = getint();
    for( int i = 1 ; i <= n ; i ++ )
        p[ i ] = getint();
}
void solve(){
    for( int i = 1 ; i <= n ; i ++ )
        if( i == p[ i ] ){
            puts( "YES" );
            for( int j = 1 ; j <= n ; j ++ )
                if( i != j )
                    printf( "%d %d\n" , i , j );
            return;
        }
    for( int i = 1 ; i <= n ; i ++ )
        if( !got[ i ] ){
            int cnt = 0 , now = i;
            while( !got[ now ] ){
                got[ now ] = true;
                cnt ++;
                now = p[ now ];
            }
            v.PB( MP( cnt , i ) );
        }
    sort( ALL( v ) );
    if( v[ 0 ].FI > 2 ){
        puts( "NO" );
        return;
    }
    for( int i = 1 ; i < (int)v.size() ; i ++ )
        if( v[ i ].FI % 2 == 1 ){
            puts( "NO" );
            return;
        }
    vector<PII> vans;
    int t1 = v[ 0 ].SE , t2 = p[ v[ 0 ].SE ];
    vans.PB( MP( t1 , t2 ) );
    for( int i = 1 ; i < (int)v.size() ; i ++ ){
        int now = v[ i ].SE;
        do{
            vans.PB( MP( t1 , now ) ); now = p[ now ];
            vans.PB( MP( t2 , now ) ); now = p[ now ];
        }while( now != v[ i ].SE );
    }
    puts( "YES" );
    for( int i = 0 ; i < (int)vans.size() ; i ++ )
        printf( "%d %d\n" , vans[ i ].FI , vans[ i ].SE );
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}