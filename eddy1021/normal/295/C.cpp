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
#define N 55
int C[ N ][ N ];
void build(){
  for( int i = 0 ; i < N ; i ++ )
    C[ i ][ 0 ] = C[ i ][ i ] = 1;
  for( int i = 2 ; i < N ; i ++ )
    for( int j = 1 ; j < i ; j ++ )
      C[ i ][ j ] = add( C[ i - 1 ][ j ], C[ i - 1 ][ j - 1 ] );
}
int n , k , cnt[ 2 ];
void init(){
  n = getint();
  k = getint() / 50;
  for( int i = 0 ; i < n ; i ++ )
    cnt[ getint() / 50 - 1 ] ++;
}
PII dp[ N ][ N ][ 2 ];
queue< tuple< int , int , int > > Q;
inline void go(){
  dp[ cnt[ 0 ] ][ cnt[ 1 ] ][ 0 ] = { 0 , 1 };
  Q.push( MT( cnt[ 0 ] , cnt[ 1 ] , 0 ) );
  while( Q.size() ){
    tiii tp = Q.front(); Q.pop();
    int c0 = get<0>( tp );
    int c1 = get<1>( tp );
    int sd = get<2>( tp );
    if( sd == 0 ){
      for( int i = 0 ; i <= c0 ; i ++ )
        for( int j = 0 ; j <= c1 ; j ++ ){
          if( i + j == 0 ) continue;
          if( i + 2 * j > k ) break;
          int dlt = mul( dp[ c0 ][ c1 ][ sd ].SE , mul( C[ c0 ][ i ] , C[ c1 ][ j ] ) );
          if( dp[ c0 - i ][ c1 - j ][ 1 - sd ].FI == -1 ){
            dp[ c0 - i ][ c1 - j ][ 1 - sd ] = { dp[ c0 ][ c1 ][ sd ].FI + 1 , dlt };
            Q.push( MT( c0 - i , c1 - j , 1 - sd ) );
          }else if( dp[ c0 - i ][ c1 - j ][ 1 - sd ].FI == dp[ c0 ][ c1 ][ sd ].FI + 1 ){
            dp[ c0 - i ][ c1 - j ][ 1 - sd ].SE = add( dp[ c0 - i ][ c1 - j ][ 1 - sd ].SE , dlt );
          }
        }
    }else{
      for( int i = 0 ; i <= cnt[ 0 ] - c0 ; i ++ )
        for( int j = 0 ; j <= cnt[ 1 ] - c1 ; j ++ ){
          if( i + j == 0 ) continue;
          if( i + 2 * j > k ) break;
          int dlt = mul( dp[ c0 ][ c1 ][ sd ].SE , mul( C[ cnt[ 0 ] - c0 ][ i ] , C[ cnt[ 1 ] - c1 ][ j ] ) );
          if( dp[ c0 + i ][ c1 + j ][ 1 - sd ].FI == -1 ){
            dp[ c0 + i ][ c1 + j ][ 1 - sd ] = { dp[ c0 ][ c1 ][ sd ].FI + 1 , dlt };
            Q.push( MT( c0 + i , c1 + j , 1 - sd ) );
          }else if( dp[ c0 + i ][ c1 + j ][ 1 - sd ].FI == dp[ c0 ][ c1 ][ sd ].FI + 1 ){
            dp[ c0 + i ][ c1 + j ][ 1 - sd ].SE = add( dp[ c0 + i ][ c1 + j ][ 1 - sd ].SE , dlt );
          }
        }
    }
  }
}
void solve(){
  for( int i = 0 ; i <= cnt[ 0 ] ; i ++ )
    for( int j = 0 ; j <= cnt[ 1 ] ; j ++ )
      dp[ i ][ j ][ 0 ] = dp[ i ][ j ][ 1 ] = { -1 , 0 };
  go();
  printf( "%d\n%d\n" , dp[ 0 ][ 0 ][ 1 ].FI , dp[ 0 ][ 0 ][ 1 ].SE );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}