// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long double LD;
typedef long long ll;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef pair<LD,LD> Pt;
typedef tuple<int,int,int> tiii;
typedef tuple<LL,LL,LL> tlll;
#define mod9 1000000009ll
#define mod7 1000000007ll
#define INF  1023456789ll
#define INF16 10000000000000000ll
#define FI first
#define SE second
#define X FI
#define Y SE
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define eps 1e-9
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
#ifndef ONLINE_JUDGE
#define debug(...) printf(__VA_ARGS__)
#else 
#define debug(...)
#endif
inline ll getint(){
  ll _x=0,_tmp=1; char _tc=getchar();    
  while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
  if( _tc == '-' ) _tc=getchar() , _tmp = -1;
  while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
  return _x*_tmp;
}
inline ll add( ll _x , ll _y , ll _mod = mod7 ){
  ll _ = _x + _y;
  if( _ >= _mod ) _ -= _mod;
  return _;
}
inline ll sub( ll _x , ll _y , ll _mod = mod7 ){
  ll _ = _x - _y;
  if( _ < 0 ) _ += _mod;
  return _;
}
inline ll mul( ll _x , ll _y , ll _mod = mod7 ){
  ll _ = _x * _y;
  if( _ >= _mod ) _ %= _mod;
  return _;
}
ll mypow( ll _a , ll _x , ll _mod ){
  if( _x == 0 ) return 1ll;
  ll _tmp = mypow( _a , _x / 2 , _mod );
  _tmp = mul( _tmp , _tmp , _mod );
  if( _x & 1 ) _tmp = mul( _tmp , _a , _mod );
  return _tmp;
}
ll mymul( ll _a , ll _x , ll _mod ){
  if( _x == 0 ) return 0ll;
  ll _tmp = mymul( _a , _x / 2 , _mod );
  _tmp = add( _tmp , _tmp , _mod );
  if( _x & 1 ) _tmp = add( _tmp , _a , _mod );
  return _tmp;
}
inline bool equal( D _x ,  D _y ){
  return _x > _y - eps && _x < _y + eps;
}
int __ = 1 , _cs;
/*********default*********/
#define N 9
int n , m;
char c[ N + N ][ N + N ];
vector< pair<short,short> > dir[ 4 ];
void build(){
  // 0
  // dir[ 0 ].PB( MP( -2 , -1 ) );
  dir[ 0 ].PB( MP( -2 , 0 ) );
  dir[ 0 ].PB( MP( -2 , 1 ) );
  dir[ 0 ].PB( MP( -1 , 0 ) );
  // 1
  dir[ 1 ].PB( MP( -2 , 0 ) );
  dir[ 1 ].PB( MP( -1 , -2 ) );
  dir[ 1 ].PB( MP( -1 , -1 ) );
  dir[ 1 ].PB( MP( -1 , 0 ) );
  // 2
  // dir[ 2 ].PB( MP( -2 , -1 ) );
  dir[ 2 ].PB( MP( -1 , -1 ) );
  dir[ 2 ].PB( MP( 0 , -2 ) );
  dir[ 2 ].PB( MP( 0 , -1 ) );
  // 3
  dir[ 3 ].PB( MP( -2 , 0 ) );
  dir[ 3 ].PB( MP( -1 , 0 ) );
  dir[ 3 ].PB( MP( -1 , 1 ) );
  dir[ 3 ].PB( MP( -1 , 2 ) );
}
short dp[ 2 ][ N ][ N ][ 1 << 9 ][ 1 << 9 ];
int fv[ 2 ][ N ][ N ][ 1 << 9 ][ 1 << 9 ];
bitset<2*N*N*(1<<9)*(1<<9)> inq;
queue<int> Q;
void init(){
  n = getint(); m = getint();
  for( short i = 0 ; i < n ; i ++ )
    for( short j = 0 ; j < m ; j ++ )
      c[ i ][ j ] = '.';
  for( short i = 0 ; i < n ; i ++ )
    for( short j = 0 ; j < m ; j ++ )
      for( short k = 0 ; k < ( 1 << m ) ; k ++ )
        for( short l = 0 ; l < ( 1 << m ) ; l ++ )
          dp[ 0 ][ i ][ j ][ k ][ l ] =
          dp[ 1 ][ i ][ j ][ k ][ l ] = -100;
  dp[ 0 ][ 0 ][ 0 ][ 0 ][ 0 ] = 0;
  Q.push( 0 );
}
inline int trans( int bt , int xn , int xm , int msk1 , int msk2 ){
  return ( bt << ( 2 * m + 8 ) ) +
         ( xn << ( 2 * m + 4 ) ) +
         ( xm << ( 2 * m ) ) +
         ( msk1 << m ) + msk2;
}
int bans , fdp , bdp;
char in = 'A';
inline void find_ans(){
  printf( "%d\n" , bans );
  int vl = fdp;
  int nown = n - 1 , nowm = m - 1 , bdir = bdp;
  while( nown >= 2 && nowm >= 0 ){
    int msk2 = vl & ( ( 1 << m ) - 1 ); vl >>= m;
    int msk1 = vl & ( ( 1 << m ) - 1 ); vl >>= m;
    int nm = vl & ( ( 1 << 4 ) - 1 ); vl >>= 4;
    int nn = vl & ( ( 1 << 4 ) - 1 ); vl >>= 4;
    int bt = vl & ( ( 1 << 4 ) - 1 ); vl >>= 4;
    if( bdir < 4 ){
      if( ( bdir == 0 && nowm >= 1 && nowm + 1 < m ) ||
          ( bdir == 1 && nowm >= 2 ) ||
          ( bdir == 2 && nowm >= 2 ) ||
          ( bdir == 3 && nowm + 2 < m ) ){
        for( size_t i = 0 ; i < dir[ bdir ].size() ; i ++ ){
          int ttn = nn + dir[ bdir ][ i ].FI;
          int ttm = nm + dir[ bdir ][ i ].SE;
          c[ ttn ][ ttm ] = in;
        }
        if( bdir == 0 || bdir == 2 )
          c[ nn - 2 ][ nm - 1 ] = in;
        c[ nn ][ nm ] = in;
        in ++;
      }
    }
    vl = fv[ bt ][ nn ][ nm ][ msk1 ][ msk2 ];
    bdir = dp[ bt ][ nn ][ nm ][ msk1 ][ msk2 ] % 10;
    nowm --;
    if( nowm < 0 ){
      nowm = m - 1;
      nown --;
    }
  }
  for( int i = 0 ; i < n ; i ++ )
    puts( c[ i ] );
}
inline void update( int nxtbt , int nxtn , int nxtm , int nxtmsk1 , int nxtmsk2 , int dpv , int vl , int tdir ){
  if( nxtn >= n ){
    if( dpv / 10 > bans ){
      bans = dpv / 10;
      fdp = vl;
      bdp = tdir;
    }
  }else{
    if( dpv / 10 >
        dp[ nxtbt ][ nxtn ][ nxtm ][ nxtmsk1 ][ nxtmsk2 ] / 10 ){
      dp[ nxtbt ][ nxtn ][ nxtm ][ nxtmsk1 ][ nxtmsk2 ] = ( dpv / 10 ) * 10 + tdir;
      fv[ nxtbt ][ nxtn ][ nxtm ][ nxtmsk1 ][ nxtmsk2 ] = vl;
      int nvl = trans( nxtbt , nxtn , nxtm , nxtmsk1 , nxtmsk2 );
      if( !inq[ nvl ] ){
        inq[ nvl ] = 1;
        Q.push( nvl );
      }
    }
  }
}
inline void solve(){
  while( Q.size() ){
    int vl = Q.front(); Q.pop();
    int svl = vl;
    int msk2 = svl & ( ( 1 << m ) - 1 ); svl >>= m;
    int msk1 = svl & ( ( 1 << m ) - 1 ); svl >>= m;
    int nm = svl & ( ( 1 << 4 ) - 1 ); svl >>= 4;
    int nn = svl & ( ( 1 << 4 ) - 1 ); svl >>= 4;
    int bt = svl & ( ( 1 << 4 ) - 1 ); svl >>= 4;
    int nxtmsk2 , nxtmsk1 , nxtm = nm + 1 , nxtn = nn , nxtbt;
    if( nxtm >= m ) nxtm = 0, nxtn ++;
    nxtbt = ( msk2 >> nm ) & 1;
    nxtmsk2 = ( msk2 & ( ~( 1 << nm ) ) ) | ( msk1 & ( 1 << nm ) );
    nxtmsk1 = ( msk1 & ( ~( 1 << nm ) ) );
    update( nxtbt , nxtn , nxtm , nxtmsk1 , nxtmsk2 , dp[ bt ][ nn ][ nm ][ msk1 ][ msk2 ] , vl , 5 );
    if( nn - 2 >= 0 && nm - 1 >= 0 && nm + 1 < m ){
      bool flag = true;
      for( size_t i = 0 ; i < dir[ 0 ].size() && flag ; i ++ ){
        int xxm = nm + dir[ 0 ][ i ].SE;
        if( dir[ 0 ][ i ].FI == -2 ){
          if( ( msk2 >> xxm ) & 1 ) flag = false;
        }else{
          if( ( msk1 >> xxm ) & 1 ) flag = false;
        }
      }
      if( bt ) flag = false;
      if( flag ){
        nxtbt = 1;
        nxtmsk2 = msk2 | ( 3 << nm );
        nxtmsk1 = msk1 | ( 1 << nm );
        update( nxtbt , nxtn , nxtm , nxtmsk1 , nxtmsk2 , dp[ bt ][ nn ][ nm ][ msk1 ][ msk2 ] + 10 , vl , 0 );
      }
    }
    if( nn - 2 >= 0 && nm - 2 >= 0 ){
      bool flag = true;
      for( size_t i = 0 ; i < dir[ 1 ].size() && flag ; i ++ ){
        int xxm = nm + dir[ 1 ][ i ].SE;
        if( dir[ 1 ][ i ].FI == -1 && dir[ 1 ][ i ].SE == 0 ){
          if( ( msk1 >> xxm ) & 1 ) flag = false;
        }else{
          if( ( msk2 >> xxm ) & 1 ) flag = false;
        }
      }
      if( flag ){
        nxtbt = 1;
        nxtmsk2 = msk2 | ( 7 << ( nm - 2 ) );
        nxtmsk1 = msk1 | ( 1 << nm );
        update( nxtbt , nxtn , nxtm , nxtmsk1 , nxtmsk2 , dp[ bt ][ nn ][ nm ][ msk1 ][ msk2 ] + 10 , vl , 1 );
      }
    }
    if( nn - 2 >= 0 && nm - 2 >= 0 ){
      bool flag = true;
      for( size_t i = 0 ; i < dir[ 2 ].size() && flag ; i ++ ){
        int xxm = nm + dir[ 2 ][ i ].SE;
        if( dir[ 2 ][ i ].FI == -1 && dir[ 2 ][ i ].SE == -1 ){
          if( ( msk2 >> xxm ) & 1 ) flag = false;
        }else{
          if( ( msk1 >> xxm ) & 1 ) flag = false;
        }
      }
      if( bt ) flag = false;
      if( flag ){
        nxtbt = ( msk2 >> nm ) & 1;
        nxtmsk2 = ( ( msk2 & (~( 1 << nm )) ) | ( msk1 & ( 1 << nm ) ) ) | ( 1 << ( nm - 1 ) );
        nxtmsk1 = msk1 | ( 7 << ( nm - 2 ) );
        update( nxtbt , nxtn , nxtm , nxtmsk1 , nxtmsk2 , dp[ bt ][ nn ][ nm ][ msk1 ][ msk2 ] + 10 , vl , 2 );
      }
    }
    if( nn - 2 >= 0 && nm + 2 < m ){
      bool flag = true;
      for( size_t i = 0 ; i < dir[ 3 ].size() && flag ; i ++ ){
        int xxm = nm + dir[ 3 ][ i ].SE;
        if( dir[ 3 ][ i ].FI == -2 ){
          if( ( msk2 >> xxm ) & 1 ) flag = false;
        }else{
          if( ( msk1 >> xxm ) & 1 ) flag = false;
        }
      }
      if( flag ){
        nxtbt = 1;
        nxtmsk2 = msk2 | ( 1 << nm );
        nxtmsk1 = msk1 | ( 7 << nm );
        update( nxtbt , nxtn , nxtm , nxtmsk1 , nxtmsk2 , dp[ bt ][ nn ][ nm ][ msk1 ][ msk2 ] + 10 , vl , 3 );
      }
    }
  }
  find_ans();
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}