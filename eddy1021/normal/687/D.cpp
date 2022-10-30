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
void build(){

}
int n , m , q , p[ N * 2 ];
int find_p( int x ){ return x == p[ x ] ? x : p[ x ] = find_p( p[ x ] ); }
void Union( int x , int y ){ p[ find_p( x ) ] = find_p( y ); }
vector< pair< PII , PII > > v;
void init(){
  n = getint();
  m = getint();
  q = getint();
  for( int i = 1 ; i <= m ; i ++ ){
    int ui = getint();
    int vi = getint();
    int wi = getint();
    v.push_back( { { wi , i } , { ui , vi } } );
  }
  sort( ALL( v ) );
  reverse( ALL( v ) );
}
void solve(){
  while( q -- ){
    int li = getint();
    int ri = getint();
    int ans = -1;
    for( int i = 1 ; i <= n + n ; i ++ ) p[ i ] = i;
    for( size_t i = 0 ; i < v.size() ; i ++ ){
      if( v[ i ].FI.SE < li || v[ i ].FI.SE > ri ) continue;
      int ui = v[ i ].SE.FI , vi = v[ i ].SE.SE;
      if( find_p( ui ) == find_p( vi ) ){
        ans = v[ i ].FI.FI;
        break;
      }
      Union( ui , vi + n );
      Union( vi , ui + n );
    }
    printf( "%d\n" , ans );
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