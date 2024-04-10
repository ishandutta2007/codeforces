#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define N 101010
int n , a[ N ];
vector<int> v[ N ];
void init(){
  scanf( "%d" , &n );
  for( int i = 1 ; i <= n ; i ++ )
    scanf( "%d" , &a[ i ] );
  for( int i = 1 ; i < n ; i ++ ){
    int ui , vi; scanf( "%d%d" , &ui , &vi );
    v[ ui ].push_back( vi );
    v[ vi ].push_back( ui );
  }
}
LL cnt;
inline pair<int,int> operator+( const pair<int,int> p1 , const pair<int,int> p2 ){
  return { p1.first + p2.first , p1.second + p2.second };
}
pair<int,int> go( int now , int prt , int bt ){
  pair<int,int> tp = { 0 , 0 };
  int nt = ( a[ now ] >> bt ) & 1;
  for( int son : v[ now ] ){
    if( son == prt ) continue;
    pair<int,int> ttp = go( son , now , bt );
    if( nt ){
      cnt += (LL)tp.first * ttp.first;
      cnt += (LL)tp.second * ttp.second;
    }else{
      cnt += (LL)tp.first * ttp.second;
      cnt += (LL)tp.second * ttp.first;
    }
    tp = tp + ttp;
  }
  if( nt ){
    swap( tp.first , tp.second );
    tp.second ++;
  }else
    tp.first ++;
  cnt += tp.second;
  return tp;
}
inline LL cal( int bt ){
  cnt = 0;
  go( 1 , 1 , bt );
  return cnt;
}
void solve(){
  LL ans = 0;
  for( int i = 0 ; i < 20 ; i ++ )
    ans += ( 1 << i ) * cal( i );
  printf( "%lld\n" , ans );
}
int main(){
  init();
  solve();
}