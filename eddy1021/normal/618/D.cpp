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
#define N 222222
ll n , x , y;
vector<int> v[ N ];
void build(){

}
void init(){
  n = getint();
  x = getint();
  y = getint();
  for( int i = 1 ; i < n ; i ++ ){
    int tx = getint();
    int ty = getint();
    v[ tx ].PB( ty );
    v[ ty ].PB( tx );
  }
}
int dp[ N ][ 3 ];
void DP( int now , int prt ){
  int bst = 0;
  for( size_t i = 0 ; i < v[ now ].size() ; i ++ ){
    int son = v[ now ][ i ];
    if( son != prt ){
      DP( son , now );
      bst += max( dp[ son ][ 0 ] , max( dp[ son ][ 1 ] ,
                                        dp[ son ][ 2 ] ) );
    }
  }
  dp[ now ][ 0 ] = bst;
  dp[ now ][ 1 ] = 0;
  dp[ now ][ 2 ] = 0;
  int got = 0 , good[ 3 ];
  for( size_t i = 0 ; i < v[ now ].size() ; i ++ ){
    int son = v[ now ][ i ];
    if( son != prt ){
      int tbst = bst - max( dp[ son ][ 0 ] , max( dp[ son ][ 1 ] ,
                                                  dp[ son ][ 2 ] ) );
      tbst += max( dp[ son ][ 0 ] , dp[ son ][ 1 ] ) + 1;
      dp[ now ][ 1 ] = max( dp[ now ][ 1 ] , tbst );
      int dlt = max( dp[ son ][ 0 ] , dp[ son ][ 1 ] ) -
                max( dp[ son ][ 0 ] , max( dp[ son ][ 1 ] ,
                                           dp[ son ][ 2 ] ) );
      good[ got ++ ] = dlt;
      for( int j = 0 ; j < got ; j ++ )
        for( int k = j + 1 ; k < got ; k ++ )
          if( good[ k ] > good[ j ] )
            swap( good[ k ] , good[ j ] );
      got = min( got , 2 );
    }
  }
  if( got > 1 ) dp[ now ][ 2 ] = bst + good[ 0 ] + good[ 1 ] + 2;
}
void solve2(){
  DP( 1 , -1 );
  ll ans = max( dp[ 1 ][ 0 ] , max( dp[ 1 ][ 1 ] , 
                                    dp[ 1 ][ 2 ] ) );
  printf( "%lld\n" , ( n - 1 ) * y - ans * ( y - x ) );
}
void solve(){
  if( x == y ){
    printf( "%lld\n" , ( n - 1 ) * x );
    return;
  }else if( x < y ) solve2();
  else{
    bool flag = true;
    for( int i = 1 ; i <= n ; i ++ )
      if( (int)v[ i ].size() == n - 1 ){
        flag = false;
        break;
      }
    ll ans = ( n - 1 ) * y;
    if( !flag ) ans += x - y;
    printf( "%lld\n" , ans );
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