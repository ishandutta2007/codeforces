#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define N 514
#define Z 35140
int n , a[ N ];
vector<int> cand;
LL ans;
inline LL best( LL x , LL b ){
  LL gr = x / b , res = x % b;
  LL ret = gr;
  gr -= res;
  return ret - gr / ( b + 1 );
}
int main(){
  scanf( "%d" , &n );
  for( int i = 0 ; i < n ; i ++ )
    scanf( "%d" , &a[ i ] );
  sort( a , a + n );
  ans = accumulate( a , a + n , 0ll );
  for( int i = 1 ; i < Z ; i ++ ){
    cand.push_back( i );
    if( i <= a[ 0 ] ){
      for( int j = -2 ; j <= 2 ; j ++ ){
        int tmp = a[ 0 ] / i + j;
        if( tmp > 0 )
          cand.push_back( tmp );
      }
    }
  }
  sort( cand.begin() , cand.end() );
  cand.resize( unique( cand.begin() , cand.end() ) - cand.begin() );
  for( auto st : cand ){
    LL tans = 0;
    bool ok = true;
    for( int i = 0 ; i < n ; i ++ ){
      if( a[ i ] % ( st + 1 ) == 0 ){
        tans += a[ i ] / ( st + 1 );
        continue;
      }
      if( a[ i ] / st < a[ i ] % st ){
        ok = false;
        break;
      }
      tans += best( a[ i ] , st );
    }
    if( not ok ) continue;
    //printf( "%d %lld\n" , st , tans );
    ans = min( ans , tans );
  }
  cout << ans << endl;
}