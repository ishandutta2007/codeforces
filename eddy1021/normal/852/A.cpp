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
#define N 202020
#define int long long
bool good( int vl ){
  int ret = 0;
  while( vl ){
    ret += vl % 10;
    vl /= 10;
  }
  return ret < 10;
}
int n;
string pre;
void okay( int vl ){
  vector<int> d;
  int tv = vl;
  while( tv ){
    d.push_back( tv % 10 );
    tv /= 10;
  }
  reverse( d.begin() , d.end() );
  if( d.size() < 2 ){
    cout << pre << endl;
    cout << vl << endl;
    cout << vl << endl;
    exit(0);
  }
  int tmp = (int)d.size() - 1;
  for( int i = 0 ; i < (1 << tmp) ; i ++ ){
    vector<int> dd(d);
    vector<int> vv;
    for( int j = 0 ; j <= tmp ; j ++ )
      if( j < tmp and ((i >> j) & 1) )
        dd[j+1] += dd[j] * 10;
      else
        vv.push_back(dd[j]);
    int ss = 0;
    for( auto j : vv )
      ss += j;
    if( good( ss ) ){
      cout << pre << endl;
      for( int j = 0 ; j <= tmp ; j ++ ){
        cout << d[j];
        if( j < tmp and ((i >> j) & 1) == 0 )
          cout << '+';
      }
      cout << endl;
      vector<int> tt;
      while( ss ){
        tt.push_back( ss % 10 );
        ss /= 10;
      }
      reverse( tt.begin() , tt.end() );
      for( size_t j = 0 ; j < tt.size() ; j ++ ){
        if( j ) cout << "+";
        cout << tt[ j ];
      }
      cout << endl;
      exit(0);
    }
  }
}
void build(){
}
char c[ 202020 ];
void init(){
  n = getint();
  scanf( "%s" , c );
}
void solve(){ 
  for( int i = 1 ; i < 10 ; i ++ ){
    vector<int> vvv;
    int p = 0 , cc = 0;
    pre.clear();
    for( int j = 0 ; j < n ; j ++ ){
      cc ++; p = p * 10 + c[ j ] - '0';
      pre += c[ j ];
      if( cc >= i or j + 1 == n ){
        vvv.push_back( p );
        p = cc = 0;
        pre += '+';
      }
    }
    pre.pop_back();
    int sum = 0;
    for( auto j : vvv )
      sum += j;
    okay( sum );
  }
  assert( false );
}
int32_t main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}