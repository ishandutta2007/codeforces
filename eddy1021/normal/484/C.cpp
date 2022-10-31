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
class Permu{
public:
    int sz;
    deque<int> v;
    Permu(){}
    Permu( int _sz ){
        sz = _sz; v.clear();
        for( int i = 1 ; i <= sz ; i ++ )
            v.PB( i );
    }
    void Sorting( int n , int k ){
        vector<int> tv;
        for( int i = 0 ; i < k && i < n ; i ++ )
            for( int j = i ; j < n ; j += k )
                tv.PB( v[ j ] );
        for( int i = 0 ; i < n ; i ++ )
            v[ i ] = tv[ i ];
    }
    void Shift(){
        v.PB( v[ 0 ] );
        v.pop_front();
    }
    void Mul( Permu & p ){
        deque<int> td( sz );
        for( int i = 0 ; i < sz ; i ++ )
            td[ i ] = v[ p.v[ i ] - 1 ];
        for( int i = 0 ; i < sz ; i ++ )
            v[ i ] = td[ i ];
    }
    void Dsorting( int n , int k ){
        int times = sz - n + 1;
        Permu i( sz ) , a( sz );
        a.Sorting( n , k );
        a.Shift();
        while( times ){
            if( times & 1 ) i.Mul( a );
            a.Mul( a ); times >>= 1;
        }
        Mul( i );
        for( int j = 0 ; j < sz - n + 1 ; j ++ ){
            v.push_front( v.back() );
            v.pop_back();
        }
    }
};
void build(){
    
}
#define N 1000010
char c[ N ];
int q , n;
void init(){
    scanf( "%s%d" , c , &q );
    n = (int)strlen( c );
}
void solve(){
    Permu p( n );
    while( q -- ){
        int tn , tk;
        tn = getint(); tk = getint();
        p.Dsorting( tn , tk );
        for( int i = 0 ; i < n ; i ++ )
            putchar( c[ p.v[ i ] - 1 ] );
        puts( "" );
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