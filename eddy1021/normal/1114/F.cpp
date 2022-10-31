#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int P=300;
const int mod=1e9+7;
inline int add(int a, int b){
  a+=b;
  return a>=mod?a-mod:a;
}
inline int mul(LL a, int b){
  a*=b;
  return a>=mod?a%mod:a;
}
inline int mpow(int a, int b){
  int r=1;
  while(b){
    if(b&1) r=mul(r, a);
    a=mul(a, a);
    b>>=1;
  }
  return r;
}
bool p[P];
vector<int> ps;
int dv[P];
void build(){
  for(int i=2; i<P; i++) if(!p[i]){
    ps.push_back(i);
    for(int j=i; j<P; j+=i) p[j]=true;
  }
  for(size_t i=0; i<ps.size(); i++)
    dv[i]=mul(ps[i]-1, mpow(ps[i], mod-2));
}
const int N=400040;
#define L(X) (X<<1)
#define R(X) (1+(X<<1))
#define mid ((l+r)>>1)
int n, q, a[N], st[N<<2], pm[N<<2];
LL tg[N<<2], pg[N<<2];
LL sv[P+1];
LL magic(int val){
  if(val == 1) return 0;
  if(sv[val]) return sv[val];
  for(size_t i=0; i<ps.size(); i++)
    if(val % ps[i] == 0)
      sv[val]|=(1LL<<i);
  return sv[val];
}
void pull(int no){
  st[no]=mul(st[L(no)], st[R(no)]);
  tg[no]=tg[L(no)]|tg[R(no)];
}
void build_st(int no, int l, int r){
  pm[no]=1;
  if(l == r){
    st[no]=a[l];
    tg[no]=magic(a[l]);
    return;
  }
  build_st(L(no), l, mid);
  build_st(R(no), mid+1, r);
  pull(no);
}
void push(int no, int l, int r){
  if(pg[no] == 0) return;
  st[L(no)]=mul(st[L(no)], mpow(pm[no], mid-l+1));
  st[R(no)]=mul(st[R(no)], mpow(pm[no], r-mid));
  tg[L(no)]|=pg[no];
  tg[R(no)]|=pg[no];

  pm[L(no)]=mul(pm[L(no)], pm[no]);
  pm[R(no)]=mul(pm[R(no)], pm[no]);
  pg[L(no)]|=pg[no];
  pg[R(no)]|=pg[no];

  pm[no]=1; pg[no]=0;
}
void modify(int no, int l, int r, int ql, int qr, int qv, LL qg){
  if(r<ql or l>qr) return;
  if(ql<=l and r<=qr){
    st[no]=mul(st[no], mpow(qv, r-l+1));
    tg[no]|=qg;

    pm[no]=mul(pm[no], qv);
    pg[no]|=qg;
    return;
  }
  push(no, l, r);
  modify(L(no), l, mid, ql, qr, qv, qg);
  modify(R(no), mid+1, r, ql, qr, qv, qg);
  pull(no);
}
pair<int, LL> query(int no, int l, int r, int ql, int qr){
  if(l==ql and r==qr) return {st[no], tg[no]};
  push(no, l, r);
  if(qr <= mid) return query(L(no), l, mid, ql, qr);
  if(mid<ql) return query(R(no), mid+1, r, ql, qr);
  pair<int, LL> lret=query(L(no), l, mid, ql, mid);
  pair<int, LL> rret=query(R(no), mid+1, r, mid+1, qr);
  return {mul(lret.first, rret.first),
          lret.second|rret.second};
}
int query(int l, int r){
  pair<int, LL> ret=query(1, 1, n, l, r);
  int ans=ret.first;
  for(size_t i=0; i<ps.size(); i++)
    if((ret.second >> i) & 1LL)
      ans=mul(ans, dv[i]);
  return ans;
}
int main(){
  build();
  scanf("%d%d", &n, &q);
  for(int i=1; i<=n; i++) scanf("%d", &a[i]);
  build_st(1, 1, n);
  char buf[16];
  while(q--){
    scanf("%s", buf);
    if(buf[0] == 'M'){
      int ql, qr, qx; scanf("%d%d%d", &ql, &qr, &qx);
      modify(1, 1, n, ql, qr, qx, magic(qx));
    }else{
      int ql, qr; scanf("%d%d", &ql, &qr);
      printf("%d\n", query(ql, qr));
    }
  }
}