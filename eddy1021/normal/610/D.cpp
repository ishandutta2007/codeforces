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
ll mypow( ll _a , ll _x , ll _mod ){
  if( _x == 0 ) return 1ll;
  ll _tmp = mypow( _a , _x / 2 , _mod );
  _tmp = ( _tmp * _tmp ) % _mod;
  if( _x & 1 ) _tmp = ( _tmp * _a ) % _mod;
  return _tmp;
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
inline bool equal( D _x ,  D _y ){
  return _x > _y - eps && _x < _y + eps;
}
int __ = 1 , _cs;
/*********default*********/
#define N 222222
int st[ N << 2 ];
#define L(X) (X<<1)
#define R(X) (1+(X<<1))
inline void pull( int no ){ st[ no ] = st[ L( no ) ] + st[ R( no ) ]; }
void modify( int no , int l , int r , int pos , int num ){
  if( l == r ){
    st[ no ] += num;
    return;
  }
  int mid = ( l + r ) >> 1;
  if( pos <= mid ) modify( L( no ) , l , mid , pos , num );
  else  modify( R( no ) , mid + 1 , r , pos , num );
  pull( no );
}
int query( int no , int l , int r , int ql , int qr ){
  if( l == ql && r == qr ) return st[ no ];
  int mid = ( l + r ) >> 1;
  if( qr <= mid ) return query( L( no ) , l , mid , ql , qr );
  if( mid < ql ) return query( R( no ) , mid + 1 , r , ql , qr );
  int lret = query( L( no ) , l , mid , ql , mid );
  int rret = query( R( no ) , mid + 1 , r , mid + 1 , qr );
  return lret + rret;
}
int n , xx1[ N ] , yy1[ N ] , xx2[ N ] , yy2[ N ];
int lxx1[ N ] , lyy1[ N ] , lxx2[ N ] , lyy2[ N ];
vector< int > vx;
vector< int > vy;
void build(){

}
vector<PII> hor[ N ] , ver[ N ];
vector<int> in[ N ] , out[ N ];
ll ans;
void discrete(){
  sort( ALL( vx ) );
  sort( ALL( vy ) );
  vx.resize( unique( ALL( vx ) ) - vx.begin() );
  vy.resize( unique( ALL( vy ) ) - vy.begin() );
  for( int i = 1 ; i <= n ; i ++ ){
    lxx1[ i ] = lower_bound( ALL( vx ) , xx1[ i ] ) - vx.begin();
    lxx2[ i ] = lower_bound( ALL( vx ) , xx2[ i ] ) - vx.begin();
    lyy1[ i ] = lower_bound( ALL( vy ) , yy1[ i ] ) - vy.begin();
    lyy2[ i ] = lower_bound( ALL( vy ) , yy2[ i ] ) - vy.begin();
    if( lyy1[ i ] == lyy2[ i ] ) hor[ lyy1[ i ] ].PB( MP( xx1[ i ] , xx2[ i ] ) );
    else ver[ lxx1[ i ] ].PB( MP( yy1[ i ] , yy2[ i ] ) );
  }
}
void init(){
  n = getint();
  for( int i = 1 ; i <= n ; i ++ ){
    xx1[ i ] = getint();
    yy1[ i ] = getint();
    xx2[ i ] = getint();
    yy2[ i ] = getint();
    if( xx1[ i ] > xx2[ i ] ) swap( xx1[ i ] , xx2[ i ] );
    if( yy1[ i ] > yy2[ i ] ) swap( yy1[ i ] , yy2[ i ] );
    vx.PB( xx1[ i ] );
    vx.PB( xx2[ i ] );
    vy.PB( yy1[ i ] );
    vy.PB( yy2[ i ] );
  }
  discrete();
}
void solve(){
  for( int i = 0 ; i < (int)vy.size() ; i ++ ){
    if( (int)hor[ i ].size() == 0 ) continue;
    sort( ALL( hor[ i ] ) );
    int _sz = 1;
    for( int j = 1 ; j < (int)hor[ i ].size() ; j ++ )
      if( hor[ i ][ j ].FI <= hor[ i ][ _sz - 1 ].SE ){
        hor[ i ][ _sz - 1 ].FI = min( hor[ i ][ _sz - 1 ].FI , hor[ i ][ j ].FI );
        hor[ i ][ _sz - 1 ].SE = max( hor[ i ][ _sz - 1 ].SE , hor[ i ][ j ].SE );
      }else{
        hor[ i ][ _sz ].FI = hor[ i ][ j ].FI;
        hor[ i ][ _sz ].SE = hor[ i ][ j ].SE;
        _sz ++;
      }
    for( int j = 0 ; j < _sz ; j ++ ){
      ans += hor[ i ][ j ].SE - hor[ i ][ j ].FI + 1;
      int lft = lower_bound( ALL( vx ) , hor[ i ][ j ].FI ) - vx.begin();
      int rgt = lower_bound( ALL( vx ) , hor[ i ][ j ].SE ) - vx.begin();
      in[ lft ].PB( i );
      out[ rgt ].PB( i );
    }
  }
  int yn = (int)vy.size();
  for( int i = 0 ; i < (int)vx.size() ; i ++ ){
    for( int j = 0 ; j < (int)in[ i ].size() ; j ++ ){
      modify( 1 , 1 , yn , in[ i ][ j ] + 1 , +1 );
      // debug( "%d %d\n" , in[ i ][ j ] + 1 , +1 );
    }
    if( (int)ver[ i ].size() != 0 ){
      sort( ALL( ver[ i ] ) );
      int _sz = 1;
      for( int j = 1 ; j < (int)ver[ i ].size() ; j ++ )
        if( ver[ i ][ j ].FI <= ver[ i ][ _sz - 1 ].SE ){
          ver[ i ][ _sz - 1 ].FI = min( ver[ i ][ _sz - 1 ].FI , ver[ i ][ j ].FI );
          ver[ i ][ _sz - 1 ].SE = max( ver[ i ][ _sz - 1 ].SE , ver[ i ][ j ].SE );
        }else{
          ver[ i ][ _sz ].FI = ver[ i ][ j ].FI;
          ver[ i ][ _sz ].SE = ver[ i ][ j ].SE;
          _sz ++;
        }
      for( int j = 0 ; j < _sz ; j ++ ){
        int ly = ver[ i ][ j ].FI;
        int ry = ver[ i ][ j ].SE;
        int lly = lower_bound( ALL( vy ) , ly ) - vy.begin() + 1;
        int lry = lower_bound( ALL( vy ) , ry ) - vy.begin() + 1;
        ll dlt = ry - ly + 1;
        // debug( "%d %d\n" , lly , lry );
        int tmp = query( 1 , 1 , yn , lly , lry );
        dlt -= tmp;
        ans += max( 0ll , dlt );
      }
    }
    for( int j = 0 ; j < (int)out[ i ].size() ; j ++ ){
      modify( 1 , 1 , yn , out[ i ][ j ] + 1 , -1 );
      // debug( "%d %d\n" , out[ i ][ j ] + 1 , -1 );
    }
  }
  cout << ans << endl;
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}