#include <bits/stdc++.h>
using namespace std;
#define N 1021
string tar = "heidi" , s;
int main(){
  cin >> s;
  int len = s.length() , ptr = 0;
  for( int i = 0 ; i < 5 ; i ++ ){
    while( ptr < len and s[ ptr ] != tar[ i ] )
      ptr ++;
    if( ptr == len ){
      puts( "NO" );
      exit(0);
    }
  }
  puts( "YES" );
}