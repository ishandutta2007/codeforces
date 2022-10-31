#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <bitset>
using namespace std;
typedef long long ll;
#define mod 1000000007
#define N 150
ll qp(ll x,ll y=mod-2) {
	ll re=1;for(;y;y>>=1,x=x*x%mod)if(y&1)re=re*x%mod;return re;
}
void mul(ll *a,ll *b,int la,int lb,int lc) {
	int i,j;
	static ll tmp[105];
	memset(tmp,0,(lc+1)<<3);
	for(i=0;i<=la;i++)if(a[i])for(j=0;j<=lb&&j<=lc-i;j++){
		tmp[i+j]=(tmp[i+j]+a[i]*b[j])%mod;
	}
	for(i=0;i<=lc;i++)a[i]=tmp[i];
	la=lc;
}
ll a[N][N];
ll Gauss(int n) {
	ll re=1;
	int i,j,k;
	for(i=1;i<=n;i++) {
		for(j=i;j<=n&&!a[j][i];j++);
		if(j>n)return 0;
		if(i!=j) {
			re=mod-re;
			for(k=i;k<=n;k++)swap(a[i][k],a[j][k]);
		}re=re*a[i][i]%mod;
		ll iv=qp(a[i][i]);
		for(j=i+1;j<=n;j++) {
			ll del=a[j][i]*iv%mod;
			for(k=i;k<=n;k++) a[j][k]=(a[j][k]-del*a[i][k])%mod;
		}
	}return re;
}
int n,xx[N],yy[N];
ll f[N],g[N],ans[N],fx[N];
ll calc(ll X) {
	int i,j; X--;
	for(i=1;i<=n;i++) for(j=1;j<=n;j++) a[i][j]=mod-1;
	for(i=1;i<=n;i++) a[i][i]=n-1;
	for(i=1;i<n;i++) {
		a[xx[i]][yy[i]]-=X; a[yy[i]][xx[i]]-=X;
		a[xx[i]][xx[i]]+=X; a[yy[i]][yy[i]]+=X;
	}return Gauss(n-1);
}
int main() {
	scanf("%d",&n);
	int i,j;
	for(i=1;i<n;i++)scanf("%d%d",&xx[i],&yy[i]);
	f[0]=1;
	for(i=1;i<=n;i++) {
		g[0]=mod-i;
		g[1]=1;
		mul(f,g,i-1,1,i);
	}
	for(i=1;i<=n;i++) {
		ll Y=(calc(i)%mod+mod)%mod;
		for(j=0;j<=n;j++)fx[j]=f[j];
		ll iv=qp(i);
		for(j=0;j<=n;j++) {
			fx[j]=mod-fx[j]*iv%mod;
			fx[j+1]=(fx[j+1]-fx[j])%mod;
		}
		for(j=1;j<=n;j++)if(i!=j)Y=Y*qp(i-j)%mod;
		for(j=0;j<n;j++) {
			ans[j]=(ans[j]+Y*fx[j])%mod;
		}
	}
	for(i=0;i<n;i++) printf("%lld ",(ans[i]+mod)%mod);
}