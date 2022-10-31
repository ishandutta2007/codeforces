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
#define N 1021
#define K 10
short n , m , a[ N ][ N ] , two[ K ] , bt[ N ];
short dp[ N ][ N ][ K ][ K ];
void build_rmq(){
  for( short ib = 0 ; ib < K ; ib ++ )
    for( short jb = 0 ; jb < K ; jb ++ ){
      if( ib == 0 && jb == 0 ) continue;
      for( short i = 1 ; i + two[ ib ] - 1 <= n ; i ++ )
        for( short j = 1 ; j + two[ jb ] - 1 <= m ; j ++ ){
          if( jb )
            dp[ i ][ j ][ ib ][ jb ] = max( dp[ i ][ j ][ ib ][ jb - 1 ] ,
                                            dp[ i ][ j + two[ jb - 1 ] ][ ib ][ jb - 1 ] );
          if( ib )
            dp[ i ][ j ][ ib ][ jb ] = max( dp[ i ][ j ][ ib - 1 ][ jb ] ,
                                            dp[ i + two[ ib - 1 ] ][ j ][ ib - 1 ][ jb ] );
        }
    }
}
int query( int ql , int qr , int qu , int qd ){
  int ibt = bt[ qr - ql + 1 ];
  int jbt = bt[ qd - qu + 1 ];
  return max( max( dp[ ql ][ qu ][ ibt ][ jbt ] ,
                   dp[ ql ][ qd - two[ jbt ] + 1 ][ ibt ][ jbt ] ) ,
              max( dp[ qr - two[ ibt ] + 1 ][ qu ][ ibt ][ jbt ] ,
                   dp[ qr - two[ ibt ] + 1 ][ qd - two[ jbt ] + 1 ][ ibt ][ jbt ] ) );
}
void build(){
  two[ 0 ] = 1;
  for( int i = 1 ; i < K ; i ++ )
    two[ i ] = two[ i - 1 ] * 2;
  short tbt = 0 , nxt = 2;
  for( int i = 1 ; i < N ; i ++ ){
    bt[ i ] = tbt;
    if( i == nxt ){
      nxt <<= 1;
      tbt ++;
    }
  }
}
void init(){
  n = getint();
  m = getint();
  for( short i = 1 ; i <= n ; i ++ )
    for( short j = 1 ; j <= m ; j ++ )
      a[ i ][ j ] = getint();
  for( short i = 1 ; i <= n ; i ++ )
    for( short j = 1 ; j <= m ; j ++ )
      if( a[ i ][ j ] )
        dp[ i ][ j ][ 0 ][ 0 ] = 1 + min( dp[ i - 1 ][ j - 1 ][ 0 ][ 0 ] , 
                                          min( dp[ i - 1 ][ j ][ 0 ][ 0 ] ,
                                               dp[ i ][ j - 1 ][ 0 ][ 0 ] ) );
  build_rmq();
}
void solve(){
  int qry = getint(); while( qry -- ){
    short al = getint();
    short au = getint();
    short ar = getint();
    short ad = getint();
    short bl = 0 , br = min( ar - al + 1 , ad - au + 1 ) , ans = 0;
    short ql , qr , qu , qd;
    qr = ar; qd = ad;
    while( bl <= br ){
      short bmid = ( bl + br ) >> 1;
      ql = al + bmid - 1;
      qu = au + bmid - 1;
      if( query( ql , qr , qu , qd ) >= bmid ) ans = bmid , bl = bmid + 1;
      else br = bmid - 1;
    }
    printf( "%d\n" , (int)ans );
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