#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

long long f[100010], g[100010], h[100010], pw1[100010], pw2[100010], pw[100010];
char s[100010], t[100010];
int n;

long long calc(char *s) {
	long long ans = 0, up = 0, lst = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (s[i] == '7') {
			if (i == 0) {
				ans = (ans + (up + 7) * (up + 4)) % mod;
				up = (up + 7 * pw[i]) % mod;
				goto END;
			}
			up = (up + 4 * pw[i]) % mod;
			ans = (ans + f[i] + up * g[i] + up * up % mod * h[i]) % mod;
			ans = (ans + (up + 3 * pw[i] + pw1[i]) % mod * (up + pw2[i])) % mod;
			up = (up + 3 * pw[i]) % mod;
		} else {
			up = (up + 4 * pw[i]) % mod;
		}
		END:;
	}
	return ans;
}

int main () {
	f[1] = 4 * 7, g[1] = 4 + 7, h[1] = 1, pw1[0] = pw2[0] = 0, pw1[1] = 4, pw2[1] = 7, pw[0] = 1, pw[1] = 10;
	long long t1 = 40, t2 = 70;
	for (int i = 2; i <= 100000; i++) {
		f[i] = (f[i - 1] + t1 * g[i - 1] + t1 * t1 % mod * h[i - 1] + 
				f[i - 1] + t2 * g[i - 1] + t2 * t2 % mod * h[i - 1] + 
				(pw2[i - 1] + t1) * (pw1[i - 1] + t2)) % mod;
		g[i] = (g[i - 1] + g[i - 1] + 2 * h[i - 1] * (t1 + t2) + pw2[i - 1] + t1 + pw1[i - 1] + t2) % mod;
		h[i] = (h[i - 1] * 2 + 1) % mod;
		t1 = t1 * 10 % mod, t2 = t2 * 10 % mod;
		pw1[i] = (pw1[i - 1] * 10 + 4) % mod, pw2[i] = (pw2[i - 1] * 10 + 7) % mod;
		pw[i] = pw[i - 1] * 10 % mod;
	}
	scanf("%s%s", s, t), n = strlen(s);
	reverse(s, s + n), reverse(t, t + n);
	long long ans = (calc(t) - calc(s) + mod) % mod;
	printf("%I64d\n", ans);
	return 0;
}