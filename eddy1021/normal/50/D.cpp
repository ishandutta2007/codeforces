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
#define N 111
int n , k , e;
Pt p[ N ];
inline Pt operator-( const Pt& p1 , const Pt& p2 ){
  return MP( p1.X - p2.X , p1.Y - p2.Y );
}
inline LD operator%( const Pt& p1 , const Pt& p2 ){
  return p1.X * p2.X + p1.Y * p2.Y;
}
inline LD norm( const Pt& tp ){
  return sqrt( tp % tp );
}
inline LD sqr( LD x ){
  return x * x;
}
void build(){

}
void init(){
  n = getint();
  k = getint();
  e = 1000 - getint();
  for( int i = 0 ; i <= n ; i ++ ){
    p[ i ].X = getint();
    p[ i ].Y = getint();
  }
}
LD dp[ N ][ N ];
LD prob[ N ];
inline bool okay( LD r ){
  int ott = 0 , itt = 0;
  for( int i = 1 ; i <= n ; i ++ ){
    LD dst = norm( p[ i ] - p[ 0 ] );
    if( dst < r + eps ) itt ++;
    else
      prob[ ++ ott ] = expl( 1.0 - sqr( dst ) / sqr( r ) );
  }
  if( itt >= k ) return true;
  for( int i = 0 ; i <= ott ; i ++ )
    for( int j = 0 ; j <= ott ; j ++ )
      dp[ i ][ j ] = 0.0;
  dp[ 1 ][ 1 ] = prob[ 1 ];
  dp[ 1 ][ 0 ] = 1.0 - prob[ 1 ];
  for( int i = 2 ; i <= ott ; i ++ )
    for( int j = 0 ; j < i ; j ++ ){
      dp[ i ][ j ] += dp[ i - 1 ][ j ] * ( 1.0 - prob[ i ] );
      dp[ i ][ j + 1 ] += dp[ i - 1 ][ j ] * prob[ i ];
    }
  LD acc = 0.0;
  for( int i = k - itt ; i <= ott ; i ++ )
    acc += dp[ ott ][ i ];
  return acc * 1000.0 + eps > (LD)e;
}
void solve(){
  LD l = 0 , r = 10000 , mid , ans = 0;
  for( int _ = 0 ; _ < 100 ; _ ++ ){
    mid = ( l + r ) * 0.5;
    if( okay( mid ) ) ans = mid , r = mid;
    else l = mid;
  }
  printf( "%.12f\n" , (D)ans );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}