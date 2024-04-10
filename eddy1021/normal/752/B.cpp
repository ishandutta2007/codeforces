#include <bits/stdc++.h>
using namespace std;
#define N 1021
char to[ N ];
bool gt[ N ];
char a[ N ] , b[ N ];
int main(){
  scanf( "%s%s" , a , b );
  for( int i = 0 ; a[ i ] ; i ++ )
    if( a[ i ] != b[ i ] ){
      if( gt[ (int)a[ i ] ] && to[ (int)a[ i ] ] != b[ i ] ){
        puts( "-1" );
        exit( 0 );
      }
      if( gt[ (int)b[ i ] ] && to[ (int)b[ i ] ] != a[ i ] ){
        puts( "-1" );
        exit( 0 );
      }
      gt[ (int)a[ i ] ] = gt[ (int)b[ i ] ] = true;
      to[ (int)a[ i ] ] = b[ i ];
      to[ (int)b[ i ] ] = a[ i ];
    }
  for( int i = 0 ; i < 26 ; i ++ )
    if( !gt[ 97 + i ] )
      to[ 97 + i ] = 97 + i;
  for( int i = 0 ; a[ i ] ; i ++ )
    if( to[ (int)a[ i ] ] != b[ i ] ){
      puts( "-1" );
      exit( 0 );
    }
  vector< pair<char,char> > ans;
  for( int i = 0 ; i < 26 ; i ++ )
    if( to[ 97 + i ] != (char)(97 + i) &&
        97 + i < (int)to[ 97 + i ] )
      ans.push_back( { (char)( 97 + i ) , to[ 97 + i ] } );
  printf( "%d\n" , (int)ans.size() );
  for( auto i : ans )
    printf( "%c %c\n" , i.first , i.second );
}