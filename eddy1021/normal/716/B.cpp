#include <bits/stdc++.h>
using namespace std;
#define N 50505
char c[ N ];
int len;
bool go( int st ){
  bool ap[ 26 ] = {};
  for( int i = st ; i < st + 26 ; i ++ ){
    if( c[ i ] == '?' ) continue;
    if( ap[ c[ i ] - 'A' ] ) return false;
    ap[ c[ i ] - 'A' ] = true;
  }
  int ptr = 0;
  for( int i = st ; i < st + 26 ; i ++ )
    if( c[ i ] == '?' ){
      while( ptr < 26 && ap[ ptr ] ) ptr ++;
      assert( ptr < 26 );
      c[ i ] = 'A' + ptr;
      ap[ ptr ] = true;
    }
  return true;
}
int main(){
  scanf( "%s" , c );
  len = strlen( c );
  bool okay = false;
  for( int i = 0 ; i + 26 <= len ; i ++ )
    okay |= go( i );
  if( okay ){
    for( int i = 0 ; i < len ; i ++ )
      if( c[ i ] == '?' )
        c[ i ] = 'Y';
    puts( c );
  }else
    puts( "-1" );
}