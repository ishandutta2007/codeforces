#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <iostream>
using namespace std;
#define N 1000050
typedef long long ll;
#define mod 1000000007
ll fac[N],inv[N];
ll qp(ll x,ll y) {if(y<0)return qp(qp(x,-y),mod-2);ll re=1;for(;y;y>>=1,x=x*x%mod)if(y&1) re=re*x%mod; return re;}
int n,m,a,b;
ll C(int n,int m) {return n<m?0:fac[n]*inv[m]%mod*inv[n-m]%mod;}
int main() {
	int i;
	scanf("%d%d%*d%*d",&n,&m);
	for(fac[0]=i=1;i<N;i++) fac[i]=fac[i-1]*i%mod; inv[N-1]=qp(fac[N-1],mod-2);
	for(i=N-2;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mod;
	ll ans=0;
	for(i=0;i<=n-2;i++) {
		ans=(ans+fac[i]*C(n-2,i)%mod*C(m-1,i)%mod*(i+2)%mod*qp(n,n-i-3)%mod*qp(m,n-i-2))%mod;
	}
	printf("%lld\n",ans);
}