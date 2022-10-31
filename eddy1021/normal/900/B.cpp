#include <bits/stdc++.h>
using namespace std;
#define N 101010
bool tg[ N ];
int main(){
  int a , b , c;
  cin >> a >> b >> c;
  for( int i = 1 ; ; i ++ ){
    if( tg[ a ] ) break;
    tg[ a ] = true;
    a *= 10;
    if( a / b == c ){
      printf( "%d\n" , i );
      exit(0);
    }
    a %= b;
  }
  puts( "-1" );
}