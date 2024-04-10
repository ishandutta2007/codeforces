// eddy11021
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
#define P 500001
#define N 200010
bool p[ P ];
vector<int> pset;
vector<int> fac[ P ];
int tcnt[ P ];
void build(){
    int idx = 0;
    for( int i = 2 ; i < P ; i ++ ) if( !p[ i ] ){
        pset.PB( i );
        for( int j = i ; j < P ; j += i ){
            p[ j ] = true;
            fac[ j ].PB( idx );
        }
        idx ++;
    }
}
int s[ P ];
int n , q , a[ N ] , total;
ll ans;
bool on[ N ];
void init(){
    n = getint(); q = getint();
    for( int i = 1 ; i <= n ; i ++ )
        a[ i ] = getint();
}
void del( int tn ){
    on[ tn ] = false;
    tn = a[ tn ];
    total --;
    if( tn == 1 ) ans -= total;
    else{
        ll dlt = 0; int sz = (int)fac[ tn ].size();
        for( int i = 1 ; i < ( 1 << sz ) ; i ++ ){
            int got = 0 , tmp = 1;
            for( int j = 0 ; j < sz ; j ++ )
                if( i & ( 1 << j ) ){
                    got ++;
                    tmp *= pset[ fac[ tn ][ j ] ];
                }
            s[ tmp ] --;
            if( got & 1 ) dlt -= s[ tmp ];
            else dlt += s[ tmp ];
        }
        if( dlt < 0 ) dlt *= -1;
        dlt = total - dlt;
        ans -= dlt;
    }
}
void add( int tn ){
    on[ tn ] = true;
    tn = a[ tn ];
    if( tn == 1 ) ans += total;
    else{
        ll dlt = 0; int sz = (int)fac[ tn ].size();
        for( int i = 1 ; i < ( 1 << sz ) ; i ++ ){
            int got = 0 , tmp = 1;
            for( int j = 0 ; j < sz ; j ++ )
                if( i & ( 1 << j ) ){
                    got ++;
                    tmp *= pset[ fac[ tn ][ j ] ];
                }
            if( got & 1 ) dlt -= s[ tmp ];// , printf( "%d -%d\n" , tmp , s[ tmp ] );
            else dlt += s[ tmp ];// , printf( "%d +%d\n" , tmp , s[ tmp ] );
            s[ tmp ] ++;
        }
        if( dlt < 0 ) dlt *= -1;
        dlt = total - dlt;
        ans += dlt;
    }
    total ++;
}
void solve(){
    while( q -- ){
        int tn = getint();
        if( on[ tn ] ) del( tn );
        else add( tn );
        cout << ans << endl;
    }
}
int main(){
    build();
    //__ = getint();
    while( __ -- ){
        init();
        solve();
    }
}