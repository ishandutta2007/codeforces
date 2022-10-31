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
#define N 5010
set<ll> S;
ll n , k , a[ N ];
void build(){

}
void init(){
    n = getint(); k = getint();
    for( int i = 1 ; i <= n ; i ++ ){
        a[ i ] = getint();
        S.insert( a[ i ] );
    }
}
int find_ans( ll nd ){
    int tans = -1;
    for( int i = 1 ; i <= n && a[ i ] <= nd  ; i ++ )
        for( ll j = 1 ; j <= k && a[ i ] * j <= nd ; j ++ )
            if( a[ i ] * j == nd ){
                if( tans == -1 || j < tans )
                    tans = j;
            }else{
                ll res = nd - a[ i ] * j;
                for( ll j2 = 1 ; j2 + j <= k ; j2 ++ )
                    if( res % j2 == 0 ){
                        ll ttt = res / j2;
                        if( S.count( ttt ) ){
                            if( tans == -1 || j + j2 < tans )
                                tans = j + j2;                            
                        }
                    }
            }
    return tans;
}
void solve(){
    int q = getint();
    while( q -- ){
        ll tmp = getint();
        printf( "%d\n" , find_ans( tmp ) );
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