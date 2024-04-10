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
#define N 18
int cnt[ 1 << N ];
void build(){
  for( int i = 1 ; i < ( 1 << N ) ; i ++ )
    cnt[ i ] = cnt[ i / 2 ] + ( i % 2 );
}
int n , m , k;
ll vl[ N ][ N ] , dp[ 1 << N ][ N ] , a[ N ];
void init(){
  n = getint(); m = getint(); k = getint();
  for( int i = 0 ; i < n ; i ++ ) a[ i ] = getint();
  while( k -- ){
    int xi = getint() - 1;
    int yi = getint() - 1;
    vl[ xi ][ yi ] = getint();
  }
}
ll ans;
queue<PII> Q;
bool tag[ 1 << N ][ N ];
void solve(){
  for( int i = 0 ; i < n ; i ++ ){
    dp[ ( 1 << i ) ][ i ] = a[ i ];
    Q.push( MP( 1 << i , i ) );
    tag[ ( 1 << i ) ][ i ] = true;
  }
  while( Q.size() ){
    PII tp = Q.front(); Q.pop();
    int msk = tp.FI , lst = tp.SE;
    if( cnt[ msk ] == m ){
      ans = max( ans , dp[ msk ][ lst ] );
      continue;
    }
    for( int i = 0 ; i < n ; i ++ )
      if( !( ( msk >> i ) & 1 ) ){
        dp[ msk | ( 1 << i ) ][ i ] = max( dp[ msk | ( 1 << i ) ][ i ],
                                           dp[ msk ][ lst ] + a[ i ] + vl[ lst ][ i ] );
        if( !tag[ msk | ( 1 << i ) ][ i ] ){
          tag[ msk | ( 1 << i ) ][ i ] = true;
          Q.push( MP( msk | ( 1 << i ) , i ) );
        }
      }
  }
  printf( "%lld\n" , ans );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}