// Given an array A[1..N], find the number of nom-empty subsequences of A[L..R] that sums up to K

#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N = 1e5 + 1, MAX_Q = 1e5;
int SQRT, t[MAX_N], id[MAX_N], idL[MAX_N], idR[MAX_N], cntL[MAX_N], cntR[MAX_N]; 
long long a[MAX_N], res, ans[MAX_Q];
inline bool comp_a (const int &i, const int &j) {
	return (a[i] < a[j]);
}
struct TQuery { int L, R, id; } Q[MAX_Q];
inline bool operator < (const TQuery &Q1, const TQuery &Q2) { 
	return (Q1.L / SQRT < Q2.L / SQRT || Q1.L / SQRT == Q2.L / SQRT && Q1.R < Q2.R); 
}

int main() {
	int n, k; scanf("%d%d", &n, &k);
	SQRT = floor(sqrt(++n));
	for (int i = 1; i < n; ++i)
		scanf("%d", &t[i]);
	for (int i = 1; i < n; ++i) {
		scanf("%lld", &a[i]);
		if (t[i] == 2) 
			a[i] = -a[i];
		a[i] += a[i - 1];
		id[i] = i;
	}
	sort(id, id + n, comp_a);
	sort(a, a + n);
	for (int i = 0, L = 0, R = 0; i < n; ++i) {
		if (binary_search(a, a + n, a[i] + k))
			idL[id[i]] = L += !i || a[i] ^ a[i - 1];
		if (binary_search(a, a + n, a[i] - k))
			idR[id[i]] = R += !i || a[i] ^ a[i - 1];
	}
	int q; scanf("%d", &q);
	for (int i = 0; i < q; ++i) {
		int L, R; scanf("%d%d", &L, &R);
		Q[i] = {--L, R, i};
	}
	sort(Q, Q + q);
	for (int i = 0, L = 0, R = -1; i < q; ++i) {
		while (R < Q[i].R) {
			++R;
			if (idR[R]) {
				res += cntL[idR[R]];
				++cntR[idR[R]];
			}
			++cntL[idL[R]];
		}
		while (R > Q[i].R) {
			--cntL[idL[R]];
			if (idR[R]) {
				res -= cntL[idR[R]];
				--cntR[idR[R]];
			}
			--R;
		}
		while (L < Q[i].L) {
			--cntR[idR[L]];
			if (idL[L]) {
				res -= cntR[idL[L]];
				--cntL[idL[L]];
			}
			++L;
		}
		while (L > Q[i].L) {
			--L;
			if (idL[L]) {
				res += cntR[idL[L]];
				++cntL[idL[L]];
			}
			++cntR[idR[L]];
		}
		ans[Q[i].id] = res;
	}
	for (int i = 0; i < q; ++i)
		printf("%lld\n", ans[i]);
}