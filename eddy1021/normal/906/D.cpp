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
void sleep( double sec = 1021 ){
  clock_t s = clock();
  while( clock() - s < CLOCKS_PER_SEC * sec );
}
#define Bye exit(0)
int __ = 1 , _cs;
/*********default*********/
#define N 101010
#define K 30
const LL inf = 2000000000;
bool p[ N ];
vector<int> pri;
LL sv_pw[ K ][ K ];
void build(){
  for( int i = 2 ; i < N ; i ++ ) if( !p[ i ] ){
    pri.push_back( i );
    for( int j = i ; j < N ; j += i )
      p[ j ] = true;
  }
  for( int i = 2 ; i < K ; i ++ ){
    sv_pw[ i ][ 0 ] = 1;
    for( int j = 1 ; j < K ; j ++ ){
      sv_pw[ i ][ j ] = min( sv_pw[ i ][ j - 1 ] * i , inf );
    }
  }
}
inline int phi( int x ){
  int ret = x;
  for( int i : pri ){
    if( (LL)i * i > x ) break;
    if( x % i ) continue;
    ret = (ret / i) * (i - 1);
    while( x % i == 0 )
      x /= i;
  }
  if( x > 1 )
    ret = (ret / x) * (x - 1);
  return ret;
}
int n , m , q;
int w[ N ];
vector<int> mod;
void gogo(){
  mod.push_back( m );
  while( mod.back() > 1 )
    mod.push_back( phi( mod.back() ) );
}
void init(){
  n = getint();
  m = getint();
  for( int i = 1 ; i <= n ; i ++ )
    w[ i ] = getint();
  gogo();
}
inline LL magic( LL base , LL pw ){
  if( base == 1 ) return 1;
  if( pw >= K ) return inf;
  if( base < K ) return sv_pw[ base ][ pw ];
  LL ret = 1;
  while( pw -- ){
    ret = min( ret * base , inf );
    if( ret == inf ) return ret;
  }
  return ret;
}
inline LL cal2( int li , int ri , int cnt ){
  if( li == ri ) return w[ li ];
  if( w[ li ] == 1 ) return 1;
  if( cnt >= K ) return inf;
  LL ret = cal2( li + 1 , ri , cnt + 1 );
  return magic( w[ li ] , ret );
}
inline pair<int,LL> cal( int li , int ri , int pmod ){
  if( li == ri ) return { w[ li ] % mod[ pmod ] , w[ li ] };
  if( mod[ pmod ] == 1 ){
    LL vl = cal2( li , ri , 0 );
    return { 0 , vl };
  }
  pair<int,LL> ret = cal( li + 1 , ri , pmod + 1 );
  LL pww = ret.first;
  if( ret.second >= mod[ pmod + 1 ] )
    pww += mod[ pmod + 1 ];
  int vret = mypow( w[ li ] , pww , mod[ pmod ] );
  return { vret , magic( w[ li ] , ret.second ) };
}
void solve(){
  q = getint(); while( q -- ){
    int ql = getint();
    int qr = getint();
    printf( "%d\n" , cal( ql , qr , 0 ).first );
  }
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}