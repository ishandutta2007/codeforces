#include <bits/stdc++.h>
#define mod 998244353
#define N 2050
using namespace std;
typedef long long LL;
int n,m,k;
LL F[N][N];
inline int rd() {int r;scanf("%d",&r);return r;}
inline void inc(LL &x, LL y) {x=(x+y)%mod;}
int main() {
	n = rd(), m = rd(), k = rd();
	if (m == 1) {
		if (n == 1)
			puts("1");
		else {
			if (k == 0)
				puts("1");
			else
				puts("0");
		}
		return 0;
	}
	F[1][0] = m;
	for (int i=1;i<n;i++) {
		for (int j=0;j<=k;j++) {
			inc(F[i+1][j], F[i][j]);
			if (j+1 <= k) inc(F[i+1][j+1], 1LL * (m-1) * F[i][j] % mod);
		}
	}

	cout << F[n][k] << endl;
	return 0;
}