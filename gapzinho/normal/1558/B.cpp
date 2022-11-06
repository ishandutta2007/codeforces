#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

const int ms = 4e6+5;

int mod;
int ans[ms];
int pre[ms];
int preMul[ms];

inline int add(int a, int b) {
    a += b;
    if (a >= mod) {
        a -= mod;
    }
    return a;
}



inline int mul(int a, int b) {
    int ans = 0;
    asm(
        "mull %%ebx;"
        "divl %3;"
        : "=d" (ans)
        : "a" (a), "b" (b), "c" (mod)
    );
    return ans;
}



main() {
	cin.tie(0); ios::sync_with_stdio(0);
	int n;
	cin >> n >> mod;
	ans[1] = pre[1] = 1;
	preMul[1] = 1;
	// ans[2] = 2;
	// pre[2] = 3;
	// ans[3] = 5;
	// pre[3] = 8;
	for(int i = 2; i <= n; i++) {
		preMul[i]++;
	}
	for (int i = 2; i <= n; i++) {
		preMul[i] = (preMul[i] + preMul[i-1]) % mod;
		preMul[i] = ((preMul[i] - ans[i-1]) % mod + mod) % mod;
		// cout << preMul[i] << endl;
		ans[i] = (pre[i-1] + preMul[i]) % mod;
		int lastK = i;
		int cnt = 0;
		preMul[i] = (preMul[i] + ans[i]) % mod;
		for(int j = i+i; j <= n; j += i) {
			cnt++;
			preMul[j] = (preMul[j] + ans[i]) % mod;
			preMul[j] = ((preMul[j] - ans[i-1]) % mod + mod) % mod;
		}
		// for (int j = 2; j <= lastK; j++) {
		// 	int k = i/j;
		// 	ans[i] = add(add(ans[i], mul(lastK - max(k, j), ans[j-1])), ans[k]);
		// 	lastK = k;
		// }
		// cout << i << ' ' << lastK << endl;
		pre[i] = add(ans[i], pre[i-1]);
	}
	cout << ans[n] << endl;
}