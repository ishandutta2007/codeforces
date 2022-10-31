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
#define N 101010
void build(){

}
int n , t[ N ] , e;
string f[ N ];
string to_s( int x ){
  string ret = "";
  while( x ){
    ret += '0' + x % 10;
    x /= 10;
  }
  reverse( ret.begin() , ret.end() );
  return ret;
}
set<string> op;
int nxt = 0;
string gen( int x ){
  string ret = "";
  for( int i = 0 ; i < 6 ; i ++ ){
    ret += x % 26 + 'a';
    x /= 10;
  }
  return ret;
}
int ptr;
string gar(){
  while( true ){
    string ss = gen( ptr ++ );
    if( op.find( ss ) == op.end() ){
      op.insert( ss );
      return ss;
    }
  }
}
void init(){
  cin >> n;
  //n = 100000;
  for( int i = 0 ; i < n ; i ++ ){
    cin >> f[ i ] >> t[ i ];
    //t[ i ] = i >= 50000;
    //f[ i ] = to_s( i + 1 );
    e += t[ i ];
    op.insert( f[ i ] );
  }
}
bool ok[ N ] , used[ N ] , blk[ N ];
int wt[ N ] , okc;
map<string,int> M;
vector<int> nok[ 2 ];
vector<int> gg[ 2 ] , other[ 2 ];
vector< pair<string,string> > ans;
void solve(){
  for( int i = 1 ; i <= n ; i ++ )
    M[ to_s( i ) ] = i;
  for( int i = 0 ; i < n ; i ++ ){
    auto it = M.find( f[ i ] );
    if( it == M.end() ) continue;
    int vl = it->second;
    if( ( t[ i ] == 1 and vl <= e ) or
        ( t[ i ] == 0 and vl > e ) ){
      used[ vl ] = true;
      ok[ i ] = true;
      okc ++;
      continue;
    }
  }
  for( int i = 0 ; i < n ; i ++ ){
    if( ok[ i ] ) continue;
    auto it = M.find( f[ i ] );
    if( it == M.end() ){
      other[ t[ i ] ].push_back( i );
      continue;
    }
    int vl = it->second;
    gg[ t[ i ] ].push_back( i );
    blk[ vl ] = true;
  }
  for( int i = 1 ; i <= n ; i ++ ){
    if( used[ i ] or blk[ i ] ) continue;
    if( i <= e )
      nok[ 1 ].push_back( i );
    else
      nok[ 0 ].push_back( i );
  }
  while( okc < n ){
    bool keep = false;
    for( int i = 0 ; i < 2 ; i ++ )
      while( not nok[ i ].empty() and
             not gg[ i ].empty() ){
        int vl = nok[ i ].back(); nok[ i ].pop_back();
        int who = gg[ i ].back(); gg[ i ].pop_back();
        ans.push_back( { f[ who ] , to_s( vl ) } );
        used[ vl ] = true;
        ok[ who ] = true;
        okc ++;
        {
          auto it = M.find( f[ who ] );
          int tvl = it->second;
          blk[ tvl ] = false;
          if( tvl <= e )
            nok[ 1 ].push_back( tvl );
          else
            nok[ 0 ].push_back( tvl );
        }
        keep = true;
      }
    if( keep )
      continue;
    keep = false;
    for( int i = 0 ; i < 2 ; i ++ )
      while( not nok[ i ].empty() and
             not other[ i ].empty() ){
        int vl = nok[ i ].back(); nok[ i ].pop_back();
        int who = other[ i ].back(); other[ i ].pop_back();
        ans.push_back( { f[ who ] , to_s( vl ) } );
        used[ vl ] = true;
        ok[ who ] = true;
        okc ++;
        keep = true;
      }
    if( keep )
      continue;
    for( int i = 0 ; i < 2 ; i ++ )
      if( not gg[ i ].empty() ){
        int who = gg[ i ].back(); gg[ i ].pop_back();
        string cur = gar();
        ans.push_back( { f[ who ] , cur } );
        {
          auto it = M.find( f[ who ] );
          int tvl = it->second;
          blk[ tvl ] = false;
          if( tvl <= e )
            nok[ 1 ].push_back( tvl );
          else
            nok[ 0 ].push_back( tvl );
        }
        other[ i ].push_back( who );
        f[ who ] = cur;
        break;
      }
  }
  cout << ans.size() << endl;
  for( auto i : ans )
    cout << "move " << i.first << " " << i.second << endl;
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}