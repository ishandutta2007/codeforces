#include <bits/stdc++.h>
using namespace std;
#define N 1010101
char c[ N ];
vector<int> v;
int k , len;
bool okay( int mx ){
  int cnt = 0 , pc = 0;
  for( auto i : v ){
    if( pc + i > mx ){
      cnt ++;
      pc = i;
    }else
      pc += i;
  }
  if( pc ) cnt ++;
  return cnt <= k;
}
int main(){
  scanf( "%d" , &k );
  fgets( c , N , stdin );
  fgets( c , N , stdin );
  len = strlen( c );
  for( int i = 0 , cc = 0 ; i + 1 < len ; i ++ ){
    cc ++;
    if( i + 2 == len or c[ i ] == ' ' or c[ i ] == '-' ){
      v.push_back( cc );
      cc = 0;
    }
  }
  int bl = *max_element( v.begin() , v.end() ) , br = len , ba = br;
  while( bl <= br ){
    int mid = ( bl + br ) >> 1;
    if( okay( mid ) ) ba = mid , br = mid - 1;
    else bl = mid + 1;
  }
  printf( "%d\n" , ba );
}