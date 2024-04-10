#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=101010;
int n, M, a[N], sa[N];
int main(){
  scanf("%d%d", &n, &M);
  for(int i=1; i<=n; i++) scanf("%d", &a[i]);
  a[n+1]=M;
  int ans=0;
  for(int i=0; i<=n; i+=2) ans+=a[i+1]-a[i];
  for(int i=n; i>=0; i--){
    sa[i]+=sa[i+1];
    if(i%2==0) sa[i]+=a[i+1]-a[i];
  }
  int pa=0;
  for(int i=0; i<=n; i++){
    int tans=pa+a[i+1]-a[i]-1;
    int res=M-a[i+1];
    tans+=res-sa[i+1];
    ans=max(ans, tans);
    if(i%2)
      pa+=a[i]-a[i-1];
  }
  printf("%d\n", ans);
}