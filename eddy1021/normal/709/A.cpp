#include <bits/stdc++.h>
using namespace std;
int n , b , d , a , s , k;
int main(){
  scanf( "%d%d%d" , &n , &b , &d );
  while( n -- ){
    scanf( "%d" , &a );
    if( a > b ) continue;
    s += a;
    if( s > d ) s = 0 , k ++;
  }
  printf( "%d\n" , k );
}