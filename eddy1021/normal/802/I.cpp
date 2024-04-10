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
#define L(X) (X<<1)
#define R(X) (1+(X<<1))
#define mid ((l+r)>>1)
struct SegT{
  LL st[ N << 2 ] , tg[ N << 2 ];
  bool cl[ N << 2 ];
  void build( int no , int l , int r ){
    st[ no ] = tg[ no ] = 0; cl[ no ] = false;
    if( l == r ) return;
    build( L( no ) , l , mid );
    build( R( no ) , mid + 1 , r );
  }
  void push( int no , int l , int r ){
    if( cl[ no ] ){
      st[ L( no ) ] = st[ R( no ) ] =
      tg[ L( no ) ] = tg[ R( no ) ] = 0;
      cl[ L( no ) ] = cl[ R( no ) ] = true;
      cl[ no ] = false;
    }
    if( tg[ no ] ){
      tg[ L( no ) ] += tg[ no ];
      tg[ R( no ) ] += tg[ no ];
      st[ L( no ) ] += tg[ no ] * ( mid - l + 1 );
      st[ R( no ) ] += tg[ no ] * ( r - mid );
      tg[ no ] = 0;
    }
  }
  void add( int no , int l , int r , int ql , int qr , int dlt ){
    if( r < ql or l > qr ) return;
    if( ql <= l and r <= qr ){
      tg[ no ] += dlt;
      st[ no ] += dlt * ( r - l + 1 );
      return;
    }
    push( no , l , r );
    add( L( no ) , l , mid , ql , qr , dlt );
    add( R( no ) , mid + 1 , r , ql , qr , dlt );
    st[ no ] = st[ L( no ) ] + st[ R( no ) ];
  }
  void clear( int no , int l , int r , int ql , int qr ){
    if( r < ql or l > qr ) return;
    if( ql <= l and r <= qr ){
      tg[ no ] = st[ no ] = 0;
      cl[ no ] = true;
      return;
    }
    push( no , l , r );
    clear( L( no ) , l , mid , ql , qr );
    clear( R( no ) , mid + 1 , r , ql , qr );
    st[ no ] = st[ L( no ) ] + st[ R( no ) ];
  }
} st;
//const int N = 300010;
struct SA{
#define REP(i,n) for ( int i=0; i<int(n); i++ )
#define REP1(i,a,b) for ( int i=(a); i<=int(b); i++ )
  bool _t[N*2];
  int _s[N*2], _sa[N*2], _c[N*2], x[N], _p[N], _q[N*2], hei[N], r[N];
  int operator [] (int i){ return _sa[i]; }
  void build(int *s, int n, int m){
    memcpy(_s, s, sizeof(int) * n);
    sais(_s, _sa, _p, _q, _t, _c, n, m);
    mkhei(n);
  }
  void mkhei(int n){
    REP(i,n) r[_sa[i]] = i;
    hei[0] = 0;
    REP(i,n) if(r[i]) {
      int ans = i>0 ? max(hei[r[i-1]] - 1, 0) : 0;
      while(_s[i+ans] == _s[_sa[r[i]-1]+ans]) ans++;
      hei[r[i]] = ans;
    }
  }
  void sais(int *s, int *sa, int *p, int *q, bool *t, int *c, int n, int z){
    bool uniq = t[n-1] = true, neq;
    int nn = 0, nmxz = -1, *nsa = sa + n, *ns = s + n, lst = -1;
#define MS0(x,n) memset((x),0,n*sizeof(*(x)))
#define MAGIC(XD) MS0(sa, n); \
    memcpy(x, c, sizeof(int) * z); \
    XD; \
    memcpy(x + 1, c, sizeof(int) * (z - 1)); \
    REP(i,n) if(sa[i] && !t[sa[i]-1]) sa[x[s[sa[i]-1]]++] = sa[i]-1; \
    memcpy(x, c, sizeof(int) * z); \
    for(int i = n - 1; i >= 0; i--) if(sa[i] && t[sa[i]-1]) sa[--x[s[sa[i]-1]]] = sa[i]-1;
    MS0(c, z);
    REP(i,n) uniq &= ++c[s[i]] < 2;
    REP(i,z-1) c[i+1] += c[i];
    if (uniq) { REP(i,n) sa[--c[s[i]]] = i; return; }
    for(int i = n - 2; i >= 0; i--) t[i] = (s[i]==s[i+1] ? t[i+1] : s[i]<s[i+1]);
    MAGIC(REP1(i,1,n-1) if(t[i] && !t[i-1]) sa[--x[s[i]]]=p[q[i]=nn++]=i);
    REP(i, n) if (sa[i] && t[sa[i]] && !t[sa[i]-1]) {
      neq=lst<0||memcmp(s+sa[i],s+lst,(p[q[sa[i]]+1]-sa[i])*sizeof(int));
      ns[q[lst=sa[i]]]=nmxz+=neq;
    }
    sais(ns, nsa, p + nn, q + n, t + n, c + z, nn, nmxz + 1);
    MAGIC(for(int i = nn - 1; i >= 0; i--) sa[--x[s[p[nsa[i]]]]] = p[nsa[i]]);
  }
}sa;
int H[ N ], SA[ N ];
void suffix_array(int* ip, int len) {
  // should padding a zero in the back
  // ip is int array, len is array length
  // ip[0..n-1] != 0, and ip[len] = 0
  ip[len++] = 0;
  sa.build(ip, len, 128);
  for (int i=0; i<len; i++) {
    H[i] = sa.hei[i + 1];
    SA[i] = sa._sa[i + 1];
  }
  // resulting height, sa array \in [0,len)
}
void build(){

}
char c[ N ];
int n , a[ N ];
void init(){
  scanf( "%s" , c );
  n = strlen( c );
  for( int i = 0 ; i < n ; i ++ )
    a[ i ] = c[ i ] - 'a' + 1;
  suffix_array( a , n );
}
void solve(){
  st.build( 1 , 1 , n );
  LL ans = 0;
  //for( int i = 0 ; i < n ; i ++ )
    //printf( "%d %d\n" , SA[ i ] , H[ i ] );
  for( int i = 0 ; i < n ; i ++ ){
    int tlen = n - SA[ i ];
    if( H[ i ] < n )
      st.clear( 1 , 1 , n , H[ i ] + 1 , n );
    if( H[ i ] )
      st.add( 1 , 1 , n , 1 , H[ i ] , 2 );
    if( H[ i ] < tlen )
      st.add( 1 , 1 , n , H[ i ] + 1 , tlen , 1 );
    ans += st.st[ 1 ];
  }
  printf( "%lld\n" , ans );
}
int main(){
  build();
  __ = getint();
  while( __ -- ){
    init();
    solve();
  }
}