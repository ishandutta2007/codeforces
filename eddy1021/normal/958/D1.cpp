#include <bits/stdc++.h>
using namespace std;
#define N 202020
int n;
char buf[ 512 ];
pair<int,int> v[ N ];
map< pair<int,int> , int > cnt;
int main(){
  cin >> n;
  for( int i = 0 ; i < n ; i ++ ){
    scanf( "%s" , buf );
    int a , b , c;
    sscanf( buf , "(%d+%d)/%d" , &a , &b , &c );
    a += b;
    int g = __gcd( a , c );
    a /= g;
    c /= g;
    v[ i ] = {a, c};
    cnt[ v[ i ] ] ++;
  }
  for( int i = 0 ; i < n ; i ++ )
    printf( "%d%c" , cnt[ v[ i ] ] , " \n"[ i + 1 == n ] );
}