#include <bits/stdc++.h>
using namespace std;
int ans;
pair<int,int> match( int aa , int bb ){
  int ia[ 4 ] , ib[ 4 ];
  for( int i = 0 ; i < 4 ; i ++ ){
    ia[ i ] = aa % 10; aa /= 10;
    ib[ i ] = bb % 10; bb /= 10;
  }
  bool got[ 10 ] = {};
  int a = 0 , b = 0;
  for( int i = 0 ; i < 4 ; i ++ )
    if( ia[ i ] == ib[ i ] )
      a ++;
    else
      got[ ia[ i ] ] = true;
  for( int i = 0 ; i < 4 ; i ++ )
    if( ia[ i ] != ib[ i ] && got[ ib[ i ] ] )
      b ++;
  return { a , b };
}
inline pair<int,int> ask( int x ){
  int a, b;
#ifdef ONLINE_JUDGE
  printf( "%04d\n" , x );
  fflush( stdout );
  scanf( "%d%d" , &a , &b );
#else
  cerr << "guessing " << x << endl;
  tie(a, b) = match( ans , x );
#endif
  if( a == 4 && b == 0 ) exit(0);
  return {a, b};
}
vector< int > pos;
bool okay( int x ){
  set<int> S;
  for( int i = 0 ; i < 4 ; i ++ ){
    S.insert( x % 10 );
    x /= 10;
  }
  return S.size() == 4u;
}
void build(){
  for( int i = 0 ; i < 10000 ; i ++ )
    if( okay( i ) )
      pos.push_back( i );
}
void upd( int now , int a , int b ){
  vector<int> npos;
  for( auto i : pos )
    if( match( now , i ) == make_pair( a , b ) )
      npos.push_back( i );
  pos.swap( npos );
}
int cal( int tmp ){
  int cnt[ 5 ][ 5 ] = {};
  for( int x : pos ){
    pair<int,int> ret = match( tmp , x );
    cnt[ ret.first ][ ret.second ] ++;
  }
  int wst = 0;
  for( int i = 0 ; i <= 4 ; i ++ )
    for( int j = 0 ; i + j <= 4 ; j ++ )
      wst = max( wst , cnt[ i ][ j ] );
  return wst;
}
void guess(){
  int nxt = pos[ 0 ];
  for( int i = 0 ; i < 7 ; i ++ ){
    pair<int,int> ret = ask( nxt );
    upd( nxt , ret.first , ret.second );
    int bst = pos[ 0 ] , bg = 10000;
    for( int x : pos ){
      int gg = cal( x );
      if( gg < bg ){
        bst = x; bg = gg; 
      }
    }
    nxt = bst;
  }
  assert( false );
}
int main(){
  srand( 514 * 514 );
  build();
#ifndef ONLINE_JUDGE
  srand( time(0) );
  ans = pos[ rand() % pos.size() ];
  cerr << ans << endl;
#endif
  guess();
}