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
inline void bye(){ exit(0); }
int __ = 1 , _cs;
/*********default*********/
#define N 303030
struct St{
  LL lft , rgt , tag;
  int l1 , l2 , l3 , r1 , r2 , r3 , bst;
} st[ N << 2 ];
#define L(X) (X<<1)
#define R(X) (1+(X<<1))
#define mid ((l+r)>>1)
int n , a[ N ];
void pull( int no , int l , int r ){
  st[ no ].lft = st[ L( no ) ].lft;
  st[ no ].rgt = st[ R( no ) ].rgt;
  { // l1
    st[ no ].l1 = st[ L( no ) ].l1;
    if( st[ L( no ) ].l1 == ( mid - l + 1 ) &&
        st[ L( no ) ].rgt > st[ R( no ) ].lft )
      st[ no ].l1 = st[ L( no ) ].l1 + st[ R( no ) ].l2;
    if( st[ L( no ) ].l3 == ( mid - l + 1 ) &&
        st[ L( no ) ].rgt < st[ R( no ) ].lft )
      st[ no ].l1 = max( st[ no ].l1 , 
                         st[ L( no ) ].l3 + st[ R( no ) ].l1 );
    if( st[ L( no ) ].l3 == ( mid - l + 1 ) &&
        st[ L( no ) ].rgt != st[ R( no ) ].lft )
      st[ no ].l1 = max( st[ no ].l1 , 
                         st[ L( no ) ].l3 + st[ R( no ) ].l2 );
  }
  { // l2
    st[ no ].l2 = st[ L( no ) ].l2;
    if( st[ L( no ) ].l2 == ( mid - l + 1 ) &&
        st[ L( no ) ].rgt > st[ R( no ) ].lft )
      st[ no ].l2 = st[ L( no ) ].l2 + st[ R( no ) ].l2;
  }
  { // l3
    st[ no ].l3 = st[ L( no ) ].l3;
    if( st[ L( no ) ].l3 == ( mid - l + 1 ) ){
      if( st[ L( no ) ].rgt < st[ R( no ) ].lft )
        st[ no ].l3 = max( st[ no ].l3 ,
                           st[ L( no ) ].l3 + st[ R( no ) ].l3 );
    }
  }
  { // r1
    st[ no ].r1 = st[ R( no ) ].r1;
    if( st[ R( no ) ].r1 == ( r - mid ) ){
      if( st[ R( no ) ].lft > st[ L( no ) ].rgt )
        st[ no ].r1 = st[ R( no ) ].r1 + st[ L( no ) ].r1;
    }
  }
  { // r2
    st[ no ].r2 = st[ R( no ) ].r2;
    if( st[ R( no ) ].r2 == ( r - mid ) ){
      if( st[ R( no ) ].lft > st[ L( no ) ].rgt ){
        st[ no ].r2 = st[ R( no ) ].r2 + st[ L( no ) ].r1;
      }
    }
    if( st[ R( no ) ].r3 == ( r - mid ) ){
      if( st[ R( no ) ].lft < st[ L( no ) ].rgt ){
        st[ no ].r2 = max( st[ no ].r2 ,
                           st[ R( no ) ].r3 + st[ L( no ) ].r2 );
      }
    }
    if( st[ R( no ) ].r3 == ( r - mid ) ){
      if( st[ R( no ) ].lft != st[ L( no ) ].rgt ){
        st[ no ].r2 = max( st[ no ].r2 , 
                           st[ R( no ) ].r3 + st[ L( no ) ].r1 );
      }
    }
  }
  { // r3
    st[ no ].r3 = st[ R( no ) ].r3;
    if( st[ R( no ) ].r3 == ( r - mid ) ){
      if( st[ R( no ) ].lft < st[ L( no ) ].rgt )
        st[ no ].r3 = st[ R( no ) ].r3 + st[ L( no ) ].r3;
    }
  }
  { // bst
    st[ no ].bst = max( st[ L( no ) ].bst , st[ R( no ) ].bst );
    st[ no ].bst = max( st[ no ].bst , st[ no ].l1 );
    st[ no ].bst = max( st[ no ].bst , st[ no ].l2 );
    st[ no ].bst = max( st[ no ].bst , st[ no ].l3 );
    st[ no ].bst = max( st[ no ].bst , st[ no ].r1 );
    st[ no ].bst = max( st[ no ].bst , st[ no ].r2 );
    st[ no ].bst = max( st[ no ].bst , st[ no ].r3 );
    if( st[ L( no ) ].rgt < st[ R( no ) ].lft ){
      st[ no ].bst = max( st[ no ].bst , st[ L( no ) ].r1 + st[ R( no ) ].l1 );
      st[ no ].bst = max( st[ no ].bst , st[ L( no ) ].r1 + st[ R( no ) ].l2 );
      st[ no ].bst = max( st[ no ].bst , st[ L( no ) ].r1 + st[ R( no ) ].l3 );
    }
    if( st[ L( no ) ].rgt > st[ R( no ) ].lft ){
      st[ no ].bst = max( st[ no ].bst , st[ L( no ) ].r1 + st[ R( no ) ].l2 );
      st[ no ].bst = max( st[ no ].bst , st[ L( no ) ].r2 + st[ R( no ) ].l2 );
      st[ no ].bst = max( st[ no ].bst , st[ L( no ) ].r3 + st[ R( no ) ].l2 );
    }
  }
}
void build_st( int no , int l , int r ){
  if( l == r ){
    st[ no ].lft = st[ no ].rgt = a[ l ];
    st[ no ].tag = 0;
    st[ no ].l1 = st[ no ].l2 = 
    st[ no ].l3 = st[ no ].r3 = 
    st[ no ].r1 = st[ no ].r2 = 1;
    st[ no ].bst = 1;
    return;
  }
  build_st( L( no ) , l , mid );
  build_st( R( no ) , mid + 1 , r );
  pull( no , l , r );
}
void push( int no , int l , int r ){
  if( st[ no ].tag == 0 ) return;
  st[ L( no ) ].lft += st[ no ].tag;
  st[ L( no ) ].rgt += st[ no ].tag;
  st[ L( no ) ].tag += st[ no ].tag;
  st[ R( no ) ].lft += st[ no ].tag;
  st[ R( no ) ].rgt += st[ no ].tag;
  st[ R( no ) ].tag += st[ no ].tag;
  st[ no ].tag = 0;
}
void modify( int no , int l , int r , int ql , int qr , LL dlt ){
  if( qr < l || ql > r ) return;
  if( ql <= l && r <= qr ){
    st[ no ].lft += dlt;
    st[ no ].rgt += dlt;
    st[ no ].tag += dlt;
    return;
  }
  push( no , l , r );
  modify( L( no ) , l , mid , ql , qr , dlt );
  modify( R( no ) , mid + 1 , r , ql , qr , dlt );
  pull( no , l , r );
}
void init(){
  n = getint();
  for( int i = 1 ; i <= n ; i ++ )
    a[ i ] = getint();
}
void solve(){
  build_st( 1 , 1 , n );
  int q = getint(); while( q -- ){
    int ql = getint();
    int qr = getint();
    int qd = getint();
    modify( 1 , 1 , n , ql , qr , qd );
    printf( "%d\n" , st[ 1 ].bst );
  }
}
int main(){
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}