#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=201010;
#define L(X) (X<<1)
#define R(X) (1+(X<<1))
#define mid ((l+r)>>1)
int mx[N<<2];
void modify(int no, int l, int r, int p, int x){
  if(l == r){
    mx[no]=x;
    return;
  }
  if(p<=mid) modify(L(no), l, mid, p, x);
  else modify(R(no), mid+1, r, p, x);
  mx[no]=max(mx[L(no)], mx[R(no)]);
}
int query(int no, int l, int r, int ql, int qr, LL g){
  if(r<ql or l>qr or mx[no]<g) return N;
  if(ql<=l and r<=qr){
    if(l==r) return l;
    if(mx[L(no)]>=g) return query(L(no), l, mid, ql, qr, g);
    return query(R(no), mid+1, r, ql, qr, g);
  }
  int lret=query(L(no), l, mid, ql, qr, g);
  if(lret < N) return lret;
  return query(R(no), mid+1, r, ql, qr, g);
}
LL BIT[N];
int lb(int x){ return x&(-x); }
void modify_bit(int x, LL d){
  for(int i=x; i<N; i+=lb(i))
    BIT[i]+=d;
}
LL query_bit(int x){
  LL ret=0;
  for(int i=x; i; i-=lb(i))
    ret+=BIT[i];
  return ret;
}
int n, q, a[N];
int main(){
  scanf("%d%d", &n, &q);
  for(int i=1; i<=n; i++)
    scanf("%d", &a[i]);
  for(int i=1; i<=n; i++){
    modify(1, 1, n, i, a[i]);
    modify_bit(i, a[i]);
  }
  while(q--){
    {
      int p, v; scanf("%d%d", &p, &v);
      modify(1, 1, n, p, v);
      modify_bit(p, v-a[p]);
      a[p]=v;
    }
    if(a[1] == 0){
      puts("1");
      continue;
    }
    int til=1, ans=-1;
    while(til < n){
      LL sum=query_bit(til);
      int nxt=query(1, 1, n, til+1, n, sum);
      if(nxt == N) break;
      if(query_bit(nxt-1) == a[nxt]){
        ans=nxt;
        break;
      }
      til=nxt;
    }
    printf("%d\n", ans);
  }
}