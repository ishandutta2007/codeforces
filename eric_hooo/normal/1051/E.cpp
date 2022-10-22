#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

void ADD(int &x, int y) {
	x += y;
	if (x >= mod) x -= mod;
}

void SUB(int &x, int y) {
	x -= y;
	if (x < 0) x += mod;
}

char a[1000010], lb[1000010], rb[1000010];
int zl[1000010], zr[1000010];
int dp[1000010], sum[1000010];

namespace ZBOX {
	char s[2000010];
	int z[2000010];
	void GetZ(char *a, char *b, int *output) {
		int A = strlen(a), B = strlen(b);
		for (int i = 0; i < A; i++) {
			s[i] = a[i];
		}
		for (int i = 0; i < B; i++) {
			s[A + i] = b[i];
		}
		s[A + B] = '\0';
		int n = A + B;
		int L = -1, R = -1;
		for (int i = 1; i < n; i++) {
			// L = R = i;
			// while (R < n && s[R] == s[R - L]) R++; R--;
			// z[i] = R - L + 1;
			// continue;
			if (R < i) {
				L = R = i;
				while (R < n && s[R] == s[R - L]) R++; R--;
				z[i] = R - L + 1;
			} else if (i + z[i - L] - 1 < R) {
				z[i] = z[i - L];
			} else {
				L = i;
				while (R < n && s[R] == s[R - L]) R++; R--;
				z[i] = R - L + 1;
			}
		}
		for (int i = 0; i < B; i++) {
			output[i] = z[A + i];
		}
	}
}

using ZBOX :: GetZ;

int main() {
	scanf("%s%s%s", a, lb, rb);
	int n = strlen(a);
	[&]() -> void {
		int len = strlen(rb);
		reverse(rb, rb + len);
		int pos = 0;
		while (pos < len && rb[pos] == '9') rb[pos] = '0', pos++;
		if (pos == len) rb[pos] = '0', len++;
		rb[pos]++;
		reverse(rb, rb + len);
	}();
	GetZ(lb, a, zl), GetZ(rb, a, zr);
	int llen = strlen(lb), rlen = strlen(rb);
	dp[0] = 1, sum[1] = 1;
	for (int i = 1; i <= n; i++) {
		int &res = dp[i] = 0;
		auto GetSum = [&](char *s, int len, int *z) -> int {
			int ans = sum[i];
			if (i - len + 1 >= 0) SUB(ans, sum[i - len + 1]);
			if (len > 1 && a[i - 1] == '0') {
				ADD(ans, dp[i - 1]);
			}
			int x = i - len;
			if (x < 0) return ans;
			if (a[x] == '0') {
				if (len == 1 && s[0] > '0') ADD(ans, dp[x]);
				return ans;
			}
			int lcp = z[x];
			if (lcp < len && s[lcp] > a[x + lcp]) ADD(ans, dp[x]);
			return ans;
		};
		ADD(res, GetSum(rb, rlen, zr));
		SUB(res, GetSum(lb, llen, zl));
		sum[i + 1] = sum[i];
		if (a[i] != '0') ADD(sum[i + 1], res);
	}
	printf("%d\n", dp[n]);
	return 0;
}