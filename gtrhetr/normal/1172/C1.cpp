#include <bits/stdc++.h>
#define MOD 998244353

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

inline void update(ll &x,ll y) {
  x=(x+y)%MOD;
}

ll num[55];
int op[55];

ll f[55][55][55],invsum[105];

int main() {
  int n,m;
  scanf("%d%d",&n,&m);
  for(int i=1;i<=n;i++) scanf("%d",&op[i]);
  for(int i=1;i<=n;i++) scanf("%lld",&num[i]);
  ll s=0;
  for(int i=1;i<=n;i++) s+=num[i];
  for(int i=0;i<=2*m;i++) invsum[i]=pow_mod(s+i-m,MOD-2);
  for(int i=1;i<=n;i++) {
  	memset(f,0,sizeof(f));
  	ll s1=0,s2=0;
  	for(int j=1;j<=n;j++)
  	  if (j!=i) {
  	  	  if (op[j]) s1+=num[j]; else s2+=num[j];
		}
	f[0][0][0]=1;
	for(int j=0;j<m;j++)
	for(int k=0;k<=j;k++)
	for(int l=0;l+k<=j;l++)
	  if (f[j][k][l]) {
	  	int v=(j-k-l)*((op[i])?1:-1);
	  	update(f[j+1][k][l],f[j][k][l]*invsum[k-l+v+m]%MOD*(num[i]+v));
	  	update(f[j+1][k+1][l],f[j][k][l]*invsum[k-l+v+m]%MOD*(s1+k));
	  	update(f[j+1][k][l+1],f[j][k][l]*invsum[k-l+v+m]%MOD*(s2-l));
	  }
	ll ans=num[i];
	for(int j=0;j<=m;j++)
	  for(int k=0;j+k<=m;k++) update(ans,(ll)(m-j-k)*((op[i])?1:MOD-1)%MOD*f[m][j][k]);
	printf("%lld\n",ans);
  }
  return 0;
}