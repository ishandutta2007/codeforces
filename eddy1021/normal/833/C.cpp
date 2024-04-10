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
#define Bye exit(0)
int __ = 1 , _cs;
/*********default*********/
void build(){

}
int digit( LL tmp ){
  int ret = 0;
  while( tmp ){
    ret ++;
    tmp /= 10;
  }
  return ret;
}
LL l , r;
LL vl[ 20 ] , vr[ 20 ];
void init(){
  l = getint();
  r = getint();
  LL tmpl = l , tmpr = r;
  for( int i = 0 ; i < 20 ; i ++ ){
    vl[ i ] = tmpl % 10;
    vr[ i ] = tmpr % 10;
    tmpl /= 10;
    tmpr /= 10;
  }
}
int ans , cc[ 10 ] , res;
bool debug;
bool ok( int bt , bool up , bool dn ){
  if( bt < 0 ) return true;
  if( up and dn ){
    for( int i = vl[ bt ] ; i <= vr[ bt ] ; i ++ ){
      if( i == 0 and bt + 1 == res ) continue;
      if( i and cc[ i ] == 0 ) continue;
      if( vl[ bt ] < i and i < vr[ bt ] ) return true;
      if( i ){
        res --;
        cc[ i ] --;
      }
      if( ok( bt - 1 , i == vr[ bt ] , i == vl[ bt ] ) ){
        if( i ){
          res ++;
          cc[ i ] ++;
        }
        return true;
      }
      if( i ){
        res ++;
        cc[ i ] ++;
      }
    }
    return false;
  }
  if( up ){
    for( int i = 0 ; i <= vr[ bt ] ; i ++ ){
      if( i == 0 and bt + 1 == res ) continue;
      if( i and cc[ i ] == 0 ) continue;
      if( i < vr[ bt ] ) return true;
      if( i ){
        res --;
        cc[ i ] --;
      }
      if( ok( bt - 1 , up , dn ) ){
        if( i ){
          cc[ i ] ++;
          res ++;
        }
        return true;
      }
      if( i ){
        cc[ i ] ++;
        res ++;
      }
    }
    return false;
  }
  if( dn ){
    for( int i = 9 ; i >= vl[ bt ] ; i -- ){
      if( i == 0 and bt + 1 == res ) continue;
      if( i and cc[ i ] == 0 ) continue;
      if( i > vl[ bt ] ) return true;
      if( i ){
        cc[ i ] --;
        res --;
      }
      if( ok( bt - 1 , up , dn ) ){
        if( i ){
          cc[ i ] ++;
          res ++;
        }
        return true;
      }
      if( i ){
        cc[ i ] ++;
        res ++;
      }
    }
    return false;
  }
  assert( false );
}
bool okay( LL vv , int tot ){
  if( l <= vv and vv <= r ) return true;
  if( vv > r ) return false;
  //debug = ( vv == 126 );
  res = tot;
  return ok( 18 , true , true );
}
void go( int now , int tot , LL vv ){
  if( now == 10 ){
    if( tot == 0 ) return;
    if( okay( vv , tot ) ){
      //cerr << vv << endl;
      ans ++;
    }
    return;
  }
  for( int i = 0 ; tot + i <= 18 ; i ++ ){
    cc[ now ] = i;
    go( now + 1 , tot + i , vv );
    vv = vv * 10 + now;
  }
}
void solve(){
  go( 1 , 0 , 0 );
  printf( "%d\n" , ans );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}