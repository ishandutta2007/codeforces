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
// #define X FI
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
#define N 161616
#define X 350
int n , m , p , a[ N ] , nd;
int tag[ X + X ] , all;
int sz[ X + X ];
int cnt[ N ][ X ];
unsigned int _x, _y, _z, _w;
void build(){
  srand( 514514 );
  _x = ( rand() << 15 ) + rand();
  _y = ( rand() << 15 ) + rand();
  _z = ( rand() << 15 ) + rand();
  _w = ( rand() << 15 ) + rand();
}
inline unsigned int rnd() {
	unsigned int _t = _x;
	_t ^= _t << 11;
	_t ^= _t >> 8;
	_x = _y; _y = _z; _z = _w;
	_w ^= _w >> 19;
	_w ^= _t;
	return _w;
}
inline void build_table(){
  for( int i = 0 ; i < n ; i ++ ){
    cnt[ a[ i ] ][ i / X ] ++;
    sz[ i / X ] ++;
  }
}
inline void rebuild( int bi , int l , int r , int vl ){
  for( int i = bi * X ; i < n && i < ( bi + 1 ) * X ; i ++ ){
    cnt[ a[ i ] ][ bi ] --;
    if( l <= i && i <= r ) a[ i ] = vl;
    else if( tag[ bi ] ) a[ i ] = tag[ bi ];
    cnt[ a[ i ] ][ bi ] ++;
  }
  tag[ bi ] = 0;
}
inline void modify( int l , int r , int vl ){
  int lb = l / X , rb = r / X;
  for( int i = lb + 1 ; i < rb ; i ++ )
    tag[ i ] = vl;
  rebuild( lb , l , r , vl );
  if( lb != rb )
    rebuild( rb , l , r , vl );
}
inline int query( int pos ){
  if( tag[ pos / X ] ) return tag[ pos / X ];
  return a[ pos ];
}
inline int count( int bi , int l , int r , int vl ){
  if( tag[ bi ] )
    return min( ( bi + 1 ) * X , r + 1 ) - max( bi * X , l );
  int sum = 0;
  for( int i = bi * X ; i < n && i < ( bi + 1 ) * X ; i ++ )
    if( l <= i && i <= r ){
      if( ( tag[ bi ] && tag[ bi ] == vl ) ||
          ( !tag[ bi ] && a[ i ] == vl ) )
        sum ++;
    }
  return sum;
}
inline int query( int l , int r , int vl ){
  int lb = l / X , rb = r / X , sum = 0;
  for( int i = lb + 1 ; i < rb ; i ++ )
    if( tag[ i ] ){
      if( tag[ i ] == vl )
        sum += sz[ i ];
    }else
      sum += cnt[ vl ][ i ];
  sum += count( lb , l , r , vl );
  if( lb != rb )
    sum += count( rb , l , r , vl );
  return sum;
}
#define MAGIC 200
int ans[ MAGIC ] , anssz;
int flag[ N ] , flag2[ N ] , ccnt[ N ] , cand[ MAGIC ] , candsz , stamp;
int pcnt[ MAGIC * 2 ] , tcand[ MAGIC ];
inline void calc( int ql , int qr ){
  anssz = candsz = 0; ++ stamp;
  for( int _ = 0 ; _ < MAGIC ; _ ++ ){
    int pos = rnd() % ( qr - ql + 1 ) + ql;
    if( flag[ pos ] == stamp ) continue;
    int who = query( pos );
    if( flag2[ who ] == stamp ) ccnt[ who ] ++;
    else{
      ccnt[ who ] = 1;
      flag2[ who ] = stamp;
      tcand[ candsz ++ ] = who;
    }
  }
  for( int i = 0 ; i <= MAGIC ; i ++ ) pcnt[ i ] = 0;
  for( int i = 0 ; i < candsz ; i ++ ) ++ pcnt[ ccnt[ tcand[ i ] ] ];
  for( int i = 1 ; i <= MAGIC ; i ++ ) pcnt[ i ] += pcnt[ i - 1 ];
  for( int i = candsz - 1 ; i >= 0 ; i -- )
    cand[ candsz - ( --pcnt[ ccnt[ tcand[ i ] ] ] ) - 1 ] = tcand[ i ];
  int bad = 0;
  for( int i = 0 ; i < candsz && anssz < nd ; i ++ ){
    int slots = query( ql , qr , cand[ i ] );
    if( slots * 100 >= p * ( qr - ql + 1 ) )
      ans[ anssz ++ ] = cand[ i ], bad = 0;
    else bad ++;
    if( bad >= 11 ) break;
  }
  if( anssz == 0 ) ans[ anssz ++ ] = 1;
  printf( "%d " , anssz );
  for( int i = 0 ; i < anssz ; i ++ )
    printf( "%d%c" , ans[ i ] , " \n"[ i + 1 == anssz ] );
}
void init(){
  n = getint();
  m = getint();
  p = getint();
  for( int i = 0 ; i < n ; i ++ )
    a[ i ] = getint();
  build_table();
}
void solve(){
  nd = 100 / p;
  while( m -- ){
    int cmd = getint();
    int ql = getint() - 1;
    int qr = getint() - 1;
    if( cmd == 1 ) modify( ql , qr , getint() );
    else calc( ql , qr );
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