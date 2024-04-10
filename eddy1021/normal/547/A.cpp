// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long long ll;
typedef pair<int,int> PII;
#define mod9 1000000009ll
#define mod7 1000000007ll 
#define INF 1023456789ll
#define INF16 10000000000000000ll
#define FI first
#define SE second
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define eps 1e-7
ll getint(){
    ll tmp; cin >> tmp;
    return tmp;
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
#define N 5000010
ll m , h1 , a1 , x1 , y11;
ll h2 , a2 , x2 , y22;
ll tag1[ N ] , tag2[ N ];
ll aa1 , bb1 , pp1;
ll aa2 , bb2 , pp2;
void build(){

}
void init(){
    m = getint();
    for( int i = 0 ; i < m ; i ++ )
        tag1[ i ] = tag2[ i ] = -1;
    h1 = getint(); a1 = getint();
    x1 = getint(); y11 = getint();
    h2 = getint(); a2 = getint();
    x2 = getint(); y22 = getint();
    pp1 = pp2 = -1;
}
void solve(){
    ll now = h1 , flag = 0;
    while( true ){
        if( now == a1 && pp1 == -1 ) pp1 = flag;
        if( tag1[ now ] != -1 ){
            aa1 = tag1[ now ];
            bb1 = flag - tag1[ now ];
            break;
        }else{
            tag1[ now ] = flag ++;
            now = ( x1 * now + y11 ) % m;
        }
    }
    now = h2; flag = 0;
    while( true ){
        if( now == a2 && pp2 == -1 ) pp2 = flag;
        if( tag2[ now ] != -1 ){
            aa2 = tag2[ now ];
            bb2 = flag - tag2[ now ];
            break;
        }else{
            tag2[ now ] = flag ++;
            now = ( x2 * now + y22 ) % m;
        }
    }
    if( pp1 == -1 || pp2 == -1 ){
        puts( "-1" );
        return;
    }
    if( pp1 < aa1 && pp2 < aa2 ){
        if( pp1 != pp2 ) puts( "-1" );
        else cout << pp1 << endl;
        return;
    }
    if( pp1 < aa1 ){
        pp2 -= aa2;
        if( ( pp1 - pp2 - aa2 ) >= 0 && ( pp1 - pp2 - aa2 ) % bb2 == 0 )
            cout << pp1 << endl;
        else puts( "-1" );
        return;
    }
    if( pp2 < aa2 ){
        pp1 -= aa1;
        if( ( pp2 - pp1 - aa1 ) >= 0 && ( pp2 - pp1 - aa1 ) % bb1 == 0 )
            cout << pp2 << endl;
        else puts( "-1" );
        return;
    }
    pp1 -= aa1;
    pp2 -= aa2;
    ll ttc = aa2 + pp2 - aa1 - pp1;
    for( ll i = 0 ; i < 2 * bb1 ; i ++ )
        if( ( bb2 * i + ttc ) % bb1 == 0 ){
            if( aa2 + bb2 * i + pp2 <= 0 ) continue;
            cout << aa2 + bb2 * i + pp2 << endl;
            return;
        }
    puts( "-1" );
}
int main(){
    build();
    //__ = getint();
    while( __ -- ){
        init();
        solve();
    }
}