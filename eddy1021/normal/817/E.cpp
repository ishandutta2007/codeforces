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
#define Bye exit(0)
int __ = 1 , _cs;
/*********default*********/
struct Trie{
  Trie *zer , *one;
  int cnt;
  Trie(){
    zer = one = NULL;
    cnt = 0;
  }
};
int Cnt( Trie* tn ){
  return tn ? tn->cnt : 0;
}
void modify( Trie* now , int bt , int vl , int dlt ){
  now->cnt += dlt;
  if( bt < 0 ) return;
  if( (vl >> bt) & 1 ){
    if( !now->one ) now->one = new Trie();
    modify( now->one , bt - 1 , vl , dlt );
  }else{
    if( !now->zer ) now->zer = new Trie();
    modify( now->zer , bt - 1 , vl , dlt );
  }
}
int query( Trie* now , int bt , int pi , int li ){
  if( !now or bt < 0 ) return 0;
  if( (pi >> bt) & 1 ){
    if( (li >> bt) & 1 )
      return Cnt( now->one ) + query( now->zer , bt - 1 , pi , li );
    else
      return query( now->one , bt - 1 , pi , li );
  }else{
    if( (li >> bt) & 1 )
      return Cnt( now->zer ) + query( now->one , bt - 1 , pi , li );
    else
      return query( now->zer , bt - 1 , pi , li );
  }
}
void build(){

}
Trie *root;
int q;
void init(){
  q = getint();
}
void solve(){
  root = new Trie();
  while( q -- ){
    int cmd = getint();
    if( cmd <= 2 )
      modify( root , 30 , getint() , cmd == 1 ? 1 : -1 );
    else{
      int pi = getint();
      int li = getint();
      printf( "%d\n" , query( root , 30 , pi , li ) );
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