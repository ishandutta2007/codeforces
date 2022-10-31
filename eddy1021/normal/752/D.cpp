// eddy1021
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long double LD;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef tuple<int,int,int> tiii;
typedef tuple<LL,LL,LL> tlll;
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
#define N 101010
void build(){

}
#define BS 13131
int n , k;
LL a[ N ];
char c[ N ];
map<int,int> lM , rM , pM;
int lcnt , rcnt , pcnt , lvl[ N ] , rvl[ N ];
set<int> lv[ N ] , rv[ N ] , pv[ N ];
void init(){
  scanf( "%d%d" , &n , &k );
  for( int i = 0 ; i < n ; i ++ ){
    scanf( "%s%lld" , c , &a[ i ] );
    int lhsh = 0 , rhsh = 0;
    for( int j = 0 ; j < k ; j ++ )
      lhsh = add( mul( lhsh , BS ) , c[ j ] );
    for( int j = k - 1 ; j >= 0 ; j -- )
      rhsh = add( mul( rhsh , BS ) , c[ j ] );
    bool isp = true;
    for( int jl = 0 , jr = k - 1 ; jl < jr ; jl ++ , jr -- )
      if( c[ jl ] != c[ jr ] ){
        isp = false;
        break;
      }
    //printf( "%d %d\n" , lhsh , rhsh );
    if( isp ){
      if( pM.find( lhsh ) == pM.end() )
        pM[ lhsh ] = pcnt ++;
      pv[ pM[ lhsh ] ].insert( i );
    }else{
      if( lM.find( lhsh ) == lM.end() )
        lM[ lhsh ] = lcnt ++;
      if( rM.find( rhsh ) == rM.end() )
        rM[ rhsh ] = rcnt ++;
      lv[ lM[ lhsh ] ].insert( i );
      rv[ rM[ rhsh ] ].insert( i );
    }
    lvl[ i ] = lhsh;
    rvl[ i ] = rhsh;
  }
}
void bye( int id ){
  lv[ lM[ lvl[ id ] ] ].erase( id );
  rv[ rM[ rvl[ id ] ] ].erase( id );
}
void solve(){
  LL ans = 0 , bst = 0;
  for( auto it = lM.begin() ; it != lM.end() ; it ++ ){
    int vl = it->first;
    if( rM.count( vl ) == 0 ) continue;
    vector< pair<int,int> > vv;
    for( int j : lv[ it->second ] )
      vv.push_back( { a[ j ] , j } );
    if( vv.empty() ) continue;
    sort( vv.begin() , vv.end() );
    reverse( vv.begin() , vv.end() );
   
    vector< pair<int,int> > vv2;
    for( int j : rv[ rM[ vl ] ] )
      vv2.push_back( { a[ j ] , j } );
    if( vv2.empty() ) continue;
    sort( vv2.begin() , vv2.end() );
    reverse( vv2.begin() , vv2.end() );
    for( size_t i = 0 ; i < min( vv.size() , vv2.size() ) ; i ++ )
      if( vv[ i ].first + vv2[ i ].first > 0 ){
        ans += vv[ i ].first + vv2[ i ].first;
        //printf( "%d %d\n" , vv[ i ].second , vv2[ i ].second );
        assert( vv[ i ].second != vv2[ i ].second );
        bye( vv[ i ].second );
        bye( vv2[ i ].second );
      }
  }
  vector< pair<LL,LL> > vv;
  for( int i = 0 ; i < pcnt ; i ++ ){
    priority_queue<int> heap;
    for( auto j : pv[ i ] )
      heap.push( a[ j ] );
    bool flag = false;
    while( (int)heap.size() > 1 ){
      LL a1 = heap.top(); heap.pop();
      LL a2 = heap.top(); heap.pop();
      if( a2 >= 0 ){
        ans += a1 + a2;
      }else if( a1 + a2 > 0 ){
        vv.push_back( { a1 + a2 , a1 } );
        flag = true;
        break;
      }else if( a1 > 0 ){
        vv.push_back( { 0 , a1 } );
        flag = true;
        break;
      }else break;
    }
    if( (int)heap.size() && !flag && heap.top() > 0 )
      vv.push_back( { 0 , heap.top() } );
  }
  LL sum = 0;
  for( auto i : vv )
    sum += i.first;
  bst = max( bst , sum );
  for( auto i : vv ){
    LL tsum = sum - i.first + i.second;
    bst = max( bst , tsum );
  }
  printf( "%lld\n" , ans + bst );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}