// eddy1021
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL mod7=1000000007LL;
inline LL getint(){
  LL _x=0,_tmp=1; char _tc=getchar();    
  while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
  if( _tc == '-' ) _tc=getchar() , _tmp = -1;
  while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
  return _x*_tmp;
}
inline LL add(LL _x, LL _y, LL _mod=mod7){
  _x+=_y;
  return _x>=_mod ? _x-_mod : _x;
}
inline LL sub(LL _x, LL _y, LL _mod=mod7){
  _x-=_y;
  return _x<0 ? _x+_mod : _x;
}
inline LL mul(LL _x, LL _y ,LL _mod=mod7){
  _x*=_y;
  return _x>=_mod ? _x%_mod : _x;
}
LL mypow(LL _a, LL _x, LL _mod){
  if(_x == 0) return 1LL;
  LL _ret = mypow(mul(_a, _a, _mod), _x>>1, _mod);
  if(_x & 1) _ret=mul(_ret, _a, _mod);
  return _ret;
}
LL mymul(LL _a, LL _x, LL _mod){
  if(_x == 0) return 0LL;
  LL _ret = mymul(add(_a, _a, _mod), _x>>1, _mod);
  if(_x & 1) _ret=add(_ret, _a, _mod);
  return _ret;
}
void sleep(double sec = 1021){
  clock_t s = clock();
  while(clock() - s < CLOCKS_PER_SEC * sec);
}
#define Bye exit(0)
int __ = 1 , _cs;
/*********default*********/
#define SZ(c) ((int)(c).size())
struct Maxflow {
  static const int MAXV = 20010;
  static const int INF  = 1000000;
  struct Edge {
    int v, c, id, r;
    Edge(int _v, int _c, int _id, int _r):
      v(_v), c(_c), id(_id), r(_r) {}
  };
  int s, t;
  vector<Edge> G[MAXV*2];
  int iter[MAXV*2], d[MAXV*2], gap[MAXV*2], tot;
  void init(int x) {
    tot = x+2;
    s = x+1, t = x+2;
    for(int i = 0; i <= tot; i++) {
      G[i].clear();
      iter[i] = d[i] = gap[i] = 0;
    }
  }
  void addEdge(int u, int v, int c, int id) {
    G[u].push_back(Edge(v, c, id, SZ(G[v]) ));
    G[v].push_back(Edge(u, 0, id, SZ(G[u]) - 1));
  }
  int dfs(int p, int flow) {
    if(p == t) return flow;
    for(int &i = iter[p]; i < SZ(G[p]); i++) {
      Edge &e = G[p][i];
      if(e.c > 0 && d[p] == d[e.v]+1) {
        int f = dfs(e.v, min(flow, e.c));
        if(f) {
          e.c -= f;
          G[e.v][e.r].c += f;
          return f;
        }
      }
    }
    if( (--gap[d[p]]) == 0) d[s] = tot;
    else {
      d[p]++;
      iter[p] = 0;
      ++gap[d[p]];
    }
    return 0;
  }
  int solve() {
    int res = 0;
    gap[0] = tot;
    for(res = 0; d[s] < tot; res += dfs(s, INF));
    return res;
  }
} flow;
void build(){

}
const int N=2020;
int n1, n2, m, a[N], b[N];
vector<int> l[N], r[N];
void init(){
  n1=getint();
  n2=getint();
  m=getint();
  for(int i=1; i<=m; i++){
    a[i]=getint();
    b[i]=getint();
    l[a[i]].push_back(i);
    r[b[i]].push_back(i);
  }
}
int tk[N];
void go(int goal){
  flow.init(n1+n2);
  for(int i=1;i<=m;i++)
    flow.addEdge(a[i], n1+b[i], 1, i);
  for(int i=1;i<=n1;i++)
    flow.addEdge(flow.s, i, goal, 0);
  for(int i=1;i<=n2;i++)
    flow.addEdge(n1+i, flow.t, goal, 0);
  flow.solve();
  for(int i=1;i<=n1;i++)
    for(auto e: flow.G[i])
      if(e.c == 0 and n1<e.v and e.v<=n1+n2)
        tk[e.id]=goal;
  for(int i=1;i<=n1;i++){
    int nd=goal;
    for(auto ii: l[i]){
      if(nd <= 0) break;
      if(tk[ii] == goal) nd --;
    }
    for(auto ii: l[i]){
      if(nd <= 0) break;
      if(tk[ii] == goal) continue;
      nd --;
      tk[ii] = goal;
    }
  }
  for(int i=1;i<=n2;i++){
    int nd=goal;
    for(auto ii: r[i]){
      if(nd <= 0) break;
      if(tk[ii] == goal) nd --;
    }
    for(auto ii: r[i]){
      if(nd <= 0) break;
      if(tk[ii] == goal) continue;
      nd --;
      tk[ii] = goal;
    }
  }
}
void solve(){
  puts("0");
  int mind=m;
  for(int i=1;i<=n1;i++) mind=min(mind, (int)l[i].size());
  for(int i=1;i<=n2;i++) mind=min(mind, (int)r[i].size());
  for(int i=1;i<=mind;i++){
    go(i);
    vector<int> va;
    for(int j=1; j<=m; j++)
      if(tk[j] == i)
        va.push_back(j);
    printf("%d", (int)va.size());
    for(auto j: va)
      printf(" %d", j);
    puts("");
  }
}
int main(){
  build();
  //__ = getint();
  while(__ --){
    init();
    solve();
  }
}