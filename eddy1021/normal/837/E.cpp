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
void build(){

}
void init(){
}
LL slow( LL x , LL y ){
  LL ret = 0;
  while( y ){
    ret ++;
    y -= __gcd( x , y );
  }
  return ret;
}
inline LL next( LL x , LL g , LL curg ){
  LL tar = x / g * g;
  LL dlt = x - tar;
  if( dlt % curg == 0 ) return tar;
  return 0;
}
LL fast( LL x , LL y ){
  vector<LL> dv;
  for( LL i = 1 ; i * i <= x ; i ++ )
    if( x % i == 0 ){
      dv.push_back( i );
      if( i * i < x )
        dv.push_back( x / i );
    }
  sort( dv.begin() , dv.end() );
  LL curg = __gcd( x , y );
  size_t ptr = 0;
  while( dv[ ptr ] != curg ) ptr ++;
  LL ret = 0;
  while( ptr < dv.size() ){
    LL nxt = 0 , who = -1;
    for( size_t i = ptr + 1 ; i < dv.size() ; i ++ ){
      LL tnxt = next( y , dv[ i ] , curg );
      if( tnxt == 0 ) continue;
      if( tnxt >= nxt ){
        nxt = tnxt;
        who = dv[ i ];
      }
    }
    //cout << curg << " ";
    //cout << y << " ";
    //cout << nxt << " ";
    //cout << who << "\n";
    if( who == -1 )
      return ret + y / curg;
    ret += ( y - nxt ) / curg;
    y = nxt;
    curg = who;
    while( dv[ ptr ] != curg ) ptr ++;
  }
  assert( false );
  priority_queue< pair<LL,LL> ,
          vector< pair<LL,LL> >,
         greater< pair<LL,LL> > > heap;
  for( size_t i = ptr + 1 ; i < dv.size() ; i ++ ){
    LL nxt = next( y , dv[ i ] , curg );
    if( nxt )
      heap.push( { nxt , dv[ i ] } );
  }
  while( heap.size() ){
    auto nxt = heap.top(); heap.pop();
    if( nxt.second < curg ) continue;
    if( nxt.first >= y ){
      LL tnxt = next( y , nxt.second , curg );
      if( tnxt )
        heap.push( { tnxt , nxt.second } );
      continue;
    }
    ret += ( y - nxt.first ) / curg;
    y = nxt.first;
    curg = nxt.second;
  }
  return ret + y / curg;
}
void solve(){
  //for( LL xx = 1 ; xx <= 100 ; xx ++ ){
    //for( LL yy = 1 ; yy <= 100 ; yy ++ ){
      //LL v1 = slow( xx , yy );
      //LL v2 = fast( xx , yy );
      //if( v1 != v2 ){
        //fprintf( stderr , "x=%lld, y=%lld, expected %lld, found %lld\n",
                 //xx, yy, v1, v2 );
      //}
    //}
    //fprintf( stderr , "x=%lld done\n" , xx );
  //}
  LL x = getint();  
  LL y = getint();
  cout << fast( x , y ) << endl;
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}