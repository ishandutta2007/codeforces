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
#define N 808080
void build(){

}
char c[ N ] , op[ N ];
int n , m , p , nxt[ N ] , pre[ N ] , wt[ N ];
inline void build_pair(){
  vector<int> v;
  for( int i = 1 ; i <= n ; i ++ )
    if( c[ i ] == '(' ) v.PB( i );
    else{
      wt[ v.back() ] = i;
      wt[ i ] = v.back();
      v.pop_back();
    }
  for( int i = 0 ; i <= n ; i ++ ){
    nxt[ i ] = i + 1;
    pre[ i + 1 ] = i;
  }
}
void init(){
  n = getint();
  m = getint();
  p = getint();
  scanf( "%s" , c + 1 );
  scanf( "%s" , op );
}
void solve(){
  build_pair();
  for( int i = 0 ; i < m ; i ++ )
    if( op[ i ] == 'L' ) p = pre[ p ];
    else if( op[ i ] == 'R' ) p = nxt[ p ];
    else{
      int pp = wt[ p ];
      if( pp < p ) swap( p , pp );
      pre[ nxt[ pp ] ] = pre[ p ];
      nxt[ pre[ p ] ] = nxt[ pp ];
      if( nxt[ pp ] > n ) p = pre[ p ];
      else p = nxt[ pp ];
    }
  int now = nxt[ 0 ];
  while( now <= n ){
    putchar( c[ now ] );
    now = nxt[ now ];
  }
  puts( "" );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}