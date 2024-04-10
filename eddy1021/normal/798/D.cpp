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
void build(){

}
#define N 101010
LL n , a[ N ] , b[ N ];
void init(){
  n = getint();
  for( int i = 0 ; i < n ; i ++ )
    a[ i ] = getint();
  for( int i = 0 ; i < n ; i ++ )
    b[ i ] = getint();
}
bool got[ N ];
void solve(){
  vector<int> ans;
  LL suma = accumulate( a , a + n , 0LL );
  LL sumb = accumulate( b , b + n , 0LL );
  LL gota = 0 , gotb = 0;
  int mst = n / 2 + 1;
  set< pair<pair<int,int>,int> > canda , candb , ga , gb;
  for( int i = 0 ; i < n and (int)ans.size() < mst ; i ++ )
    if( false and a[ i ] * n >= suma and b[ i ] * n >= sumb ){
      ans.push_back( i + 1 );
      gota += a[ i ];
      gotb += b[ i ];
      got[ i ] = true;
    }else{
      canda.insert( { { a[ i ] , b[ i ] } , i } );
      candb.insert( { { b[ i ] , a[ i ] } , i } );
    }
  int nxt = 0;
  while( (int)ans.size() < mst ){
    if( nxt == 0 and gota * 2 <= suma ){
      auto it = -- canda.end();
      int who = it->second;
      canda.erase( it );
      ans.push_back( who + 1 );
      gota += a[ who ];
      gotb += b[ who ];
      candb.erase( { { b[ who ] , a[ who ] } , who } );
      ga.insert( { { a[ who ] , b[ who ] } , who } );
      gb.insert( { { b[ who ] , a[ who ] } , who } );
    }else if( nxt == 1 and gotb * 2 <= sumb ){
      auto it = -- candb.end();
      int who = it->second;
      candb.erase( it );
      ans.push_back( who + 1 );
      gota += a[ who ];
      gotb += b[ who ];
      canda.erase( { { a[ who ] , b[ who ] } , who } );
      ga.insert( { { a[ who ] , b[ who ] } , who } );
      gb.insert( { { b[ who ] , a[ who ] } , who } );
    }else if( gota * 2 <= suma ){
      auto it = -- canda.end();
      int who = it->second;
      canda.erase( it );
      ans.push_back( who + 1 );
      gota += a[ who ];
      gotb += b[ who ];
      candb.erase( { { b[ who ] , a[ who ] } , who } );
      ga.insert( { { a[ who ] , b[ who ] } , who } );
      gb.insert( { { b[ who ] , a[ who ] } , who } );
    }else{
      auto it = -- candb.end();
      int who = it->second;
      candb.erase( it );
      ans.push_back( who + 1 );
      gota += a[ who ];
      gotb += b[ who ];
      canda.erase( { { a[ who ] , b[ who ] } , who } );
      ga.insert( { { a[ who ] , b[ who ] } , who } );
      gb.insert( { { b[ who ] , a[ who ] } , who } );
    }
    nxt = 1 - nxt;
  }
  map< pair<pair<int,int>,int> , int > fuck;
  while( gota * 2 <= suma or gotb * 2 <= sumb ){
    if( gota * 2 <= suma ){
      {
        auto it = ga.begin();
        int who = it->second;
        gota -= a[ who ];
        gotb -= b[ who ];
        ga.erase( it );
        gb.erase( { { b[ who ] , a[ who ] } , who } );
        fuck[ { { a[ who ] , b[ who ] } , who } ] ++;
        if( fuck[ { { a[ who ] , b[ who ] } , who } ] <= 2 ){
          canda.insert( { { a[ who ] , b[ who ] } , who } );
          candb.insert( { { b[ who ] , a[ who ] } , who } );
        }
      }
      auto it = -- canda.end();
      int who = it->second;
      canda.erase( it );
      //ans.push_back( who + 1 );
      gota += a[ who ];
      gotb += b[ who ];
      candb.erase( { { b[ who ] , a[ who ] } , who } );
      ga.insert( { { a[ who ] , b[ who ] } , who } );
      gb.insert( { { b[ who ] , a[ who ] } , who } );
    }else{
      {
        auto it = gb.begin();
        int who = it->second;
        gota -= a[ who ];
        gotb -= b[ who ];
        gb.erase( it );
        ga.erase( { { a[ who ] , b[ who ] } , who } );
        fuck[ { { a[ who ] , b[ who ] } , who } ] ++;
        if( fuck[ { { a[ who ] , b[ who ] } , who } ] <= 2 ){
          canda.insert( { { a[ who ] , b[ who ] } , who } );
          candb.insert( { { b[ who ] , a[ who ] } , who } );
        }
      }
      auto it = -- candb.end();
      int who = it->second;
      candb.erase( it );
      //ans.push_back( who + 1 );
      gota += a[ who ];
      gotb += b[ who ];
      canda.erase( { { a[ who ] , b[ who ] } , who } );
      ga.insert( { { a[ who ] , b[ who ] } , who } );
      gb.insert( { { b[ who ] , a[ who ] } , who } );
    }
  }
  ans.clear();
  for( auto i : ga )
    ans.push_back( i.second + 1 );
  printf( "%d\n" , (int)ans.size() );
  for( size_t i = 0 ; i < ans.size() ; i ++ )
    printf( "%d%c" , ans[ i ] , " \n"[ i + 1 == ans.size() ] );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}