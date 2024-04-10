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
#define N 4010
vector<int> v[ N ];
int n , m , deg[ N ];
bool tag[ N ][ N ];
void build(){

}
void init(){
  n = getint(); m = getint();
  while( m -- ){
    int tu , tv;
    tu = getint();
    tv = getint();
    deg[ tu ] ++;
    deg[ tv ] ++;
    v[ tu ].PB( tv );
    v[ tv ].PB( tu );
    tag[ tu ][ tv ] =
    tag[ tv ][ tu ] = true;
  }
}
void solve(){
  int ans = -1;
  for( int i = 1 ; i <= n ; i ++ )
    for( int j = 0 ; j < (int)v[ i ].size() ; j ++ )
      for( int k = j + 1 ; k < (int)v[ i ].size() ; k ++ )
        if( tag[ v[ i ][ j ] ][ v[ i ][ k ] ] ){
          int tans = deg[ i ] + deg[ v[ i ][ j ] ] +
                      deg[ v[ i ][ k ] ] - 6;
          if( ans == -1 || ( tans < ans ) )
            ans = tans;
        }
  cout << ans << endl;
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}