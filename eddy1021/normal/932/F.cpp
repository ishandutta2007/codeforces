#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define N 101010
struct LiChao_min{
  struct line{
    LL m, c;
    line(LL _m=0, LL _c=0) { m = _m; c = _c; }
    LL eval(LL x) { return m * x + c; }
  };
  struct node{
    node *l, *r; line f;
    node(line v) { f = v; l = r = NULL; }
  };
  typedef node* pnode;
  pnode root; int sz;
#define mid ((l+r)>>1)
  void insert(line &v, int l, int r, pnode &nd){
    if(!nd) { nd = new node(v); return; }
    LL trl = nd->f.eval(l), trr = nd->f.eval(r);
    LL vl = v.eval(l), vr = v.eval(r);
    if(trl <= vl && trr <= vr) return;
    if(trl > vl && trr > vr) { nd->f = v; return; }
    if(trl > vl) swap(nd->f, v);
    if(nd->f.eval(mid) < v.eval(mid)) insert(v, mid + 1, r, nd->r);
    else swap(nd->f, v), insert(v, l, mid, nd->l);
  }
  LL query(int x, int l, int r, pnode &nd){
    if(!nd) return LLONG_MAX;
    if(l == r) return nd->f.eval(x);
    if(mid >= x) return min(nd->f.eval(x), query(x, l, mid, nd->l));
    return min(nd->f.eval(x), query(x, mid + 1, r, nd->r));
  }
  void init(int _sz){ sz = _sz + 1; root = NULL; }
  /* -sz <= query_x <= sz */
  void add_line(LL m, LL c){ line v(m, c); insert(v, -sz, sz, root); }
  LL query(LL x) { return query(x, -sz, sz, root); }
} dp[ N ];
LL n , a[ N ] , b[ N ] , c[ N ];
int id[ N ];
vector<int> v[ N ];
void init(){
  scanf( "%lld" , &n );
  for( int i = 1 ; i <= n ; i ++ )
    scanf( "%lld" , &a[ i ] );
  for( int i = 1 ; i <= n ; i ++ )
    scanf( "%lld" , &b[ i ] );
  for( int i = 1 ; i < n ; i ++ ){
    int ui , vi;
    scanf( "%d%d" , &ui , &vi );
    v[ ui ].push_back( vi );
    v[ vi ].push_back( ui );
  }
}
int sz[ N ];
void collect( int now , int prt , int ID ){
  dp[ ID ].add_line( b[ now ] , c[ now ] );
  for( int son : v[ now ] ){
    if( son == prt ) continue;
    collect( son , now , ID );
  }
}
void go( int now , int prt ){
  sz[ now ] = 1;
  int mx = -1;
  for( int son : v[ now ] ){
    if( son == prt ) continue;
    go( son , now );
    sz[ now ] += sz[ son ];
    if( mx == -1 or sz[ son ] > sz[ mx ] )
      mx = son;
  }
  if( mx == -1 )
    dp[ id[ now ] ].init( N );
  else{
    id[ now ] = id[ mx ];
    for( int son : v[ now ] ){
      if( son == prt or son == mx ) continue;
      collect( son , now , id[ now ] );
    }
    c[ now ] = dp[ id[ now ] ].query( a[ now ] );
  }
  dp[ id[ now ] ].add_line( b[ now ] , c[ now ] );
}
void solve(){
  for( int i = 1 ; i <= n ; i ++ )
    id[ i ] = i;
  go( 1 , 1 );
  for( int i = 1 ; i <= n ; i ++ )
    printf( "%lld%c" , c[ i ] , " \n"[ i == n ] );
}
int main(){
  init();
  solve();
}