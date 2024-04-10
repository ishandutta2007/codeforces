#include <bits/stdc++.h>
using namespace std;
const int N=303030;
int n, l[N], r[N], pl[N], pr[N], ans;
int main(){
  scanf("%d", &n);
  for(int i=1; i<=n; i++)
    scanf("%d%d", &l[i], &r[i]);
  pl[0]=0; pr[0]=1e9;
  for(int i=1; i<=n; i++){
    pl[i]=max(pl[i-1], l[i]);
    pr[i]=min(pr[i-1], r[i]);
  }
  int sl=0, sr=1e9;
  for(int i=n; i>=1; i--){
    {
      int al=max(sl, pl[i-1]);
      int ar=min(sr, pr[i-1]);
      ans=max(ans, ar-al);
    }
    sl=max(sl, l[i]);
    sr=min(sr, r[i]);
  }
  printf("%d\n", ans);
}