#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=(1<<20);
void upd(LL &ap, LL &as, LL &a, LL &b,
         LL cp, LL cs, LL ca, LL cb){
  if(a == -1 or cp*cp*as < ap*ap*cs){
    ap=cp, as=cs, a=ca, b=cb;
    return;
  }
}
int t, n, A[N], c[N];
int main(){
  scanf("%d", &t); while(t--){
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d", &A[i]);
    sort(A, A+n);
    int x=0;
    LL pp=-1, s=-1, a=-1, b=-1;
    for(int l=0, r=0; l<n; l=r){
      while(r<n and A[l] == A[r]) r++;
      if(r-l>3){
        LL np=A[l]*4;
        LL ns=A[l]*A[l];
        upd(pp, s, a, b, np, ns, A[l], A[l]);
      }
      if(r-l>1) c[x++]=A[l];
    }
    for(int i=1; i<x; i++)
      upd(pp, s, a, b, 
          (c[i-1]+c[i])*2LL,
          c[i-1]*(LL)c[i],
          c[i-1], c[i]);
    printf("%lld %lld %lld %lld\n", a, a, b, b);
  }
}