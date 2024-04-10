// eddy1021
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
inline int getint(){
  int _x=0; char _tc=getchar();    
  while( _tc<'0'||_tc>'9' ) _tc=getchar();
  while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
  return _x;
}
int _id;
unordered_map<int,int> map_to;
int Id( int x ){
  auto it = map_to.find( x );
  if( it != map_to.end() ) return it->second;
  return map_to[ x ] = _id ++;
}
#define N 101010
int n , q , a[ N ];
int cmd[ N ] , ql[ N ] , qr[ N ] , pr[ N ];
vector<int> wt;
vector<int> rec[ N ];
int cur[ N ];
void init(){
  n = getint();
  q = getint();
  for( int i = 1 ; i <= n ; i ++ ){
    a[ i ] = Id( getint() );
    rec[ i ].push_back( a[ i ] );
  }
  for( int i = 0 ; i < q ; i ++ ){
    cmd[ i ] = getint();
    ql[ i ] = getint();
    qr[ i ] = getint();
    if( cmd[ i ] == 2 ){
      qr[ i ] = Id( qr[ i ] );
      rec[ ql[ i ] ].push_back( qr[ i ] );
      wt.push_back( ql[ i ] );
    }else
      pr[ i ] = wt.size();
  }
}
int ans[ N ] , mex[ N ] , cnt[ N + N ];
void modify( int pos , int dlt ){
  mex[ cnt[ a[ pos ] ] ] --;
  cnt[ a[ pos ] ] += dlt;
  mex[ cnt[ a[ pos ] ] ] ++;
}
void change( int pos , int dlt , int cql , int cqr ){
  if( cql <= pos and pos <= cqr )
    modify( pos , -1 );
  cur[ pos ] += dlt;
  a[ pos ] = rec[ pos ][ cur[ pos ] ];
  if( cql <= pos and pos <= cqr )
    modify( pos , +1 );
}
void solve(){
  int k = 1;
  while( (long long)k * k * k <= (long long)n * n ) k ++;
  vector< pair< pair<int,int> , pair<int,int> > > qry;
  for( int i = 0 ; i < q ; i ++ ){
    if( cmd[ i ] == 2 ) continue;
    qry.push_back( { { ql[ i ] / k , pr[ i ] / k } ,
                     { qr[ i ] , i } } );
  }
  sort( qry.begin() , qry.end() );
  modify( 1 , +1 );
  int lb = 1 , rb = 1 , ch = 0;
  for( auto _ : qry ){
    int i = _.second.second;
    ans[ i ] = 1;
    while( lb > ql[ i ] ) modify( -- lb , +1 );
    while( rb < qr[ i ] ) modify( ++ rb , +1 );
    while( lb < ql[ i ] ) modify( lb ++ , -1 );
    while( rb > qr[ i ] ) modify( rb -- , -1 );
    while( ch < pr[ i ] ) change( wt[ ch ++ ] , +1 , ql[ i ] , qr[ i ] );
    while( ch > pr[ i ] ) change( wt[ -- ch ] , -1 , ql[ i ] , qr[ i ] );
    while( mex[ ans[ i ] ] ) ans[ i ] ++;
  }
  for( int i = 0 ; i < q ; i ++ ){
    if( cmd[ i ] == 2 ) continue;
    printf( "%d\n" , ans[ i ] );
  }
}
int main(){
  init();
  solve();
}