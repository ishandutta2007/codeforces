#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define N 62
LL cnt[ N ] , sft[ N ] , nsft[ N ];
LL at( LL x ){
  LL ret = 0;
  while( x ){
    ret ++;
    x >>= 1;
  }
  return ret - 1;
}
LL ans[ N ] , asz;
void rotate( LL& x , int cur , LL dlt ){
  x ^= (1LL << cur);
  x = (x + dlt) % cnt[cur];
  x ^= (1LL << cur);
}
int main(){
  for( int i = 0 ; i < N ; i ++ )
    cnt[ i ] = (1LL << i);
  int q; scanf( "%d" , &q ); while( q -- ){
    int cmd;
    scanf( "%d" , &cmd );
    if( cmd <= 2 ){
      LL x , k;
      scanf( "%lld%lld" , &x , &k );
      int lvl = at( x );
      k = (k % cnt[lvl] + cnt[lvl]) % cnt[lvl];
      sft[ lvl ] = (sft[lvl] + k) % cnt[lvl];
      if( cmd == 1 )
        nsft[ lvl ] = (nsft[lvl] + k) % cnt[lvl];
      continue;
    }
    LL x; scanf( "%lld" , &x );
    asz = 0;
    int cur = at( x );
    while( x ){
      ans[ asz ++ ] = x;
      rotate( x , cur , sft[ cur ] );
      x >>= 1;
      if( cur == 0 ) break;
      cur --;
      rotate( x , cur , (cnt[cur] - nsft[ cur ]) % cnt[cur] );
    }
    for( int i = 0 ; i < asz ; i ++ )
      printf( "%lld%c" , ans[ i ] , " \n"[ i + 1 == asz ] );
  }
}