#include <bits/stdc++.h>
using namespace std;
const int N = 5010;
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
int n , k , v[ N ];
char c[ N ];
void init(){
  scanf( "%s" , c );
  scanf( "%d" , &k );
  n = strlen( c );
  for( int i = 0 ; i < n ; i ++ )
    v[ i ] = c[ i ] - 'a' + 1;
  v[ n ] = 0;
  suffix_array( v , n );
}
bool gt[ N ][ N ] , pp[ N ][ N ];
bool go( int l , int r ){
  if( l > r ) return true;
  if( gt[ l ][ r ] ) return pp[ l ][ r ];
  gt[ l ][ r ] = true;
  if( c[ l ] != c[ r ] ) return false;
  return pp[ l ][ r ] = go( l + 2 , r - 2 );
}
void solve(){
  for( int i = 0 ; i < n ; i ++ )
    for( int j = i ; j < n ; j ++ )
      go( i , j );
  for( int i = 0 ; i < n ; i ++ )
    for( int j = H[ i ] ; SA[ i ] + j < n ; j ++ ){
      if( !pp[ SA[ i ] ][ SA[ i ] + j ] ) continue;
      int tlen = j + 1;
      for( int ii = i ; ii < n ; ii ++ ){
        if( ii > i ) tlen = min( tlen , H[ ii ] );
        if( tlen < j + 1 ) break;
        k --;
        if( k == 0 ){
          for( int u = SA[ i ] ; u <= SA[ i ] + j ; u ++ )
            putchar( c[ u ] );
          puts( "" );
          exit( 0 );
        }
      }
    }
}
int main(){
  init();
  solve();
}