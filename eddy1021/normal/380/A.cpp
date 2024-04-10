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
void build(){

}
LL m , cmd[ N ] , x[ N ] , y[ N ];
LL q , ans[ N ];
vector< PLL > v;
void init(){
  m = getint();
  for( int i = 0 ; i < m ; i ++ ){
    cmd[ i ] = getint();
    x[ i ] = getint();
    if( cmd[ i ] == 2 )
      y[ i ] = getint();
  }
  q = getint();
  for( int i = 0 ; i < q ; i ++ )
    v.push_back( { getint() , i } );
  sort( ALL( v ) );
}
LL vl[ N ];
void solve(){
  size_t ptr = 0;
  LL len = 0;
  for( int i = 0 ; i < m && ptr < v.size() ; i ++ )
    if( cmd[ i ] == 1 ){
      len ++;
      if( len < N ) vl[ len ] = x[ i ];
      while( ptr < v.size() && v[ ptr ].FI <= len )
        ans[ v[ ptr ++ ].SE ] = x[ i ];
    }else{
      LL nlen = len + x[ i ] * y[ i ];
      for( LL k = len + 1 , j = 1 ; k <= min( (LL)N - 1 , nlen ) ; k ++ , j ++ ){
        if( j > x[ i ] ) j = 1;
        vl[ k ] = vl[ j ];
      }
      while( ptr < v.size() && v[ ptr ].FI <= nlen ){
        LL mr = ( v[ ptr ].FI - len ) % x[ i ];
        if( mr == 0 ) mr = x[ i ];
        ans[ v[ ptr ++ ].SE ] = vl[ mr ];
      }
      len = nlen;
    }
  for( int i = 0 ; i < q ; i ++ )
    printf( "%lld%c" , ans[ i ] , " \n"[ i + 1 == q ] );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}