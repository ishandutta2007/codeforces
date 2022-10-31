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
#define N 50505
int nn , ss , xx , rans;
int nxt[ N ] , vv[ N ] , pp[ N ];
void build(){
#ifdef LOCAL
  nn = getint();
  for( int i = 0 ; i < nn ; i ++ )
    pp[ i ] = i + 1;
  random_shuffle( pp , pp + nn );
  for( int i = 0 ; i < nn ; i ++ ){
    vv[ pp[ i ] ] = i;
    nxt[ pp[ i ] ] = pp[ i + 1 ];
  }
  nxt[ pp[ nn - 1 ] ] = -1;
  ss = pp[ 0 ];
  xx = rand() % nn;
  printf( "%d %d %d\n" , nn , ss , xx );
#endif
}
int n , s , x;
int qqq;
pair<int,int> ask( int v ){
  assert( 1 <= v and v <= n );
  assert( ++ qqq < 2000 );
#ifdef LOCAL
  return { vv[ v ] , nxt[ v ] };
#else
  printf( "? %d\n" , v );
  fflush( stdout );
  int vi = getint();
  int ni = getint();
  return { vi , ni };
#endif
}
int ans = -1;
void answer(){
#ifdef LOCAL
  printf( "query %d times\n" , qqq );
#endif
  printf( "! %d\n" , ans );
  fflush( stdout );
  exit(0);
}
void init(){
#ifdef LOCAL
  n = nn;
  s = ss;
  x = xx;
#else
  n = getint();
  s = getint();
  x = getint();
#endif
}
#define K 500
int p[ N ] , bst = -1 , bi = -1;
void solve(){
  for( int i = 0 ; i < n ; i ++ )
    p[ i ] = i + 1;
  random_shuffle( p , p + n );
  p[ K ] = s;
  int res = 1999;
  for( int i = 0 ; i < min( n , K + 1 ) ; i ++ ){
    int value , next;
    tie( value , next ) = ask( p[ i ] );
    if( value >= x ){
      if( ans == -1 or value < ans )
        ans = value;
    }else{
      if( value > bi ){
        bi = value;
        bst = next;
      }
    }
    res --;
  }
  for( int i = 0 ; bst != -1 and i < res ; i ++ ){
    int value , next;
    tie( value , next ) = ask( bst );
    if( value >= x ){
      if( ans == -1 or value < ans )
        ans = value;
      break;
    }
    bst = next;
  }
  for( int i = K + 1 ; i < n and qqq < 1998 ; i ++ ){
    int value , next;
    tie( value , next ) = ask( p[ i ] );
    if( value >= x ){
      if( ans == -1 or value < ans )
        ans = value;
    }
  }
  answer();
}
int main(){
  srand( 0x1021 ); // lucky, right?
  srand( time( 0 ) );
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}