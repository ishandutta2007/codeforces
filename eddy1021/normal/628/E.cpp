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
#define N 3030
int st[ N << 2 ];
#define L(X) (X<<1)
#define R(X) (1+(X<<1))
#define mid ((l+r)>>1)
void modify( int no , int l , int r , int p , int dlt ){
  if( l == r ){
    st[ no ] += dlt;
    return;
  }
  if( p <= mid ) modify( L( no ) , l , mid , p , dlt );
  else modify( R( no ) , mid + 1 , r , p , dlt );
  st[ no ] = st[ L( no ) ] + st[ R( no ) ];
}
int query( int no , int l , int r , int ql , int qr ){
  if( l == ql && r == qr ) return st[ no ];
  if( qr <= mid ) return query( L( no ) , l , mid , ql , qr );
  if( mid < ql ) return query( R( no ) , mid + 1 , r , ql , qr );
  return query( L( no ) , l , mid , ql , mid ) +
         query( R( no ) , mid + 1 , r , mid + 1 , qr );
}
void build(){

}
int n , m;
char c[ N ][ N ];
int dpl[ N ][ N ] , dpr[ N ][ N ];
void init(){
  n = getint();
  m = getint();
  for( int i = 1 ; i <= n ; i ++ )
    scanf( "%s" , c[ i ] + 1 );
}
set<PII> S;
typedef set<PII>::iterator si;
void Clear(){
  for( si it = S.begin() ; it != S.end() ; it ++ )
    modify( 1 , 1 , m , it->SE , -1 );
  S.clear();
}
ll ans;
void solve(){
  for( int i = 1 ; i <= n ; i ++ ){
    for( int j = 1 ; j <= m ; j ++ )
      if( c[ i ][ j ] == 'z' ){
        ans ++;
        dpl[ i ][ j ] = dpl[ i ][ j - 1 ] + 1;
      }
    for( int j = m ; j >= 1 ; j -- )
      if( c[ i ][ j ] == 'z' )
        dpr[ i ][ j ] = dpr[ i ][ j + 1 ] + 1;
  }
  for( int ss = 3 ; ss <= n + m - 1 ; ss ++ ){
    for( int i = max( 1 , ss - m ) ; i <= min( n , ss - 1 ) ; i ++ ){
      int j = ss - i;
      if( c[ i ][ j ] == '.' ){
        Clear();
        continue;
      }
      while( S.size() && (*--S.end()).FI > j ){
        modify( 1 , 1 , m , (*--S.end()).SE , -1 );
        S.erase( --S.end() );
      }
      ans += query( 1 , 1 , m , j , j + dpr[ i ][ j ] - 1 );
      S.insert( MP( j - dpl[ i ][ j ] + 1 , j ) );
      modify( 1 , 1 , m , j , 1 );
    }
    Clear();
  }
  cout << ans << endl;
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}