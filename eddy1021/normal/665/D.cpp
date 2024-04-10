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
#define N 1021
#define P 2222222
bool p[ P + P ];
void build(){
  for( int i = 2 ; i < P ; i ++ ) p[ i ] = true;
  for( int i = 2 ; i < P ; i ++ ) if( p[ i ] )
    for( int j = P / i ; j >= i ; j -- )
      p[ i * j ] = false;
}
int n , a[ N ] , cnt;
void init(){
  n = getint();
  for( int i = 1 ; i <= n ; i ++ ){
    a[ i ] = getint();
    if( a[ i ] == 1 )
      cnt ++;
  }
}
void solve(){
  int ans1 = cnt , ansx = -1;
  for( int i = 1 ; i <= n ; i ++ )
    if( a[ i ] != 1 && p[ a[ i ] + 1 ] ){
      ans1 = cnt + 1;
      ansx = a[ i ];
      break;
    }
  if( ans1 >= 2 ){
    printf( "%d\n" , ans1 );
    if( ansx != -1 ){
      printf( "%d " , ansx ); ans1 --;
    }
    for( int i = 0 ; i < ans1 ; i ++ )
      printf( "1 " );
    puts( "" );
    exit( 0 );
  }
  for( int i = 1 ; i <= n ; i ++ )
    for( int j = i + 1 ; j <= n ; j ++ )
      if( p[ a[ i ] + a[ j ] ] ){
        puts( "2" );
        printf( "%d %d\n" , a[ i ] , a[ j ] );
        exit( 0 );
      }
  puts( "1" );
  printf( "%d\n" , a[ 1 ] );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}