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
ll mypow( ll _a , ll _x , ll _mod ){
  if( _x == 0 ) return 1ll;
  ll _tmp = mypow( _a , _x / 2 , _mod );
  _tmp = ( _tmp * _tmp ) % _mod;
  if( _x & 1 ) _tmp = ( _tmp * _a ) % _mod;
  return _tmp;
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
inline bool equal( D _x ,  D _y ){
  return _x > _y - eps && _x < _y + eps;
}
int __ = 1 , _cs;
/*********default*********/
struct SA{
#define REP(i,n) for ( int i=0; i<int(n); i++ )
#define REP1(i,a,b) for ( int i=(a); i<=int(b); i++ )
  static const int MXN = 300010;
  bool _t[MXN*2];
  int _s[MXN*2], _sa[MXN*2], _c[MXN*2], x[MXN], _p[MXN], _q[MXN*2], hei[MXN], r[MXN];
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
#define N 101010
int h[ N ] , s[ N ];
void suffix_array(int* ip, int len) {
  // should padding a zero in the back
  // s is int array, n is array length
  // s[0..n-1] != 0, and s[n] = 0
  // resulting SA will be length n+1
  ip[len++] = 0;
  sa.build(ip, len, 128);
  // original 1-base
  for (int i=0; i<len; i++) {
    h[i] = sa.hei[i + 1];
    s[i] = sa._sa[i + 1];
  }
}
ll st[ N << 2 ] , ad[ N << 2 ] , tg[ N << 2 ];
#define L(X) (X<<1)
#define R(X) (1+(X<<1))
#define mid ((l+r)>>1)
inline void push( int no , int l , int r ){
  if( ad[ no ] || tg[ no ] ){
    if( l < r ){
      if( tg[ no ] ){
        tg[ L( no ) ] = tg[ R( no ) ] = 1;
        ad[ L( no ) ] = ad[ R( no ) ] = 0;
        st[ L( no ) ] = mid - l + 1;
        st[ R( no ) ] = r - mid;
      }
      if( ad[ no ] ){
        ad[ L( no ) ] += ad[ no ];
        ad[ R( no ) ] += ad[ no ];
        st[ L( no ) ] += ( mid - l + 1 ) * ad[ no ];
        st[ R( no ) ] += ( r - mid ) * ad[ no ];
      }
    }
  }
  ad[ no ] = tg[ no ] = 0;
}
inline void pull( int no ){
  st[ no ] = st[ L( no ) ] + st[ R( no ) ];
}
void Add( int no , int l , int r , int ql , int qr ){
  if( l > qr || r < ql ) return;
  push( no , l , r );
  if( ql <= l && r <= qr ){
    ad[ no ] ++;
    st[ no ] += r - l + 1;
    return;
  }
  Add( L( no ) , l , mid , ql , qr );
  Add( R( no ) , mid + 1 , r , ql , qr );
  pull( no );
}
void Tag( int no , int l , int r , int ql , int qr ){
  if( l > qr || r < ql ) return;
  push( no , l , r );
  if( ql <= l && r <= qr ){
    tg[ no ] = 1;
    ad[ no ] = 0;
    st[ no ] = r - l + 1;
    return;
  }
  Tag( L( no ) , l , mid , ql , qr );
  Tag( R( no ) , mid + 1 , r , ql , qr );
  pull( no );
}
ll query( int no , int l , int r , int ql , int qr ){
  if( l > qr || r < ql || ql > qr ) return 0;
  push( no , l , r );
  if( ql <= l && r <= qr ) return st[ no ];
  return query( L( no ) , l , mid , ql , qr ) +
         query( R( no ) , mid + 1 , r , ql , qr );
}
char c[ N ];
int vl[ N ] , len , l[ N ];
void build(){

}
void init(){
  scanf( "%s" , c );
  len = strlen( c );
  for( int i = 0 ; i < len ; i ++ )
    vl[ i ] = c[ i ] - 'a' + 1;
  suffix_array( vl , len );
  for( int i = 0 ; i < len ; i ++ )
    l[ i ] = len - s[ i ];
  // h[0]..h[len-1]
  // s[0]..s[len-1]
}
void solve(){
  ll ans = l[ 0 ];
  Tag( 1 , 1 , len , 1 , l[ 0 ] );
  for( int i = 1 ; i < len ; i ++ ){
    if( h[ i ] )
      Add( 1 , 1 , len , 1 , h[ i ] );
    if( h[ i ] < l[ i ] )
      Tag( 1 , 1 , len , h[ i ] + 1 , l[ i ] );
    ans += query( 1 , 1 , len , 1 , l[ i ] );
  }
  cout << ans << endl;
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}