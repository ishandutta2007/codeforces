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
#define INF16 10000000000000000ll
#define INF INF16
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
void build(){

}
#define K 16
#define N 1021
inline D sqr( LL x ){ return x * x; }
int r , c , k , vl[ N ][ N ] , vd[ N ][ N ] , po;
inline D cal( int ii , int jj ){
  int r1 = ii * po + po - 1;
  int r2 = jj * po;
  D cu = 0;
  for( int j = 0 ; j < c ; j ++ )
    cu += sqr( vd[ r1 ][ j ] - vd[ r2 ][ j ] );
  return cu;
}
const D inf = 1e40;
D cst[ K ][ K ];
void init(){
  r = getint();
  c = getint();
  k = getint();
  po = r / k;
  for( int i = 0 ; i < r ; i ++ )
    for( int j = 0 ; j < c ; j ++ )
      vl[ i ][ j ] = getint();
  for( int i = 0 ; i < r ; i ++ )
    for( int j = 0 ; j < c ; j ++ ){
      vd[ i ][ j ] = 0;
      int got = 0;
      for( int di = -1 ; di <= 1 ; di ++ )
        for( int dj = -1 ; dj <= 1 ; dj ++ ){
          int nxti = i + di;
          int nxtj = j + dj;
          if( nxti < 0 || nxti >= r || nxtj < 0 || nxtj >= c ||
              i / po != nxti / po ) continue;
          vd[ i ][ j ] += vl[ nxti ][ nxtj ];
          got ++;
        }
      vd[ i ][ j ] /= got;
    }
  for( int i = 0 ; i < k ; i ++ )
    for( int j = 0 ; j < k ; j ++ )
      if( i == j ) cst[ i ][ j ] = inf;
      else cst[ i ][ j ] = cal( i , j );
}
D dp[ K ][ 1 << K ];
int bk[ K ][ 1 << K ];
void solve(){
  for( int i = 0 ; i < k ; i ++ ){
    for( int j = 0 ; j < ( 1 << k ) ; j ++ )
      dp[ i ][ j ] = inf;
    dp[ i ][ 1 << i ] = 0;
  }
  for( int msk = 0 ; msk < ( 1 << k ) ; msk ++ )
    for( int i = 0 ; i < k ; i ++ ) if( dp[ i ][ msk ] < inf ){
      for( int j = 0 ; j < k ; j ++ ){
        if( ( msk >> j ) & 1 ) continue;
        D tcst = dp[ i ][ msk ] + cst[ i ][ j ];
        if( tcst < dp[ j ][ msk | ( 1 << j ) ] ){
          dp[ j ][ msk | ( 1 << j ) ] = tcst;
          bk[ j ][ msk | ( 1 << j ) ] = i;
        }
      }
    }
  D bst = inf;
  int lst = -1;
  for( int i = 0 ; i < k ; i ++ )
    if( dp[ i ][ ( 1 << k ) - 1 ] < bst ){
      bst = dp[ i ][ ( 1 << k ) - 1 ];
      lst = i;
    }
  vector< int > ans , rans;
  rans.resize( k );
  int msk = ( 1 << k ) - 1;
  for( int i = 0 ; i < k ; i ++ ){
    ans.push_back( lst );
    int nxt = bk[ lst ][ msk ];
    msk ^= ( 1 << lst );
    lst = nxt;
  }
  reverse( ALL( ans ) );
  for( size_t i = 0 ; i < ans.size() ; i ++ )
    rans[ ans[ i ] ] = i;
  for( int i = 0 ; i < k ; i ++ )
    printf( "%d%c" , rans[ i ] + 1 , " \n"[ i + 1 == k ] );
}
int main(){
  build();
  __ = getint();
  while( __ -- ){
    init();
    solve();
  }
}