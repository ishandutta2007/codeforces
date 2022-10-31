#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> v;
int main(){
  cin >> n;
  v.resize( n );
  for( int i = 0 ; i < n ; i ++ )
    cin >> v[ i ];
  int st = -1;
  for( int i = 0 ; i < n ; i ++ )
    if( v[ i ] ){
      st = i;
      break;
    }
  if( st == -1 ){
    puts( "NO" );
    exit( 0 );
  }
  puts( "YES" );
  vector< pair<int,int> > ans;
  int pre = -1;
  for( int i = st , j = st ; i < n ; i = j + 1 ){
    j = i;
    while( j + 1 < n && v[ j + 1 ] == 0 ) j ++;

    ans.push_back( { pre + 1 , j } );
    pre = j;

  }
  printf( "%d\n" , (int)ans.size() );
  for( auto i : ans )
    printf( "%d %d\n" , i.first + 1 , i.second + 1 );
}