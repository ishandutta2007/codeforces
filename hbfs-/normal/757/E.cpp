#include <bits/stdc++.h>
#define mod 1000000007
#define tp 1000000
#define N 1000500
#define lg 20
using namespace std;
typedef long long LL;
bool isp[N];
int pr[N],g[N],F[N][lg+1],n,r,k,ans,cur,cnt;
inline int rd() { int r; scanf("%d",&r); return r; }

void _pre() {
	for (int _=2;_<=tp;_++) {
		if (!isp[_]) pr[++cnt] = _;
		for (int i=1;i<=cnt && pr[i]*_ <= tp;i++) {
			isp[_*pr[i]] = 1;
			if (_ % pr[i] == 0) break;
		}
	}
	
	for (int _=2;_<=tp;_++) if (isp[_]) {
		for (int i=1;i<=cnt;i++) if (_%pr[i] == 0) {
			g[_] = pr[i];
			break;
		}
	} else g[_] = _;
	
	for (int _=0;_<=tp;_++) F[_][0] = 1;
	for (int _=1;_<=lg;_++) F[0][_] = 2;
	
	for (int _=1;_<=tp;_++)
		for (int i=1;i<=lg;i++) F[_][i] = ( F[_-1][i] + F[_][i-1] ) % mod;
}

int main() {
	_pre();
	
	for (int T=rd();T;T--) {
		r = rd(), n = rd(), ans = 1, cur = 0, k = 0;
		while (n != 1) {
			if (g[n] == cur) {
				k++;
			} else {
				ans = 1LL * ans * F[r][k] % mod;
				cur = g[n];
				k = 1;
			}
			n /= g[n];
		}
		k ? ans = 1LL * ans * F[r][k] % mod : 0;
		printf("%d\n",(int)ans);
	}
	return 0;
}