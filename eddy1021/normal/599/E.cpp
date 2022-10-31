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
ll add( ll _x , ll _y , ll _mod = mod7 ){
  ll _ = _x + _y;
  if( _ >= _mod ) _ -= _mod;
  return _;
}
ll sub( ll _x , ll _y , ll _mod = mod7 ){
  ll _ = _x - _y;
  if( _ < 0 ) _ += _mod;
  return _;
}
ll mul( ll _x , ll _y , ll _mod = mod7 ){
  ll _ = _x * _y;
  if( _ >= _mod ) _ %= _mod;
  return _;
}
bool equal( D _x ,  D _y ){
  return _x > _y - eps && _x < _y + eps;
}
int __ = 1 , cs;
/*********default*********/
#define N 14
int n , m , q;
bool fb[ N ][ 1 << N ];
vector<int> v[ N ];
int son[ N ] , rd[ N ];
void build(){

}
void init(){
  n = getint();
  m = getint();
  q = getint();
  while( m -- ){
    int ui = getint();
    int vi = getint();
    v[ ui ].PB( vi );
    v[ vi ].PB( ui );
    rd[ ui ] |= ( 1 << ( vi - 1 ) );
    rd[ vi ] |= ( 1 << ( ui - 1 ) );
  }
  while( q -- ){
    int ai = getint();
    int bi = getint();
    int ci = getint();
    son[ ci ] |= ( 1 << ( ai - 1 ) );
    son[ ci ] |= ( 1 << ( bi - 1 ) );
    for( int i = 0 ; i < ( 1 << n ) ; i ++ )
      if( ( ( i >> ( ai - 1 ) ) & 1 ) &&
          ( ( i >> ( bi - 1 ) ) & 1 ) )
        fb[ ci ][ i ] = true;
  }
  for( int i = 1 ; i <= n ; i ++ )
    for( int j = 0 ; j < (int)v[ i ].size() ; j ++ )
      for( int k = j + 1 ; k < (int)v[ i ].size() ; k ++ )
        for( int msk = 0 ; msk < ( 1 << n ) ; msk ++ )
          if( ( ( msk >> ( v[ i ][ j ] - 1 ) ) & 1 ) &&
              ( ( msk >> ( v[ i ][ k ] - 1 ) ) & 1 ) )
            fb[ i ][ msk ] = true;
}
ll dp[ N ][ 1 << N ];
bool got[ N ][ 1 << N ];
ll DP( int now , int msk , int prt , bool fir , int tmp ){
  tmp &= (~( 1 << ( prt - 1 ) ));
  if( ( tmp & msk ) != tmp ) return 0;
  if( fir && ( msk & son[ now ] ) != son[ now ] ) return 0;
  if( got[ now ][ msk ] ) return dp[ now ][ msk ];
  got[ now ][ msk ] = true;
  if( msk == ( msk & (-msk) ) ) return dp[ now ][ msk ] = 1;
  msk &= (~( 1 << ( now - 1 ) ));
  for( int i = 1 ; i <= n ; i ++ )
    if( ( msk >> ( i - 1 ) ) & 1 ){
      ll tans = 0;
      for( int tmsk = msk ; tmsk ; tmsk = ( tmsk - 1 ) & msk ){
        if( fb[ now ][ tmsk ] ) continue;
        if( ( ( tmsk >> ( i - 1 ) ) & 1 ) == 0 ) continue;
        for( int j = 1 ; j <= n ; j ++ )
          if( ( tmsk >> ( j - 1 ) ) & 1 )
            tans += DP( j , tmsk , now , true , rd[ j ] ) *
                    DP( now , ( msk ^ tmsk ) | ( 1 << ( now - 1 ) ) ,
                        prt , false , tmp & ( ~( 1 << ( j - 1 ) ) ) );
      }
      // printf( "%d %d %d : " , now , msk , i );
      // printf( "%lld\n" , tans );
      return dp[ now ][ msk | ( 1 << ( now - 1 ) ) ] = tans;
    }
  return 0;
}
void solve(){
  printf( "%lld\n" , DP( 1 , ( 1 << n ) - 1 , 1 , true , rd[ 1 ] ) );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}