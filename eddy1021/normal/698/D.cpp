// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long double LD;
typedef long long ll;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef pair<LL,LL> Pt;
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
#define M 8
#define N 1010
inline Pt operator-( const Pt& p1 , const Pt& p2 ){
  return { p1.X - p2.X , p1.Y - p2.Y };
}
inline LL operator*( const Pt& p1 , const Pt& p2 ){
  return p1.X * p2.X + p1.Y * p2.Y;
}
inline LL operator^( const Pt& p1 , const Pt& p2 ){
  return p1.X * p2.Y - p1.Y * p2.X;
}
inline LL norm2( const Pt& tp ){
  return tp * tp;
}
void build(){

}
int k , n;
Pt a[ M ] , p[ N ];
void scan( Pt& tp ){
  tp.X = getint();
  tp.Y = getint();
}
vector< pair<Pt,int> > v[ M ];
int reg( const Pt& tp ){
  assert( tp.X != 0 || tp.Y != 0 );
  return tp.Y > 0 || ( tp.Y == 0 && tp.X >= 0 ); 
}
inline bool same_dir( const Pt& p1 , const Pt& p2 ){
  return ( p1 * p2 ) > 0 && ( p1 ^ p2 ) == 0;
}
bool cmp( const pair<Pt,int>& p1 , const pair<Pt,int>& p2 ){
  if( reg( p1.FI ) != reg( p2.FI ) )
    return reg( p1.FI ) < reg( p2.FI );
  LL ret = p1.FI ^ p2.FI;
  if( ret != 0 ) return ret > 0;
  return norm2( p1.FI ) < norm2( p2.FI );
}
int pos[ M ][ N ] , st[ M ][ N ];
void init(){
  k = getint(); n = getint();
  for( int i = 0 ; i < k ; i ++ ) scan( a[ i ] );
  for( int i = 0 ; i < n ; i ++ ) scan( p[ i ] );
  for( int i = 0 ; i < k ; i ++ ){
    for( int j = 0 ; j < n ; j ++ )
      v[ i ].push_back( { p[ j ] - a[ i ] , j } );
    sort( ALL( v[ i ] ) , cmp );
    pos[ i ][ v[ i ][ 0 ].SE ] = 0;
    st[ i ][ v[ i ][ 0 ].SE ] = 0;
    for( int j = 1 ; j < n ; j ++ ){
      pos[ i ][ v[ i ][ j ].SE ] = j;
      if( same_dir( v[ i ][ j ].FI , v[ i ][ j - 1 ].FI ) )
        st[ i ][ v[ i ][ j ].SE ] = st[ i ][ v[ i ][ j - 1 ].SE ];
      else
        st[ i ][ v[ i ][ j ].SE ] = j;
    }
  }
}
vector< int > per;
bool bye[ N ] , inq[ N ];
inline void cal(){
  for( int i = 0 ; i < n ; i ++ ){
    vector< int > target;
    int ptr = 0; target.push_back( i );
    inq[ i ] = true;
    for( int j = 0 ; j < k && ptr < (int)target.size() ; j ++ ){
      if( k - j < (int)target.size() - ptr ) break;
      int tar = target[ ptr ++ ] , now = per[ j ];
      for( int u = st[ now ][ tar ] ; u < pos[ now ][ tar ] ; u ++ ){
        int tmp = v[ now ][ u ].SE;
        if( inq[ tmp ] ) continue;
        inq[ tmp ] = true; target.push_back( tmp );
        if( (int)target.size() - ptr > k - j - 1 ) break;
      }
    }
    if( ptr == (int)target.size() ) bye[ i ] = true;
    for( int tmp : target ) inq[ tmp ] = false;
  }
}
void solve(){
  for( int i = 0 ; i < k ; i ++ ) per.push_back( i );
  do cal(); while( next_permutation( ALL( per ) ) );
  int ans = 0;
  for( int i = 0 ; i < n ; i ++ ) if( bye[ i ] ) ans ++;
  printf( "%d\n" , ans );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}