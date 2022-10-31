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
void build(){

}
#define N 1021
int n , m , p;
int dp[ N ][ N ] , tg[ N ][ N ] , tmp[ N ][ N ];
vector< PII > v[ N * N ];
void init(){
  n = getint();
  m = getint();
  p = getint();
  for( int i = 1 ; i <= n ; i ++ )
    for( int j = 1 ; j <= m ; j ++ ){
      int a = getint();
      v[ a ].push_back( { i , j } );
    }
}
void solve(){
  for( int i = 1 ; i <= p ; i ++ ){
    for( PII tp : v[ i ] ){
      int bst = INF;
      if( i == 1 ){
        bst = tp.X + tp.Y - 2;
      }else{
        for( int j = 1 ; j <= m ; j ++ )
          if( tg[ tp.X ][ j ] == i - 1 )
            bst = min( bst , dp[ tp.X ][ j ] + abs( j - tp.Y ) );
      }
      tmp[ tp.X ][ tp.Y ] = bst;
      if( i == p ){
        cout << bst << endl;
        exit( 0 );
      }
    }
    for( PII tp : v[ i ] ){
      for( int j = 1 ; j <= n ; j ++ )
        if( tg[ j ][ tp.Y ] != i ||
            ( tg[ j ][ tp.Y ] == i &&
              tmp[ tp.X ][ tp.Y ] + abs( tp.X - j ) < dp[ j ][ tp.Y ] ) ){
          tg[ j ][ tp.Y ] = i;
          dp[ j ][ tp.Y ] = tmp[ tp.X ][ tp.Y ] + abs( tp.X - j );
        }
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