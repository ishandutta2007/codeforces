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
#define N 202020
char c[ N ];
bool t[ 30 ][ 30 ][ 30 ];
bool t2[ 30 ][ 30 ] , flag[ N ];
int len;
void build(){
}
void init(){
  scanf( "%s" , c );
  len = strlen( c );
}
void solve(){
  flag[ len ] = true;
  for( int i = len - 2 ; i >= 5 ; i -- ){
    bool can2 = true , can3 = true;
    if( i + 3 < len ){
      if( c[ i ] == c[ i + 2 ] && c[ i + 1 ] == c[ i + 3 ] ){
        can2 = false;
        if( i + 4 < len && flag[ i + 5 ] )
          can2 = true;
      }
    }
    if( !flag[ i + 2 ] ) can2 = false;
    if( i + 5 < len ){
      if( c[ i ] == c[ i + 3 ] &&
          c[ i + 1 ] == c[ i + 4 ] &&
          c[ i + 2 ] == c[ i + 5 ] ){
        can3 = false;
        if( flag[ i + 5 ] )
          can3 = true;
      }
    }
    if( !flag[ i + 3 ] ) can3 = false;
    if( can2 ){
      t2[ c[ i ] - 'a' ][ c[ i + 1 ] - 'a' ] = true;
      flag[ i ] = true;
    }
    if( can3 ){
      t[ c[ i ] - 'a' ][ c[ i + 1 ] - 'a' ][ c[ i + 2 ] - 'a' ] = true;
      flag[ i ] = true;
    }
  }
  vector<string> vv;
  for( int i = 0 ; i < 26 ; i ++ )
    for( int j = 0 ; j < 26 ; j ++ ){
      if( t2[ i ][ j ] ){
        string tt = "";
        tt += (char)( i + 'a' );
        tt += (char)( j + 'a' );
        vv.PB( tt );
      }
      for( int k = 0 ; k < 26 ; k ++ )
        if( t[ i ][ j ][ k ] ){
          string tt = "";
          tt += (char)( i + 'a' );
          tt += (char)( j + 'a' );
          tt += (char)( k + 'a' );
          vv.PB( tt );
        }
    }
  sort( ALL( vv ) );
  printf( "%d\n" , (int)vv.size() );
  for( size_t i = 0 ; i < vv.size() ; i ++ )
    cout << vv[ i ] << endl;
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}