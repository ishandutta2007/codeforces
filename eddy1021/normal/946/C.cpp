#include <bits/stdc++.h>
using namespace std;
#define N 101010
char c[ N ];
int main(){
  scanf( "%s" , c );
  int ptr = 0;
  for( int i = 0 ; i < 26 ; i ++ ){
    while( c[ ptr ] and c[ ptr ] - 'a' > i ) ptr ++;
    if( !c[ ptr ] ){
      puts( "-1" );
      exit(0);
    }
    c[ ptr ] = i + 'a';
    ptr ++;
  }
  puts( c );
}