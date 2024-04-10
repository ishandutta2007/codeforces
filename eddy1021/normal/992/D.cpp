#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=201010;
const LL inf=4e18;
LL mul(LL a, LL b){
  if(a==0 or b==0) return 0;
  if(a>inf/b) return inf;
  return min(inf, a*b);
}
LL n, k, a[N], ans, nxt[N];
int main(){
  scanf("%lld%lld", &n, &k);
  for(int i=1; i<=n; i++)
    scanf("%lld", &a[i]);
  nxt[n+1]=n+1;
  for(int i=n; i>=1; i--)
    nxt[i]=a[i]>1?i:nxt[i+1];
  for(int i=1; i<=n; i++){
    LL p=1, s=0;
    int j=i;
    while(j <= n and p<inf){
      int nj=nxt[j];
      if(j == nj){
        s+=a[j];
        p=mul(p, a[j]);
        if(p == s*k) ans++;
        j++;
        continue;
      }
      if(p%k==0){
        LL goal=p/k;
        LL nd=goal-s;
        if(1<=nd and nd<=nj-j)
          ans++;
      }
      s+=nj-j;
      j=nj;
      continue;
    }
  }
  cout<<ans<<endl;
}