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
#define N 1010101
int p[ N ];
int find_p( int x ){
  return x == p[ x ] ? x : p[ x ] = find_p( p[ x ] );
}
inline void Union( int x , int y ){
  x = find_p( x );
  y = find_p( y );
  if( x == y ) return ;
  p[ x ] = y;
}
void build(){
  
}
int n , m , a[ N ] , deg[ N ];
inline int pos( int in , int im ){
  return in * m + im;
}
vector<int> nxt[ N ];
void init(){
  n = getint(); m = getint();
  for( int i = 0 ; i < n * m ; i ++ ){
    a[ i ] = getint();
    p[ i ] = i;
  }
}
void build_edge(){
  for( int i = 0 ; i < n ; i ++ ){
    vector<PII> v;
    for( int j = 0 ; j < m ; j ++ )
      v.PB( MP( a[ pos( i , j ) ] , pos( i , j ) ) );
    sort( ALL( v ) );
    for( size_t j = 0 ; j + 1 < v.size() ; j ++ )
      if( v[ j ].FI == v[ j + 1 ].FI )
        Union( v[ j + 1 ].SE , v[ j ].SE );
  }
  for( int j = 0 ; j < m ; j ++ ){
    vector<PII> v;
    for( int i = 0 ; i < n ; i ++ )
      v.PB( MP( a[ pos( i , j ) ] , pos( i , j ) ) );
    sort( ALL( v ) );
    for( size_t i = 0 ; i + 1 < v.size() ; i ++ )
      if( v[ i ].FI == v[ i + 1 ].FI )
        Union( v[ i + 1 ].SE , v[ i ].SE );
  }
  for( int i = 0 ; i < n ; i ++ ){
    vector<PII> v;
    for( int j = 0 ; j < m ; j ++ )
      v.PB( MP( a[ pos( i , j ) ] , pos( i , j ) ) );
    sort( ALL( v ) );
    for( size_t j = 0 ; j + 1 < v.size() ; j ++ )
      if( v[ j ].FI != v[ j + 1 ].FI ){
        nxt[ find_p( v[ j ].SE ) ].PB( find_p( v[ j + 1 ].SE ) );
        deg[ find_p( v[ j + 1 ].SE ) ] ++;
      }
  }
  for( int j = 0 ; j < m ; j ++ ){
    vector<PII> v;
    for( int i = 0 ; i < n ; i ++ )
      v.PB( MP( a[ pos( i , j ) ] , pos( i , j ) ) );
    sort( ALL( v ) );
    for( size_t i = 0 ; i + 1 < v.size() ; i ++ )
      if( v[ i ].FI != v[ i + 1 ].FI ){
        nxt[ find_p( v[ i ].SE ) ].PB( find_p( v[ i + 1 ].SE ) );
        deg[ find_p( v[ i + 1 ].SE ) ] ++;
      }
  }
}
queue<int> Q;
int ans[ N ];
void build_ans(){
  for( int i = 0 ; i < n * m ; i ++ )
    if( i == find_p( i ) && deg[ i ] == 0 ){
      Q.push( i ); ans[ i ] = 1;
    }
  while( Q.size() ){
    int tn = Q.front(); Q.pop();
    for( size_t i = 0 ; i < nxt[ tn ].size() ; i ++ ){
      int tnxt = nxt[ tn ][ i ];
      ans[ tnxt ] = max( ans[ tnxt ] , ans[ tn ] + 1 );
      deg[ tnxt ] --;
      if( deg[ tnxt ] == 0 ) Q.push( tnxt );
    }
  }
}
void solve(){
  if( n == 1 && m == 1 ){
    puts( "1" );
    return;
  }
  build_edge();
  build_ans();
  for( int i = 0 ; i < n ; i ++ )
    for( int j = 0 ; j < m ; j ++ )
      printf( "%d%c" , ans[ find_p( pos( i , j ) ) ] , " \n"[ j + 1 == m ] );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}