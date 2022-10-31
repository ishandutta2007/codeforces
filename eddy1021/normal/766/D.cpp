#include <bits/stdc++.h>
using namespace std;
#define N 202020
#define O(I) (I<<1)
#define X(I) (1+(I<<1))
int n , m , q , p[ N ];
int f( int x ){
  return x == p[ x ] ? x : p[ x ] = f( p[ x ] );
}
void uni( int x , int y ){
  p[ f( x ) ] = f( y );
}
map<string,int> M;
void init(){
  scanf( "%d%d%d" , &n , &m , &q );
  for( int i = 0 ; i < n * 2 ; i ++ )
    p[ i ] = i;
  for( int i = 0 ; i < n ; i ++ ){
    string ss; cin >> ss;
    M[ ss ] = i;
  }
  while( m -- ){
    int type; string s1 , s2;
    scanf( "%d" , &type );
    cin >> s1 >> s2;
    int id1 = M[ s1 ] , id2 = M[ s2 ];
    if( type == 1 ){
      if( f( O( id1 ) ) == f( X( id2 ) ) or 
          f( X( id1 ) ) == f( O( id2 ) ) )
        puts( "NO" );
      else{
        puts( "YES" );
        uni( O( id1 ) , O( id2 ) );
        uni( X( id1 ) , X( id2 ) );
      }
    }else{
      if( f( O( id1 ) ) == f( O( id2 ) ) or 
          f( X( id1 ) ) == f( X( id2 ) ) )
        puts( "NO" );
      else{
        puts( "YES" );
        uni( O( id1 ) , X( id2 ) );
        uni( X( id1 ) , O( id2 ) );
      }
    }
  }
}
void solve(){
  while( q -- ){
    string s1 , s2;
    cin >> s1 >> s2;
    int id1 = M[ s1 ] , id2 = M[ s2 ];
    if( f( O( id1 ) ) == f( O( id2 ) ) and
        f( X( id1 ) ) == f( X( id2 ) ) )
      puts( "1" );
    else if( f( O( id1 ) ) == f( X( id2 ) ) and
        f( X( id1 ) ) == f( O( id2 ) ) )
      puts( "2" );
    else
      puts( "3" );
  }
}
int main(){
  init();
  solve();
}