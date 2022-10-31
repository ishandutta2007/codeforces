// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int mod=998244353;
inline int add(int a, int b){
  a+=b;
  return a>=mod?a-mod:a;
}
inline int mul(LL a, int b){
  a*=b;
  return a>=mod?a%mod:a;
}
inline int mpow(int a, int b){
  int ret=1;
  while(b){
    if(b&1) ret=mul(ret, a);
    a=mul(a, a);
    b>>=1;
  }
  return ret;
}
const int N=(1<<20);
const int inv2=(mod+1)/2;
int n, a[N], ip2[N];
int main(){
  ip2[0]=1;
  for(int i=1; i<N; i++) ip2[i]=mul(ip2[i-1], inv2);
  scanf("%d", &n);
  for(int i=1; i<=n; i++)
    scanf("%d", &a[i]);
  for(int i=n; i>=1; i--)
    a[i]-=a[i-1];
  int ans=0;
  for(int i=1; i<=n; i++)
    ans=add(ans, mul(a[i], mul(n+1-i, ip2[i-1])));
  ans=mul(ans, mpow(2, n-1));
  printf("%d\n", ans);
}