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
#define N 1001001
#define K 22
int n , k , v[ N ] , c[ N ] , lg[ N ] , two[ K ];
void build(){
  int nxt = 2 , pre = 0;
  for( int i = 1 ; i < N ; i ++ ){
    lg[ i ] = pre;
    if( i == nxt ){
      nxt *= 2;
      pre ++;
    }
  }
  two[ 0 ] = 1;
  for( int i = 1 ; i < K ; i ++ )
    two[ i ] = ( two[ i - 1 ] << 1 );
}
int Rmin[ K ][ N ];
int Rmax[ K ][ N ];
void init(){
  n = getint();
  k = getint();
  for( int i = 0 ; i < n ; i ++ ){
    v[ i ] = getint() * 100;
    Rmax[ 0 ][ i ] = v[ i ];
  }
  for( int i = 0 ; i < n ; i ++ ){
    c[ i ] = getint();
    Rmin[ 0 ][ i ] = c[ i ];
  }
  for( int i = 1 ; i < K ; i ++ )
    for( int j = 0 ; j < n ; j ++ ){
      if( j + two[ i ] - 1 >= n ) break;
      Rmax[ i ][ j ] = max( Rmax[ i - 1 ][ j ] , Rmax[ i - 1 ][ j + two[ i - 1 ] ] );
      Rmin[ i ][ j ] = min( Rmin[ i - 1 ][ j ] , Rmin[ i - 1 ][ j + two[ i - 1 ] ] );
    }
}
inline int tk_max( int l , int r ){
  int nlg = lg[ r - l + 1 ];
  return max( Rmax[ nlg ][ l ] , Rmax[ nlg ][ r - two[ nlg ] + 1 ] );
}
inline int tk_min( int l , int r ){
  int nlg = lg[ r - l + 1 ];
  return min( Rmin[ nlg ][ l ] , Rmin[ nlg ][ r - two[ nlg ] + 1 ] );
}
int vl[ N ];
void solve(){
  for( int i = 0 ; i < n ; i ++ ){
    int bstv = min( tk_max( i , i ) , tk_min( i , i ) );
    int bl = i , br = n - 1 , mid;
    while( bl <= br ){
      mid = ( bl + br ) >> 1;
      if( tk_max( i , mid ) < tk_min( i , mid ) ){
        bstv = max( bstv , tk_max( i , mid ) );
        bl = mid + 1;
      }else{
        bstv = max( bstv , tk_min( i , mid ) );
        br = mid - 1;
      }
    }
    vl[ i ] = bstv;
  }
  sort( vl , vl + n );
  LD ans = 0.0 , pro = 1.0 / (LD) n * (LD)k;
  for( int i = 0 ; i <= n - k ; i ++ ){
    ans += pro * (LD)vl[ i ];
    pro *= (LD)( n - k - i );
    pro /= (LD)( n - i - 1 );
  }
  printf( "%.16f\n" , (D)ans );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}