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
int __ = 1 , _cs;
/*********default*********/
#define N 202
void build(){

}
int n , m , deg[ N ] , odeg[ N ];
set< int > v[ N ];
void init(){
  scanf( "%d%d" , &n , &m );
  for( int i = 1 ; i <= n ; i ++ ){
    odeg[ i ] = deg[ i ] = 0;
    v[ i ].clear();
  }
  while( m -- ){
    int ui , vi; scanf( "%d%d" , &ui , &vi );
    deg[ ui ] ++; deg[ vi ] ++;
    v[ ui ].insert( vi );
    v[ vi ].insert( ui );
  }
}
vector< pair<int,int> > ans;
void go( int now ){
  while( v[ now ].size() ){
    int st = *v[ now ].begin();
    v[ now ].erase( st );
    v[ st ].erase( now );
    odeg[ now ] ++;
    ans.push_back( { now , st } );
    while( v[ st ].size() ){
      int nxt = *v[ st ].begin();
      v[ st ].erase( nxt );
      v[ nxt ].erase( st );
      odeg[ st ] ++;
      ans.push_back( { st , nxt } );
      st = nxt;
    }
  }
}
void solve(){
  ans.clear();
  for( int i = 1 ; i <= n ; i ++ )
    if( deg[ i ] % 2 )
      go( i );
  for( int i = 1 ; i <= n ; i ++ )
    if( deg[ i ] % 2 == 0 )
      go( i );
  int cnt = 0;
  for( int i = 1 ; i <= n ; i ++ )
    if( odeg[ i ] == deg[ i ] - odeg[ i ] )
      cnt ++;
  printf( "%d\n" , cnt );
  for( auto e : ans )
    printf( "%d %d\n" , e.first , e.second );
}
int main(){
  build();
  __ = getint();
  while( __ -- ){
    init();
    solve();
  }
}