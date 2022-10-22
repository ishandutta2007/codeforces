#include <bits/stdc++.h>
using namespace std;

const long long BAD = -2333;
const long long EPT = -1;
const long long INF = 0x3f3f3f3f3f3f3f3f;

int n, t;
long long k;
long long A[210], B[210], C[210];
long long SB[210], SA[210];
long long f[210][210]; // []
long long g[210][210]; // [)

long long Ceil(long long x, long long y) {
	return (x + y - 1) / y;
}

long long Floor(long long x, long long y) {
	return x / y - (x % y == 0);
}

long long GetF(int n, int t);
long long GetG(int n, int t);
long long GetPre(int n, int t);
long long GetPpp(int n, int t);

long long GetG(int n, int t) {
	if (g[n][t] != EPT) return g[n][t];
	if (SB[n] * t == 0) return BAD;
	long long &res = g[n][t] = INF;
	if (B[n - 1] * t <= C[n - 1]) {
		long long tmp = GetF(n - 1, t);
		if (tmp != BAD) {
			long long rush = tmp * k - SB[n - 1] * t;
			long long cur = B[n - 1] * t;
			if (rush < cur) res = min(res, tmp);
		}
	}
	for (int i = 1; i < t; i++) {
		long long tmp = GetG(n, i);
		if (tmp == BAD) continue;
		long long cur = SB[n] * i - tmp * k;
		long long lim = C[n - 1] - B[n - 1] * (t - i);
		if (cur % k <= lim) {
			lim = min(cur, (lim - cur % k) / k * k + cur % k);
			tmp += (cur - lim) / k;
			cur = lim + (t - i) * B[n - 1];
			long long nxt = GetF(n - 1, t - i);
			if (nxt == BAD) continue;
			long long rush = nxt * k - SB[n - 1] * (t - i);
			if (cur > rush) res = min(res, tmp + nxt);
		}
	}
	if (res == INF) res = BAD;
	return res;
}

long long GetF(int n, int t) {
	if (n == 0) return 0;
	if (f[n][t] != EPT) return f[n][t];
	long long &res = f[n][t] = Ceil(SB[n] * t, k);
	if (t * B[n - 1] <= C[n - 1] && GetF(n - 1, t) != BAD) return res;
	for (int i = 1; i < t; i++) {
		long long tmp = GetG(n, i);
		if (tmp == BAD) continue;
		long long cur = SB[n] * i - tmp * k;
		cur %= k;
		if (cur + (t - i) * B[n - 1] <= C[n - 1] && GetF(n - 1, t - i) != BAD) return res;
	}
	return res = BAD;
}

long long pre[210][210], ppp[210][210];

long long GetPpp(int n, int t) {
	if (n == 0) return 0;
	if (ppp[n][t] != EPT) return ppp[n][t];
	if (SA[n] + SB[n] * t == 0) return BAD;
	long long &res = ppp[n][t] = INF;
	if (A[n - 1] + B[n - 1] * t <= C[n - 1]) {
		long long tmp = GetPre(n - 1, t);
		if (tmp != BAD) {
			long long rush = tmp * k - SA[n - 1] - SB[n - 1] * t;
			if (A[n - 1] + B[n - 1] * t > rush) res = min(res, tmp);
		}
	}
	for (int i = 0; i < t; i++) {
		long long tmp = GetPpp(n, i);
		if (tmp == BAD) continue;
		long long cur = SA[n] + SB[n] * i - tmp * k;
		long long lim = C[n - 1] - B[n - 1] * (t - i);
		if (cur % k <= lim) {
			lim = min(cur, (lim - cur % k) / k * k + cur % k);
			tmp += (cur - lim) / k;
			cur = lim + (t - i) * B[n - 1];
			long long nxt = GetF(n - 1, t - i);
			if (nxt == BAD) continue;
			long long rush = nxt * k - SB[n - 1] * (t - i);
			if (cur > rush) res = min(res, tmp + nxt);
		}
	}
	if (res == INF) res = BAD;
	return res;
}

long long GetPre(int n, int t) {
	if (n == 0) return 0;
	if (pre[n][t] != EPT) return pre[n][t];
	long long &res = pre[n][t] = Ceil(SA[n] + SB[n] * t, k);
	if (A[n - 1] + t * B[n - 1] <= C[n - 1] && GetPre(n - 1, t) != BAD) return res;
	for (int i = 0; i < t; i++) {
		long long tmp = GetPpp(n, i);
		if (tmp == BAD) continue;
		long long cur = SA[n] + SB[n] * i - tmp * k;
		cur %= k;
		if (cur + (t - i) * B[n - 1] <= C[n - 1] && GetF(n - 1, t - i) != BAD) return res;
	}
	return res = BAD;
}

long long suc[210][210];

long long GetSuc(int n, int t) {
	if (n == 0) return 0;
	if (suc[n][t] != EPT) return suc[n][t];
	long long &res = suc[n][t] = INF;
	if (B[n - 1] * t <= C[n - 1]) res = min(res, GetSuc(n - 1, t));
	for (int i = 1; i < t; i++) {
		long long tmp = GetG(n, i);
		if (tmp == BAD) continue;
		long long cur = SB[n] * i - tmp * k;
		long long lim = C[n - 1] - B[n - 1] * (t - i);
		if (lim >= cur % k) {
			lim = min(cur, (lim - cur % k) / k * k + cur % k);
			tmp += (cur - lim) / k;
			res = min(res, tmp + GetSuc(n - 1, t - i));
		} else if (lim >= 0) {
			lim = 0;
			tmp += (cur + k - 1) / k;
			res = min(res, tmp + GetSuc(n - 1, t - i));
		}
	}
	return res;
}

long long Solve(int n, int t) {
	if (n == 0) return 0;
	if (A[n - 1] + B[n - 1] * t <= C[n - 1]) return Solve(n - 1, t);
	A[n] = 2000000000, B[n] = 2000000000, C[n] = INF;
	SA[n + 1] = SA[n] + A[n], SB[n + 1] = SB[n] + B[n];
	long long ans = INF;
	for (int i = 0; i < t; i++) {
		long long tmp = GetPpp(n, i);
		if (tmp == BAD) continue;
		long long cur = SA[n] + SB[n] * i - tmp * k;
		long long lim = C[n - 1] - (t - i) * B[n - 1];
		if (cur % k <= lim) {
			lim = min(cur, (lim - cur % k) / k * k + cur % k);
			tmp += (cur - lim) / k;
			ans = min(ans, tmp + GetSuc(n - 1, t - i));
		}
	}
	for (int i = 0; i < t; i++) {
		long long tmp = GetPpp(n + 1, i);
		if (tmp == BAD) continue;
		ans = min(ans, tmp + GetSuc(n, t - i));
	}
	return ans;
}

int main() {
	memset(f, EPT, sizeof(f)), memset(g, EPT, sizeof(g)), memset(pre, EPT, sizeof(pre)), memset(ppp, EPT, sizeof(ppp));
	memset(suc, EPT, sizeof(suc));
	scanf("%d%d%lld", &n, &t, &k);
	for (int i = 0; i < n; i++) {
		scanf("%lld%lld%lld", &A[i], &B[i], &C[i]);
		SB[i + 1] = SB[i] + B[i], SA[i + 1] = SA[i] + A[i];
	}
	printf("%lld\n", Solve(n, t));
	return 0;
}