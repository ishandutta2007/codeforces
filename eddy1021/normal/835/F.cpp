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
#define N 202020
#define L(X) (X<<1)
#define R(X) (1+(X<<1))
#define mid ((l+r)>>1)
LL mx[ N << 3 ] , lft[ N << 3 ] , rgt[ N << 3 ];
void modify( int no , int l , int r , int p , LL tl = INF16 , LL tr = -INF16 ){
  if( l == r ){
    lft[ no ] = tl;
    rgt[ no ] = tr;
    mx[ no ] = 0;
    return;
  }
  if( p <= mid )
    modify( L( no ) , l , mid , p , tl , tr );
  else
    modify( R( no ) , mid + 1 , r , p , tl , tr );
  lft[ no ] = min( lft[ L( no ) ] , lft[ R( no ) ] );
  rgt[ no ] = max( rgt[ L( no ) ] , rgt[ R( no ) ] );
  mx[ no ] = max( max( mx[ L( no ) ] , mx[ R( no ) ] ) ,
                  rgt[ R( no ) ] - lft[ L( no ) ] );
}
void build(){

}
int n , p[ N ] , deg[ N ];
vector< pair<int,int> > v[ N ] , s[ N ];
void init(){
  n = getint();
  for( int i = 0 ; i < n ; i ++ ){
    int ui = getint();
    int vi = getint();
    int li = getint();
    v[ ui ].push_back( { vi , li } );
    v[ vi ].push_back( { ui , li } );
    deg[ ui ] ++;
    deg[ vi ] ++;
  }
}
bool gt[ N ];
vector<int> cycle;
LL dst[ N ] , tot , gg[ N ] , gb;
LL dp( int now ){
  LL tmx = 0;
  for( auto e : s[ now ] ){
    LL ret = dp( e.first ) + e.second;
    gb = max( gb , tmx + ret );
    tmx = max( tmx , ret );
  }
  return tmx;
}
void gogo( int now , LL dd ){
  gt[ now ] = true;
  dst[ now ] = dd;
  cycle.push_back( now );
  for( auto i : v[ now ] ){
    if( gt[ i.first ] ){
      if( dd == 0 and i.first == cycle.back() )
        tot = dst[ i.first ] + i.second;
      continue;
    }
    gogo( i.first , dd + i.second );
  }
}
void solve(){
  queue<int> Q;
  for( int i = 1 ; i <= n ; i ++ )
    if( deg[ i ] == 1 ){
      Q.push( i );
      gt[ i ] = true;
    }
  while( Q.size() ){
    int tn = Q.front(); Q.pop();
    for( auto e : v[ tn ] ){
      if( gt[ e.first ] ) continue;
      p[ tn ] = e.first;
      s[ p[ tn ] ].push_back( { tn , e.second } );
      deg[ e.first ] --;
      if( deg[ e.first ] == 1 ){
        Q.push( e.first );
        gt[ e.first ] = true;
      }
    }
  }
  int who = 0;
  for( int i = 1 ; i <= n and !who ; i ++ )
    if( !p[ i ] )
      who = i;
  gogo( who , 0 );
  for( auto pp : cycle )
    gg[ pp ] = dp( pp );
  int csz = (int)cycle.size();
  for( int i = 0 ; i < csz ; i ++ ){
    int now = cycle[ i ];
    modify( 1 , 0 , csz + csz - 1 , i ,
            dst[ now ] - gg[ now ] , dst[ now ] + gg[ now ] );
    //printf( "%d : dst = %lld, gg=%lld, lft=%lld, rgt%lld\n" ,
            //i , dst[ i ] , gg[ i ] ,
            //dst[ i ] - gg[ i ] , dst[ i ] + gg[ i ] );
  }
  for( int i = csz ; i < csz + csz ; i ++ )
    modify( 1 , 0 , csz + csz - 1 , i );
  LL bst = mx[ 1 ];
  //printf( "%lld\n" , bst );
  for( int i = 0 ; i < csz ; i ++ ){
    int now = cycle[ i ];
    modify( 1 , 0 , csz + csz - 1 , i );
    modify( 1 , 0 , csz + csz - 1 , i + csz ,
            dst[ now ] + tot - gg[ now ] , dst[ now ] + tot + gg[ now ] );
    bst = min( bst , mx[ 1 ] );
    //printf( "%lld\n" , bst );
  }
  printf( "%lld\n" , max( bst , gb ) );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}