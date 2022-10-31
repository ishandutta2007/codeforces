#include <iostream>

using namespace std;
typedef long long ll;
#define mod 1000000007
ll n, m, c[11][11], f[11], a[11], cnt, ans;
void dfs(ll d, ll x, ll s) {
	if (d>5) {ans=(ans+s)%mod; return; }
	for (int i=0; i<x; i++) f[i]--, dfs(d+1, x-i, s*(f[i]+1)%mod), f[i]++;
}
int main(){
	cin >> m; m++, f[0]--; while (m) a[++n]=m%10, m/=10;
	for (int i=0; i<11; i++) for (int j=0; j<=i; j++) c[i][j]=i&&j?(c[i-1][j]+c[i-1][j-1])%mod:1;
	for (int i=n; i; i--) {
		for (int j=0; j<a[i]; j++) {
			ll now=1LL<<i-1;
			for (int k=i-1; k>=0; k--) f[cnt+(j==4||j==7)+k]+=now*c[i-1][k], now<<=2;
		}
		cnt+=(a[i]==4||a[i]==7);
	}
	for (int i=1; i<=n; i++) if (f[i]) f[i]--, dfs(0, i, f[i]+1), f[i]++;
	cout << ans;
	return 0;
}