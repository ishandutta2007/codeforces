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
int n;
char c[ N ][ N ];
int con[ N ][ N ][ 8 ];
int cnt2[ N ][ N ][ 8 ];
int cnt3[ N ][ N ][ 8 ];
int dx[]={0,-1,-1,-1,0,1,1,1};
int dy[]={-1,-1,0,1,1,1,0,-1};
inline PII cross( int st , int xi , int yi ){
  int mn = N;
  int c2 = 0 , c3 = 0;
  for( int i = st ; i < 8 ; i += 2 )
    mn = min( mn , con[ xi ][ yi ][ i ] );
  for( int i = st ; i < 8 ; i += 2 ){
    c2 += cnt2[ xi ][ yi ][ i ] - cnt2[ xi + mn * dx[ i ] ][ yi + mn * dy[ i ] ][ i ];
    c3 += cnt3[ xi ][ yi ][ i ] - cnt3[ xi + mn * dx[ i ] ][ yi + mn * dy[ i ] ][ i ];
  }
  if( c[ xi ][ yi ] == '2' ) c2 -= 3;
  if( c[ xi ][ yi ] == '3' ) c3 -= 3;
  return { c2 , c3 };
}
void init(){
  n = getint();
  for( int i = 1 ; i <= n ; i ++ )
    scanf( "%s" , c[ i ] + 1 );
  for( int i = 1 ; i <= n ; i ++ )
    for( int j = 1 ; j <= n ; j ++ )
      for( int k = 0 ; k < 4 ; k ++ ){
        if( c[ i ][ j ] == '0' )
          con[ i ][ j ][ k ] = 0;
        else
          con[ i ][ j ][ k ] = 1 + con[ i + dx[ k ] ][ j + dy[ k ] ][ k ];
        cnt2[ i ][ j ][ k ] = cnt2[ i + dx[ k ] ][ j + dy[ k ] ][ k ];
        cnt3[ i ][ j ][ k ] = cnt3[ i + dx[ k ] ][ j + dy[ k ] ][ k ];
        if( c[ i ][ j ] == '2' ) cnt2[ i ][ j ][ k ] ++;
        if( c[ i ][ j ] == '3' ) cnt3[ i ][ j ][ k ] ++;
      }
  for( int i = n ; i >= 1 ; i -- )
    for( int j = n ; j >= 1 ; j -- )
      for( int k = 4 ; k < 8 ; k ++ ){
        if( c[ i ][ j ] == '0' )
          con[ i ][ j ][ k ] = 0;
        else
          con[ i ][ j ][ k ] = 1 + con[ i + dx[ k ] ][ j + dy[ k ] ][ k ];
        cnt2[ i ][ j ][ k ] = cnt2[ i + dx[ k ] ][ j + dy[ k ] ][ k ];
        cnt3[ i ][ j ][ k ] = cnt3[ i + dx[ k ] ][ j + dy[ k ] ][ k ];
        if( c[ i ][ j ] == '2' ) cnt2[ i ][ j ][ k ] ++;
        if( c[ i ][ j ] == '3' ) cnt3[ i ][ j ][ k ] ++;
      }
}
void solve(){
  LD l2 = logl( 2.0 ) , l3 = logl( 3.0 );
  LD ans = -1; int bst2 = 0 , bst3 = 0;
  for( int i = 1 ; i <= n ; i ++ )
    for( int j = 1 ; j <= n ; j ++ ){
      if( c[ i ][ j ] == '0' ) continue;
      for( int k = 0 ; k < 2 ; k ++ ){
        PII tp = cross( k , i , j );
        LD tans = tp.FI * l2 + tp.SE * l3;
        if( tans > ans ){
          ans = tans;
          bst2 = tp.FI;
          bst3 = tp.SE;
        }
      }
    }
  if( ans < -0.5 ){
    puts( "0" );
  }else{
    LL aa = 1;
    for( int i = 0 ; i < bst2 ; i ++ )
      aa = mul( aa , 2 );
    for( int i = 0 ; i < bst3 ; i ++ )
      aa = mul( aa , 3 );
    cout << aa << endl;
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