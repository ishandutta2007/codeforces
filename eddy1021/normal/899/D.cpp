// eddy1021
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long double LD;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
#define mod9 1000000009LL
#define mod7 1000000007LL
#define INF  1023456789LL
#define INF16 10000000000000000LL
#define eps 1e-9
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#ifndef ONLINE_JUDGE
#define debug(...) printf(__VA_ARGS__)
#else 
#define debug(...)
#endif
inline LL getint(){
  LL _x=0,_tmp=1; char _tc=getchar();    
  while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
  if( _tc == '-' ) _tc=getchar() , _tmp = -1;
  while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
  return _x*_tmp;
}
inline LL add( LL _x , LL _y , LL _mod = mod7 ){
  _x += _y;
  return _x >= _mod ? _x - _mod : _x;
}
inline LL sub( LL _x , LL _y , LL _mod = mod7 ){
  _x -= _y;
  return _x < 0 ? _x + _mod : _x;
}
inline LL mul( LL _x , LL _y , LL _mod = mod7 ){
  _x *= _y;
  return _x >= _mod ? _x % _mod : _x;
}
LL mypow( LL _a , LL _x , LL _mod ){
  if( _x == 0 ) return 1LL;
  LL _ret = mypow( mul( _a , _a , _mod ) , _x >> 1 , _mod );
  if( _x & 1 ) _ret = mul( _ret , _a , _mod );
  return _ret;
}
LL mymul( LL _a , LL _x , LL _mod ){
  if( _x == 0 ) return 0LL;
  LL _ret = mymul( add( _a , _a , _mod ) , _x >> 1 , _mod );
  if( _x & 1 ) _ret = add( _ret , _a , _mod );
  return _ret;
}
inline bool equal( D _x ,  D _y ){
  return _x > _y - eps && _x < _y + eps;
}
void sleep( double sec = 1021 ){
  clock_t s = clock();
  while( clock() - s < CLOCKS_PER_SEC * sec );
}
#define Bye exit(0)
int __ = 1 , _cs;
/*********default*********/
void build(){

}
LL n;
void init(){
  n = getint();
}
LL cnt( LL x ){
  LL ret = 0;
  while( x % 10 == 9 ){
    ret ++;
    x /= 10;
  }
  return ret;
}
LL bf(){
  LL ret = 0 , bst = 0;
  for( LL i = 1 ; i <= n ; i ++ )
    for( LL j = i + 1 ; j <= n ; j ++ ){
      LL tc = cnt( i + j );
      if( tc < bst ) continue;
      if( tc == bst ) ret ++;
      else{
        bst = tc;
        ret = 1;
      }
    }
  return ret;
}
LL cal( LL N ){
  if( N < 10 ) return bf();
  LL ans = 0;
  LL goal = 1;
  while( goal <= N ) goal *= 10;
  if( goal - 1 - N >= N ){
    goal /= 10;
    // 0 -> 999999
    // 1 -> 999998
    // 2 -> 999997
    // 49999 -> 500000
    LL tot = N / goal;
    for( int i = 0 ; i < tot ; i ++ )
      for( int j = 0 ; j < tot ; j ++ )
        if( i )
          ans += goal / 2;
        else
          ans += goal / 2 - 1;
    //cerr << tot << " " << goal << " " << ans << endl;

    ans += (N % goal + 1) * tot;
    if( N % goal == goal - 1 ) ans --;
    {
      N %= goal;
      if( goal - 1 - N < N ){
        LL bl = 0 , br = N , ba = 0;
        while( bl <= br ){
          LL bmid = (bl + br) >> 1;
          if( goal - 1 - bmid < bmid )
            ba = bmid , br = bmid - 1;
          else
            bl = bmid + 1;
        }
        ans += N - ba + 1;
      }
    }
  }else{
    LL bl = 1 , br = N , ba = N;
    while( bl <= br ){
      LL bmid = (bl + br) >> 1;
      if( goal - 1 - bmid < bmid )
        ba = bmid , br = bmid - 1;
      else
        bl = bmid + 1;
    }
    ans = N - ba + 1;
    if( N == goal - 1 ) ans --;
  }
  return ans;
}
void solve(){
  if( n < 1000 ){
    cout << bf() << endl;
    return;
  }
  LL ans = cal( n );
  cout << ans << endl;
  //LL tans = bf();
  //if( ans != tans )
    //cerr << n << " " << ans << " " << tans << endl;
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}