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
const int N=505050;


LL st[N<<2], tg[N<<2];
#define L(X) (X<<1)
#define R(X) (1+(X<<1))
#define mid ((l+r)>>1)
const LL INF=1e18;
void build_st(int no, int l, int r){
  st[no]=INF; tg[no]=0;
  if(l==r) return;
  build_st(L(no), l, mid);
  build_st(R(no), mid+1, r);
}
void assign(int no, int l, int r, int qi, LL val){
  if(l == r){
    st[no]=val;
    return;
  }
  if(qi <= mid)
    assign(L(no), l, mid, qi, val);
  else
    assign(R(no), mid+1, r, qi, val);
  st[no]=min(st[L(no)],
             st[R(no)]);
}
void push(int no, int l, int r){
  if(tg[no] == 0) return;
  st[L(no)]+=tg[no];
  st[R(no)]+=tg[no];
  tg[L(no)]+=tg[no];
  tg[R(no)]+=tg[no];
  tg[no]=0;
}
void modify(int no, int l, int r, int ql, int qr, LL dlt){
  if(r<ql or l>qr or ql>qr) return;
  if(ql<=l and r<=qr){
    st[no]+=dlt;
    tg[no]+=dlt;
    return;
  }
  push(no, l, r);
  modify(L(no), l, mid, ql, qr, dlt);
  modify(R(no), mid+1, r, ql, qr, dlt);
  st[no]=min(st[L(no)],
             st[R(no)]);
}
LL query(int no, int l, int r, int ql, int qr){
  if(r<ql or l>qr or ql>qr) return INF;
  if(ql<=l and r<=qr) return st[no];
  push(no, l, r);
  return min(query(L(no), l, mid, ql, qr),
             query(R(no), mid+1, r, ql, qr));
}


int n, q, v[N], l[N], r[N], cl[N], cr[N];
vector< pair<int, int> > s[N];
LL ans[N];
void build(){
  
}
vector<int> qry[N];
void go(int now){
  cl[now]=cr[now]=now;
  for(auto e: s[now]){
    go(e.first);
    cl[now]=min(cl[now], cl[e.first]);
    cr[now]=max(cr[now], cr[e.first]);
  }
}
void init(){
  n=getint();
  q=getint();
  for(int i=2; i<=n; i++){
    int pi=getint();
    LL wi=getint();
    s[pi].push_back({i, wi});
  }
  for(int i=0; i<q; i++){
    v[i]=getint();
    l[i]=getint();
    r[i]=getint();
    qry[v[i]].push_back(i);
  }
  go(1);
}
void gogo(int now, LL dep){
  if(s[now].size() == 0u){
    assign(1, 1, n, now, dep);
    return;
  }
  for(auto e: s[now])
    gogo(e.first, dep+e.second);
}
void gogo2(int now){
  // solve query
  for(auto qid: qry[now])
    ans[qid]=query(1, 1, n, l[qid], r[qid]);
  for(auto e: s[now]){
    int son=e.first;
    int dst=e.second;
    int lb=cl[son], rb=cr[son];
    modify(1, 1, n, 1, lb-1, +dst);
    modify(1, 1, n, lb, rb, -dst);
    modify(1, 1, n, rb+1, n, +dst);
    gogo2(son);
    modify(1, 1, n, 1, lb-1, -dst);
    modify(1, 1, n, lb, rb, +dst);
    modify(1, 1, n, rb+1, n, -dst);
  }
}
void solve(){
  build_st(1, 1, n);
  gogo(1, 0);
  gogo2(1);
  for(int i=0; i<q; i++)
    printf("%lld\n", ans[i]);
}
int main(){
  build();
  //__ = getint();
  while(__ --){
    init();
    solve();
  }
}