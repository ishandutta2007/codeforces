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
#define N 505050
void build(){

}
int n , q , s , nn;
vector< pair<int,int> > g[ N ];
int id[ 2 ][ 303030 ];
#define L(X) (X<<1)
#define R(X) (1+(X<<1))
#define mid ((l+r)>>1)
void mark_idx( int dir , int no , int l , int r ){
  id[ dir ][ no ] = ++ nn;
  if( l == r ){
    g[ id[ dir ][ no ] ].push_back( { l , 0 } );
    g[ l ].push_back( { id[ dir ][ no ] , 0 } );
    return;
  }
  mark_idx( dir , L( no ) , l , mid );
  mark_idx( dir , R( no ) , mid + 1 , r );
  if( dir == 0 ){
    g[ id[ dir ][ L( no ) ] ].push_back( { id[ dir ][ no ] , 0 } );
    g[ id[ dir ][ R( no ) ] ].push_back( { id[ dir ][ no ] , 0 } );
  }else{
    g[ id[ dir ][ no ] ].push_back( { id[ dir ][ L( no ) ] , 0 } );
    g[ id[ dir ][ no ] ].push_back( { id[ dir ][ R( no ) ] , 0 } );
  }
}
void add_edge( int dir , int no , int l , int r , int ql , int qr , int to , int dd ){
  if( r < ql or l > qr ) return;
  if( ql <= l and r <= qr ){
    if( dir == 0 )
      g[ id[ dir ][ no ] ].push_back( { to , dd } );
    else
      g[ to ].push_back( { id[ dir ][ no ] , dd } );
    return;
  }
  add_edge( dir , L( no ) , l , mid , ql , qr , to , dd );
  add_edge( dir , R( no ) , mid + 1 , r , ql , qr , to , dd );
}
void init(){
  nn = n = getint();
  q = getint();
  s = getint();
  mark_idx( 0 , 1 , 1 , n );
  mark_idx( 1 , 1 , 1 , n );
  for( int i = 0 ; i < q ; i ++ ){
    int ti = getint();
    if( ti == 1 ){
      int vi = getint();
      int ui = getint();
      int wi = getint();
      g[ vi ].push_back( { ui , wi } );
    }else{
      int vi = getint();
      int li = getint();
      int ri = getint();
      int wi = getint();
      add_edge( 3 - ti , 1 , 1 , n , li , ri , vi , wi );
    }
  }
}
LL dst[ N ];
bool gt[ N ];
void solve(){
  priority_queue< pair<LL,int> ,
          vector< pair<LL,int> > ,
         greater< pair<LL,int> > > heap;
  for( int i = 1 ; i <= nn ; i ++ )
    dst[ i ] = INF16;
  heap.push( { 0 , s } );
  while( heap.size() ){
    auto tp = heap.top(); heap.pop();
    LL dd = tp.first;
    int who = tp.second;
    if( gt[ who ] ) continue;
    gt[ who ] = true;
    dst[ who ] = dd;
    for( auto e : g[ who ] ){
      int nxt = e.first;
      LL td = e.second;
      if( gt[ nxt ] ) continue;
      heap.push( { dd + td , nxt } );
    }
  }
  for( int i = 1 ; i <= n ; i ++ )
    printf( "%lld%c" , dst[ i ] == INF16 ? -1 : dst[ i ] , " \n"[ i == n ] );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}