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
int __ = 1 , _cs;
/*********default*********/
#define N 303030
void build(){

}
LL n , t[ N ] , w[ N ];
vector< pair<LL,LL> > vv;
void init(){
  n = getint();
  for( int i = 1 ; i <= n ; i ++ ){
    t[ i ] = getint();
    w[ i ] = getint();
  }
}
void solve(){
  for( int i = 2 ; i <= n ; i ++ )
    vv.push_back( { t[ i ] , w[ i ] } );
  sort( vv.begin() , vv.end() );
  reverse( vv.begin() , vv.end() );
  priority_queue< LL , vector<LL> , greater<LL> > heap;
  size_t ptr = 0;
  while( ptr < vv.size() && vv[ ptr ].first > t[ 1 ] ){
    heap.push( vv[ ptr ].second - vv[ ptr ].first + 1 );
    ptr ++;
  }
  LL ans = (int)heap.size() + 1;
  while( heap.size() && t[ 1 ] ){
    LL nd = heap.top(); heap.pop();
    if( t[ 1 ] < nd ) break;
    t[ 1 ] -= nd;
    while( ptr < vv.size() && vv[ ptr ].first > t[ 1 ] ){
      heap.push( vv[ ptr ].second - vv[ ptr ].first + 1 );
      ptr ++;
    } 
    ans = min( ans , (int)heap.size() + 1ll );
  }
  printf( "%lld\n" , ans );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}