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
#define N 101010
#define K 20
struct Node{
  int cnt , lft , rgt;
  Node(){
    cnt = lft = rgt = 0;
  }
} p[ N * 40 ];
int pcnt = 0;
inline int new_node(){
  return ++ pcnt;
}
int v[ 20 ];
void modify( int now , int id , int dlt ){
  if( id == K ){
    p[ now ].cnt += dlt;
    return;
  }
  if( v[ id ] % 2 ){
    if( p[ now ].lft == 0 )
      p[ now ].lft = new_node();
    modify( p[ now ].lft , id + 1 , dlt );
  }else{
    if( p[ now ].rgt == 0 )
      p[ now ].rgt = new_node();
    modify( p[ now ].rgt , id + 1 , dlt );
  }
}
int query( int now , int id ){
  if( !now ) return 0;
  if( id == K ) return p[ now ].cnt;
  if( v[ id ] % 2 ) return query( p[ now ].lft , id + 1 );
  return query( p[ now ].rgt , id + 1 );
}
void build(){

}
int t;
void init(){
  t = getint();
}
char cmd[ N ] , c[ N ];
void solve(){
  int root = new_node();
  while( t -- ){
    scanf( "%s%s" , cmd , c );
    if( cmd[ 0 ] == '?' ){
      int len = strlen( c );
      for( int i = 0 ; i < K ; i ++ )
        v[ i ] = 0;
      for( int i = len - 1 , j = 0 ; i >= 0 ; i -- , j ++ )
        v[ j ] = c[ i ] - '0';
      printf( "%d\n" , query( root , 0 ) );
    }else{
      int dlt = ( cmd[ 0 ] == '+' ? 1 : -1 );
      int len = strlen( c );
      for( int i = 0 ; i < K ; i ++ )
        v[ i ] = 0;
      for( int i = len - 1 , j = 0 ; i >= 0 ; i -- , j ++ )
        v[ j ] = ( c[ i ] - '0' ) % 2;
      modify( root , 0 , dlt );
    }
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