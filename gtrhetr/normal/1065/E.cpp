#include <cstdio>
#include <cstring>
#include <algorithm>
#define MOD 998244353
#define inv2 499122177

using namespace std;

typedef long long ll;

ll pow_mod(ll x,int k) {
  ll ans=1;
  while (k) {
  	if (k&1) ans=ans*x%MOD;
  	x=x*x%MOD;
  	k>>=1;
  }
  return ans;
}

int num[200005];

int main() {
  int n,m,k;
  scanf("%d%d%d",&n,&m,&k);
  for(int i=1;i<=m;i++) scanf("%d",&num[i]);
  ll ans=1;
  for(int i=1;i<=m;i++) {
  	int x=num[i]-num[i-1];
  	ll s=(pow_mod(k,2*x)+pow_mod(k,x))*inv2%MOD;
  	ans=ans*s%MOD;
  }
  ans=ans*pow_mod(k,n-2*num[m])%MOD;
  printf("%I64d\n",ans);
  return 0;
}