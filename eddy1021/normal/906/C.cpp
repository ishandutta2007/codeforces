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
#define N 23
void build(){

}
int n , m;
int v[ N ];
void init(){
  n = getint();
  m = getint();
  while( m -- ){
    int ui = getint() - 1;
    int vi = getint() - 1;
    v[ ui ] |= (1 << vi);
    v[ vi ] |= (1 << ui);
  }
  for( int i = 0 ; i < n ; i ++ )
    v[ i ] |= (1 << i);
}
void to_buf( int msk , int* buf , int& bt ){
  bt = 0;
  while( msk ){
    int now = __lg( msk & (-msk) );
    buf[ bt ++ ] = now;
    msk ^= (1 << now);
  }
}
bool is_cliq( int msk ){
  int buf[ N ] , bt;
  to_buf( msk , buf , bt );
  int goal = msk;
  for( int i = 0 ; i < bt ; i ++ ){
    goal &= v[ buf[ i ] ];
    if( goal < msk )
      return false;
  }
  return true;
}
char dp[ 1 << N ];
bool gt[ 1 << N ];
int frm[ 1 << N ];
int who[ 1 << N ];
#define K 10
vector<int> tans;
int cand[ N ];
void go( int now ){
  if( now >= (int)tans.size() ) return;
  if( is_cliq( (1 << n) - 1 ) ){
    tans.clear();
    for( int i = 0 ; i < now ; i ++ )
      tans.push_back( cand[ i ] + 1 );
    return;
  }
  int sv[ N ];
  for( int i = 0 ; i < n ; i ++ )
    sv[ i ] = v[ i ];
  for( int i = 0 ; i < n ; i ++ ){
    int buf[ N ] , bt;
    to_buf( v[ i ] , buf , bt );
    for( int j = 0 ; j < bt ; j ++ )
      v[ j ] |= v[ i ];
    bool dif = false;
    for( int j = 0 ; j < bt ; j ++ )
      if( v[ j ] != sv[ j ] ){
        dif = true;
        break;
      }
    if( dif ){
      cand[ now ] = i;
      go( now + 1 );
    }
    for( int j = 0 ; j < n ; j ++ )
      v[ j ] = sv[ j ];
  }
}
void solve2(){
  tans.resize( n );
  go( 0 );
  printf( "%d\n" , (int)tans.size() );
  for( size_t i = 0 ; i < tans.size() ; i ++ )
    printf( "%d%c" , tans[ i ] , " \n"[ i + 1 == tans.size() ] );
  Bye;
}
void solve(){
  if( n < 9 )
    solve2();
  for( int i = 1 ; i < (1 << n) ; i ++ ){
    if( is_cliq( i ) ){
      dp[ i ] = 0;
      gt[ i ] = true;
      frm[ i ] = 0;
      who[ i ] = 0;
    }
    if( not gt[ i ] ) continue;
    int buf[ N ] , bt;
    to_buf( i , buf , bt );
    for( int j = 0 ; j < bt ; j ++ ){
      int res = dp[ i ] + 1;
      int nmsk = i | v[ buf[ j ] ];
      if( not gt[ nmsk ] or res < dp[ nmsk ] ){
        dp[ nmsk ] = res;
        gt[ nmsk ] = true;
        frm[ nmsk ] = i;
        who[ nmsk ] = buf[ j ];
      }
    }
  }
  vector<int> ans;
  int cur = (1 << n) - 1;
  assert( gt[ cur ] );
  while( frm[ cur ] ){
    ans.push_back( who[ cur ] );
    cur = frm[ cur ];
  }
  reverse( ans.begin() , ans.end() );
  printf( "%d\n" , (int)ans.size() );
  for( size_t i = 0 ; i < ans.size() ; i ++ )
    printf( "%d%c" , ans[ i ] + 1 , " \n"[ i + 1 == ans.size() ] );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}