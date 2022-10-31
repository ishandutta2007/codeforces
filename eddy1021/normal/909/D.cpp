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
#define N (1 << 20)
void build(){

}
char c[ N ];
int n;
void init(){
  scanf( "%s" , c + 1 );
  n = strlen( c + 1 );
}
int l[ N ] , r[ N ];
bool dead[ N ];
vector<int> cand;
int ans;
void kill( int id ){
  //cerr << ans << " " << id << endl;
  int lft = l[ id ] , rgt = r[ id ];
  r[ lft ] = rgt;
  l[ rgt ] = lft;
}
bool gg( int id ){
  if( l[ id ] >= 1 and c[ id ] != c[ l[ id ] ] )
    return true;
  if( r[ id ] <= n and c[ id ] != c[ r[ id ] ] )
    return true;
  return false;
}
void solve(){
  for( int i = 1 ; i <= n ; i ++ )
    l[ i ] = i - 1 , r[ i ] = i + 1;
  for( int i = 1 ; i <= n ; i ++ )
    if( gg( i ) )
      cand.push_back( i );
  while( not cand.empty() ){
    ans ++;
    vector<int> nxt_cand , wt_kill;
    for( int j : cand ){
      if( dead[ j ] ) continue;
      dead[ j ] = true;
      wt_kill.push_back( j );
      nxt_cand.push_back( l[ j ] );
      nxt_cand.push_back( r[ j ] );
    }
    for( int j : wt_kill )
      kill( j );
    size_t nsz = 0;
    for( size_t j = 0 ; j < nxt_cand.size() ; j ++ ){
      int now = nxt_cand[ j ];
      if( now < 1 or now > n or dead[ now ] ) continue;
      if( gg( now ) )
        nxt_cand[ nsz ++ ] = now;
    }
    nxt_cand.resize( nsz );
    cand.swap( nxt_cand );
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