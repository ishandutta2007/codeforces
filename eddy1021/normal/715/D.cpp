#include <bits/stdc++.h>
using namespace std;
#define N 51
#define lock lllock
typedef long long LL;
set< pair< pair<int,int> , pair<int,int> > > lock;
LL t , n , m;
inline void Lock( int ax , int ay , int bx , int by ){
  if( ax < 1 || ay < 1 || bx < 1 || by < 1 )
    return;
  lock.insert( { { ax , ay } , { bx , by } } );
}
void solve(){
  n = m = 2;
  Lock( 1 , 2 , 2 , 2 );
  Lock( 2 , 1 , 2 , 2 );
  vector< LL > r;
  while( t ){
    r.push_back( t % 6 );
    t /= 6;
  }
  reverse( r.begin() , r.end() );
  for( LL nd : r ){
    Lock( n - 4 , m + 1 , n - 3 , m + 1 );
    Lock( n - 2 , m + 2 , n - 1 , m + 2 );
    if( n > 2 )
      Lock( n - 1 , m , n - 1 , m + 1 );
    Lock( n - 2 , m , n - 2 , m + 1 );
    Lock( n , m - 2 , n + 1 , m - 2 );
    if( n > 2 )
      Lock( n , m - 1 , n + 1 , m - 1 );
    Lock( n + 1 , m - 4 , n + 1 , m - 3 );
    Lock( n + 2 , m - 2 , n + 2 , m - 1 );
    n += 2; m += 2;
    Lock( n - 3 , m - 1 , n - 2 , m - 1 );
    if( nd < 3 )
      Lock( n - 1 , m - 3 , n - 1 , m - 2 );
    if( nd % 3 < 2 )
      Lock( n - 3 , m , n - 2 , m );
    if( nd % 3 < 1 )
      Lock( n , m - 3 , n , m - 2 );
  }
}
void output(){
  printf( "%lld %lld\n" , n , m );
  printf( "%d\n" , (int)lock.size() );
  for( auto i : lock )
    printf( "%d %d %d %d\n" , i.first.first ,
                              i.first.second ,
                              i.second.first ,
                              i.second.second );
}
int main(){
  scanf( "%lld" , &t );
  solve();
  output();
}