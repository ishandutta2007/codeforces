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
inline void sleep( double sec ){
  clock_t s = clock();
  while( clock() - s < sec * CLOCKS_PER_SEC );
}
/*********default*********/
#define N 404040
void build(){

}
struct Arc{
  int to , nxt , si;
  Arc(){
    to = nxt = si = 0;
  }
  Arc( int _to , int _nxt , int _si ){
    to = _to;
    nxt = _nxt;
    si = _si;
  }
} e[ N ];
int n , m , from[ N ];
void init(){
  n = getint();
  m = getint();
  for( int i = 1 ; i <= m ; i ++ ){
    int ui = getint();
    int vi = getint();
    e[ i * 2 + 0 ] = Arc( vi , from[ ui ] , ui ); from[ ui ] = i * 2 + 0;
    e[ i * 2 + 1 ] = Arc( ui , from[ vi ] , vi ); from[ vi ] = i * 2 + 1;
  }
}
bool used[ N ] , in[ N ];
set< pair<int,int> > ans;
void add_ans( int ui , int vi ){
  if( ui > vi ) swap( ui , vi );
  ans.insert( { ui , vi } );
}
int go( int now ){
  used[ now ] = true;
  in[ now ] = true;
  vector<int> wt;
  for( int i = from[ now ] ; i ; i = e[ i ].nxt ){
    int to = e[ i ].to;
    if( in[ to ] ) continue;
    int res = -1;
    if( not used[ to ] )
      res = go( to );
    if( res == -1 )
      wt.push_back( i / 2 );
    else
      add_ans( i / 2 , res );
  }
  while( wt.size() > 1 ){
    int ui = wt.back(); wt.pop_back();
    int vi = wt.back(); wt.pop_back();
    add_ans( ui , vi );
  }
  in[ now ] = false;
  int ret = -1;
  if( wt.size() ) ret = wt.back();
  return ret;
}
int one[ 2 ] , two;
void print_ans(){
  printf( "%d\n" , (int)ans.size() );
  for( auto i : ans ){
    map<int,int> M;
    M[ e[ i.first * 2 ].si ] ++;
    M[ e[ i.first * 2 ].to ] ++;
    M[ e[ i.second * 2 ].si ] ++;
    M[ e[ i.second * 2 ].to ] ++;
    int on = 0;
    two = -1;
    for( auto j : M )
      if( j.second == 2 )
        two = j.first;
      else
        one[ on ++ ] = j.first;
    assert( two != -1 and
            on == 2 );
    printf( "%d %d %d\n" , one[ 0 ] , two , one[ 1 ] );
  }
}
void solve(){
  for( int i = 1 ; i <= n ; i ++ )
    if( not used[ i ] )
      go( i );
  print_ans();
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}