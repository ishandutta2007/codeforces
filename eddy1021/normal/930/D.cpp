// eddy1021
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long double LD;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
#define mod9 1000000009LL
#define mod7 1000000007LL
#define INF  1023456789LL
#define INF16 10000000000000000LL
#define eps 1e-9
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#ifndef ONLINE_JUDGE
#define debug(...) printf(__VA_ARGS__)
#else 
#define debug(...)
#endif
inline LL getint(){
  LL _x=0,_tmp=1; char _tc=getchar();    
  while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
  if( _tc == '-' ) _tc=getchar() , _tmp = -1;
  while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
  return _x*_tmp;
}
inline LL add( LL _x , LL _y , LL _mod = mod7 ){
  _x += _y;
  return _x >= _mod ? _x - _mod : _x;
}
inline LL sub( LL _x , LL _y , LL _mod = mod7 ){
  _x -= _y;
  return _x < 0 ? _x + _mod : _x;
}
inline LL mul( LL _x , LL _y , LL _mod = mod7 ){
  _x *= _y;
  return _x >= _mod ? _x % _mod : _x;
}
LL mypow( LL _a , LL _x , LL _mod ){
  if( _x == 0 ) return 1LL;
  LL _ret = mypow( mul( _a , _a , _mod ) , _x >> 1 , _mod );
  if( _x & 1 ) _ret = mul( _ret , _a , _mod );
  return _ret;
}
LL mymul( LL _a , LL _x , LL _mod ){
  if( _x == 0 ) return 0LL;
  LL _ret = mymul( add( _a , _a , _mod ) , _x >> 1 , _mod );
  if( _x & 1 ) _ret = add( _ret , _a , _mod );
  return _ret;
}
inline bool equal( D _x ,  D _y ){
  return _x > _y - eps && _x < _y + eps;
}
void sleep( double sec = 1021 ){
  clock_t s = clock();
  while( clock() - s < CLOCKS_PER_SEC * sec );
}
#define Bye exit(0)
int __ = 1 , _cs;
/*********default*********/
#define N 101010
void build(){

}
LL n , ans;
vector< pair<LL,LL> > v[ 2 ];
void init(){
  n = getint();
  for( int i = 0 ; i < n ; i ++ ){
    LL xi = getint();
    LL yi = getint();
    v[ abs(xi + yi) & 1 ].push_back( {xi, yi} );
  }
}
inline LL magic( const pair<LL,LL>& pp ){
  return pp.first + pp.second;
}
inline LL secret( const pair<LL,LL>& pp ){
  return pp.first - pp.second;
}
bool cmp( pair<LL,LL> p1 , pair<LL,LL> p2 ){
  return magic( p1 ) < magic( p2 );
}
LL _ub[ N * 6 ] , _lb[ N * 6 ];
LL *ub, *lb;
LL _ub2[ N * 6 ] , _lb2[ N * 6 ];
LL *ub2, *lb2;
const LL inf = 1e8;
void cal( vector<pair<LL,LL>>& cand ){
  if( cand.size() < 4u ) return;
  sort( cand.begin() , cand.end() , cmp );
  for( LL i = magic( cand[ 0 ] ) ; i <= magic( cand.back() ) ; i ++ ){
    lb[ i ] = + inf;
    ub[ i ] = - inf;
    lb2[ i ] = + inf;
    ub2[ i ] = - inf;
  }
  {
    LL clb = + inf , crb = - inf;
    LL pre = magic( cand[ 0 ] );
    for( size_t l = 0 , r = 0 ; l < cand.size() ; l = r ){
      while( r < cand.size() and magic( cand[ l ] ) == magic( cand[ r ] ) ) r ++;
      for( LL ii = pre + 1 ; ii < magic( cand[ l ] ) ; ii ++ ){
        ub[ ii ] = crb;
        lb[ ii ] = clb;
      }
      for( size_t i = l ; i < r ; i ++ ){
        clb = min( clb , secret( cand[ i ] ) );
        crb = max( crb , secret( cand[ i ] ) );
      }
      pre = magic( cand[ l ] );
      ub[ pre ] = crb;
      lb[ pre ] = clb;
    }
    reverse( cand.begin() , cand.end() );
  }
  {
    LL clb = + inf , crb = - inf;
    LL pre = magic( cand[ 0 ] );
    for( size_t l = 0 , r = 0 ; l < cand.size() ; l = r ){
      while( r < cand.size() and magic( cand[ l ] ) == magic( cand[ r ] ) ) r ++;
      for( LL ii = pre - 1 ; ii > magic( cand[ l ] ) ; ii -- ){
        ub2[ ii ] = crb;
        lb2[ ii ] = clb;
      }
      for( size_t i = l ; i < r ; i ++ ){
        clb = min( clb , secret( cand[ i ] ) );
        crb = max( crb , secret( cand[ i ] ) );
      }
      pre = magic( cand[ l ] );
      ub2[ pre ] = crb;
      lb2[ pre ] = clb;
    }
    reverse( cand.begin() , cand.end() );
  }
  for( LL i = magic( cand[ 0 ] ) + 1 ; i <= magic( cand.back() ) ; i += 2 ){
    LL gl = max( lb[ i - 1 ] , lb2[ i + 1 ] );
    LL gr = min( ub[ i - 1 ] , ub2[ i + 1 ] );
    if( gl > gr ) continue;
    ans += (gr - gl) / 2;
  }
}
void solve(){
  ub = _ub + (N * 3);
  lb = _lb + (N * 3);
  ub2 = _ub2 + (N * 3);
  lb2 = _lb2 + (N * 3);
  cal( v[ 0 ] );
  cal( v[ 1 ] );
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