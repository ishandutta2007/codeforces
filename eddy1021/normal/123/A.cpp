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
#define N 1021
int cnt[ N ] , len;
int p[ N ] , sz[ N ];
char c[ N ] , ans[ N ];
int find_p( int x ){
  return x == p[ x ] ? x : p[ x ] = find_p( p[ x ] );
}
void Union( int x , int y ){
  x = find_p( x );
  y = find_p( y );
  if( x == y ) return;
  p[ x ] = y;
  sz[ y ] += sz[ x ];
}
void build(){
  
}
bool pr[ N ];
void init(){
  scanf( "%s" , c );
  len = strlen( c );
  for( int i = 0 ; i < len ; i ++ )
    cnt[ c[ i ] - 'a' ] ++;
  for( int i = 1 ; i <= len ; i ++ ) p[ i ] = i , sz[ i ] = 1;
  for( int i = 2 ; i <= len ; i ++ ) if( !pr[ i ] ){
    for( int j = i + i ; j <= len ; j += i  ){
      pr[ j ] = true;
      Union( i , j );
    }
  }
}
bool done[ N ];
void solve(){
  int got = 0;
  while( got < len ){
    int mx = -1 , mt = -1;
    for( int i = 1 ; i <= len ; i ++ )
      if( i == find_p( i ) && !done[ i ] ){
        // printf( "%d %d\n" , i , sz[ i ] );
        if( sz[ i ] > mx ){
          mx = sz[ i ];
          mt = i;
        }
      }
    // puts( "" );
    done[ mt ] = true;
    bool good = false;
    for( int i = 0 ; i < 26 ; i ++ )
      if( cnt[ i ] >= mx ){
        good = true;
        for( int j = 1 ; j <= len ; j ++ )
          if( find_p( j ) == mt ){
            ans[ j ] = i + 'a';
            cnt[ i ] --;
            got ++;
          }
        break;
      }
    if( !good ){
      puts( "NO" );
      return;
    }
  }
  puts( "YES" );
  puts( ans + 1 );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}