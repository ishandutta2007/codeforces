// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long double LD;
typedef long long ll;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef pair<LD,LD> Pt;
typedef tuple<int,int,int> tiii;
typedef tuple<LL,LL,LL> tlll;
#define mod9 1000000009ll
#define mod7 1000000007ll
#define INF  1023456789ll
#define INF16 10000000000000000ll
#define FI first
#define SE second
#define X FI
#define Y SE
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define eps 1e-9
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
#ifndef ONLINE_JUDGE
#define debug(...) printf(__VA_ARGS__)
#else 
#define debug(...)
#endif
inline ll getint(){
  ll _x=0,_tmp=1; char _tc=getchar();    
  while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
  if( _tc == '-' ) _tc=getchar() , _tmp = -1;
  while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
  return _x*_tmp;
}
// inline ll add( ll _x , ll _y , ll _mod = mod7 ){
  // ll _ = _x + _y;
  // if( _ >= _mod ) _ -= _mod;
  // return _;
// }
inline ll sub( ll _x , ll _y , ll _mod = mod7 ){
  ll _ = _x - _y;
  if( _ < 0 ) _ += _mod;
  return _;
}
inline ll mul( ll _x , ll _y , ll _mod = mod7 ){
  ll _ = _x * _y;
  if( _ >= _mod ) _ %= _mod;
  return _;
}
ll mypow( ll _a , ll _x , ll _mod ){
  if( _x == 0 ) return 1ll;
  ll _tmp = mypow( _a , _x / 2 , _mod );
  _tmp = mul( _tmp , _tmp , _mod );
  if( _x & 1 ) _tmp = mul( _tmp , _a , _mod );
  return _tmp;
}
// ll mymul( ll _a , ll _x , ll _mod ){
  // if( _x == 0 ) return 0ll;
  // ll _tmp = mymul( _a , _x / 2 , _mod );
  // _tmp = add( _tmp , _tmp , _mod );
  // if( _x & 1 ) _tmp = add( _tmp , _a , _mod );
  // return _tmp;
// }
inline bool equal( D _x ,  D _y ){
  return _x > _y - eps && _x < _y + eps;
}
int __ = 1 , _cs;
/*********default*********/
void build(){

}
int q;
void init(){
  q = getint();
}
inline LL find_p( LL u , LL v ){
  int du = 0 , dv = 0;
  LL tu = u , tv = v;
  while( tu > 1 ) du ++ , tu >>= 1;
  while( tv > 1 ) dv ++ , tv >>= 1;
  if( du < dv ){
    swap( du , dv );
    swap( u , v );
  }
  while( du > dv ){
    du --;
    u >>= 1;
  }
  while( u != v ){
    u >>= 1;
    v >>= 1;
  }
  return u;
}
map< PLL , LL > M;
inline void add( LL u , LL v , LL w ){
  if( u == v ) return;
  LL p = find_p( u , v );
  if( v == p ) swap( u , v );
  if( u == p ){
    LL tmp = v >> 1;
    while( tmp != p ){
      if( tmp * 2 == v ) M[ { tmp , 0 } ] += w;
      else M[ { tmp , 1 } ] += w;
      tmp >>= 1;
      v >>= 1;
    }
    if( tmp * 2 == v ) M[ { tmp , 0 } ] += w;
    else M[ { tmp , 1 } ] += w;
    return;
  }
  LL tu = u >> 1 , tv = v >> 1;
  while( tu != p ){
    if( tu * 2 == u ) M[ { tu , 0 } ] += w;
    else M[ { tu , 1 } ] += w;
    tu >>= 1;
    u >>= 1;
  }
  if( tu * 2 == u ) M[ { tu , 0 } ] += w;
  else M[ { tu , 1 } ] += w;
  while( tv != p ){
    if( tv * 2 == v ) M[ { tv , 0 } ] += w;
    else M[ { tv , 1 } ] += w;
    tv >>= 1;
    v >>= 1;
  }
  if( tv * 2 == v ) M[ { tv , 0 } ] += w;
  else M[ { tv , 1 } ] += w;
}
inline LL query( LL u , LL v ){
  if( u == v ) return 0;
  LL p = find_p( u , v );
  if( v == p ) swap( u , v );
  LL ans = 0;
  if( u == p ){
    LL tv = v >> 1;
    while( tv != p ){
      if( tv * 2 == v ){
        if( M.count( { tv , 0 } ) )
          ans += M[ { tv, 0  } ];
      }else{
        if( M.count( { tv , 1 } ) )
          ans += M[ { tv , 1  } ];
      }
      tv >>= 1;
      v >>= 1;
    }
    if( tv * 2 == v ){
      if( M.count( { tv , 0 } ) )
        ans += M[ { tv, 0  } ];
    }else{
      if( M.count( { tv , 1 } ) )
        ans += M[ { tv , 1  } ];
    }
  }else{
    LL tv = v >> 1 , tu = u >> 1;
    while( tv != p ){
      if( tv * 2 == v ){
        if( M.count( { tv , 0 } ) )
          ans += M[ { tv, 0  } ];
      }else{
        if( M.count( { tv , 1 } ) )
          ans += M[ { tv , 1  } ];
      }
      tv >>= 1;
      v >>= 1;
    }
    if( tv * 2 == v ){
      if( M.count( { tv , 0 } ) )
        ans += M[ { tv, 0  } ];
    }else{
      if( M.count( { tv , 1 } ) )
        ans += M[ { tv , 1  } ];
    }
    while( tu != p ){
      if( tu * 2 == u ){
        if( M.count( { tu , 0 } ) )
          ans += M[ { tu , 0  } ];
      }else{
        if( M.count( { tu , 1 } ) )
          ans += M[ { tu , 1  } ];
      }
      tu >>= 1;
      u >>= 1;
    }
    if( tu * 2 == u ){
      if( M.count( { tu , 0 } ) )
        ans += M[ { tu, 0  } ];
    }else{
      if( M.count( { tu , 1 } ) )
        ans += M[ { tu , 1  } ];
    }
  }
  return ans;
}
void solve(){
  while( q -- ){
    int cmd = getint();
    LL u = getint();
    LL v = getint();
    if( cmd == 1 ) add( u , v , getint() );
    else printf( "%lld\n" , query( u , v ) );
  }
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}