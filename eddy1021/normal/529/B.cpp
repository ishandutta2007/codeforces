// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long long ll;
typedef int TYPE;
typedef pair<int,int> PII;
#define mod9 1000000009ll
#define mod7 1000000000007ll 
#define INF 1023456789ll
#define FI first
#define SE second
#define PB push_back
#define MP make_pair
#define eps 1e-7
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
#define N 1010
vector< pair<int,PII> > v;
#define V FI
#define H SE.FI
#define W SE.SE
int n;
void build(){

}
void init(){
    n = getint();
    for( int i = 1 ; i <= n ; i ++ ){
        int tw , th;
        tw = getint(); th = getint();
        v.PB( MP( th - tw , MP( th , tw ) ) );
    }
    sort( v.begin() , v.end() );
}
int ans = N * N * N;
int got[ N ];
int minw( int th ){
    int lie = 0 , sumw = 0;
    for( int i = 0 ; i < n ; i ++ )
        if( v[ i ].H > th && v[ i ].W > th )
            return -1;
        else if( v[ i ].H > th ){
            lie ++;
            sumw += v[ i ].H;
            got[ i ] = th;
        }
    if( lie > n / 2 ) return -1;
    for( int i = 0 ; i < n ; i ++ )
        if( got[ i ] != th ){
            if( v[ i ].W <= th && v[ i ].H < v[ i ].W && lie + 1 <= n / 2 ){
                lie ++;
                sumw += v[ i ].H;
            }else sumw += v[ i ].W;
        }
    return sumw;
}
void solve(){
    for( int i = 1 ; i < N ; i ++ ){
        int tw = minw( i );
        if( tw == -1 ) continue;
        ans = min( ans , i * tw );
    }
    printf( "%d\n" , ans );
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}