#include <bits/stdc++.h>
using namespace std;
#define N 303030
int n , k , c[ N ];
vector<int> fac[ N ];
void no(){
  puts( "No" );
  exit(0);
}
bool take[ N ];
int til;
#define K 20
int pre_cnt[ N ];
void go( int now , int res ){
  if( res < 0 ) return;
  if( res == 0 ){
    vector<int> ans;
    for( int i = 1 ; i < now ; i ++ )
      if( take[ i ] )
        ans.push_back( i );
    puts( "Yes" );
    printf( "%d\n" , (int)ans.size() );
    for( size_t i = 0 ; i < ans.size() ; i ++ )
      printf( "%d%c" , ans[ i ] , " \n"[ i + 1 == ans.size() ] );
    exit(0);
  }
  if( now > til ) return;
  take[ now ] = false;
  go( now + 1 , res );
  take[ now ] = true;
  res -= pre_cnt[ now ];
  for( int i = max( til - K + 1 , 1 ) ; i < now ; i ++ )
    if( now % i == 0 and take[ i ] )
      res --;
  go( now + 1 , res );
}
int main(){
  cin >> n >> k;
  for( int i = 1 ; i <= n ; i ++ )
    for( int j = i + i ; j <= n ; j += i ){
      c[ j ] ++;
      fac[ j ].push_back( i );
    }
  int sum = 0;
  while( sum < k ){
    til ++;
    sum += c[ til ];
  }
  if( til > n ) no();
  til = min( n , til + 3 );
  int nk = k;
  for( int i = 1 ; i <= til - K ; i ++ ){
    take[ i ] = true;
    nk -= c[ i ];
  }
  for( int i = max( til - K + 1 , 1 ) ; i <= til ; i ++ )
    for( auto j : fac[ i ] )
      if( j <= til - K )
        pre_cnt[ i ] ++;
  go( max( til - K + 1 , 1 ) , nk );
  no();
}