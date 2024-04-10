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
#define N 7777
int l[ 1010101 ];
int r[ 1010101 ];
void build(){
  int cnt = 0;
  for( int i = 1 ; i < 1010101 ; i ++ ){
    l[ i ] = r[ i ] = ++ cnt;
    if( i == ( i & (-i) ) ) r[ i ] = ++ cnt;
  }
}
int tag[ 1010101 ] , stmp;
int n , m;
vector< tuple< int , int , int > > v[ N ];
void init(){
  n = getint(); m = getint();
}
void solve(){
  while( m -- ){
    int cmd = getint();
    if( cmd == 1 ){
      int t = getint();
      int ql = getint();
      int qr = getint();
      int qx = getint();
      v[ t ].push_back( MT( ql , qr , qx ) );
    }else{
      int t = getint();
      int ql = getint();
      int qr = ql;
      int ans = 0; stmp ++;
      for( int i = t ; i <= n ; i ++ ){
        for( auto tp : v[ i ] ){
          if( max( ql , get<0>( tp ) ) <= min( qr , get<1>( tp ) ) ){
            if( tag[ get<2>( tp ) ] != stmp ){
              tag[ get<2>( tp ) ] = stmp;
              ans ++;
            }
          }
        }
        ql = l[ ql ];
        qr = r[ qr ];
      }
      printf( "%d\n" , ans );
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