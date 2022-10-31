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
#define N 514
#define M 101010
struct Arc{
  int to , nxt;
  Arc(){}
  Arc( int _to , int _nxt ){
    to = _to; nxt = _nxt;
  }
} r[ M ];
void build(){

}
int n , m , from[ N ] , id[ N ][ N ] , ind[ N ];
void init(){
  n = getint();
  m = getint();
  for( int i = 1 ; i <= m ; i ++ ){
    int ui = getint();
    int vi = getint();
    r[ i ] = Arc( vi , from[ ui ] );
    from[ ui ] = i;
    id[ ui ][ vi ] = i;
    ind[ vi ] ++;
  }
}
vector<int> cand;
bool vst[ N ] , instk[ N ];
int who[ N ];
void go( int now , int sz ){
  vst[ now ] = true;
  instk[ now ] = true;
  who[ sz ] = now;
  for( int i = from[ now ] ; i and cand.empty() ; i = r[ i ].nxt )
    if( instk[ r[ i ].to ] ){
      cand.push_back( i );
      for( int j = sz ; j ; j -- )
        if( who[ j ] == r[ i ].to ) break;
        else cand.push_back( id[ who[ j - 1 ] ][ who[ j ] ] );
      break;
    }else if( not vst[ r[ i ].to ] )
      go( r[ i ].to , sz + 1 );
  instk[ now ] = false;
}
void yes(){
  puts( "YES" );
  exit(0);
}
int block , tind[ N ];
void gogo(){
  if( block == 0 ) return;
  for( int i = 1 ; i <= n ; i ++ )
    tind[ i ] = ind[ i ];
  tind[ r[ block ].to ] --;
  queue<int> Q;
  for( int i = 1 ; i <= n ; i ++ )
    if( tind[ i ] == 0 )
      Q.push( i );
  int gt = 0;
  while( Q.size() ){
    int tn = Q.front(); Q.pop();
    gt ++;
    for( int i = from[ tn ] ; i ; i = r[ i ].nxt ){
      if( i == block ) continue;
      tind[ r[ i ].to ] --;
      if( tind[ r[ i ].to ] == 0 )
        Q.push( r[ i ].to );
    }
  }
  if( gt == n ) yes();
}
void solve(){
  for( int i = 1 ; i <= n and cand.empty() ; i ++ )
    if( ind[ i ] == 0 and not vst[ i ] )
      go( i , 0 );
  for( int i = 1 ; i <= n and cand.empty() ; i ++ )
    if( not vst[ i ] )
      go( i , 0 );
  if( cand.empty() ) yes();
  for( int i : cand ){
    block = i;
    gogo();
  }
  puts( "NO" );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}