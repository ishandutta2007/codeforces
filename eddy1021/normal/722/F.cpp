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
#define K 41
vector<int> fac[ K ];
void build(){
  for( int i = 1 ; i < K ; i ++ )
    for( int j = 1 ; j <= i ; j ++ )
      if( i % j == 0 )
        fac[ i ].push_back( j );
}
int n , m , ans[ N ];
vector< pair<int, pair<int,int> > > v[ N ];
void init(){
  n = getint();
  m = getint();
  for( int i = 1 ; i <= n ; i ++ ){
    int ki = getint();
    for( int j = 0 ; j < ki ; j ++ ){
      int vi = getint();
      v[ vi ].push_back( { i , { ki , j } } );
    }
  }
}
int cnt[ K ] , pos[ K ];
inline bool conf( int pi , int vi ){
  for( int i : fac[ pi ] )
    if( cnt[ i ] && pos[ i ] != vi % i )
      return true;
  return false;
}
void add( int pi , int vi ){
  for( int i : fac[ pi ] ){
    cnt[ i ] ++;
    pos[ i ] = vi % i;
  }
}
void sub( int pi , int vi ){
  for( int i : fac[ pi ] )
    cnt[ i ] --;
}
void cal( int now ){
  for( size_t l = 0 , r = 0 ; l < v[ now ].size() ; l = r ){
    r ++;
    while( r < v[ now ].size() &&
            v[ now ][ r ].first == v[ now ][ r - 1 ].first + 1 )
      r ++;
    // printf( "%d\n" , now );
    // for( size_t i = l ; i < r ; i ++ )
      // printf( "%d %d %d\n" , v[ now ][ i ].first , 
          // v[ now ][ i ].SE.FI , v[ now ][ i ].SE.SE );
    for( int i = 0 ; i < K ; i ++ )
      cnt[ i ] = 0;
    for( size_t pr = l , pl = l ; pr < r ; pr ++ ){
      while( conf( v[ now ][ pr ].second.first ,
                   v[ now ][ pr ].second.second ) ){
        sub( v[ now ][ pl ].second.first ,
             v[ now ][ pl ].second.second );
        pl ++;
      }
      add( v[ now ][ pr ].second.first ,
           v[ now ][ pr ].second.second );
      ans[ now ] = max( ans[ now ] , (int)(pr - pl + 1) );
    }
  }
}
void solve(){
  for( int i = 1 ; i <= m ; i ++ )
    cal( i );
  for( int i = 1 ; i <= m ; i ++ )
    printf( "%d\n" , ans[ i ] );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}