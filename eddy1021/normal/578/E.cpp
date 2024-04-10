// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long long ll;
typedef pair<int,int> PII;
#define mod9 1000000009ll
#define mod7 1000000007ll
#define INF  1023456789ll
#define INF16 10000000000000000ll
#define FI first
#define SE second
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define eps 1e-9
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
ll getint(){
    ll _x=0,_tmp=1; char _tc=getchar();    
    while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
    if( _tc == '-' ) _tc=getchar() , _tmp = -1;
    while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
    return _x*_tmp;
}
ll mypow( ll _a , ll _x , ll _mod ){
    if( _x == 0 ) return 1ll;
    ll _tmp = mypow( _a , _x / 2 , _mod );
    _tmp = ( _tmp * _tmp ) % _mod;
    if( _x & 1 ) _tmp = ( _tmp * _a ) % _mod;
    return _tmp;
}
bool equal( D _x ,  D _y ){
    return _x > _y - eps && _x < _y + eps;
}
int __ = 1 , cs;
/*********default*********/
#define N 100010
int n;
char c[ N ];
vector<int> l , r;
set<int> L , R;
typedef set<int>::iterator si;
void build(){

}
vector< vector<int> > sl , sr;
bool cmp( const vector<int>& v1 , const vector<int>& v2 ){
  return ( (int)v1.size() % 2 ) < ( (int)v2.size() % 2 );
}
void init(){
  scanf( "%s" , c + 1 );
  n = strlen( c + 1 );
  for( int i = 1 ; i <= n ; i ++ )
    if( c[ i ] == 'L' ) l.PB( i ) , L.insert( i );
    else r.PB( i ) , R.insert( i );
}
vector<int> cal( int nxt ){
  int got = 0;
  vector<int> vans;
  int pl = 0 , pr = 0;
  while( got < n ){
    if( !nxt ){
      if( pl >= (int)sl.size() ){
        vector<int> empty;
        return empty;
      }
      for( int i = 0 ; i < (int)sl[ pl ].size() ; i ++ )
        vans.PB( sl[ pl ][ i ] );
      if( (int)sl[ pl ].size() % 2 == 1 ) nxt = 1 - nxt;
      got += (int)sl[ pl ].size();
      pl ++;
    }else{
      if( pr >= (int)sr.size() ){
        vector<int> empty;
        return empty;
      }
      for( int i = 0 ; i < (int)sr[ pr ].size() ; i ++ )
        vans.PB( sr[ pr ][ i ] );
      if( (int)sr[ pr ].size() % 2 == 1 ) nxt = 1 - nxt;
      got += (int)sr[ pr ].size();
      pr ++;
    }
  }
  return vans;
}
void output(){
  vector<int> vans , vans2;
  sort( ALL( sl ) , cmp );
  sort( ALL( sr ) , cmp );
  if( l.size() != r.size() ){
    if( l.size() < r.size() ) vans = cal( 1 );
    else vans = cal( 0 );
    int cnt = 0;
    for( int i = 1 ; i < n ; i ++ )
      if( vans[ i ] < vans[ i - 1 ] ) cnt ++;
    printf( "%d\n" , cnt );
    for( int i = 0 ; i < n ; i ++ )
      printf( "%d%c" , vans[ i ] , i == n - 1 ? '\n' : ' ' );
  }else{
    vans = cal( 0 );
    vans2 = cal( 1 );
    int cnt1 = 0 , cnt2 = 0;
    if( (int)vans.size() == n ){
      for( int i = 1 ; i < n ; i ++ )
        if( vans[ i ] < vans[ i - 1 ] ) cnt1 ++;
    }else cnt1 = 1000000;
    if( (int)vans2.size() == n ){
      for( int i = 1 ; i < n ; i ++ )
        if( vans2[ i ] < vans2[ i - 1 ] ) cnt2 ++;
    }else cnt2 = 1000000;
    if( cnt1 < cnt2 ){
      printf( "%d\n" , cnt1 );
      for( int i = 0 ; i < n ; i ++ )
        printf( "%d%c" , vans[ i ] , i == n - 1 ? '\n' : ' ' );
    }else{
      printf( "%d\n" , cnt2 );
      for( int i = 0 ; i < n ; i ++ )
        printf( "%d%c" , vans2[ i ] , i == n - 1 ? '\n' : ' ' );
    }
  }
}
void solve(){
  while( L.size() || R.size() ){
    if( (int)L.size() == 0 ){
      for( si it = R.begin() ; it != R.end() ; it ++ ){
        vector<int> vtmp;
        vtmp.PB( *it );
        sr.PB( vtmp );
      }
      break;
    }
    if( (int)R.size() == 0 ){
      for( si it = L.begin() ; it != L.end() ; it ++ ){
        vector<int> vtmp;
        vtmp.PB( *it );
        sl.PB( vtmp );
      }
      break;
    }
    if( ( *L.begin() ) < ( *R.begin() ) ){
      vector<int> vtmp;
      int nxt = 1 , pre = *L.begin();
      vtmp.PB( pre );
      L.erase( pre );
      while( L.size() || R.size() ){
        if( nxt ){
          if( R.size() && ( R.upper_bound( pre ) != R.end() ) ){
            pre = *R.upper_bound( pre );
            vtmp.PB( pre );
            R.erase( pre );
          }else break;
        }else{
          if( L.size() && ( L.upper_bound( pre ) != L.end() ) ){
            pre = *L.upper_bound( pre );
            vtmp.PB( pre );
            L.erase( pre );
          }else break;
        }
        nxt = 1 - nxt;
      }
      sl.PB( vtmp );
    }else{
      vector<int> vtmp;
      int nxt = 0 , pre = *R.begin();
      vtmp.PB( pre );
      R.erase( pre );
      while( L.size() || R.size() ){
        if( nxt ){
          if( R.size() && ( R.upper_bound( pre ) != R.end() ) ){
            pre = *R.upper_bound( pre );
            vtmp.PB( pre );
            R.erase( pre );
          }else break;
        }else{
          if( L.size() && ( L.upper_bound( pre ) != L.end() ) ){
            pre = *L.upper_bound( pre );
            vtmp.PB( pre );
            L.erase( pre );
          }else break;
        }
        nxt = 1 - nxt;
      }
      sr.PB( vtmp );
    }
  }
  output();
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}