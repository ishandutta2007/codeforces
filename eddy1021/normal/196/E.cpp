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
#define N 101010
int p[ N ];
int f( int x ){
  return x == p[ x ] ? x : p[ x ] = f( p[ x ] );
}
bool uni( int x , int y ){
  x = f( x ); y = f( y );
  if( x == y ) return false;
  p[ x ] = y;
  return true;
}
void build(){

}
int n , m , pp;
LL ans;
vector< pair<int,int> > v[ N ];
bool isp[ N ];
vector<int> pr;
void init(){
  n = getint();
  m = getint(); while( m -- ){
    int ui = getint();
    int vi = getint();
    int di = getint();
    v[ ui ].push_back( { vi , di } );
    v[ vi ].push_back( { ui , di } );
  }
  pp = getint();
  for( int i = 0 ; i < pp ; i ++ ){
    int x = getint();
    pr.push_back( x );
    isp[ x ] = true;
  }
  for( int i = 1 ; i <= n ; i ++ )
    p[ i ] = i;
}
unordered_set< int > tag[ N ];
int gt[ N ];
LL gd[ N ];
void solve(){
typedef tuple<LL,int,int> data;
  priority_queue< data , vector<data> , greater<data> > heap;
  for( auto i : pr )
    heap.push( make_tuple( 0 , i , i ) );
  bool got1 = false;
  if( isp[ 1 ] ) got1 = true;
  while( heap.size() and ( pp > 1 or not got1 ) ){
    auto tp = heap.top(); heap.pop();
    LL td = get<0>( tp );
    int nd = get<1>( tp );
    int st = get<2>( tp );
    if( tag[ st ].find( nd ) != tag[ st ].end() )
      continue;
    tag[ st ].insert( nd );
    if( not got1 and nd == 1 ){
      got1 = true;
      ans += td;
    }
    if( gt[ nd ] ){
      //if( uni( gt[ nd ] , st ) ){
        //ans += td + gd[ nd ];
        //pp --;
      //}
      continue;
    }else{
      gt[ nd ] = st;
      gd[ nd ] = td;
    }
    //if( nd != st and isp[ nd ] ){
      //if( uni( nd , st ) ){
        //ans += td;
        //pp --;
      //}
      //continue;
    //}
    //if( pp <= 1 and got1 ) break;
    for( auto i : v[ nd ] ){
      auto it = tag[ st ].find( i.first );
      if( it != tag[ st ].end() ) continue;
      heap.push( make_tuple( td + i.second , i.first , st ) );
    }
  }
  vector< pair<LL, pair<int,int> > > e;
  for( int i = 1 ; i <= n ; i ++ )
    for( auto j : v[ i ] )
      e.push_back( { gd[ i ] + gd[ j.first ] + j.second ,
                     { gt[ i ] , gt[ j.first ] } } );
  sort( e.begin() , e.end() );
  for( auto i : e )
    if( uni( i.second.first , i.second.second ) )
      ans += i.first;
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