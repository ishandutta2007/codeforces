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
#define N 777777
PII _st[ N << 2 ];
#define L(X) (X<<1)
#define R(X) (1+(X<<1))
#define mid ((l+r)>>1)
void build_st( int no , int l , int r ){
  if( l == r ){
    _st[ no ].SE = -l;
    return;
  }
  build_st( L( no ) , l , mid );
  build_st( R( no ) , mid + 1 , r );
  _st[ no ] = _st[ L( no ) ];
}
void modify( int no , int l , int r , int p , int dlt ){
  if( l == r ){
    _st[ no ].FI += dlt;
    return;
  }
  if( p <= mid ) modify( L( no ) , l , mid , p , dlt );
  else modify( R( no ) , mid + 1 , r , p , dlt );
  _st[ no ] = max( _st[ L( no ) ] , _st[ R( no ) ] );
}
PII query( int no , int l , int r , int ql , int qr ){
  if( l == ql && r == qr ) return _st[ no ];
  if( qr <= mid ) return query( L( no ) , l , mid , ql , qr );
  if( mid <  ql ) return query( R( no ) , mid + 1 , r , ql , qr );
  return max( query( L( no ) , l , mid , ql , mid ) ,
              query( R( no ) , mid + 1 , r , mid + 1 , qr ) );
}
struct SA{
#define REP(i,n) for ( int i=0; i<int(n); i++ )
#define REP1(i,a,b) for ( int i=(a); i<=int(b); i++ )
  static const int MXN = N;
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
int s[ N ] , H[ N ] , SA[ N ] , n , slen , pid[ N ] , id[ N ];
char in[ N ];
int pos[ N ] , xlen[ N ];
inline void suffix_array(int* ip, int len) {
  ip[len++] = 0;
  sa.build(ip, len, 128);
  for (int i=0; i<len; i++) {
    H[i] = sa.hei[i + 1];
    SA[i] = sa._sa[i + 1];
  }
}
#define K 20
int rmq[ N ][ K ] , bt[ N ];
inline void build(){
  bt[ 0 ] = 0;
  for( int i = 1 ; i < N ; i ++ ){
    bt[ i ] = bt[ i - 1 ];
    if( ( 1 << ( bt[ i ] + 1 ) ) < i ) bt[ i ] ++;
  }
}
inline void build_rmq(){
  for( int i = 0 ; i < slen ; i ++ )
    rmq[ i ][ 0 ] = H[ i ];
  for( int i = 1 ; i < K ; i ++ )
    for( int j = 0 ; j + ( 1 << i ) - 1 < slen ; j ++ )
      rmq[ j ][ i ] = min( rmq[ j ][ i - 1 ] , rmq[ j + ( 1 << ( i - 1 ) ) ][ i - 1 ] );
}
inline int query_rmq( int l , int r ){
  if( l > r ) return 0;
  int nbt = bt[ r - l + 1 ];
  return min( rmq[ l ][ nbt ] , rmq[ r - ( 1 << nbt ) + 1 ][ nbt ] );
}
inline PII find_int( int sl , int sr ){
  int tlen = sr - sl + 1;
  int tpos = pos[ sl ];
  int bl , br , bmid , al = tpos , ar = tpos;
  bl = 0; br = tpos - 1;
  while( bl <= br ){
    bmid = ( bl + br ) >> 1;
    if( query_rmq( bmid + 1 , tpos ) >= tlen )
      al = bmid, br = bmid - 1;
    else bl = bmid + 1;
  }
  bl = tpos + 1; br = slen - 1;
  while( bl <= br ){
    bmid = ( bl + br ) >> 1;
    if( query_rmq( tpos + 1 , bmid ) >= tlen )
      ar = bmid , bl = bmid + 1;
    else br = bmid - 1;
  }
  return MP( al , ar );
}
inline void scan( int idx ){
  scanf( "%s" , in );
  xlen[ idx ] = strlen( in );
  for( int i = 0 ; i < xlen[ idx ] ; i ++ ){
    s[ slen + i ] = in[ i ] - 'a' + 1;
    pid[ slen + i ] = idx;
  }
  s[ slen + xlen[ idx ] ] = 30;
  pid[ slen + xlen[ idx ] ] = -1;
  slen += xlen[ idx ] + 1;
}
inline void init(){
  scan( 0 );
  n = getint();
  for( int i = 1 ; i <= n ; i ++ )
    scan( i );
  suffix_array( s , slen );
  for( int i = 0 ; i < slen ; i ++ ){
    id[ i ] = pid[ SA[ i ] ];
    if( id[ i ] == 0 )
      pos[ SA[ i ] ] = i;
  }
  build_st( 1 , 1 , n );
  build_rmq();
}
int ans[ N ] , ansi[ N ];
int q , l[ N ] , r[ N ] , pl[ N ] , pr[ N ] , kkk;
vector<int> qv;
bool cmp( int ii , int jj ){
  if( pl[ ii ] / kkk != pl[ jj ] / kkk )
    return pl[ ii ] / kkk < pl[ jj ] / kkk;
  return pr[ ii ] < pr[ jj ];
}
inline void pre_solve(){
  kkk = max( (int)sqrt( slen ) , 100 );
  q = getint();
  for( int i = 0 ; i < q ; i ++ ){
    qv.PB( i );
    l[ i ] = getint();      r[ i ] = getint();
    pl[ i ] = getint() - 1; pr[ i ] = getint() - 1;
    PII tp = find_int( pl[ i ] , pr[ i ] );
    pl[ i ] = tp.FI; pr[ i ] = tp.SE;
  }
  sort( ALL( qv ) , cmp );
}
inline void adj( int idx , int dlt ){
  if( idx < 0 || idx >= slen ) return;
  if( id[ idx ] < 1 || id[ idx ] > n ) return;
  modify( 1 , 1 , n , id[ idx ] , dlt );
}
inline void calc(){
  int nl = -1 , nr = -1;
  for( size_t _ = 0 ; _ < qv.size() ; _ ++ ){
    int i = qv[ _ ];
    while( nl < pl[ i ] ) adj( nl ++ , -1 );
    while( nl > pl[ i ] ) adj( -- nl , +1 );
    while( nr < pr[ i ] ) adj( ++ nr , +1 );
    while( nr > pr[ i ] ) adj( nr -- , -1 );
    PII ap = query( 1 , 1 , n , l[ i ] , r[ i ] );
    ans[ i ] = ap.FI; ansi[ i ] = -ap.SE;
  }
}
inline void solve(){
  pre_solve();
  calc();
  for( int i = 0 ; i < q ; i ++ )
    printf( "%d %d\n" , ansi[ i ] , ans[ i ] );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}