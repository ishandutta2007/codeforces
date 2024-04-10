#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <bitset>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;
#define N 1050
#define mod 998244353
int n,K,a[N],L[N];
ll f[N][N],h[100050];
ll geth(int s) {
	int i,j=1;
	// for(i=1;i<=n;i++) {
	// 	for(;j<i&&a[i]-a[j]>s;j++);
	// 	L[i]=j;
	// }
	f[0][0]=1;
	a[0]=-10000000;
	j=0;
	for(i=1;i<=n;i++) {
		for(;j<=n&&a[i]-a[j]>=s;j++) ;
		j--;
		f[i][0]=1;
		int k;
		for(k=1;k<=K;k++) {
			f[i][k]=(f[i-1][k]+f[j][k-1])%mod;
		}
	}
	return f[n][K];
}
int main() {
	scanf("%d%d",&n,&K);
	int i;
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int lim=100000/(K-1)+1;
	for(i=0;i<=lim;i++) h[i]=geth(i);
	ll ans=0;
	for(i=0;i<=lim;i++) {
		ans=(ans+i*(h[i]-h[i+1]))%mod;
	}
	printf("%lld\n",(ans+mod)%mod);
}