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
// #define X FI
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
#define X 10
#define M 6
void build(){

}
int ml[]={1,2,4,8};
int n;
string trans( int x ){
  string ss = "0";
  ss[ 0 ] = (char)( x );
  return ss;
}
inline string lea( int aa , int bb , int cc , int kk ){
  return "lea e" + trans( aa + 'a' ) + "x, [e" +
                   trans( bb + 'a' ) + "x + " + trans( ml[ kk ] + '0' ) + "*e" +
                   trans( cc + 'a' ) + "x]";
}
void init(){
  n = getint();
}
vector<string> ans , cur;
int bst = M , r[ X ];
bool got , tag[ 10000 ];
void go( int now , int mx ){
  if( now >= bst || mx > n || got ) return;
  if( mx == n ){
    got = true;
    ans = cur;
    bst = now;
    ans.resize( bst );
    return;
  }
  // if( now + 1 >= bst ) return;
  for( int i = 0 ; i <= now ; i ++ ){
    for( int k = 3 ; k >= 0 ; k -- ){
      r[ now + 1 ] = ml[ k ] * r[ i ];
      if( tag[ r[ now + 1 ] ] ) continue;
      tag[ r[ now + 1 ] ] = true;
      cur[ now ] = lea( now + 1 , X , i , k );
      if( r[ now + 1 ] > mx )
        go( now + 1 , r[ now + 1 ] );
      tag[ r[ now + 1 ] ] = false;
      if( bst == now + 1 || got ) return;
    }
    for( int j = 0 ; j <= now ; j ++ )
      for( int k = 3 ; k >= 0 ; k -- ){
        r[ now + 1 ] = r[ i ] + ml[ k ] * r[ j ];
        if( tag[ r[ now + 1 ] ] ) continue;
        tag[ r[ now + 1 ] ] = true;
        cur[ now ] = lea( now + 1 , i , j , k );
        if( r[ now + 1 ] > mx )
          go( now + 1 , r[ now + 1 ] );
        tag[ r[ now + 1 ] ] = false;
        if( bst == now + 1 || got ) return;
      }
  }
}
void solve(){
  cur.resize( M );
  for( bst = 2 ; ; bst ++ ){
    r[ 0 ] = 1;
    for( int i = 1 ; i < X ; i ++ ) r[ i ] = 0;
    tag[ 0 ] = true;
    tag[ 1 ] = true;
    go( 0 , 1 );
    if( got ){
      printf( "%d\n" , (int)ans.size() );
      for( size_t i = 0 ; i < ans.size() ; i ++ )
        cout << ans[ i ] << endl;
      exit( 0 );
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