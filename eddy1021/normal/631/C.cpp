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
ll mypow( ll _a , ll _x , ll _mod ){
  if( _x == 0 ) return 1ll;
  ll _tmp = mypow( _a , _x / 2 , _mod );
  _tmp = ( _tmp * _tmp ) % _mod;
  if( _x & 1 ) _tmp = ( _tmp * _a ) % _mod;
  return _tmp;
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
inline bool equal( D _x ,  D _y ){
  return _x > _y - eps && _x < _y + eps;
}
int __ = 1 , _cs;
/*********default*********/
#define N 202020
int n , m , a[ N ];
vector<PII> v;
void build(){

}
bool cmp( int ii , int jj ){
  return ii > jj;
}
void init(){
  n = getint(); m = getint();
  for( int i = 0 ; i < n ; i ++ )
    a[ i ] = getint();
  while( m -- ){
    int ti = getint();
    int ri = getint();
    v.PB( MP( ti , ri ) );
  }
  int sz = 0;
  for( size_t i = 0 ; i < v.size() ; i ++ ){
    while( sz > 0 && v[ i ].SE >= v[ sz - 1 ].SE ) sz --;
    v[ sz ++ ] = v[ i ];
  }
  v.resize( sz );
}
void solve(){
  if( v[ 0 ].FI == 1 ) sort( a , a + v[ 0 ].SE );
  else sort( a , a + v[ 0 ].SE , cmp );
  int ori = v[ 0 ].FI;
  int ord = v[ 0 ].FI , pre = v[ 0 ].SE;
  int l = 0 , r = v[ 0 ].SE - 1;
  vector< PII > ans;
  if( r != n - 1 ) ans.PB( MP( r + 1 , n - 1 ) );
  for( size_t i = 1 ; i < v.size() ; i ++ ){
    if( v[ i ].FI == ord ) continue;
    int dlt = pre - v[ i ].SE;
    if( v[ i ].FI == ori ){
      ans.PB( MP( l + dlt - 1 , l ) );
      l += dlt;
    }else{
      ans.PB( MP( r - dlt + 1 , r ) );
      r -= dlt;
    }
    ord = v[ i ].FI;
    pre = v[ i ].SE;
  }
  if( ord == ori )
    ans.PB( MP( min( l , r ) , max( l , r ) ) );
  else
    ans.PB( MP( max( l , r ) , min( l , r ) ) );
  for( int i = (int)ans.size() - 1 ; i >= 0 ; i -- ){
    if( ans[ i ].FI <= ans[ i ].SE ){
      for( int j = ans[ i ].FI ; j <= ans[ i ].SE ; j ++ )
        printf( "%d " , a[ j ] );
    }else{
      for( int j = ans[ i ].FI ; j >= ans[ i ].SE ; j -- )
        printf( "%d " , a[ j ] );
    }
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