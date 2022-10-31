#include <bits/stdc++.h>
using namespace std;
int n , x , i;
map<int,int> M;
long long ans;
int main(){
  scanf( "%d%d" , &n , &x );
  while( n -- ){
    scanf( "%d" , &i );
    ans += M[ i ^ x ];
    M[ i ] ++;
  }
  printf( "%lld\n" , ans );
}