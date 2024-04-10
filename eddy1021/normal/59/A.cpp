#include <bits/stdc++.h>
using namespace std;
int cnt[ 2 ];
char c[ 111 ];
int main(){
  scanf( "%s" , c );
  for( int i = 0 ; c[ i ] ; i ++ )
    cnt[ isupper( c[ i ] ) ? 1 : 0 ] ++;
  for( int i = 0 ; c[ i ] ; i ++ )
    putchar( cnt[ 1 ] > cnt[ 0 ] ? toupper( c[ i ] ) : tolower( c[ i ] ) );
}