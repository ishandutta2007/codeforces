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
inline ll add( ll _x , ll _y , ll _mod = mod7 ){
  ll _ = _x + _y;
  if( _ >= _mod ) _ -= _mod;
  return _;
}
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
ll mymul( ll _a , ll _x , ll _mod ){
  if( _x == 0 ) return 0ll;
  ll _tmp = mymul( _a , _x / 2 , _mod );
  _tmp = add( _tmp , _tmp , _mod );
  if( _x & 1 ) _tmp = add( _tmp , _a , _mod );
  return _tmp;
}
inline bool equal( D _x ,  D _y ){
  return _x > _y - eps && _x < _y + eps;
}
int __ = 1 , _cs;
/*********default*********/
void build(){

}
int sec , mnt , hr , day , dat , mon;
vector< int > sat;
bool isleap( int yy ){
  if( yy % 400 == 0 ) return true;
  if( yy % 100 == 0 ) return false;
  return yy % 4 == 0;
}
int days( int yy ){
  return isleap( yy ) ? 366 : 365;
}
int dyn[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int dyl[]={0,31,29,31,30,31,30,31,31,30,31,30,31};
void pre_build(){
  for( int hh = 0 ; hh < 24 ; hh ++ )
    for( int mm = 0 ; mm < 60 ; mm ++ )
      for( int ss = 0 ; ss < 60 ; ss ++ )
        if( ( sec == -1 || sec == ss ) &&
            ( mnt == -1 || mnt == mm ) &&
            ( hr  == -1 || hr  == hh ) )
          sat.push_back( hh * 3600 + mm * 60 + ss );
}
void init(){
  sec = getint();
  mnt = getint();
  hr  = getint();
  day = getint();
  if( day != -1 ) day --;
  dat = getint();
  mon = getint();
}
void solve(){
  pre_build();
  int q = getint(); while( q -- ){
    LL qt = getint();
    LL ny = 1970 , at = 0 , w = 3;
    while( at + 86400ll * days( ny ) <= qt ){
      w = ( w + days( ny ) ) % 7;
      at += 86400ll * days( ny ); ny ++;
    }
    bool got = false;
    while( !got ){
      bool isl = isleap( ny );
      for( int i = 1 ; i <= 12 && !got ; i ++ )
        if( ( mon == -1 || mon == i ) ){
          if( isl ){
            for( int j = 1 ; j <= dyl[ i ] ; j ++ , w = ( w + 1 ) % 7 ){
              if( ( w == day || j == dat || ( day == -1 && dat == -1 ) ) ){
                if( at + sat.back() > qt ){
                  got = true;
                  int bst = upper_bound( ALL( sat ) , qt - at ) - sat.begin();
                  at += sat[ bst ]; got = true;
                  break;
                }
              }
              at += 86400ll;
            }
          }else{
            for( int j = 1 ; j <= dyn[ i ] ; j ++ , w = ( w + 1 ) % 7 ){
              if( ( w == day || j == dat || ( day == -1 && dat == -1 ) ) ){
                if( at + sat.back() > qt ){
                  got = true;
                  int bst = upper_bound( ALL( sat ) , qt - at ) - sat.begin();
                  at += sat[ bst ]; got = true;
                  break;
                }
              }
              at += 86400ll;
            }
          }
        }else{
          if( isl ){
            at += 86400ll * dyl[ i ];
            w = ( w + dyl[ i ] ) % 7;
          }else{
            at += 86400ll * dyn[ i ];
            w = ( w + dyn[ i ] ) % 7;
          }
        }
      ny ++;
    }
    printf( "%lld\n" , at );
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