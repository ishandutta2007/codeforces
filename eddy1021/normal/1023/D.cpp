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
#define L(X) (X<<1)
#define R(X) (1+(X<<1))
#define mid ((l+r)>>1)
int st[N<<2], tg[N<<2];
void push(int no, int l, int r){
  if(tg[no]){
    st[L(no)]=st[R(no)]=
    tg[L(no)]=tg[R(no)]=tg[no];
  }
  tg[no]=0;
}
void assign(int no, int l, int r, int ql, int qr, int val){
  if(r < ql or l > qr) return;
  if(ql <= l and r <= qr){
    st[no]=tg[no]=val;
    return;
  }
  push(no, l, r);
  assign(L(no), l, mid, ql, qr, val);
  assign(R(no), mid+1, r, ql, qr, val);
}
int b[N], ptr;
void restore(int no, int l, int r){
  if(l == r){
    b[++ptr]=st[no];
    return;
  }
  push(no, l, r);
  restore(L(no), l, mid);
  restore(R(no), mid+1, r);
}
void build(){

}
int n, q, a[N];
int l[N], r[N], zer[N];
void init(){
  n=getint();
  q=getint();
  for(int i=1; i<=n; i++)
    a[i]=getint();
  for(int i=1; i<=q; i++){
    l[i]=n+1;
    r[i]=0;
  }
  for(int i=1; i<=n; i++){
    if(a[i] == 0){
      zer[i]=1;
      continue;
    }
    l[a[i]]=min(l[a[i]], i);
    r[a[i]]=max(r[a[i]], i);
  }
  for(int i=1; i<=n; i++) zer[i]+=zer[i-1];
}
void no(){
  puts("NO");
  exit(0);
}
void solve(){
  for(int i=1; i<=q; i++){
    if(l[i] == n+1) continue;
    assign(1, 1, n, l[i], r[i], i);
  }
  restore(1, 1, n);
  {
    if(l[q] == n+1){
      bool ok=false;
      for(int i=1; i<=n; i++)
        if(b[i] == 0){
          b[i]=q;
          ok=true;
          break;
        }
      if(not ok){
        for(int i=1; i<=n; i++)
          if(zer[i] > zer[i-1]){
            b[i]=q;
            ok=true;
            break;
          }
        if(not ok)
          no();
      }
    }
    for(int i=2; i<=n; i++)
      if(b[i] == 0 and b[i-1])
        b[i]=b[i-1];
    for(int i=n-1; i>=1; i--)
      if(b[i] == 0 and b[i+1])
        b[i]=b[i+1];
  }
  for(int i=1; i<=n; i++)
    if((a[i] and a[i] != b[i]) or b[i]==0)
      no();
  puts("YES");
  for(int i=1; i<=n; i++)
    printf("%d%c", b[i], " \n"[i==n]);
}
int main(){
  build();
  //__ = getint();
  while(__ --){
    init();
    solve();
  }
}