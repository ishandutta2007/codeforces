// eddy1021
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long double LD;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
#define mod9 1000000009LL
#define mod7 1000000007LL
#define INF  1023456789LL
#define INF16 10000000000000000LL
#define eps 1e-9
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#ifndef ONLINE_JUDGE
#define debug(...) printf(__VA_ARGS__)
#else 
#define debug(...)
#endif
inline LL getint(){
  LL _x=0,_tmp=1; char _tc=getchar();    
  while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
  if( _tc == '-' ) _tc=getchar() , _tmp = -1;
  while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
  return _x*_tmp;
}
inline LL add( LL _x , LL _y , LL _mod = mod7 ){
  _x += _y;
  return _x >= _mod ? _x - _mod : _x;
}
inline LL sub( LL _x , LL _y , LL _mod = mod7 ){
  _x -= _y;
  return _x < 0 ? _x + _mod : _x;
}
inline LL mul( LL _x , LL _y , LL _mod = mod7 ){
  _x *= _y;
  return _x >= _mod ? _x % _mod : _x;
}
LL mypow( LL _a , LL _x , LL _mod ){
  if( _x == 0 ) return 1LL;
  LL _ret = mypow( mul( _a , _a , _mod ) , _x >> 1 , _mod );
  if( _x & 1 ) _ret = mul( _ret , _a , _mod );
  return _ret;
}
LL mymul( LL _a , LL _x , LL _mod ){
  if( _x == 0 ) return 0LL;
  LL _ret = mymul( add( _a , _a , _mod ) , _x >> 1 , _mod );
  if( _x & 1 ) _ret = add( _ret , _a , _mod );
  return _ret;
}
inline bool equal( D _x ,  D _y ){
  return _x > _y - eps && _x < _y + eps;
}
#define Bye exit(0)
int __ = 1 , _cs;
/*********default*********/
const LL mx = 2000000000000000000LL;
struct BigInt{
  LL now;
  BigInt( LL v = 0 ){
    now = v;
  }
  BigInt operator+( const BigInt& he ){
    BigInt ret(now + he.now);
    ret.now = min(ret.now, mx);
    return ret;
  }
  BigInt operator*( const BigInt& he ){
    if( now == 0 or he.now == 0 )
      return BigInt();
    if( now > mx / he.now )
      return mx;
    BigInt ret(now * he.now);
    ret.now = min(ret.now , mx);
    return ret;
  }
};
#define X 4000
BigInt c[ X ][ X ];
void build(){
  for( int i = 0 ; i < X ; i ++ )
    c[ i ][ 0 ].now = c[ i ][ i ].now = 1;
  for( int i = 2 ; i < X ; i ++ )
    for( int j = 1 ; j < i ; j ++ )
      c[ i ][ j ] = c[ i - 1 ][ j ] + c[ i - 1 ][ j - 1 ];
}
LL tmp[ 10 ];
BigInt C( LL a , LL b ){
  if( a < b ) return BigInt( 0 );
  if( a - b < b ) b = a - b;
  if( a < X and b < X ) return c[ a ][ b ];
  if( b == 0 ) return BigInt( 1 );
  if( b == 1 ) return BigInt( a );
  if( b == 2 ){
    if( a % 2 ) return BigInt( a ) * BigInt( ( a - 1 ) / 2 );
    return BigInt( a / 2 ) * BigInt( a - 1 );
  }
  if( b < 6 ){
    for( LL i = 0 ; i < b ; i ++ )
      tmp[ i ] = a - i;
    for( LL i = 2 ; i <= b ; i ++ ){
      LL tt = i;
      for( int j = 0 ; j < b and tt > 1 ; j ++ ){
        if( tmp[ j ] == 1 ) continue;
        LL gg = __gcd( tt , tmp[ j ] );
        tt /= gg;
        tmp[ j ] /= gg;
      }
    }
    BigInt ret(1);
    for( int j = 0 ; j < b ; j ++ )
      if( tmp[ j ] > 1 )
        ret = ret * BigInt( tmp[ j ] );
    return ret;
  }
  return BigInt( mx );
}
#define N 202020
LL n , k , cmx;
BigInt a[ N ];
vector<int> cand;
void init(){
  n = getint();
  k = getint();
  //n = 200000;
  //k = 100000000000000000LL;
  for( LL i = 0 ; i < n ; i ++ ){
    LL tin = getint();
    if( tin ){
      cmx = max( cmx , tin );
      a[ i ].now = tin;
      cand.push_back( i );
    }
  }
}
bool okay( LL cur ){
  BigInt now;
  for( LL i : cand ){
  //for( LL i = 0 ; i < n ; i ++ ){
    now = now + ( C( n - i + cur - 2 , cur - 1 ) * a[ i ] );
    if( now.now >= k ) return true;
  }
  return false;
}
void solve(){
  if( cmx >= k ){
    puts( "0" );
    exit(0);
  }
  LL bl = 1 , br = mx , ba = br;
  while( bl <= br ){
    LL bmid = (bl + br) >> 1;
    if( okay( bmid ) )
      ba = bmid , br = bmid - 1;
    else
      bl = bmid + 1;
  }
  printf( "%lld\n" , ba );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}