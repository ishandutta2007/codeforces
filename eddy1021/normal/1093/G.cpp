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
const int N=202020;
const int inf=1e9;
const int K=5;
#define L(X) (X<<1)
#define R(X) (1+(X<<1))
#define mid ((l+r)>>1)
struct ST{
  int mn[N<<2], mx[N<<2];
  void modify(int no, int l, int r, int p, int v){
    if(l == r){
      mn[no]=mx[no]=v;
      return;
    }
    if(p <= mid) modify(L(no), l, mid, p, v);
    else modify(R(no), mid+1, r, p, v);
    mn[no]=min(mn[L(no)], mn[R(no)]);
    mx[no]=max(mx[L(no)], mx[R(no)]);
  }
  int q_mn(int no, int l, int r, int ql, int qr){
    if(r<ql or l>qr) return inf;
    if(ql <= l and r <= qr) return mn[no];
    return min(q_mn(L(no), l, mid, ql, qr),
               q_mn(R(no), mid+1, r, ql, qr));
  }
  int q_mx(int no, int l, int r, int ql, int qr){
    if(r<ql or l>qr) return -inf;
    if(ql <= l and r <= qr) return mx[no];
    return max(q_mx(L(no), l, mid, ql, qr),
               q_mx(R(no), mid+1, r, ql, qr));
  }
} st[1<<K];
void build(){

}
int n, k, a[N][K];
void init(){
  n=getint();
  k=getint();
  for(int i=1; i<=n; i++)
    for(int j=0; j<k; j++)
      a[i][j]=getint();
  for(int i=1; i<=n; i++)
    for(int msk=0; msk<(1<<k); msk++){
      int val=0;
      for(int j=0; j<k; j++)
        if((msk>>j)&1) val+=a[i][j];
        else val-=a[i][j];
      st[msk].modify(1, 1, n, i, val);
    }
}
void solve(){
  int q=getint(); while(q--){
    int cmd=getint();
    if(cmd == 1){
      int i=getint();
      int b[5];
      for(int j=0; j<k; j++)
        b[j]=getint();
      for(int msk=0; msk<(1<<k); msk++){
        int val=0;
        for(int j=0; j<k; j++)
          if((msk>>j)&1) val+=b[j];
          else val-=b[j];
        st[msk].modify(1, 1, n, i, val);
      }
    }else{
      int ql=getint();
      int qr=getint();
      int ans=0;
      for(int msk=0; msk<(1<<k); msk++){
        int mxx=st[msk].q_mx(1, 1, n, ql, qr);
        int mnn=st[msk].q_mn(1, 1, n, ql, qr);
        ans=max(ans, mxx-mnn);
      }
      printf("%d\n", ans);
    }
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