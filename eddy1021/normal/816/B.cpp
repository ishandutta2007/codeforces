#include <bits/stdc++.h>
using namespace std;
#define N 202020
int n , k , q , s[ N ] , ok[ N ] , li , ri;
int main(){
  cin >> n >> k >> q;
  while( n -- ){
    cin >> li >> ri;
    s[ li ] ++;
    s[ ri + 1 ] --;
  }
  for( int i = 1 ; i < N ; i ++ ){
    s[ i ] += s[ i - 1 ];
    ok[ i ] = ok[ i - 1 ] + (s[ i ] >= k);
  }
  while( q -- ){
    cin >> li >> ri;
    cout << ok[ ri ] - ok[ li - 1 ] << "\n";
  }
}