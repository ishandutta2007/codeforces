#include <bits/stdc++.h> 

using namespace std;

typedef long long ll; 
typedef pair<int, int> pii;

#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)

const int mod = 1000000007;

int modpow(int b, int e) {
	int t = 1;
	while (e) {
		if (e&1) t = (t*1ll*b) % mod;
		b = (b*1ll*b) % mod;	
		e >>= 1;
	}
	return t;
}

int x[1100000];
int y[1100000];
int n,k;
ll fac[1100000];

int main() {
	scanf("%d %d", &n, &k);

	int s = 0;
	for (int i = 1; i <= k+2; i++) {
		int th = modpow(i, k);
		s = (s + th) % mod;
		x[i-1] = i;
		y[i-1] = s;
	}

	if (n <= k+2) {
		printf("%d\n", y[n-1]);
		return 0;
	}

	int ans = 0;
	int lj = 1;
	REP(m,k+2) if (m != 0) {
		lj = (lj * 1ll * (n-x[m])) % mod;
		lj = (lj * 1ll * modpow(x[0]-x[m], mod-2)) % mod;
	}

	REP(j,k+2) {
		if (j > 0) {
			lj = (lj * 1ll * (n-x[j-1])) % mod;
			lj = (lj * 1ll * modpow(n-x[j],mod-2)) % mod;
			lj = (lj * 1ll * modpow(x[j]-x[0],mod-2)) % mod;
			lj = (lj * 1ll * (x[j-1]-x[k+1])) % mod;
		}
		//printf("l%d=%d\n", j,lj);
		ans = (ans + lj * 1ll * y[j]) % mod;
	}	

	printf("%d\n", (ans+mod)%mod);
}