#include <bits/stdc++.h>
using namespace std;
#define N 303030
#define M 256
#define K 4
int n , k , a[ N ];
int dp[ 2 ][ M ][ K ][ K ];
bool got[ 2 ][ M ][ K ][ K ];
inline void init(){
  scanf( "%d%d" , &n , &k );
  for( int i = 1 ; i <= n ; i ++ )
    scanf( "%d" , &a[ i ] );
}
int ans;
inline void go( int bt , int b , int fst , int lst , int tdp ){
  if( b == k && lst == 3 ) ans = max( ans , tdp );
  if( !got[ bt ][ b ][ fst ][ lst ] ||
      tdp > dp[ bt ][ b ][ fst ][ lst ] ){
    got[ bt ][ b ][ fst ][ lst ] = true;
    dp[ bt ][ b ][ fst ][ lst ] = tdp;
  }
}
inline void solve(){
  got[ 0 ][ 0 ][ 0 ][ 0 ] = true;
  for( int i = 1 ; i <= n ; i ++ ){
    int now = i & 1 , pre = 1 - now;
    for( int b = 0 ; b <= k ; b ++ )
      for( int fst = 0 ; fst < 4 ; fst ++ )
        for( int lst = 0 ; lst < 4 ; lst ++ )
          got[ now ][ b ][ fst ][ lst ] = false;
    for( int b = 0 ; b <= min( i - 1 , k ) ; b ++ )
      for( int fst = 0 ; fst < 3 ; fst ++ )
        for( int lst = 0 ; lst < 4 ; lst ++ ){
          if( !got[ pre ][ b ][ fst ][ lst ] ) continue;
          if( lst == 0 ){
            int tdp = dp[ pre ][ b ][ fst ][ lst ];
            go( now , b , fst , 0 , tdp );
            for( int nxt = 1 ; nxt < 4 ; nxt ++ ){
              tdp = dp[ pre ][ b ][ fst ][ lst ];
              if( nxt ){
                if( fst == 1 ) tdp += a[ i ]; if( fst == 2 ) tdp -= a[ i ];
                if( nxt == 1 ) tdp -= a[ i ]; if( nxt == 2 ) tdp += a[ i ];
              }
              go( now , b + 1 , fst , nxt , tdp );
            }
          }else{
            int tdp = dp[ pre ][ b ][ fst ][ lst ];
            if( fst == 1 ) tdp += a[ i ]; if( fst == 2 ) tdp -= a[ i ];
            if( lst == 1 ) tdp -= a[ i ]; if( lst == 2 ) tdp += a[ i ];
            go( now , b , fst , lst , tdp );
            tdp = dp[ pre ][ b ][ fst ][ lst ];
            go( now , b , lst , 0 , tdp );
            if( lst < 3 ){
              for( int nxt = 1 ; nxt < 4 ; nxt ++ ){
                tdp = dp[ pre ][ b ][ fst ][ lst ];
                if( lst == 1 ) tdp += a[ i ]; if( lst == 2 ) tdp -= a[ i ];
                if( nxt == 1 ) tdp -= a[ i ]; if( nxt == 2 ) tdp += a[ i ];
                go( now , b + 1 , lst , nxt , tdp );
              }
            }
          }
        }
  }
  printf( "%d\n" , ans );
}
int main(){
  init();
  solve();
}