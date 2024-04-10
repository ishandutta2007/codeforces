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
struct edge {
  int u, v, l, r;
  bool operator<(const edge &a) const{
    return l == a.l ? r < a.r : l < a.l;
  }
};
typedef vector<edge> ve;
int n , top;
namespace ufs {
  struct node {int fa, val, size;} t[N];
  struct info {int x, y; node a, b;} st[N];
  inline void pre() {for(int i=1; i<=n; i++) t[i] = (node){i, 0, 1};}
  inline int find(int x) {while(t[x].fa != x) x = t[x].fa; return x;}
  inline int dis(int x) {
    int ans=0; 
    while(t[x].fa != x) ans ^= t[x].val, x = t[x].fa;
    return ans;
  }
  inline void link(int x, int y) {
    int val = dis(x) ^ dis(y) ^ 1;
    x = find(x); y = find(y);
    st[++top] = (info) {x, y, t[x], t[y]};
    if(t[x].size > t[y].size) swap(x, y);
    t[x].fa = y; t[x].val = val; t[y].size += t[x].size;
  }
  inline void recov(int bot) {
    while(top != bot) {
      info &now = st[top--];
      t[now.x] = now.a; t[now.y] = now.b;
    }
  }
} using namespace ufs;

void cdq(int l, int r, ve &a) {
  int mid = (l+r)>>1, bot = top;
  ve b, c;
  for(int i=0; i<(int)a.size(); i++) {
    edge &now = a[i];
    int x = now.u, y = now.v;
    if(now.l == l && now.r == r) {
      int p = find(x), q = find(y);
      if(p == q) {
        int val = dis(x) ^ dis(y);
        if(val == 0) {
          for(int j=l; j<=r; j++) puts("NO");
          recov(bot); return;
        }
      } else link(x, y);
    } 
    else if(now.r <= mid) b.push_back(now);
    else if(mid < now.l) c.push_back(now);
    else b.push_back( (edge){now.u, now.v, now.l, mid} ), c.push_back( (edge){now.u, now.v, mid+1, now.r} );
  }
  if(l == r) puts("YES");
  else cdq(l, mid, b), cdq(mid+1, r, c);
  recov(bot);
}
void build(){

}
map< pair<int,int> , int > M;
int q;
ve a;
void init(){
  n = getint();
  q = getint();
  for( int i = 1 ; i <= q ; i ++ ){
    int ai = getint();
    int bi = getint();
    if( M.count( {ai, bi} ) ){
      a.push_back((edge){ai, bi, M[ {ai, bi} ], i-1});
      M.erase( {ai, bi} );
    }else
      M[ {ai, bi} ] = i;
  }
  for( auto i : M )
    a.push_back((edge){i.first.first, i.first.second, i.second, q});
}
void solve(){
  pre();
  cdq( 1 , q , a );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}