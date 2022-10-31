#include <bits/stdc++.h>
using namespace std;
#define N 101010
int n, cnt[ N ], tk[ N ], wt1[ N ], wt2[ N ];
map<string,int> M;
map<int,string> rM;
inline void match( const string& s , int x ){
  M[ s ] = x; rM[ x ] = s;
}
void build(){
  match( "S" , 0 );
  match( "M" , 1 );
  match( "L" , 2 );
  match( "XL" , 3 );
  match( "XXL" , 4 );
  match( "XXXL" , 5 );
}
char c[ 1021 ];
inline pair<int,int> want(){
  scanf( "%s" , c );
  string s = "";
  int len = strlen( c );
  vector<int> v;
  for( int i = 0 ; i <= len ; i ++ )
    if( i == len || c[ i ] == ',' ){
      v.push_back( M[ s ] );
      s = "";
    }else
      s += c[ i ];
  return { v[ 0 ] , v.back() };
}
bool ok[ N ];
int main(){
  build();
  for( int i = 0 ; i < 6 ; i ++ )
    scanf( "%d" , &cnt[ i ] );
  scanf( "%d" , &n );
  for( int i = 0 ; i < n ; i ++ )
    tie(wt1[i], wt2[i]) = want();
  for( int i = 0 ; i < n ; i ++ )
    if( wt1[i] == wt2[i] ){
      if( cnt[ wt1[i] ] == 0 ){
        puts( "NO" );
        exit( 0 );
      }
      cnt[ wt1[i] ] --;
      ok[i] = true;
      tk[i] = wt1[i];
    }
  for( int i = 0 ; i < 6 ; i ++ ){
    for( int j = 0 ; j < n && cnt[ i ] > 0 ; j ++ )
      if( !ok[j] && wt2[j] == i ){
        cnt[i] --;
        ok[j] = true;
        tk[j] = i;
      }
    for( int j = 0 ; j < n && cnt[ i ] > 0 ; j ++ )
      if( !ok[j] && wt1[j] == i ){
        cnt[i] --;
        ok[j] = true;
        tk[j] = i;
      }
  }
  for( int i = 0 ; i < n ; i ++ )
    if( !ok[ i ] ){
      puts( "NO" );
      exit( 0 );
    }
  puts( "YES" );
  for( int i = 0 ; i < n ; i ++ )
    printf( "%s\n" , rM[ tk[i] ].c_str() );
}