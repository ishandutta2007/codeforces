#include <bits/stdc++.h>
using namespace std;
#define N 1021
typedef long long LL;
const LL inf = 100000000000000LL;
struct Arc{
  LL st , ed , dst , nxt;
  Arc(){}
  Arc( LL _st , LL _ed , LL _dst , LL _nxt ) :
    st( _st ), ed( _ed ), dst( _dst ), nxt( _nxt ){}
} e[ N * 20 ];
LL n , m , l , s , t , mcnt = 2 , from[ N ];
void init(){
  scanf( "%lld%lld%lld%lld%lld" , &n , &m , &l , &s , &t );
  while( m -- ){
    LL ui , vi , wi; scanf( "%lld%lld%lld" , &ui , &vi , &wi );
    e[ mcnt ] = Arc( ui , vi , wi , from[ ui ] );
    from[ ui ] = mcnt ++;
    e[ mcnt ] = Arc( vi , ui , wi , from[ vi ] );
    from[ vi ] = mcnt ++;
  }
}
vector< LL > dst;
bool got[ N ];
void sp(){
  dst.resize( n );
  priority_queue< pair<LL,LL> ,
                  vector<pair<LL,LL>> ,
                  greater<pair<LL,LL>> > heap;
  for( int i = 0 ; i < n ; i ++ ){
    got[ i ] = false;
    dst[ i ] = inf * N;
  }
  heap.push( { 0 , s } );
  while( heap.size() ){
    pair<LL,LL> tp = heap.top(); heap.pop();
    LL tdst = tp.first;
    LL tnow = tp.second;
    if( got[ tnow ] ) continue;
    got[ tnow ] = true;
    dst[ tnow ] = tdst;
    for( LL i = from[ tnow ] ; i ; i = e[ i ].nxt )
      if( !got[ e[ i ].ed ] && e[ i ].dst != 0 )
        heap.push( { tdst + abs( e[ i ].dst ) , e[ i ].ed } );
  }
}
void solve(){
  sp();
  if( got[ t ] && dst[ t ] < l ){
    puts( "NO" );
    exit( 0 );
  }
  for( int i = 2 ; i < mcnt ; i ++ )
    if( e[ i ].dst == 0 )
      e[ i ].dst = -1;
  sp();
  if( !got[ t ] || dst[ t ] > l ){
    puts( "NO" );
    exit( 0 );
  }
  int cnt = 0;
  for( int i = 2 ; i < mcnt ; i += 2 )
    if( e[ i ].dst == -1 )
      cnt ++;
  LL bl = 0 , br = cnt , ba = 0;
  while( bl <= br ){
    LL mid = ( bl + br ) >> 1;
    cnt = 0;
    for( int i = 2 ; i < mcnt ; i += 2 )
      if( e[ i ].dst == -1 || e[ i ].dst == inf ){
        if( ++ cnt <= mid )
          e[ i ].dst = e[ i + 1 ].dst = -1;
        else
          e[ i ].dst = e[ i + 1 ].dst = inf;
      }
    sp();
    if( dst[ t ] > l ) bl = mid + 1;
    else br = mid - 1 , ba = mid;
  }
  int vi = -1; cnt = 0;
  for( int i = 2 ; i < mcnt ; i += 2 )
    if( e[ i ].dst == -1 || e[ i ].dst == inf ){
      if( ++ cnt <= ba )
        e[ i ].dst = e[ i + 1 ].dst = -1;
      else
        e[ i ].dst = e[ i + 1 ].dst = inf;
      if( cnt == ba )
        vi = i;
    }
  if( vi != -1 ){
    bl = 1; br = inf;
    while( bl <= br ){
      LL bmid = ( bl + br ) >> 1;
      e[ vi ].dst = e[ vi + 1 ].dst = bmid;
      sp();
      if( dst[ t ] <= l )
        ba = bmid , bl = bmid + 1;
      else br = bmid - 1;
    }
  }
  e[ vi ].dst = e[ vi + 1 ].dst = ba;
  puts( "YES" );
  for( int i = 2 ; i < mcnt ; i += 2 )
    printf( "%lld %lld %lld\n" , e[ i ].st , e[ i ].ed , abs( e[ i ].dst ) );
}
int main(){
  init();
  solve();
}